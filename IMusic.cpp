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
	delete manager, manager_2;
	delete request, request_2;
	delete set;
}

void IMusic::init()
{
	//this->setMinimumSize(1029, 673);
	this->setFixedSize(1029, 616);
	this->setWindowFlags(Qt::FramelessWindowHint);

	WSADATA wsadata;
	assert(WSAStartup(MAKEWORD(2, 2), &wsadata) == 0);

	set = new QSettings("C:/IMusic/settings.ini", QSettings::IniFormat);
	int cc = set->value("settings/skin").toString().toInt();
	changeSkin(cc);

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

	ui->tableView->setModel(model);
	ui->tableView->setColumnWidth(0, 90);
	ui->tableView->setColumnWidth(1, 70);
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

	QStringList list;
	list << "网易" << "酷我" << "QQ";
	ui->huanyuan->addItems(list);

	ui->volumebar->setValue(100);

	player->setAudioOutput(output);
	player->setLoops(QMediaPlayer::Infinite);

	ImageThread* it = new ImageThread;
	connect(it, &QThread::finished, it, &QThread::deleteLater);

	manager = new QNetworkAccessManager(this);
	manager_2 = new QNetworkAccessManager(this);
	request = new QNetworkRequest;
	request_2 = new QNetworkRequest;

	connect(manager, &QNetworkAccessManager::finished, this, &IMusic::replyFinished);
	connect(manager_2, &QNetworkAccessManager::finished, this, &IMusic::replyFinished_2);

	connect(ui->open, &QPushButton::clicked, this, &IMusic::open);
	connect(ui->searchbtn, &QPushButton::clicked, this, &IMusic::search);
	connect(ui->versionbtn, &QPushButton::clicked, this, &IMusic::version);
	connect(ui->userbtn, &QPushButton::clicked, this, &IMusic::log);
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
			ui->name->setText(name);
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
	connect(player, &QMediaPlayer::playbackStateChanged, this, &IMusic::change);
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
		ui->name->setText(ui->tableView->currentIndex().data(0).toString());
		doublePlay(QUrl(index));
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
		output->setVolume(volume);
		});
	connect(ui->volumebtn, &QPushButton::clicked, this, [&]() {
		isMute = !isMute;
		if (!isMute)
		{
			float volume = static_cast<float>(ui->volumebar->value()) / 100;
			output->setVolume(volume);
		}
		else
			output->setVolume(0);
		});
	connect(ui->faxianbtn, &QPushButton::clicked, this, [&]() {
		changePage(0);
		ui->faxianbtn->setStyleSheet("background-color:rgb(237,65,65);");
		ui->liebiaobtn->setStyleSheet("");
		ui->netbtn->setStyleSheet("");
		});
	connect(ui->netbtn, &QPushButton::clicked, this, [&]() {
		changePage(1);
		ui->netbtn->setStyleSheet("background-color:rgb(237,65,65);");
		ui->faxianbtn->setStyleSheet("");
		ui->liebiaobtn->setStyleSheet("");
		});
	connect(ui->liebiaobtn, &QPushButton::clicked, this, [&]() {
		changePage(2);
		ui->liebiaobtn->setStyleSheet("background-color:rgb(237,65,65);");
		ui->faxianbtn->setStyleSheet("");
		ui->netbtn->setStyleSheet("");
		});
	connect(ui->name, &QPushButton::clicked, this, [&]() {
		QMessageBox::information(this, "歌曲名称", ui->name->text());
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
		int id = ui->searchlist->currentIndex().data(2).toInt();
		player->setSource(map[id]);
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
		ui->name->setText(ui->tableView->currentIndex().data(0).toString());
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
		ui->name->setText(ui->searchlist->currentIndex().data(0).toString());
		int id = ui->searchlist->currentIndex().data(2).toInt();
		player->setSource(map[id]);
	}
	player->play();
	ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
}

void IMusic::next(const int index)
{
	if (index < 0 || index >= model->rowCount())
		return;
	int cindex = ui->stackedWidget->currentIndex();
	QString nextIndex;
	if (cindex == 2)
	{
		nextIndex = model->data(model->index(index, 2)).toString();
		ui->tableView->setCurrentIndex(model->index(index, 0));
		ui->name->setText(ui->tableView->currentIndex().data(0).toString());
		player->setSource(QUrl(nextIndex));
	}
	else
	{
		ui->searchlist->setCurrentIndex(model_2->index(index, 0));
		onlinePlay();
		ui->name->setText(ui->searchlist->currentIndex().data(0).toString());
		int id = ui->searchlist->currentIndex().data(2).toInt();
		player->setSource(map[id]);
	}
	player->play();
	ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
}

void IMusic::changePage(const int& index)
{
	ui->stackedWidget->setCurrentIndex(index);
}

void IMusic::change()
{
	if (player->playbackState() == QMediaPlayer::StoppedState)
	{
		switch (p)
		{
		case listloop:
			next();
			break;
		case randomloop:
			next(random(model->rowCount()));
			break;
		default:
			break;
		}
	}
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
	QString name;
	login* l = new login(cfd, name);
	l->exec();
	ui->namelabel->setText(name);
}

void IMusic::search()
{
	int count = model_2->rowCount();
	model_2->removeRows(0, count);

	QString content = QString("https://music-api.tonzhon.com/search?keyword=%1&platform=netease").arg(ui->searchedit->text());
	request->setUrl(QUrl(content));
	manager->get(*request);

	/*content = QString("https://music-api.tonzhon.com/search?keyword=%1&platform=kuwo").arg(ui->searchedit->text());
	request->setUrl(QUrl(content));
	manager->get(*request);

	content = QString("https://music-api.tonzhon.com/search?keyword=%1&platform=qq").arg(ui->searchedit->text());
	request->setUrl(QUrl(content));
	manager->get(*request);*/

}

const int IMusic::getNewCfd()
{
	int cfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(cfd >= 0);

	sockaddr_in	caddr;
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(8888);
	inet_pton(AF_INET, "192.168.10.150", &caddr.sin_addr.S_un.S_addr);

	int ret = ::connect(cfd, (sockaddr*)&caddr, sizeof(caddr));
	assert(ret == 0);

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
	int index = ui->searchlist->currentIndex().row();
	QString id = model_2->data(model_2->index(index, 2)).toString();
	QString content = QString("https://music-api.tonzhon.com/song_source/netease/%1").arg(id);
	request_2->setUrl(QUrl(content));
	manager_2->get(*request_2);
	ui->name->setText(ui->searchlist->currentIndex().data(0).toString());
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
					bool payment = songObject.value("requiringPayment").toBool();
					int id = songObject.value("originalId").toInt();
					singername.clear();
					if (payment || id == 0)
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
					list.append(new QStandardItem(QString::number(id)));
					model_2->appendRow(list);
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
		int id = ui->searchlist->currentIndex().data(2).toInt();
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
		map[id] = neturl;
		doublePlay(neturl);
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

void IMusic::mousePressEvent(QMouseEvent* event)
{
	clickPoint = event->pos();
}

void IMusic::mouseMoveEvent(QMouseEvent* event)
{
	QPoint delta = QPoint(event->pos().x() - clickPoint.x(), event->pos().y() - clickPoint.y());
	this->move(QPoint(this->x() + delta.x(), this->y() + delta.y()));
}
