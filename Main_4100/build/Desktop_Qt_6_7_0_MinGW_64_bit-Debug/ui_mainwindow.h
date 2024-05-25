/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBox;
    QTextBrowser *textBrowser;
    QLabel *MessageLabel;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QComboBox *Row_box;
    QLabel *Columnlabel;
    QLabel *Rowlabel;
    QComboBox *Column_box;
    QGridLayout *gridLayout_2;
    QComboBox *Selection_mode_box;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(1024, 840));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");

        horizontalLayout->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        MessageLabel = new QLabel(centralwidget);
        MessageLabel->setObjectName("MessageLabel");

        verticalLayout->addWidget(MessageLabel);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMaximumSize(QSize(1024, 16777215));

        verticalLayout->addWidget(lineEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Row_box = new QComboBox(centralwidget);
        Row_box->addItem(QString());
        Row_box->addItem(QString());
        Row_box->setObjectName("Row_box");

        gridLayout->addWidget(Row_box, 1, 0, 1, 1);

        Columnlabel = new QLabel(centralwidget);
        Columnlabel->setObjectName("Columnlabel");

        gridLayout->addWidget(Columnlabel, 0, 1, 1, 1);

        Rowlabel = new QLabel(centralwidget);
        Rowlabel->setObjectName("Rowlabel");

        gridLayout->addWidget(Rowlabel, 0, 0, 1, 1);

        Column_box = new QComboBox(centralwidget);
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->addItem(QString());
        Column_box->setObjectName("Column_box");

        gridLayout->addWidget(Column_box, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(10, 10, 10, 10);
        Selection_mode_box = new QComboBox(centralwidget);
        Selection_mode_box->addItem(QString());
        Selection_mode_box->addItem(QString());
        Selection_mode_box->addItem(QString());
        Selection_mode_box->setObjectName("Selection_mode_box");
        Selection_mode_box->setMaximumSize(QSize(120, 30));

        gridLayout_2->addWidget(Selection_mode_box, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(100, 24));
        pushButton->setMaximumSize(QSize(100, 24));

        gridLayout_2->addWidget(pushButton, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203 \320\276\321\202 \320\276\321\210\320\270\320\261\320\276\320\272?", nullptr));
        checkBox->setText(QString());
        MessageLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\270\320\274\320\262\320\276\320\273 \320\264\320\273\321\217 \320\276\321\202\320\277\321\200\320\260\320\262\320\272\320\270(\320\235\320\265 \320\261\320\276\320\273\320\265\320\265 \320\276\320\264\320\275\320\276\320\263\320\276)", nullptr));
        Row_box->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        Row_box->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        Columnlabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\201\321\202\320\276\320\273\320\261\321\206\320\260", nullptr));
        Rowlabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\201\321\202\321\200\320\276\320\272\320\270", nullptr));
        Column_box->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        Column_box->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        Column_box->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        Column_box->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        Column_box->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        Column_box->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        Column_box->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        Column_box->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));
        Column_box->setItemText(8, QCoreApplication::translate("MainWindow", "9", nullptr));
        Column_box->setItemText(9, QCoreApplication::translate("MainWindow", "10", nullptr));
        Column_box->setItemText(10, QCoreApplication::translate("MainWindow", "11", nullptr));
        Column_box->setItemText(11, QCoreApplication::translate("MainWindow", "12", nullptr));
        Column_box->setItemText(12, QCoreApplication::translate("MainWindow", "13", nullptr));
        Column_box->setItemText(13, QCoreApplication::translate("MainWindow", "14", nullptr));
        Column_box->setItemText(14, QCoreApplication::translate("MainWindow", "15", nullptr));
        Column_box->setItemText(15, QCoreApplication::translate("MainWindow", "16", nullptr));

        Selection_mode_box->setItemText(0, QCoreApplication::translate("MainWindow", "\320\247\321\202\320\265\320\275\320\270\320\265", nullptr));
        Selection_mode_box->setItemText(1, QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214", nullptr));
        Selection_mode_box->setItemText(2, QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260 \320\264\320\270\321\201\320\277\320\273\320\265\321\217", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "Send message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
