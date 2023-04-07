/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginClass
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *zhucebtn;
    QPushButton *denglubtn;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *pwd;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *name;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *loginClass)
    {
        if (loginClass->objectName().isEmpty())
            loginClass->setObjectName(QString::fromUtf8("loginClass"));
        loginClass->resize(609, 346);
        gridLayout_2 = new QGridLayout(loginClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(loginClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        zhucebtn = new QPushButton(widget);
        zhucebtn->setObjectName(QString::fromUtf8("zhucebtn"));

        gridLayout->addWidget(zhucebtn, 0, 0, 1, 1);

        denglubtn = new QPushButton(widget);
        denglubtn->setObjectName(QString::fromUtf8("denglubtn"));

        gridLayout->addWidget(denglubtn, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget, 5, 1, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(102, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 5, 0, 1, 1);

        pwd = new QLineEdit(loginClass);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        QFont font;
        font.setPointSize(10);
        pwd->setFont(font);
        pwd->setContextMenuPolicy(Qt::DefaultContextMenu);
        pwd->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(pwd, 3, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(244, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 2);

        name = new QLineEdit(loginClass);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(300, 0));
        name->setFont(font);

        gridLayout_2->addWidget(name, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(187, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(159, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 5, 4, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 2, 1, 1);


        retranslateUi(loginClass);

        QMetaObject::connectSlotsByName(loginClass);
    } // setupUi

    void retranslateUi(QDialog *loginClass)
    {
        loginClass->setWindowTitle(QCoreApplication::translate("loginClass", "login", nullptr));
        zhucebtn->setText(QCoreApplication::translate("loginClass", "\346\263\250\345\206\214", nullptr));
        denglubtn->setText(QCoreApplication::translate("loginClass", "\347\231\273\345\275\225", nullptr));
        pwd->setPlaceholderText(QCoreApplication::translate("loginClass", "\345\257\206\347\240\201", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("loginClass", "\346\230\265\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginClass: public Ui_loginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
