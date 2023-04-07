#pragma once

#include <mutex>
#include <semaphore.h>
#include <mysql.h>
#include <deque>

class ConnPool
{
public:
	static ConnPool& getConnPool();

	MYSQL* getConn();
	bool releaseConn(MYSQL* conn);
	void init(const std::string& host, const std::string& user, const std::string& pwd, const std::string& dbname, const int& port, const int& maxconn);
private:
	ConnPool(){}
	~ConnPool()
	{
		std::lock_guard<std::mutex> locker(mutex);
		if(!deque.empty())
		{
			for (auto& i : deque)
				mysql_close(i);
			curconn = 0;
			freecon = 0;
			deque.clear();
		}
		sem_destroy(&sem);
	}
	std::deque<MYSQL*> deque;
	std::string host, user, pwd, dbname;
	int port, maxconn, curconn = 0, freecon = 0;
	std::mutex mutex;
	sem_t sem;
};