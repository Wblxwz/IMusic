/********************************************************************************
** Form generated from reading UI file 'IMusic.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMUSIC_H
#define UI_IMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IMusicClass
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *gundong;
    QSpacerItem *horizontalSpacer_6;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_4;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *faxianbtn;
    QPushButton *liebiaobtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *userbtn;
    QLabel *label_2;
    QPushButton *minbtn;
    QPushButton *maxbtn;
    QPushButton *closebtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *name;
    QSlider *timebar;
    QLabel *time;
    QPushButton *open;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *prebtn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *play;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *nextbtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *loopbtn;
    QPushButton *volumebtn;
    QSlider *volumebar;

    void setupUi(QWidget *IMusicClass)
    {
        if (IMusicClass->objectName().isEmpty())
            IMusicClass->setObjectName(QString::fromUtf8("IMusicClass"));
        IMusicClass->resize(1029, 616);
        IMusicClass->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 171, 168);"));
        gridLayout = new QGridLayout(IMusicClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(IMusicClass);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setLineWidth(1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_3 = new QHBoxLayout(page);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(147, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        gundong = new QLabel(page);
        gundong->setObjectName(QString::fromUtf8("gundong"));
        gundong->setMinimumSize(QSize(601, 191));
        gundong->setMaximumSize(QSize(16777215, 191));

        horizontalLayout_3->addWidget(gundong);

        horizontalSpacer_6 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_4 = new QHBoxLayout(page_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tableView = new QTableView(page_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(181, 441));
        tableView->setMaximumSize(QSize(181, 441));
        tableView->setStyleSheet(QString::fromUtf8(""));
        tableView->setLineWidth(1);

        horizontalLayout_4->addWidget(tableView);

        horizontalSpacer_7 = new QSpacerItem(722, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 1, 1, 1, 1);

        widget_3 = new QWidget(IMusicClass);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        faxianbtn = new QPushButton(widget_3);
        faxianbtn->setObjectName(QString::fromUtf8("faxianbtn"));
        QFont font;
        font.setPointSize(11);
        faxianbtn->setFont(font);
        faxianbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 65, 65);"));

        verticalLayout->addWidget(faxianbtn);

        liebiaobtn = new QPushButton(widget_3);
        liebiaobtn->setObjectName(QString::fromUtf8("liebiaobtn"));
        liebiaobtn->setFont(font);

        verticalLayout->addWidget(liebiaobtn);


        gridLayout->addWidget(widget_3, 1, 0, 1, 1);

        widget = new QWidget(IMusicClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(1011, 71));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 65, 65);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(261, 51));
        label->setMaximumSize(QSize(261, 51));
        label->setStyleSheet(QString::fromUtf8("image: url(:/IMusic/images/logo.png);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(643, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        userbtn = new QPushButton(widget);
        userbtn->setObjectName(QString::fromUtf8("userbtn"));
        userbtn->setMinimumSize(QSize(20, 20));
        userbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/user.png);"));

        horizontalLayout->addWidget(userbtn);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(label_2);

        minbtn = new QPushButton(widget);
        minbtn->setObjectName(QString::fromUtf8("minbtn"));
        minbtn->setMinimumSize(QSize(21, 21));
        minbtn->setMaximumSize(QSize(21, 21));
        minbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/TitleBar/minimum.png);"));

        horizontalLayout->addWidget(minbtn);

        maxbtn = new QPushButton(widget);
        maxbtn->setObjectName(QString::fromUtf8("maxbtn"));
        maxbtn->setMaximumSize(QSize(21, 21));
        maxbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/TitleBar/maximum.png);"));

        horizontalLayout->addWidget(maxbtn);

        closebtn = new QPushButton(widget);
        closebtn->setObjectName(QString::fromUtf8("closebtn"));
        closebtn->setMinimumSize(QSize(20, 21));
        closebtn->setMaximumSize(QSize(20, 21));
        closebtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/TitleBar/close.png);"));

        horizontalLayout->addWidget(closebtn);


        gridLayout->addWidget(widget, 0, 0, 1, 2);

        widget_2 = new QWidget(IMusicClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(1011, 60));
        widget_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        name = new QPushButton(widget_2);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(60, 30));
        name->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(name);

        timebar = new QSlider(widget_2);
        timebar->setObjectName(QString::fromUtf8("timebar"));
        timebar->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(timebar);

        time = new QLabel(widget_2);
        time->setObjectName(QString::fromUtf8("time"));
        time->setMinimumSize(QSize(60, 30));
        time->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(time);

        open = new QPushButton(widget_2);
        open->setObjectName(QString::fromUtf8("open"));
        open->setMinimumSize(QSize(30, 30));
        open->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/open.png);"));

        horizontalLayout_2->addWidget(open);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        prebtn = new QPushButton(widget_2);
        prebtn->setObjectName(QString::fromUtf8("prebtn"));
        prebtn->setMinimumSize(QSize(30, 30));
        prebtn->setMaximumSize(QSize(30, 30));
        prebtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/pre.png);"));

        horizontalLayout_2->addWidget(prebtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        play = new QPushButton(widget_2);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMinimumSize(QSize(40, 40));
        play->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/play.png);"));

        horizontalLayout_2->addWidget(play);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        nextbtn = new QPushButton(widget_2);
        nextbtn->setObjectName(QString::fromUtf8("nextbtn"));
        nextbtn->setMinimumSize(QSize(30, 30));
        nextbtn->setMaximumSize(QSize(30, 30));
        nextbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/next.png);"));

        horizontalLayout_2->addWidget(nextbtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        loopbtn = new QPushButton(widget_2);
        loopbtn->setObjectName(QString::fromUtf8("loopbtn"));
        loopbtn->setMinimumSize(QSize(30, 30));
        loopbtn->setMaximumSize(QSize(30, 30));
        loopbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/danqu.jpg);"));

        horizontalLayout_2->addWidget(loopbtn);

        volumebtn = new QPushButton(widget_2);
        volumebtn->setObjectName(QString::fromUtf8("volumebtn"));
        volumebtn->setMinimumSize(QSize(30, 30));
        volumebtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/volume.jpg);"));

        horizontalLayout_2->addWidget(volumebtn);

        volumebar = new QSlider(widget_2);
        volumebar->setObjectName(QString::fromUtf8("volumebar"));
        volumebar->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(volumebar);


        gridLayout->addWidget(widget_2, 2, 0, 1, 2);


        retranslateUi(IMusicClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(IMusicClass);
    } // setupUi

    void retranslateUi(QWidget *IMusicClass)
    {
        IMusicClass->setWindowTitle(QCoreApplication::translate("IMusicClass", "IMusic", nullptr));
        gundong->setText(QString());
        faxianbtn->setText(QCoreApplication::translate("IMusicClass", "\345\217\221\347\216\260\351\237\263\344\271\220", nullptr));
        liebiaobtn->setText(QCoreApplication::translate("IMusicClass", "\346\255\214\346\233\262\345\210\227\350\241\250", nullptr));
        label->setText(QString());
        userbtn->setText(QString());
        label_2->setText(QString());
        minbtn->setText(QString());
        maxbtn->setText(QString());
        closebtn->setText(QString());
        name->setText(QString());
        time->setText(QString());
        open->setText(QString());
        prebtn->setText(QString());
        play->setText(QString());
        nextbtn->setText(QString());
        loopbtn->setText(QString());
        volumebtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IMusicClass: public Ui_IMusicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMUSIC_H
