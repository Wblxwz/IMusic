#include <qaudiooutput.h>
#include <qurl.h>
#include <qmessagebox.h>

#include "IMusic.h"
#include "imagethread.h"

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
}

void IMusic::init()
{
	//this->setMinimumSize(1029, 673);
	this->setFixedSize(1029, 616);
	this->setWindowFlags(Qt::FramelessWindowHint);

	model = new QStandardItemModel;
	model->setColumnCount(3);
	model->setHeaderData(0, Qt::Horizontal, "歌名");
	model->setHeaderData(1, Qt::Horizontal, "歌手");
	model->setHeaderData(2, Qt::Horizontal, "本地路径");
	ui->tableView->setModel(model);
	ui->tableView->setColumnWidth(0, 90);
	ui->tableView->setColumnWidth(1, 70);
	ui->tableView->setColumnWidth(2, 0);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->volumebar->setValue(100);
	player->setAudioOutput(output);
	ImageThread* it = new ImageThread;

	connect(ui->open, &QPushButton::clicked, this, &IMusic::open);
	connect(ui->play, &QPushButton::clicked, this, &IMusic::play);
	connect(ui->nextbtn, &QPushButton::clicked, this, &IMusic::next);
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
		player->setSource(QUrl(index));
		player->play();
		ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
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
			this->showMaximized();
		else
			this->showNormal();
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
		});
	connect(ui->liebiaobtn, &QPushButton::clicked, this, [&]() {
		changePage(1);
		ui->liebiaobtn->setStyleSheet("background-color:rgb(237,65,65);");
		ui->faxianbtn->setStyleSheet("");
		});
	connect(ui->name, &QPushButton::clicked, this, [&]() {
		QMessageBox::information(this, "歌曲名称", ui->name->text());
		});

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
}

void IMusic::play()
{
	isPlay = !isPlay;
	if (player->playbackState() == player->StoppedState)
	{
		QString index = model->data(model->index(ui->tableView->currentIndex().row(), 2)).toString();
		player->setSource(QUrl(index));
	}
	if (!isPlay)
	{
		ui->name->setText(ui->tableView->currentIndex().data(0).toString());
		ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
		player->play();
	}
	else
	{
		ui->play->setStyleSheet("border-image:url(:/IMusic/images/play.png);");
		player->pause();
	}
}

void IMusic::next()
{
	int n = model->rowCount();
	int nextIndex = ui->tableView->currentIndex().row() + 1;
	if (nextIndex > n)
	{
		player->setSource(QUrl(model->data(model->index(0, 2)).toString()));
		ui->tableView->setCurrentIndex(model->index(0, 0));
	}
	else
	{
		QString index = model->data(model->index(nextIndex, 2)).toString();
		player->setSource(QUrl(index));
		ui->tableView->setCurrentIndex(model->index(nextIndex, 0));
	}
	player->play();
	ui->name->setText(ui->tableView->currentIndex().data(0).toString());
	ui->play->setStyleSheet("border-image:url(:/IMusic/images/pause.png);");
}

void IMusic::changePage(const int& index)
{
	ui->stackedWidget->setCurrentIndex(index);
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
