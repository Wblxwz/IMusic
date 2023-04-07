#pragma once

#include <mysql.h>

class SqlOperate
{
public:
	SqlOperate() {}
	~SqlOperate() {}

	void useDb(MYSQL* conn);

	const char* select(MYSQL* conn, const char* sql);
	bool noReturn(MYSQL* conn, const char* sql);
};