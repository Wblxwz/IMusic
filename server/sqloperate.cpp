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

bool SqlOperate::addLove(MYSQL* conn, const char* name, const char* id, const char* song, const char* singer)
{
	char sql[100];
	sprintf(sql, "INSERT INTO loves(user,id,song,singer) VALUES('%s','%s','%s','%s')", name, id, song, singer);
	int ret = mysql_real_query(conn, sql, strlen(sql));
	if (ret == 0)
		return true;
	else
		return false;
}

void SqlOperate::getJson(MYSQL* conn, char* json, const char* name)
{
	char sql[100], sjson[4096];
	sprintf(sql, "SELECT * FROM loves WHERE user = '%s'", name);
	int ret = mysql_real_query(conn, sql, strlen(sql));
	assert(ret == 0);
	MYSQL_RES* res = mysql_store_result(conn);
	MYSQL_ROW row;
	sprintf(json, "{\n    \"data\": [\n");
	for (int i = 0; i < res->row_count - 1; ++i)
	{
		row = mysql_fetch_row(res);
		sprintf(json + strlen(json), "        {\n            \"id\": \"");
		sprintf(json + strlen(json), row[1]);
		sprintf(json + strlen(json), "\", \n            \"song\": \"");
		sprintf(json + strlen(json), row[2]);
		sprintf(json + strlen(json), "\", \n            \"singer\": \"");
		sprintf(json + strlen(json), row[3]);
		sprintf(json + strlen(json), "\"\n");
		sprintf(json + strlen(json), "        },\n");
	}
	row = mysql_fetch_row(res);
	sprintf(json + strlen(json), "        {\n            \"id\": \"");
	sprintf(json + strlen(json), row[1]);
	sprintf(json + strlen(json), "\", \n            \"song\": \"");
	sprintf(json + strlen(json), row[2]);
	sprintf(json + strlen(json), "\", \n            \"singer\": \"");
	sprintf(json + strlen(json), row[3]);
	sprintf(json + strlen(json), "\"\n");
	sprintf(json + strlen(json), "        }\n");
	sprintf(json + strlen(json), "    ]\n}");
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