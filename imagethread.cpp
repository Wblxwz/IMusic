#include "imagethread.h"

ImageThread::ImageThread(QObject* parent)
{
}

void ImageThread::run()
{
	while (true)
	{
		++num;
		if (num > 6)
			num = 1;
		emit freshImage(num);
		QThread::sleep(3);
	}
}
