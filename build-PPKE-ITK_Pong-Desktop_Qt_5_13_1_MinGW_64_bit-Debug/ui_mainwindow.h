/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *playButton;
    QRadioButton *singlePlayer;
    QRadioButton *multiPlayer;
    QPushButton *instructionsButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 608);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 781, 481));
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(350, 500, 271, 51));
        singlePlayer = new QRadioButton(centralwidget);
        singlePlayer->setObjectName(QString::fromUtf8("singlePlayer"));
        singlePlayer->setGeometry(QRect(700, 500, 82, 17));
        multiPlayer = new QRadioButton(centralwidget);
        multiPlayer->setObjectName(QString::fromUtf8("multiPlayer"));
        multiPlayer->setGeometry(QRect(700, 520, 82, 17));
        instructionsButton = new QPushButton(centralwidget);
        instructionsButton->setObjectName(QString::fromUtf8("instructionsButton"));
        instructionsButton->setGeometry(QRect(10, 500, 271, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "PLAY", nullptr));
        singlePlayer->setText(QCoreApplication::translate("MainWindow", "Single Player", nullptr));
        multiPlayer->setText(QCoreApplication::translate("MainWindow", "Multiplayer", nullptr));
        instructionsButton->setText(QCoreApplication::translate("MainWindow", "INSTRUCTIONS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
