#pragma once

#include <QtWidgets/QWidget>
#include <qmediaplayer.h>
#include <qstandarditemmodel.h>
#include <qnetworkreply.h>
#include <unordered_map>
#include <qmouseevent>
#include <qsettings.h>

#include "ui_IMusic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class IMusicClass; };
QT_END_NAMESPACE

/*ToDo:
//歌词
//切换源搜索
//Love歌单

//移动bug
//列表循环 随机 模式bug
*/

enum pattern
{
	loop,
	listloop,
	randomloop
};

enum searchmode
{
	netease,
	kuwo,
	qq
};

class IMusic : public QWidget
{
	Q_OBJECT

public:
	IMusic(QWidget* parent = nullptr);
	~IMusic();

	void init();
	void open();
	void doublePlay(const QUrl& url);
	void play();
	void pre();
	void next();
	void next(const int index);
	void change();
	void changeSkin(const int c);
	const int random(const int n) const;
	void changePage(const int& index);
	void changePattern();
	void onPositionChanged(qint64 pos);
	void onDurationChanged(qint64 dur);

	void log();
	void search();
	const int getNewCfd();
	void version();
	void onlinePlay();
	void parseJson(const QString& json);
	void parseJson_2(const QString& json);
	void replyFinished(QNetworkReply* reply);
	void replyFinished_2(QNetworkReply* reply);
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
private:
	Ui::IMusicClass* ui;

	QStandardItemModel* model, * model_2;
	QMediaPlayer* player;
	QStringList lists;
	QAudioOutput* output;

	QNetworkAccessManager* manager, * manager_2;
	QNetworkRequest* request, * request_2;

	QString durationTime;
	QString positionTime;

	QUrl neturl;

	QPoint clickPoint;

	QSettings* set;

	std::unordered_map<int, QUrl> map;

	bool isMute = false;
	bool isFullScreen = false;

	int p = 0;
};
