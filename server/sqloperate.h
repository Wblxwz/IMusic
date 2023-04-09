#pragma once

#include <mysql.h>

class SqlOperate
{
public:
	SqlOperate() {}
	~SqlOperate() {}

	void useDb(MYSQL* conn);

	bool addLove(MYSQL* conn, const char* name, const char* id, const char* song, const char* singer);
	void getJson(MYSQL* conn, char* json, const char* name);
	const char* select(MYSQL* conn, const char* sql);
	bool noReturn(MYSQL* conn, const char* sql);
};