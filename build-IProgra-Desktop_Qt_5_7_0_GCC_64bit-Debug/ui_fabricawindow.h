/********************************************************************************
** Form generated from reading UI file 'fabricawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FABRICAWINDOW_H
#define UI_FABRICAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FabricaWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FabricaWindow)
    {
        if (FabricaWindow->objectName().isEmpty())
            FabricaWindow->setObjectName(QStringLiteral("FabricaWindow"));
        FabricaWindow->resize(800, 600);
        centralwidget = new QWidget(FabricaWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 501, 51, 51));
        QFont font;
        font.setPointSize(9);
        pushButton->setFont(font);
        pushButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QStringLiteral("../../Flecha Derecha.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(50, 50));
        FabricaWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FabricaWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        FabricaWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(FabricaWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FabricaWindow->setStatusBar(statusbar);

        retranslateUi(FabricaWindow);

        QMetaObject::connectSlotsByName(FabricaWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FabricaWindow)
    {
        FabricaWindow->setWindowTitle(QApplication::translate("FabricaWindow", "F\303\241brica", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FabricaWindow: public Ui_FabricaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FABRICAWINDOW_H
