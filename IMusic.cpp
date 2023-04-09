#include <qaudiooutput.h>
#include <qurl.h>
#include <qmessagebox.h>
#include <qnetworkaccessmanager.h>
#include <qnetworkrequest.h>
#include <assert.h>
#include <random>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qjsonarray.h>
#include <qfiledialog.h>
#include <qdir.h>
#include <assert.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <qregularexpression.h>

#pragma comment (lib, "ws2_32.lib")

#include "setting.h"
#include "IMusic.h"
#include "imagethread.h"
#include "login.h"

IMusic::IMusic(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::IMusicClass())
{
	ui->setupUi(this);
	player = new QMediaPlayer;
	output = new QAudioOutput;

	init();
}

IMusic::~IMusic()
{
	delete ui;
	delete model, model_2;
	delete player;
	delete output;
	delete manager, manager_2, manager_3;
	delete request, request_2, request_3;
	delete set;
}

void IMusic::init()
{
	//this->setMinimumSize(1029, 673);
	this->setFixedSize(1029, 616);
	this->setWindowFlags(Qt::FramelessWindowHint);

	WSADATA wsadata;
	assert(WSAStartup(MAKEWORD(2, 2), &wsadata) == 0);

	QFontMetrics elideFont(ui->name->font());

	set = new QSettings("C:/IMusic/settings.ini", QSettings::IniFormat);
	int cc = set->value("settings/skin").toString().toInt();
	changeSkin(cc);

	float initvolume = set->value("settings/volume").toFloat();
	output->setVolume(initvolume);
	ui->volumebar->setValue(initvolume * 100);

	ui->geci->setPlainText("推荐使用网易云搜索");
	ui->geci->setAlignment(Qt::AlignCenter);

	model = new QStandardItemModel;
	model->setColumnCount(3);
	model->setHeaderData(0, Qt::Horizontal, "歌名");
	model->setHeaderData(1, Qt::Horizontal, "歌手");
	model->setHeaderData(2, Qt::Horizontal, "本地路径");

	model_2 = new QStandardItemModel;
	model_2->setColumnCount(3);
	model_2->setHeaderData(0, Qt::Horizontal, "歌名");
	model_2->setHeaderData(1, Qt::Horizontal, "歌手");
	model_2->setHeaderData(2, Qt::Horizontal, "ID");

	model_3 = new QStandardItemModel;
	model_3->setColumnCount(3);
	model_3->setHeaderData(0, Qt::Horizontal, "歌名");
	model_3->setHeaderData(1, Qt::Horizontal, "歌手");
	model_3->setHeaderData(2, Qt::Horizontal, "ID");

	ui->tableView->setModel(model);
	ui->tableView->setColumnWidth(0, 400);
	ui->tableView->setColumnWidth(1, 380);
	ui->tableView->setColumnWidth(2, 0);
	ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(232, 171, 168);}");
	ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(232, 171, 168);}");
	ui->tableView->verticalHeader()->setVisible(false);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	ui->searchlist->setModel(model_2);
	ui->searchlist->setColumnWidth(0, 100);
	ui->searchlist->setColumnWidth(1, 90);
	ui->searchlist->setColumnWidth(2, 0);
	ui->searchlist->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(232, 171, 168);}");
	ui->searchlist->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(232, 171, 168);}");
	ui->searchlist->verticalHeader()->setVisible(false);
	ui->searchlist->setEditTriggers(QAbstractItemView::NoEditTriggers);


	ui->loves->setModel(model_3);
	ui->loves->setColumnWidth(0, 200);
	ui->loves->setColumnWidth(1, 90);
	ui->loves->setColumnWidth(2, 0);
	ui->loves->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(232, 171, 168);}");
	ui->loves->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(232, 171, 168);}");
	ui->loves->verticalHeader()->setVisible(false);
	ui->loves->setEditTriggers(QAbstractItemView::NoEditTriggers);

	QStringList list;
	list << "网易云" << "酷我" << "QQ";
	ui->huanyuan->addItems(list);

	ui->geci->setReadOnly(true);
	ui->comments->setReadOnly(true);

	player->setAudioOutput(output);

	int pp = set->value("settings/pattern").toInt();
	switch (pp)
	{
	case loop:
		ui->loopbtn->setStyleSheet("border-image: url(:/IMusic/images/danqu.png);");
		player->setLoops(QMediaPlayer::Infinite);
		break;
	case listloop:
		ui->loopbtn->setStyleSheet("border-image: url(:/IMusic/images/loop.png);");
		player->setLoops(QMediaPlayer::Once);
		break;
	case randomloop:
		ui->loopbtn->setStyleSheet("border-image: url(:/IMusic/images/random.png);");
		player->setLoops(QMediaPlayer::Once);
		break;
	default:
		break;
	}

	ImageThread* it = new ImageThread;
	connect(it, &QThread::finished, it, &QThread::deleteLater);

	manager = new QNetworkAccessManager(this);
	manager_2 = new QNetworkAccessManager(this);
	manager_3 = new QNetworkAccessManager(this);
	manager_4 = new QNetworkAccessManager(this);
	request = new QNetworkRequest;
	request_2 = new QNetworkRequest;
	request_3 = new QNetworkRequest;
	request_4 = new QNetworkRequest;

	connect(manager, &QNetworkAccessManager::finished, this, &IMusic::replyFinished);
	connect(manager_2, &QNetworkAccessManager::finished, this, &IMusic::replyFinished_2);
	connect(manager_3, &QNetworkAccessManager::finished, this, &IMusic::replyFinished_3);
	connect(manager_4, &QNetworkAccessManager::finished, this, &IMusic::replyFinished_4);

	connect(ui->open, &QPushButton::clicked, this, &IMusic::open);
	connect(ui->searchbtn, &QPushButton::clicked, this, &IMusic::search);
	connect(ui->versionbtn, &QPushButton::clicked, this, &IMusic::version);
	connect(ui->userbtn, &QPushButton::clicked, this, &IMusic::log);
	connect(ui->lovebtn, &QPushButton::clicked, this, &IMusic::myLove);
	connect(ui->hongxinbtn, &QPushButton::clicked, this, &IMusic::addLove);

	connect(ui->commentbtn, &QPushButton::clicked, this, [&]() {
		QString content;
		if(ui->stackedWidget->currentIndex() == 1)
			content = QString("http://music.163.com/api/v1/resource/comments/R_SO_4_%1?limit=50&offset=0").arg(model_2->index(ui->searchlist->currentIndex().row(), 2).data(2).toInt());
		else
			content = QString("http://music.163.com/api/v1/resource/comments/R_SO_4_%1?limit=50&offset=0").arg(model_3->index(ui->loves->currentIndex().row(), 2).data(2).toInt());
		request_4->setUrl(content);
		manager_4->get(*request_4);
		isComment = !isComment;
		if (isComment)
		{
			tindex = ui->stackedWidget->currentIndex();
			ui->stackedWidget->setCurrentIndex(3);
		}
		else
			ui->stackedWidget->setCurrentIndex(tindex);
		});
	connect(ui->skinbtn, &QPushButton::clicked, this, [&]() {
		setting* s = new setting(set->value("settings/skin").toString().toInt());
		connect(s, &setting::sigChangeSkin, this, [&](color c) {
			changeSkin(c);
			set->setValue("settings/skin", c);
			});
		s->exec();
		});
	connect(ui->searchlist, &QTableView::doubleClicked, this, [&]() {
		onlinePlay();
		});
	connect(ui->play, &QPushButton::clicked, this, [&]() {
		QString name;
		switch (ui->stackedWidget->currentIndex())
		{
		case 0:
			name = ui->tableView->currentIndex().data(0).toString();
			songname = name;
			ui->name->setText(elideFont.elidedText(name, Qt::ElideRight, ui->name->width()));
			break;
		case 1:
			name = ui->searchlist->currentIndex().data(0).toString();
			break;
		default:
			break;
		}
		play();
		});
	connect(ui->nextbtn, &QPushButton::clicked, this, [&]() {
		next();
		});
	connect(ui->prebtn, &QPushButton::clicked, this, &IMusic::pre);
	connect(player, &QMediaPlayer::mediaStatusChanged, this, [&]() {
		if (player->mediaStatus() == QMediaPlayer::EndOfMedia)
			switch (p)
			{
			case listloop:
				next();
				break;
			case randomloop:
				if (ui->stackedWidget->currentIndex() == 1)
					next(random(model_2->rowCount()));
				else
					next(random(model->rowCount()));
				break;
			default:
				break;
			}
		});
	connect(it, &ImageThread::freshImage, this, [&](int num) {
		switch (num)
		{
		case 1:
			ui->gundong->setStyleSheet("border-image:url(:/IMusic/images/1.png);");
			break;
		case 2:
			ui->gundong->setStyleSheet("border-image:url(:/IMusic/images/2.png);");
			break;
		case 3:
			ui->gundong->setStyleSheet("border-image:url(:/IMusic/images/3.png);");
			break;
		case 4:
			ui->gundong->setStyleSheet("border-image:url(:/IMusic/images/4.png);");
			break;
		case 5:
			ui->gundong->setStyleSheet("border-image:url(:/IMusic/images/5.png);");
			break;
		case 6:
			ui->gundong->setStyleSheet("border-image:url(:/IMusic/images/6.png);");
			break;
		default:
			break;
		}
		});
	connect(ui->tableView, &QTableView::doubleClicked, this, [&]() {
		QString index = model->data(model->index(ui->tableView->currentIndex().row(), 2)).toString();
		songname = ui->tableView->currentIndex().data(0).toString();
		ui->name->setText(elideFont.elidedText(songname, Qt::ElideRight, ui->name->width()));
		doublePlay(QUrl(index));
		});
	connect(ui->loves, &QTableView::doubleClicked, this, [&]() {
		onlinePlay();
		});
	connect(ui->timebar, &QSlider::sliderReleased, this, [&]() {
		player->setPosition(ui->timebar->value());
		});
	connect(player, &QMediaPlayer::positionChanged, this, [&]() {
		onPositionChanged(player->position());
		});
	connect(player, &QMediaPlayer::durationChanged, this, [&]() {
		onDurationChanged(player->duration());
		});
	connect(ui->minbtn, &QPushButton::clicked, this, [&]() {
		this->showMinimized();
		});
	connect(ui->maxbtn, &QPushButton::clicked, this, [&]() {
		isFullScreen = !isFullScreen;
		if (isFullScreen)
		{
			this->showMaximized();
			ui->maxbtn->setStyleSheet("border-image: url(:/IMusic/images/TitleBar/maximum_cancel.png);");
		}
		else
		{
			this->showNormal();
			ui->maxbtn->setStyleSheet("border-image: url(:/IMusic/images/TitleBar/maximum.png);");
		}
		});
	connect(ui->closebtn, &QPushButton::clicked, this, [&]() {
		this->close();
		});
	connect(ui->volumebar, &QSlider::valueChanged, this, [&]() {
		float volume = static_cast<float>(ui->volumebar->value()) / 100;
		set->setValue("settings/volume", volume);
		output->setVolume(volume);
		});
	connect(ui->volumebtn, &QPushButton::clicked, this, [&]() {
		isMute = !isMute;
		if (!isMute)
		{
			float volume = static_cast<float>(ui->volumebar->value()) / 100;
			output->setVolume(volume);
			ui->volumebtn->setStyleSheet("border-image: url(:/IMusic/images/volume.jpg);");
		}
		else
		{
			output->setVolume(0);
			ui->volumebtn->setStyleSheet("border-image: url(:/IMusic/images/novolume.png);");
		}
		});
	connect(ui->faxianbtn, &QPushButton::clicked, this, [&]() {
		changePage(0);
		ui->faxianbtn->setStyleSheet("background-color:rgb(237,65,65);");
		ui->liebiaobtn->setStyleSheet("");
		ui->netbtn->setStyleSheet("");
		ui->lovebtn->setStyleSheet("");
		});
	connect(ui->netbtn, &QPushButton::clicked, this, [&]() {
		changePage(1);
		ui->netbtn->setStyleSheet("background-color:rgb(237,65,65);");
		ui->faxianbtn->setStyleSheet("");
		ui->liebiaobtn->setStyleSheet("");
		ui->lovebtn->setStyleSheet("");
		});
	connect(ui->liebiaobtn, &QPushButton::clicked, this, [&]() {
		changePage(2);
		ui->liebiaobtn->setStyleSheet("background-color:rgb(237,65,65);");
		ui->faxianbtn->setStyleSheet("");
		ui->netbtn->setStyleSheet("");
		ui->lovebtn->setStyleSheet("");
		});
	connect(ui->name, &QPushButton::clicked, this, [&]() {
		QMessageBox::information(this, "歌曲名称", songname);
		});
	connect(ui->loopbtn, &QPushButton::clicked, this, &IMusic::changePattern);
	it->start();
}

