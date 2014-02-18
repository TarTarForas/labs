/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *filename;
    QLabel *fileNameLabel;
    QListWidget *treeWordList;
    QListWidget *fileWordList;
    QLineEdit *suffix;
    QLabel *suffixLabel;
    QPushButton *treeFind;
    QListWidget *resultWordList;
    QPushButton *fillTree;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(476, 344);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(476, 344));
        MainWindow->setMaximumSize(QSize(476, 344));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        filename = new QLineEdit(centralWidget);
        filename->setObjectName(QStringLiteral("filename"));
        filename->setGeometry(QRect(9, 30, 131, 23));
        filename->setFrame(true);
        fileNameLabel = new QLabel(centralWidget);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(9, 9, 131, 16));
        treeWordList = new QListWidget(centralWidget);
        treeWordList->setObjectName(QStringLiteral("treeWordList"));
        treeWordList->setGeometry(QRect(170, 80, 131, 192));
        fileWordList = new QListWidget(centralWidget);
        fileWordList->setObjectName(QStringLiteral("fileWordList"));
        fileWordList->setGeometry(QRect(10, 80, 131, 192));
        suffix = new QLineEdit(centralWidget);
        suffix->setObjectName(QStringLiteral("suffix"));
        suffix->setGeometry(QRect(330, 30, 91, 23));
        suffixLabel = new QLabel(centralWidget);
        suffixLabel->setObjectName(QStringLiteral("suffixLabel"));
        suffixLabel->setGeometry(QRect(330, 10, 57, 15));
        treeFind = new QPushButton(centralWidget);
        treeFind->setObjectName(QStringLiteral("treeFind"));
        treeFind->setGeometry(QRect(430, 30, 31, 23));
        resultWordList = new QListWidget(centralWidget);
        resultWordList->setObjectName(QStringLiteral("resultWordList"));
        resultWordList->setGeometry(QRect(330, 80, 131, 192));
        fillTree = new QPushButton(centralWidget);
        fillTree->setObjectName(QStringLiteral("fillTree"));
        fillTree->setGeometry(QRect(170, 30, 131, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 476, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        filename->setText(QApplication::translate("MainWindow", "input.txt", 0));
        fileNameLabel->setText(QApplication::translate("MainWindow", "Input filename", 0));
        suffixLabel->setText(QApplication::translate("MainWindow", "Suffix", 0));
        treeFind->setText(QApplication::translate("MainWindow", "Find", 0));
        fillTree->setText(QApplication::translate("MainWindow", "Fill", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
