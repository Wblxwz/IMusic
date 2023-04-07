#include <sys/socket.h>
#include <iostream>
#include <string>

#include "connRAII.h"
#include "sqloperate.h"
#include "worker.h"

void Worker::work()
{
	char buf[1024];
	recv(cfd, buf, sizeof(buf), NULL);

	ConnPool* pool = &ConnPool::getConnPool();
	MYSQL* conn = nullptr;
	ConnRAII(pool, &conn);
	SqlOperate sql;
	sql.useDb(conn);

	std::string s(buf);
	if (s.find("version:v") != -1)
	{
		std::string version;
		for (int startPos = 9; startPos < s.size(); ++startPos)
			version.push_back(s[startPos]);
		const char* tbuf;
		if (version == "1.0")
			tbuf = "true";
		else
			tbuf = "false";
		send(cfd, tbuf, sizeof(tbuf), NULL);
	}
	if (s.find("login:") != -1)
	{
		int pwdStart = s.find("logpwd:");
		std::string name, pwd;
		for (int nameStart = 6; nameStart < pwdStart; ++nameStart)
			name.push_back(s[nameStart]);
		for (int pos = pwdStart + 7; pos < s.size(); ++pos)
			pwd.push_back(s[pos]);
		char sel[200];
		sprintf(sel, "SELECT pwd FROM users WHERE name = '%s'", name.c_str());
		std::string tsel = sql.select(conn, sel);
		char ret[100];
		if (tsel == pwd)
			sprintf(ret, "true");
		else
			sprintf(ret, "false");
		send(cfd, ret, sizeof(ret), NULL);
	}
	if (s.find("signup:") != -1)
	{
		int pwdStart = s.find("signpwd:");
		std::string name, pwd;
		for (int nameStart = 7; nameStart < pwdStart; ++nameStart)
			name.push_back(s[nameStart]);
		for (int pos = pwdStart + 8; pos < s.size(); ++pos)
			pwd.push_back(s[pos]);
		char insert[200];
		sprintf(insert, "INSERT INTO users (name,pwd) VALUES('%s','%s')", name.c_str(), pwd.c_str());
		char ttbuf[10];
		if (sql.noReturn(conn, insert))
			sprintf(ttbuf, "true");
		else
			sprintf(ttbuf, "false");
		send(cfd, ttbuf, sizeof(ttbuf), NULL);
	}
}