void IMusic::open()
{
	QString currPath = QDir::currentPath();
	lists = QFileDialog::getOpenFileNames(this, "选择音频文件", currPath, "mp3文件(*.mp3);;所有文件(*.*)");
	for (int i = 0; i < lists.count(); ++i)
	{
		QFileInfo info(lists[i]);
		model->setItem(i, 0, new QStandardItem(info.fileName()));
		model->setItem(i, 1, new QStandardItem("无"));
		model->setItem(i, 2, new QStandardItem(lists[i]));
	}
	ui->stackedWidget->setCurrentIndex(2);
}

void IMusic::doublePlay(const QUrl& url)
{
	player->setSource(url);
	player->play();
	ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
	if (ui->stackedWidget->currentIndex() == 1 && ui->huanyuan->currentIndex() == 0)
	{
		QString geci = QString("https://music.163.com/api/song/lyric?id=%1&lv=1&kv=1&tv=-1").arg(model_2->index(ui->searchlist->currentIndex().row(), 2).data(2).toInt());
		request_3->setUrl(geci);
		manager_3->get(*request_3);
	}
	else if (ui->stackedWidget->currentIndex() == 4)
	{
		QString geci = QString("https://music.163.com/api/song/lyric?id=%1&lv=1&kv=1&tv=-1").arg(model_3->index(ui->loves->currentIndex().row(), 2).data(2).toInt());
		request_3->setUrl(geci);
		manager_3->get(*request_3);
	}
	else
	{
		ui->geci->setPlainText("该播放源暂不支持歌词搜索");
		ui->geci->setAlignment(Qt::AlignCenter);
	}
}

