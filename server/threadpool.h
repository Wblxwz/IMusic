#pragma once

#include <mutex>
#include <semaphore.h>
#include <deque>
#include <assert.h>
#include <pthread.h>

#include "worker.h"

class ThreadPool
{
public:
	static ThreadPool& getThreadPool(const int& threadnum = 8, const int& maxrequestsnum = 10000);

	static void* worker(void* arg);
	void add(Worker* worker);
	void run();
private:
	ThreadPool(const int& threadnum, const int& maxrequestsnum)
	{
		sem_init(&sem, 0, 0);
		assert(threadnum > 0 && maxrequestsnum > 0);
		threads = new pthread_t[threadnum];
		assert(threads);
		for (int i = 0; i < threadnum; ++i)
		{
			if (pthread_create(threads + i, NULL, worker, this) != 0)
			{
				delete[] threads;
				abort();
			}
			if (pthread_detach(threads[i]) != 0)
			{
				delete[] threads;
				abort();
			}
		}
	}
	~ThreadPool()
	{
		std::lock_guard<std::mutex> locker(mutex);
		if (!deque.empty())
			for (auto& i : deque)
				delete i;
		sem_destroy(&sem);
		delete[] threads;
	}

	std::deque<Worker*> deque;

	pthread_t* threads;

	std::mutex mutex;

	sem_t sem;

	int threadnum, maxrequestsnum;
};