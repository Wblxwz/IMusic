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
//酷我和QQ源 歌词
//歌词匹配时间
//Love歌单
//本地歌曲记录？

//移动bug
//pre next 对我的最爱的bug
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
	void myLove();
	void addLove();
	void deleteLove(const QString& name, const QString& id);

	void parseJson(const QString& json);
	void parseJson_2(const QString& json);
	void parseJson_3(const QString& json);
	void parseJson_4(const QString& json);
	void myParseJson(const QString& json);

	void replyFinished(QNetworkReply* reply);
	void replyFinished_2(QNetworkReply* reply);
	void replyFinished_3(QNetworkReply* reply);
	void replyFinished_4(QNetworkReply* reply);
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
private:
	Ui::IMusicClass* ui;

	QStandardItemModel* model, * model_2, * model_3;
	QMediaPlayer* player;
	QStringList lists;
	QAudioOutput* output;

	QNetworkAccessManager* manager, * manager_2, * manager_3, * manager_4;
	QNetworkRequest* request, * request_2, * request_3, * request_4;

	QString durationTime;
	QString positionTime;
	QString songname;

	QUrl neturl;

	QPoint clickPoint;

	QSettings* set;

	std::unordered_map<int, QUrl> map;
	std::unordered_map<QString, QUrl> qq_map;

	bool isMute = false;
	bool isComment = false;
	bool isFullScreen = false;

	int p = 0;
	int tindex = 0;
};