void IMusic::play()
{
	if (player->playbackState() == player->PausedState)
	{
		player->play();
		ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
	}
	else
	{
		ui->play->setStyleSheet("border-image:url(:/IMusic/images/play.png);");
		player->pause();
	}
}

void IMusic::pre()
{
	int index = ui->stackedWidget->currentIndex();
	int n = 0;
	int preIndex = 0;
	QString tindex;
	if (index == 2)
	{
		n = model->rowCount();
		preIndex = ui->tableView->currentIndex().row() - 1;
		if (preIndex < 0)
			preIndex = n - 1;
		tindex = model->data(model->index(preIndex, 2)).toString();
		player->setSource(QUrl(tindex));
		ui->tableView->setCurrentIndex(model->index(preIndex, 0));
	}
	else
	{
		n = model_2->rowCount();
		preIndex = ui->searchlist->currentIndex().row() - 1;
		if (preIndex < 0)
			preIndex = n - 1;
		ui->searchlist->setCurrentIndex(model_2->index(preIndex, 0));
		onlinePlay();
		if (ui->huanyuan->currentIndex() == 2)
		{
			QString id = ui->searchlist->currentIndex().data(2).toString();
			player->setSource(qq_map[id]);
		}
		else
		{
			int id = ui->searchlist->currentIndex().data(2).toInt();
			player->setSource(map[id]);
		}
	}
	player->play();
	ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
}

