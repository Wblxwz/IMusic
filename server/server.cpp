#include <sys/epoll.h>
#include <sys/socket.h>
#include <assert.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <iostream>

#include "connpool.h"
#include "server.h"
#include "threadpool.h"

void setNonBlock(const int& fd)
{
	int flag = fcntl(fd, F_GETFL);
	assert(flag >= 0);
	flag |= O_NONBLOCK;
	assert(fcntl(fd, F_SETFL, flag) >= 0);
}

void addFd(const int& epollfd, const int& fd, bool oneshot)
{
	epoll_event events;
	events.data.fd = fd;
	events.events = EPOLLIN | EPOLLET | EPOLLHUP;
	if (oneshot)
		events.events |= EPOLLONESHOT;
	setNonBlock(fd);
	assert(epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &events) != -1);
}

int main(int argc, char* argv[])
{
	ThreadPool* pool = &ThreadPool::getThreadPool();
	ConnPool* cpool = &ConnPool::getConnPool();
	cpool->init("localhost", "root", "a2394559659", "IMusic", 3306, 5);

	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(listenfd >= 0);

	sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);

	int tmp = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &tmp, sizeof(tmp));
	//close前等待一段时间并进行发送缓冲区内数据直到超时
	setsockopt(listenfd, SOL_SOCKET, SO_LINGER, &tmp, sizeof(tmp));

	int ret = bind(listenfd, (sockaddr*)&addr, sizeof(addr));
	assert(ret >= 0);

	ret = listen(listenfd, 5);
	assert(ret >= 0);

	int epollfd = epoll_create(5);
	assert(epollfd != -1);

	addFd(epollfd, listenfd, false);

	epoll_event eve[1024];

	while (true)
	{
		int num = epoll_wait(epollfd, eve, 1024, -1);
		if (num < 0 && errno != EINTR)
			break;
		for (int i = 0; i < num; ++i)
		{
			int fd = eve[i].data.fd;
			if (fd == listenfd)
			{
				sockaddr_in caddr;
				socklen_t tmplen = sizeof(caddr);
				while (true)
				{
					int connfd = accept(listenfd, (sockaddr*)&caddr, &tmplen);
					if (connfd < 0)
						break;
					addFd(epollfd, connfd, true);
				}
			}
			else if (eve[i].events & EPOLLIN)
			{
				Worker* worker = new Worker(eve[i].data.fd);
				pool->add(worker);
			}
		}
	}

	close(epollfd);
	close(listenfd);

	return 0;
}