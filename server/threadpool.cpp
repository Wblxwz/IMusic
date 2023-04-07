

#include "threadpool.h"

ThreadPool& ThreadPool::getThreadPool(const int& threadnum, const int& maxrequestsnum)
{
	static ThreadPool pool(threadnum, maxrequestsnum);
	return pool;
}

void* ThreadPool::worker(void* arg)
{
	ThreadPool* pool = (ThreadPool*)arg;
	pool->run();
	return pool;
}

void ThreadPool::add(Worker* worker)
{
	std::unique_lock<std::mutex> locker(mutex);
	if (deque.size() > maxrequestsnum)
	{
		locker.unlock();
		return;
	}
	deque.push_back(worker);
	sem_post(&sem);
}

void ThreadPool::run()
{
	while (true)
	{
		sem_wait(&sem);
		std::unique_lock<std::mutex> locker(mutex);

		if (deque.empty())
		{
			locker.unlock();
			continue;
		}

		Worker* request = deque.front();
		deque.pop_front();
		locker.unlock();

		if (!request)
			continue;

		request->work();
	}
}