void IMusic::next()
{
	int index = ui->stackedWidget->currentIndex();
	int n = 0;
	int nextIndex = 0;
	QString tindex;
	if (index == 2)
	{
		n = model->rowCount();
		nextIndex = ui->tableView->currentIndex().row() + 1;
		if (nextIndex > n - 1)
			nextIndex = 0;
		tindex = model->data(model->index(nextIndex, 2)).toString();
		ui->tableView->setCurrentIndex(model->index(nextIndex, 0));
		QFontMetrics elideFont(ui->name->font());
		songname = ui->tableView->currentIndex().data(0).toString();
		ui->name->setText(elideFont.elidedText(ui->tableView->currentIndex().data(0).toString(), Qt::ElideRight, ui->name->width()));
		player->setSource(QUrl(tindex));
	}
	else
	{
		n = model_2->rowCount();
		nextIndex = ui->searchlist->currentIndex().row() + 1;
		if (nextIndex > n - 1)
			nextIndex = 0;
		ui->searchlist->setCurrentIndex(model_2->index(nextIndex, 0));
		onlinePlay();
		QFontMetrics elideFont(ui->name->font());
		songname = ui->searchlist->currentIndex().data(0).toString();
		ui->name->setText(elideFont.elidedText(ui->searchlist->currentIndex().data(0).toString(), Qt::ElideRight, ui->name->width()));
		if (ui->huanyuan->currentIndex() == 2)
		{
			QString id = ui->searchlist->currentIndex().data(2).toString();
			player->setSource(qq_map[id]);
		}
		else
		{
			int id = ui->searchlist->currentIndex().data(2).toInt();
			player->setSource(map[id]);
		}
	}
	player->play();
	ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
}

void IMusic::next(const int index)
{
	int cindex = ui->stackedWidget->currentIndex();
	QString nextIndex;
	if (cindex == 2)
	{
		if (index < 0 || index >= model->rowCount())
			return;
		nextIndex = model->data(model->index(index, 2)).toString();
		ui->tableView->setCurrentIndex(model->index(index, 0));
		QFontMetrics elideFont(ui->name->font());
		songname = ui->tableView->currentIndex().data(0).toString();
		ui->name->setText(elideFont.elidedText(ui->tableView->currentIndex().data(0).toString(), Qt::ElideRight, ui->name->width()));
		player->setSource(QUrl(nextIndex));
	}
	else
	{
		if (index < 0 || index >= model_2->rowCount())
			return;
		ui->searchlist->setCurrentIndex(model_2->index(index, 0));
		onlinePlay();
		QFontMetrics elideFont(ui->name->font());
		songname = ui->searchlist->currentIndex().data(0).toString();
		ui->name->setText(elideFont.elidedText(ui->searchlist->currentIndex().data(0).toString(), Qt::ElideRight, ui->name->width()));
		if (ui->huanyuan->currentIndex() == 2)
		{
			QString id = ui->searchlist->currentIndex().data(2).toString();
			player->setSource(qq_map[id]);
		}
		else
		{
			int id = ui->searchlist->currentIndex().data(2).toInt();
			player->setSource(map[id]);
		}
	}
	player->play();
	ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
}

