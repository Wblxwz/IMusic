#pragma once

#include <QDialog>
#include "ui_login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class loginClass; };
QT_END_NAMESPACE

class login : public QDialog
{
	Q_OBJECT

public:
	login(const int cfd,QString& name, QWidget *parent = nullptr);
	~login();
private:
	Ui::loginClass *ui;
};
