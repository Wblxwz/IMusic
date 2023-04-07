#include "setting.h"

setting::setting(int c, QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::settingClass())
{
	ui->setupUi(this);

	this->setAttribute(Qt::WA_DeleteOnClose);

	this->setFixedSize(600, 400);

	changeSkin(c);

	connect(ui->morenbtn, &QPushButton::clicked, this, [&]() {
		emit sigChangeSkin(moren);
		changeSkin(moren);
		});
	connect(ui->danhuang, &QPushButton::clicked, this, [&]() {
		emit sigChangeSkin(huang);
		changeSkin(huang);
		});
	connect(ui->bai, &QPushButton::clicked, this, [&]() {
		emit sigChangeSkin(bai);
		changeSkin(bai);
		});
	connect(ui->lan, &QPushButton::clicked, this, [&]() {
		emit sigChangeSkin(lan);
		changeSkin(lan);
		});
	connect(ui->lv, &QPushButton::clicked, this, [&]() {
		emit sigChangeSkin(lv);
		changeSkin(lv);
		});
	connect(ui->hei, &QPushButton::clicked, this, [&]() {
		emit sigChangeSkin(hei);
		changeSkin(hei);
		});
}

setting::~setting()
{
	delete ui;
}

void setting::changeSkin(const int c)
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