void IMusic::changePage(const int& index)
{
	ui->stackedWidget->setCurrentIndex(index);
}

void IMusic::changeSkin(const int c)
{
	switch (c)
	{
	case moren:
		this->setStyleSheet("background-color: rgb(232, 171, 168);");
		break;
	case huang:
		this->setStyleSheet("background-color: rgb(255, 255, 153);");
		break;
	case bai:
		this->setStyleSheet("background-color: rgb(255, 255, 255);");
		break;
	case lan:
		this->setStyleSheet("background-color: rgb(153, 204, 255);");
		break;
	case lv:
		this->setStyleSheet("background-color: rgb(153, 204, 0);");
		break;
	case hei:
		this->setStyleSheet("background-color: rgb(51, 51, 51);");
		break;
	default:
		break;
	}
}

const int IMusic::random(const int n) const
{
	std::default_random_engine e;
	e.seed(time(nullptr));
	std::uniform_int_distribution<int> u(0, n - 1);
	return u(e);
}

void IMusic::changePattern()
{
	++p;
	if (p > randomloop)
		p = loop;
	set->setValue("settings/pattern", p);
	switch (p)
	{
	case loop:
		ui->loopbtn->setStyleSheet("border-image: url(:/IMusic/images/danqu.png);");
		player->setLoops(QMediaPlayer::Infinite);
		break;
	case listloop:
		ui->loopbtn->setStyleSheet("border-image: url(:/IMusic/images/loop.png);");
		player->setLoops(QMediaPlayer::Once);
		break;
	case randomloop:
		ui->loopbtn->setStyleSheet("border-image: url(:/IMusic/images/random.png);");
		player->setLoops(QMediaPlayer::Once);
		break;
	default:
		break;
	}
}

void IMusic::onPositionChanged(qint64 pos)
{
	if (ui->timebar->isSliderDown())
		return;
	ui->timebar->setSliderPosition(pos);
	int secs = pos / 1000;
	int mins = secs / 60;
	secs = secs % 60;
	positionTime = QString::asprintf("%d:%d", mins, secs);
	ui->time->setText(positionTime + "/" + durationTime);
}

void IMusic::onDurationChanged(qint64 dur)
{
	ui->timebar->setMaximum(dur);
	int secs = dur / 1000;
	int mins = secs / 60;
	secs = secs % 60;
	durationTime = QString::asprintf("%d:%d", mins, secs);
	ui->time->setText(positionTime + "/" + durationTime);
}

void IMusic::log()
{
	int cfd = getNewCfd();
	if (cfd == -1)
		return;
	QString name;
	login* l = new login(cfd, name);
	l->exec();
	ui->namelabel->setText(name);
}

void IMusic::search()
{
	int count = model_2->rowCount();
	model_2->removeRows(0, count);
	QString content;
	switch (ui->huanyuan->currentIndex())
	{
	case 0:
		content = QString("https://music-api.tonzhon.com/search?keyword=%1&platform=netease").arg(ui->searchedit->text());
		break;
	case 1:
		content = QString("https://music-api.tonzhon.com/search?keyword=%1&platform=kuwo").arg(ui->searchedit->text());
		break;
	case 2:
		content = QString("https://music-api.tonzhon.com/search?keyword=%1&platform=qq").arg(ui->searchedit->text());
		break;
	default:
		break;
	}
	request->setUrl(QUrl(content));
	manager->get(*request);
}

const int IMusic::getNewCfd()
{
	int cfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(cfd >= 0);

	unsigned long ul = 0;
	//cfd = ioctlsocket(cfd, FIONBIO, static_cast<unsigned long*>(&ul));

	sockaddr_in	caddr;
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(8888);
	inet_pton(AF_INET, "192.168.10.150", &caddr.sin_addr.S_un.S_addr);

	int ret = ::connect(cfd, (sockaddr*)&caddr, sizeof(caddr));
	if (ret != 0)
	{
		QMessageBox::critical(this, "连接服务器失败", "请检测当前网络状态或等待服务器修复");
		return -1;
	}

	return cfd;
}

