#pragma once

#include <QDialog>
#include "ui_setting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class settingClass; };
QT_END_NAMESPACE

enum color
{
	moren,
	huang,
	bai,
	lan,
	lv,
	hei
};

class setting : public QDialog
{
	Q_OBJECT

public:
	setting(int c, QWidget* parent = nullptr);
	~setting();

	void changeSkin(const int c);
signals:
	void sigChangeSkin(color c);
private:
	Ui::settingClass* ui;
};
