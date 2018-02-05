/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *labRegion;
    QTableWidget *tableRegion;
    QComboBox *cbRegion;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(832, 539);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labRegion = new QLabel(centralWidget);
        labRegion->setObjectName(QStringLiteral("labRegion"));
        labRegion->setGeometry(QRect(40, 50, 501, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font1.setBold(true);
        font1.setWeight(75);
        labRegion->setFont(font1);
        labRegion->setAlignment(Qt::AlignCenter);
        tableRegion = new QTableWidget(centralWidget);
        if (tableRegion->columnCount() < 5)
            tableRegion->setColumnCount(5);
        tableRegion->setObjectName(QStringLiteral("tableRegion"));
        tableRegion->setGeometry(QRect(40, 110, 501, 291));
        tableRegion->setCornerButtonEnabled(true);
        tableRegion->setColumnCount(5);
        cbRegion = new QComboBox(centralWidget);
        cbRegion->setObjectName(QStringLiteral("cbRegion"));
        cbRegion->setGeometry(QRect(540, 50, 181, 25));
        cbRegion->setEditable(false);
        MainWindow->setCentralWidget(centralWidget);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Progetto Regioni", 0));
        labRegion->setText(QApplication::translate("MainWindow", "Seleziona una regione", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