void IMusic::version()
{
	int cfd = getNewCfd();

	char buf[1024];
	sprintf(buf, "version:%s", ui->versionbtn->text().toStdString().c_str());

	char tbuf[50]{ '0' };

	send(cfd, buf, sizeof(buf), NULL);
	recv(cfd, tbuf, sizeof(tbuf), NULL);

	if (QString(tbuf) == "true")
		QMessageBox::information(this, "版本号检查", "当前已是最新版本");
	else
		QMessageBox::critical(this, "版本号检查", "当前已有更新版本，请前往官网更新");

	closesocket(cfd);
}

void IMusic::onlinePlay()
{
	int index = 0;
	QString id;
	QString content;
	if (ui->stackedWidget->currentIndex() == 1)
	{
		index = ui->searchlist->currentIndex().row();
		id = model_2->data(model_2->index(index, 2)).toString();
		switch (ui->huanyuan->currentIndex())
		{
		case 0:
			content = QString("https://music-api.tonzhon.com/song_source/netease/%1").arg(id);
			break;
		case 1:
			content = QString("https://music-api.tonzhon.com/song_source/kuwo/%1").arg(id);
			break;
		case 2:
			content = QString("https://music-api.tonzhon.com/song_source/qq/%1").arg(id);
			break;
		default:
			break;
		}
	}
	else
	{
		index = ui->loves->currentIndex().row();
		id = model_3->data(model_3->index(index, 2)).toString();
		std::string tname = model_3->data(model_3->index(index, 0)).toString().toStdString();
		if(tname.find("网易云") != -1)
			content = QString("https://music-api.tonzhon.com/song_source/netease/%1").arg(id);
		else if(tname.find("QQ") != -1)
			content = QString("https://music-api.tonzhon.com/song_source/qq/%1").arg(id);
		else if(tname.find("酷我") != -1)
			content = QString("https://music-api.tonzhon.com/song_source/kuwo/%1").arg(id);
	}
	
	request_2->setUrl(QUrl(content));
	manager_2->get(*request_2);
	QFontMetrics elideFont(ui->name->font());
	if(ui->stackedWidget->currentIndex() == 1)
	{
		songname = ui->searchlist->currentIndex().data(0).toString();
		ui->name->setText(elideFont.elidedText(songname, Qt::ElideRight, ui->name->width()));
	}
	else
	{
		songname = ui->loves->currentIndex().data(0).toString();
		ui->name->setText(elideFont.elidedText(songname, Qt::ElideRight, ui->name->width()));
	}
}

void IMusic::myLove()
{
	if (ui->namelabel->text() == "请登录")
	{
		QMessageBox::critical(this, "获取歌单失败", "请先登录");
		return;
	}
	changePage(4);
	ui->faxianbtn->setStyleSheet("");
	ui->liebiaobtn->setStyleSheet("");
	ui->netbtn->setStyleSheet("");
	ui->lovebtn->setStyleSheet("background-color:rgb(237,65,65);");
	int count = model_3->rowCount();
	model_3->removeRows(0, count);
	int cfd = getNewCfd();
	char buf[50];
	sprintf(buf, "love:");
	sprintf(buf + strlen(buf), ui->namelabel->text().toStdString().c_str());
	int ret = send(cfd, buf, sizeof(buf), NULL);
	char jsonBuf[4096];
	recv(cfd, jsonBuf, sizeof(jsonBuf), NULL);
	myParseJson(jsonBuf);
}

void IMusic::addLove()
{
	if (ui->namelabel->text() == "请登录")
	{
		QMessageBox::critical(this, "错误", "请登录后再添加");
		return;
	}
	if (ui->stackedWidget->currentIndex() == 2)
		QMessageBox::warning(this, "抱歉", "本地歌曲暂不支持添加至我的最爱");
	/*if (ui->huanyuan->currentIndex() != 0)
	{
		QMessageBox::critical(this, "错误", "除网易云外暂不支持添加至我的最爱");
		return;
	}*/
	int cfd = getNewCfd();
	char buf[1024];
	sprintf(buf, "addLove:");
	QString name, id, song, singer;
	switch (ui->stackedWidget->currentIndex())
	{
	case 1:
		if (ui->huanyuan->currentIndex() == 1)
			song = ("酷我");
		else if (ui->huanyuan->currentIndex() == 2)
			song = ("QQ");
		else
			song = ("网易云");
		song += model_2->index(ui->searchlist->currentIndex().row(), 0).data(0).toString();
		singer = model_2->index(ui->searchlist->currentIndex().row(), 1).data(0).toString();
		id = model_2->index(ui->searchlist->currentIndex().row(), 2).data(0).toString();
		break;
	case 2:
		song = "本地";
		song += model->index(ui->tableView->currentIndex().row(), 0).data(0).toString();
		singer = model->index(ui->tableView->currentIndex().row(), 1).data(0).toString();
		id = model->index(ui->tableView->currentIndex().row(), 2).data(0).toString();
		break;
	default:
		break;
	}
	sprintf(buf + strlen(buf), ui->namelabel->text().toStdString().c_str());
	sprintf(buf + strlen(buf), "song:");
	sprintf(buf + strlen(buf), song.toStdString().c_str());
	sprintf(buf + strlen(buf), "singer:");
	sprintf(buf + strlen(buf), singer.toStdString().c_str());
	sprintf(buf + strlen(buf), "id:");
	sprintf(buf + strlen(buf), id.toStdString().c_str());
	send(cfd, buf, sizeof(buf), NULL);
	char tbuf[10];
	recv(cfd, tbuf, sizeof(tbuf), NULL);
	QString s(tbuf);
	if (s == "true")
	{
		QMessageBox::information(this, "添加成功", "已添加至我的最爱");
		myLove();
	}
	else
	{
		QMessageBox::information(this, "添加失败", "请等待服务器修复");
	}
}

