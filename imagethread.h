#pragma once

#include <qthread.h>
#include <unordered_map>
#include <qurl.h>
#include <qstandarditemmodel.h>

#include "IMusic.h"

class ImageThread :public QThread
{
	Q_OBJECT
public:
	explicit ImageThread(QObject* parent = nullptr);
	~ImageThread() = default;
protected:
	void run();
signals:
	void freshImage(int num);
private:
	int num = 0;
};