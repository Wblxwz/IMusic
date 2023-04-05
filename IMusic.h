#pragma once

#include <QtWidgets/QWidget>
#include <qmediaplayer.h>
#include <qfiledialog.h>
#include <qdir.h>
#include <qstandarditemmodel.h>
#include <random>

#include "ui_IMusic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class IMusicClass; };
QT_END_NAMESPACE

enum pattern
{
	loop,
	listloop,
	randomloop
};

class IMusic : public QWidget
{
	Q_OBJECT

public:
	IMusic(QWidget* parent = nullptr);
	~IMusic();

	void init();
	void open();
	void play();
	void pre();
	void next();
	void next(const int index);
	void change();
	const int random(const int n) const;
	void changePage(const int& index);
	void changePattern();
	void onPositionChanged(qint64 pos);
	void onDurationChanged(qint64 dur);
private:
	Ui::IMusicClass* ui;

	QStandardItemModel* model;
	QMediaPlayer* player;
	QStringList lists;
	QAudioOutput* output;

	QString durationTime;
	QString positionTime;

	bool isPlay = false;
	bool isMute = false;
	bool isFullScreen = false;

	int p = 0;
};
