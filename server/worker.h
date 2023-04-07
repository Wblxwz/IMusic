#pragma once

class Worker
{
public:
	Worker(const int cfd) :cfd(cfd) { }
	void work();
	~Worker() = default;
private:
	int cfd;
};