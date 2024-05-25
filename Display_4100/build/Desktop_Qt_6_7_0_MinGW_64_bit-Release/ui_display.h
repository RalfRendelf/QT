/********************************************************************************
** Form generated from reading UI file 'display.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Display
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Display)
    {
        if (Display->objectName().isEmpty())
            Display->setObjectName("Display");
        Display->resize(800, 600);
        Display->setMinimumSize(QSize(800, 600));
        Display->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(Display);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(120, 24));
        pushButton->setMaximumSize(QSize(50, 24));

        verticalLayout->addWidget(pushButton);

        Display->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Display);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Display->setMenuBar(menubar);
        statusbar = new QStatusBar(Display);
        statusbar->setObjectName("statusbar");
        Display->setStatusBar(statusbar);

        retranslateUi(Display);

        QMetaObject::connectSlotsByName(Display);
    } // setupUi

    void retranslateUi(QMainWindow *Display)
    {
        Display->setWindowTitle(QCoreApplication::translate("Display", "Display", nullptr));
        pushButton->setText(QCoreApplication::translate("Display", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260 \320\272\320\276\320\275\321\201\320\276\320\273\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Display: public Ui_Display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H