void IMusic::parseJson(const QString& json)
{
	QString song_name, singername;
	QJsonParseError json_error;
	QJsonDocument document = QJsonDocument::fromJson(json.toUtf8(), &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (document.isObject())
		{
			QJsonObject rootObject = document.object();
			QJsonValue rootValue = rootObject.value("data");
			QJsonObject arrObject = rootValue.toObject();
			QJsonValue arrValue = arrObject.value("songs");
			if (arrValue.isArray())
			{
				QJsonArray array = arrValue.toArray();
				for (int i = 0; i < array.size(); ++i)
				{
					QJsonObject songObject = array.at(i).toObject();
					bool payment = false;
					int qq_payment = 1;
					int id = 0;
					QString qq_id = "";
					if (ui->huanyuan->currentIndex() == 2)
					{
						qq_payment = songObject.value("requiringPayment").toInt();
						qq_id = songObject.value("originalId").toString();
					}
					else
					{
						payment = songObject.value("requiringPayment").toBool();
						id = songObject.value("originalId").toInt();
					}
					singername.clear();
					if (ui->huanyuan->currentIndex() == 2)
					{
						if (qq_id == "" || qq_payment == 1)
							continue;
					}
					else
						if (id == 0 || payment)
							continue;
					QJsonValue artistsValue = songObject.value("artists");
					QJsonArray artistsArray = artistsValue.toArray();
					for (int i = 0; i < artistsArray.size(); ++i)
					{
						QJsonObject artistsNameObject = artistsArray.at(i).toObject();
						QJsonValue artistsNameValue = artistsNameObject.value("name");
						singername.append(artistsNameValue.toString() + " ");
					}
					song_name = songObject.value("name").toString();
					QList<QStandardItem*> list;
					list.append(new QStandardItem(song_name));
					list.append(new QStandardItem(singername));
					if (ui->huanyuan->currentIndex() == 2)
						list.append(new QStandardItem(qq_id));
					else
						list.append(new QStandardItem(QString::number(id)));
					model_2->appendRow(list);
					if (model_2->rowCount() == 0)
						model_2->appendRow(new QStandardItem("没有搜索到数据,请换源重试"));
				}
			}
		}
	}
}

void IMusic::parseJson_2(const QString& json)
{
	QJsonParseError error;
	QJsonDocument document = QJsonDocument::fromJson(json.toUtf8(), &error);
	if (error.error == QJsonParseError::NoError)
	{
		QJsonObject rootObject = document.object();
		QJsonValue rootValue = rootObject.value("success");
		int id = 0;
		QString qq_id = "";
		if (ui->huanyuan->currentIndex() == 2)
			qq_id = ui->searchlist->currentIndex().data(2).toString();
		else
			id = ui->searchlist->currentIndex().data(2).toInt();
		if (rootValue.toBool() == false)
		{
			QMessageBox::warning(this, "无法播放", "请稍后重试或等待修复");
			model_2->removeRow(ui->searchlist->currentIndex().row());
			return;
		}
		QJsonValue dataValue = rootObject.value("data");
		QJsonObject dataObject = dataValue.toObject();
		QJsonValue songValue = dataObject.value("songSource");
		neturl = songValue.toString();
		if (ui->huanyuan->currentIndex() == 2)
		{
			qq_map[qq_id] = neturl;
		}
		else
			map[id] = neturl;
		doublePlay(neturl);
	}
}

