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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *namelabel;
    QPushButton *userbtn;
    QPushButton *skinbtn;
    QLabel *label_2;
    QPushButton *minbtn;
    QPushButton *maxbtn;
    QPushButton *closebtn;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *faxianbtn;
    QPushButton *netbtn;
    QPushButton *liebiaobtn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *gundong;
    QSpacerItem *horizontalSpacer_6;
    QWidget *page_3;
    QGridLayout *gridLayout_3;
    QComboBox *huanyuan;
    QLineEdit *searchedit;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *searchbtn;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QTableView *searchlist;
    QPlainTextEdit *geci;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_4;
    QTableView *tableView;
    QWidget *page_4;
    QWidget *widget_5;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *comments;
    QPlainTextEdit *usercomment;
    QPushButton *commitbtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *name;
    QSlider *timebar;
    QLabel *time;
    QPushButton *open;
    QPushButton *commentbtn;
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
    QPushButton *versionbtn;

    void setupUi(QWidget *IMusicClass)
    {
        if (IMusicClass->objectName().isEmpty())
            IMusicClass->setObjectName(QString::fromUtf8("IMusicClass"));
        IMusicClass->resize(1029, 623);
        IMusicClass->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(IMusicClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
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

        namelabel = new QLabel(widget);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setMinimumSize(QSize(100, 30));
        namelabel->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setPointSize(11);
        namelabel->setFont(font);

        horizontalLayout->addWidget(namelabel);

        userbtn = new QPushButton(widget);
        userbtn->setObjectName(QString::fromUtf8("userbtn"));
        userbtn->setMinimumSize(QSize(20, 20));
        userbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/user.png);"));

        horizontalLayout->addWidget(userbtn);

        skinbtn = new QPushButton(widget);
        skinbtn->setObjectName(QString::fromUtf8("skinbtn"));
        skinbtn->setMinimumSize(QSize(25, 25));
        skinbtn->setMaximumSize(QSize(25, 25));
        skinbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/skin.png);"));

        horizontalLayout->addWidget(skinbtn);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(30, 0));
        label_2->setMaximumSize(QSize(30, 16777215));

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

        widget_3 = new QWidget(IMusicClass);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        faxianbtn = new QPushButton(widget_3);
        faxianbtn->setObjectName(QString::fromUtf8("faxianbtn"));
        faxianbtn->setFont(font);
        faxianbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 65, 65);"));

        verticalLayout->addWidget(faxianbtn);

        netbtn = new QPushButton(widget_3);
        netbtn->setObjectName(QString::fromUtf8("netbtn"));
        netbtn->setFont(font);

        verticalLayout->addWidget(netbtn);

        liebiaobtn = new QPushButton(widget_3);
        liebiaobtn->setObjectName(QString::fromUtf8("liebiaobtn"));
        liebiaobtn->setFont(font);

        verticalLayout->addWidget(liebiaobtn);


        gridLayout->addWidget(widget_3, 1, 0, 1, 1);

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
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_3 = new QGridLayout(page_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        huanyuan = new QComboBox(page_3);
        huanyuan->setObjectName(QString::fromUtf8("huanyuan"));
        huanyuan->setMinimumSize(QSize(73, 20));
        huanyuan->setMaximumSize(QSize(73, 20));

        gridLayout_3->addWidget(huanyuan, 0, 1, 1, 1);

        searchedit = new QLineEdit(page_3);
        searchedit->setObjectName(QString::fromUtf8("searchedit"));
        searchedit->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(searchedit, 0, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(287, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(287, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_10, 0, 4, 1, 1);

        searchbtn = new QPushButton(page_3);
        searchbtn->setObjectName(QString::fromUtf8("searchbtn"));
        searchbtn->setMinimumSize(QSize(25, 25));
        searchbtn->setMaximumSize(QSize(25, 25));
        searchbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/search.png);"));

        gridLayout_3->addWidget(searchbtn, 0, 3, 1, 1);

        widget_4 = new QWidget(page_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        searchlist = new QTableView(widget_4);
        searchlist->setObjectName(QString::fromUtf8("searchlist"));
        searchlist->setMinimumSize(QSize(200, 200));
        searchlist->setMaximumSize(QSize(200, 400));

        gridLayout_2->addWidget(searchlist, 0, 0, 1, 1);

        geci = new QPlainTextEdit(widget_4);
        geci->setObjectName(QString::fromUtf8("geci"));
        geci->setMinimumSize(QSize(600, 400));
        geci->setMaximumSize(QSize(600, 400));
        QFont font1;
        font1.setPointSize(15);
        geci->setFont(font1);

        gridLayout_2->addWidget(geci, 0, 1, 1, 1);


        gridLayout_3->addWidget(widget_4, 1, 0, 1, 5);

        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_4 = new QHBoxLayout(page_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tableView = new QTableView(page_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(800, 441));
        tableView->setMaximumSize(QSize(181, 441));
        tableView->setStyleSheet(QString::fromUtf8(""));
        tableView->setLineWidth(1);

        horizontalLayout_4->addWidget(tableView);

        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        widget_5 = new QWidget(page_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(20, 20, 891, 451));
        gridLayout_4 = new QGridLayout(widget_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        comments = new QPlainTextEdit(widget_5);
        comments->setObjectName(QString::fromUtf8("comments"));
        comments->setMinimumSize(QSize(0, 0));
        comments->setFont(font1);

        gridLayout_4->addWidget(comments, 0, 0, 1, 2);

        usercomment = new QPlainTextEdit(widget_5);
        usercomment->setObjectName(QString::fromUtf8("usercomment"));
        usercomment->setMaximumSize(QSize(16777215, 100));
        usercomment->setFont(font1);

        gridLayout_4->addWidget(usercomment, 1, 0, 1, 1);

        commitbtn = new QPushButton(widget_5);
        commitbtn->setObjectName(QString::fromUtf8("commitbtn"));

        gridLayout_4->addWidget(commitbtn, 1, 1, 1, 1);

        stackedWidget->addWidget(page_4);

        gridLayout->addWidget(stackedWidget, 1, 1, 1, 1);

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

        commentbtn = new QPushButton(widget_2);
        commentbtn->setObjectName(QString::fromUtf8("commentbtn"));
        commentbtn->setMinimumSize(QSize(25, 25));
        commentbtn->setMaximumSize(QSize(25, 25));
        commentbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/comment.png);"));

        horizontalLayout_2->addWidget(commentbtn);

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
        loopbtn->setStyleSheet(QString::fromUtf8("border-image: url(:/IMusic/images/danqu.png);"));

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

        versionbtn = new QPushButton(widget_2);
        versionbtn->setObjectName(QString::fromUtf8("versionbtn"));
        versionbtn->setMinimumSize(QSize(26, 18));
        versionbtn->setMaximumSize(QSize(26, 18));

        horizontalLayout_2->addWidget(versionbtn);


        gridLayout->addWidget(widget_2, 2, 0, 1, 2);


        retranslateUi(IMusicClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(IMusicClass);
    } // setupUi

    void retranslateUi(QWidget *IMusicClass)
    {
        IMusicClass->setWindowTitle(QCoreApplication::translate("IMusicClass", "IMusic", nullptr));
        label->setText(QString());
        namelabel->setText(QString());
        userbtn->setText(QString());
        skinbtn->setText(QString());
        label_2->setText(QString());
        minbtn->setText(QString());
        maxbtn->setText(QString());
        closebtn->setText(QString());
        faxianbtn->setText(QCoreApplication::translate("IMusicClass", "\345\217\221\347\216\260\351\237\263\344\271\220", nullptr));
        netbtn->setText(QCoreApplication::translate("IMusicClass", "\347\275\221\347\273\234\346\255\214\346\233\262", nullptr));
        liebiaobtn->setText(QCoreApplication::translate("IMusicClass", "\346\234\254\345\234\260\346\255\214\346\233\262", nullptr));
        gundong->setText(QString());
        searchedit->setPlaceholderText(QCoreApplication::translate("IMusicClass", "\350\257\267\350\276\223\345\205\245\346\255\214\346\233\262\345\220\215\347\247\260\346\210\226\346\255\214\346\211\213\345\220\215\347\247\260", nullptr));
        searchbtn->setText(QString());
        geci->setPlainText(QCoreApplication::translate("IMusicClass", "\346\216\250\350\215\220\344\275\277\347\224\250\347\275\221\346\230\223\344\272\221\346\220\234\347\264\242", nullptr));
        comments->setPlainText(QString());
        usercomment->setPlaceholderText(QCoreApplication::translate("IMusicClass", "\350\257\264\347\202\271\344\273\200\344\271\210\345\220\247:\360\237\230\200", nullptr));
        commitbtn->setText(QCoreApplication::translate("IMusicClass", "\346\217\220\344\272\244", nullptr));
        name->setText(QString());
        time->setText(QString());
        open->setText(QString());
        commentbtn->setText(QString());
        prebtn->setText(QString());
        play->setText(QString());
        nextbtn->setText(QString());
        loopbtn->setText(QString());
        volumebtn->setText(QString());
        versionbtn->setText(QCoreApplication::translate("IMusicClass", "v1.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IMusicClass: public Ui_IMusicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMUSIC_H
