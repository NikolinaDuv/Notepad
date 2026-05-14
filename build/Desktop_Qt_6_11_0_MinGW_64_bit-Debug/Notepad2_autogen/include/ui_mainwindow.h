/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionFont;
    QAction *actionColor;
    QAction *actionBackground_color;
    QAction *actionFind;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionDark_Mode;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionZoomReset;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuUredi;
    QMenu *menuView;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8("../new.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../exit.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionExit->setIcon(icon3);
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName("actionFont");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../font.webp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFont->setIcon(icon4);
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName("actionColor");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../color.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionColor->setIcon(icon5);
        actionBackground_color = new QAction(MainWindow);
        actionBackground_color->setObjectName("actionBackground_color");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../back.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionBackground_color->setIcon(icon6);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../find.webp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFind->setIcon(icon7);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../undo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionUndo->setIcon(icon8);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../redo.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRedo->setIcon(icon9);
        actionDark_Mode = new QAction(MainWindow);
        actionDark_Mode->setObjectName("actionDark_Mode");
        actionDark_Mode->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../dark.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionDark_Mode->setIcon(icon10);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName("actionZoomIn");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../zoonin.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionZoomIn->setIcon(icon11);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName("actionZoomOut");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("../zoonout.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionZoomOut->setIcon(icon12);
        actionZoomReset = new QAction(MainWindow);
        actionZoomReset->setObjectName("actionZoomReset");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("../zoomr.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionZoomReset->setIcon(icon13);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuUredi = new QMenu(menubar);
        menuUredi->setObjectName("menuUredi");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuUredi->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuUredi->addAction(actionFont);
        menuUredi->addAction(actionColor);
        menuUredi->addAction(actionBackground_color);
        menuUredi->addAction(actionFind);
        menuUredi->addAction(actionUndo);
        menuUredi->addAction(actionRedo);
        menuView->addAction(actionDark_Mode);
        menuView->addAction(actionZoomIn);
        menuView->addAction(actionZoomOut);
        menuView->addAction(actionZoomReset);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "Novo", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionFont->setText(QCoreApplication::translate("MainWindow", "Font", nullptr));
        actionColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        actionBackground_color->setText(QCoreApplication::translate("MainWindow", "Background Color", nullptr));
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionDark_Mode->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        actionZoomIn->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
        actionZoomOut->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
        actionZoomReset->setText(QCoreApplication::translate("MainWindow", "Zoom Reset", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuUredi->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "&View", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
