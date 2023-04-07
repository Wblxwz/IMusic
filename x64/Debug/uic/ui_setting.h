/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingClass
{
public:
    QGridLayout *gridLayout_7;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *morenbtn;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *danhuang;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QPushButton *bai;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QPushButton *lan;
    QWidget *widget_6;
    QGridLayout *gridLayout_6;
    QLabel *label_6;
    QPushButton *lv;
    QWidget *widget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QPushButton *hei;

    void setupUi(QDialog *settingClass)
    {
        if (settingClass->objectName().isEmpty())
            settingClass->setObjectName(QString::fromUtf8("settingClass"));
        settingClass->resize(600, 400);
        gridLayout_7 = new QGridLayout(settingClass);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        widget = new QWidget(settingClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 20));
        label->setMaximumSize(QSize(50, 20));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        morenbtn = new QPushButton(widget);
        morenbtn->setObjectName(QString::fromUtf8("morenbtn"));
        morenbtn->setMinimumSize(QSize(80, 70));
        morenbtn->setMaximumSize(QSize(80, 70));
        morenbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 171, 168);"));

        gridLayout->addWidget(morenbtn, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(settingClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 20));
        label_2->setMaximumSize(QSize(50, 20));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        danhuang = new QPushButton(widget_2);
        danhuang->setObjectName(QString::fromUtf8("danhuang"));
        danhuang->setMinimumSize(QSize(80, 70));
        danhuang->setMaximumSize(QSize(80, 70));
        danhuang->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 153);"));

        gridLayout_2->addWidget(danhuang, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget_2, 0, 1, 1, 1);

        widget_3 = new QWidget(settingClass);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 20));
        label_3->setMaximumSize(QSize(50, 20));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        bai = new QPushButton(widget_3);
        bai->setObjectName(QString::fromUtf8("bai"));
        bai->setMinimumSize(QSize(80, 70));
        bai->setMaximumSize(QSize(80, 70));
        bai->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(bai, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget_3, 0, 2, 1, 1);

        widget_4 = new QWidget(settingClass);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(50, 20));
        label_4->setMaximumSize(QSize(50, 20));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        lan = new QPushButton(widget_4);
        lan->setObjectName(QString::fromUtf8("lan"));
        lan->setMinimumSize(QSize(80, 70));
        lan->setMaximumSize(QSize(80, 70));
        lan->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 204, 255);"));

        gridLayout_4->addWidget(lan, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget_4, 1, 0, 1, 1);

        widget_6 = new QWidget(settingClass);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_6 = new QGridLayout(widget_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(50, 20));
        label_6->setMaximumSize(QSize(50, 20));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_6, 1, 0, 1, 1);

        lv = new QPushButton(widget_6);
        lv->setObjectName(QString::fromUtf8("lv"));
        lv->setMinimumSize(QSize(80, 70));
        lv->setMaximumSize(QSize(80, 70));
        lv->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 204, 0);"));

        gridLayout_6->addWidget(lv, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget_6, 1, 1, 1, 1);

        widget_5 = new QWidget(settingClass);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_5 = new QGridLayout(widget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(50, 20));
        label_5->setMaximumSize(QSize(50, 20));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_5, 1, 0, 1, 1);

        hei = new QPushButton(widget_5);
        hei->setObjectName(QString::fromUtf8("hei"));
        hei->setMinimumSize(QSize(80, 70));
        hei->setMaximumSize(QSize(80, 70));
        hei->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));

        gridLayout_5->addWidget(hei, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget_5, 1, 2, 1, 1);


        retranslateUi(settingClass);

        QMetaObject::connectSlotsByName(settingClass);
    } // setupUi

    void retranslateUi(QDialog *settingClass)
    {
        settingClass->setWindowTitle(QCoreApplication::translate("settingClass", "setting", nullptr));
        label->setText(QCoreApplication::translate("settingClass", "\351\273\230\350\256\244", nullptr));
        morenbtn->setText(QString());
        label_2->setText(QCoreApplication::translate("settingClass", "\346\267\241\351\273\204", nullptr));
        danhuang->setText(QString());
        label_3->setText(QCoreApplication::translate("settingClass", "\347\272\257\347\231\275", nullptr));
        bai->setText(QString());
        label_4->setText(QCoreApplication::translate("settingClass", "\345\244\251\350\223\235", nullptr));
        lan->setText(QString());
        label_6->setText(QCoreApplication::translate("settingClass", "\346\265\205\347\273\277", nullptr));
        lv->setText(QString());
        label_5->setText(QCoreApplication::translate("settingClass", "\347\272\257\351\273\221", nullptr));
        hei->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class settingClass: public Ui_settingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
