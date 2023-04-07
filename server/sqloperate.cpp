#include <string>
#include <string.h>
#include <assert.h>
#include <iostream>

#include "connpool.h"
#include "sqloperate.h"

void SqlOperate::useDb(MYSQL* conn)
{
	std::string sql = "USE IMusic";
	int ret = mysql_real_query(conn, sql.c_str(), sql.length());
	assert(ret == 0);
}

const char* SqlOperate::select(MYSQL* conn, const char* sql)
{
	int ret = mysql_real_query(conn, sql, strlen(sql));
	assert(ret == 0);
	MYSQL_RES* res = mysql_store_result(conn);
	MYSQL_ROW row = mysql_fetch_row(res);
	if (row)
		return row[0];
	return mysql_error(conn);
}

bool SqlOperate::noReturn(MYSQL* conn, const char* sql)
{
	int ret = mysql_real_query(conn, sql, strlen(sql));
	if (ret == 0)
		return true;
	else
		return false;
}