void IMusic::parseJson_3(const QString& json)
{
	QJsonParseError error;
	QJsonDocument document = QJsonDocument::fromJson(json.toUtf8(), &error);
	if (error.error == QJsonParseError::NoError)
	{
		QJsonObject rootObject = document.object();
		QJsonValue rootValue = rootObject.value("lrc");
		QJsonObject lrcObject = rootValue.toObject();
		QJsonValue lrcValue = lrcObject.value("lyric");
		QString lrc = lrcValue.toString();

		QRegularExpression express("[[0-9:.]*]");
		lrc.replace(express, "");
		if (ui->stackedWidget->currentIndex() == 1)
		{
			if (lrc != "")
			{
				ui->geci->setPlainText(lrc);
				ui->geci->document()->setDefaultTextOption(QTextOption(Qt::AlignHCenter));
			}
			else
			{
				ui->geci->setPlainText("未找到当前歌曲歌词");
				ui->geci->setAlignment(Qt::AlignCenter);
			}
		}
		else if (ui->stackedWidget->currentIndex() == 4)
		{
			if (lrc != "")
			{
				ui->geci_2->setPlainText(lrc);
				ui->geci_2->document()->setDefaultTextOption(QTextOption(Qt::AlignHCenter));
			}
			else
			{
				ui->geci_2->setPlainText("未找到当前歌曲歌词");
				ui->geci_2->setAlignment(Qt::AlignCenter);
			}
		}
	}
}

void IMusic::parseJson_4(const QString& json)
{
	ui->comments->clear();
	QJsonParseError error;
	QJsonDocument document = QJsonDocument::fromJson(json.toUtf8(), &error);
	if (error.error == QJsonParseError::NoError)
	{
		QJsonObject rootObject = document.object();
		QJsonValue rootValue = rootObject.value("hotComments");
		if (rootValue.isArray())
		{
			QJsonArray array = rootValue.toArray();
			for (int i = 0; i < array.size(); ++i)
			{
				QJsonObject object = array.at(i).toObject();
				QJsonValue userValue = object.value("user");
				QJsonObject userObject = userValue.toObject();
				QJsonValue nickname = userObject.value("nickname");
				QJsonValue contentValue = object.value("content");
				QString comment;
				comment.append(nickname.toString() + ":" + contentValue.toString() + "\n");
				ui->comments->appendPlainText(comment);
			}
		}
		if (ui->huanyuan->currentIndex() != 0)
			ui->comments->setPlainText("该播放源暂不支持评论查看");
	}
}

void IMusic::myParseJson(const QString& json)
{
	QJsonParseError error;
	QJsonDocument document = QJsonDocument::fromJson(json.toUtf8(), &error);
	if (error.error == QJsonParseError::NoError)
	{
		QJsonObject rootObject = document.object();
		QJsonValue rootValue = rootObject.value("data");
		if (rootValue.isArray())
		{
			QJsonArray array = rootValue.toArray();
			for (int i = 0; i < array.size(); ++i)
			{
				QJsonObject listObject = array.at(i).toObject();
				QJsonValue id = listObject.value("id");
				QJsonValue song = listObject.value("song");
				QJsonValue singer = listObject.value("singer");

				QList<QStandardItem*> list;
				list << new QStandardItem(song.toString());
				list << new QStandardItem(singer.toString());
				list << new QStandardItem(id.toString());

				model_3->appendRow(list);
			}
		}
	}
}

void IMusic::replyFinished(QNetworkReply* reply)
{
	QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	//assert(status_code.toString() == "200");
	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = reply->readAll();
		QString result(bytes);
		//qDebug() << result;
		parseJson(result);
	}
	else
		QMessageBox::critical(this, "错误", "请稍后再试或等待当前错误修复");
}

void IMusic::replyFinished_2(QNetworkReply* reply)
{
	QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = reply->readAll();
		QString result(bytes);
		//qDebug() << result;
		parseJson_2(result);
	}
	else
		QMessageBox::critical(this, "错误", "请稍后再试或等待当前错误修复");
}

void IMusic::replyFinished_3(QNetworkReply* reply)
{
	QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = reply->readAll();
		QString result(bytes);
		parseJson_3(result);
	}
	else
	{
		ui->geci->setPlainText("未找到歌词");
		ui->geci->setAlignment(Qt::AlignCenter);
	}
}

void IMusic::replyFinished_4(QNetworkReply* reply)
{
	QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = reply->readAll();
		QString result(bytes);
		//qDebug() << result;
		parseJson_4(result);
	}
	else
		ui->comments->setPlainText("当前歌曲暂无评论");
}

void IMusic::mousePressEvent(QMouseEvent* event)
{
	clickPoint = event->pos();
}

void IMusic::mouseMoveEvent(QMouseEvent* event)
{
	QPoint delta = QPoint(event->pos().x() - clickPoint.x(), event->pos().y() - clickPoint.y());
	this->move(QPoint(this->x() + delta.x(), this->y() + delta.y()));
}
