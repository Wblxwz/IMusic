#include <WinSock2.h>
#include <qsettings.h>
#include <qmessagebox.h>

#include "setting.h"
#include "login.h"

login::login(const int cfd,QString& name, QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::loginClass())
{
	ui->setupUi(this);

	QSettings* set = new QSettings("C:/IMusic/settings.ini", QSettings::IniFormat);
	int cc = set->value("settings/skin").toString().toInt();
	switch (cc)
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

	connect(ui->denglubtn, &QPushButton::clicked, this, [&]() {
		char buf[1024];
		sprintf(buf, "login:%s", ui->name->text().toStdString().c_str());
		sprintf(buf + strlen(buf), "logpwd:%s", ui->pwd->text().toStdString().c_str());
		send(cfd, buf, sizeof(buf), NULL);
		char tbuf[100];
		recv(cfd, tbuf, sizeof(tbuf), NULL);
		std::string ts(tbuf);
		if (ts == "true")
		{
			name = ui->name->text();
			QMessageBox::information(this, "登录成功", "登录成功！");
		}
		else
			QMessageBox::information(this, "登录失败", "请检查输入后重试或等待服务器修复");
		closesocket(cfd);
		this->close();
		});
	connect(ui->zhucebtn, &QPushButton::clicked, this, [&]() {
		char buf[1024];
		sprintf(buf, "signup:%s", ui->name->text().toStdString().c_str());
		sprintf(buf + strlen(buf), "signpwd:%s", ui->pwd->text().toStdString().c_str());
		send(cfd, buf, sizeof(buf), NULL);
		char tbuf[10];
		recv(cfd, tbuf, sizeof(tbuf), NULL);
		QString ts(tbuf);
		if (ts == "true")
			QMessageBox::information(this, "注册成功", "注册成功，请重新登录");
		else
			QMessageBox::critical(this, "注册失败", "请检查输入后重试(可能存在格式错误或重名等情况)或等待服务器修复");
		closesocket(cfd);
		this->close();
		});
}

login::~login()
{
	delete ui;
}
