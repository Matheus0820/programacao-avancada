/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *inputIp;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *button_connect;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_disconnect;
    QHBoxLayout *horizontalLayout_4;
    QSlider *horizontalSlider_min;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLCDNumber *lcdMin;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider_max;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLCDNumber *lcdMax;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSlider *horizontalSlider_timing;
    QLCDNumber *lcdNumber_timing;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_start;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_stop;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLabel *labelStatus;
    QSpacerItem *horizontalSpacer_3;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(715, 334);
        MainWindow->setWindowOpacity(1.000000000000000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout_10 = new QHBoxLayout(centralwidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(-1, 3, -1, 3);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(label);

        inputIp = new QLineEdit(centralwidget);
        inputIp->setObjectName("inputIp");
        QFont font1;
        font1.setPointSize(10);
        inputIp->setFont(font1);

        horizontalLayout_6->addWidget(inputIp);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        button_connect = new QPushButton(centralwidget);
        button_connect->setObjectName("button_connect");

        horizontalLayout_5->addWidget(button_connect);

        horizontalSpacer = new QSpacerItem(118, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        button_disconnect = new QPushButton(centralwidget);
        button_disconnect->setObjectName("button_disconnect");

        horizontalLayout_5->addWidget(button_disconnect);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSlider_min = new QSlider(centralwidget);
        horizontalSlider_min->setObjectName("horizontalSlider_min");
        horizontalSlider_min->setMaximum(100);
        horizontalSlider_min->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_min);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        lcdMin = new QLCDNumber(centralwidget);
        lcdMin->setObjectName("lcdMin");

        verticalLayout_3->addWidget(lcdMin);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 7);

        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSlider_max = new QSlider(centralwidget);
        horizontalSlider_max->setObjectName("horizontalSlider_max");
        horizontalSlider_max->setMaximum(100);
        horizontalSlider_max->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_max);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        lcdMax = new QLCDNumber(centralwidget);
        lcdMax->setObjectName("lcdMax");

        verticalLayout_2->addWidget(lcdMax);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 7);

        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        horizontalLayout_2->addWidget(label_4);

        horizontalSlider_timing = new QSlider(centralwidget);
        horizontalSlider_timing->setObjectName("horizontalSlider_timing");
        horizontalSlider_timing->setMinimum(1);
        horizontalSlider_timing->setMaximum(10);
        horizontalSlider_timing->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_timing);

        lcdNumber_timing = new QLCDNumber(centralwidget);
        lcdNumber_timing->setObjectName("lcdNumber_timing");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdNumber_timing->sizePolicy().hasHeightForWidth());
        lcdNumber_timing->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lcdNumber_timing);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        button_start = new QPushButton(centralwidget);
        button_start->setObjectName("button_start");

        horizontalLayout->addWidget(button_start);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        button_stop = new QPushButton(centralwidget);
        button_stop->setObjectName("button_stop");

        horizontalLayout->addWidget(button_stop);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_7->addWidget(label_5);

        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setFont(font2);
        labelStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_7->addWidget(labelStatus);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalLayout_4->setStretch(2, 20);
        verticalLayout_4->setStretch(3, 20);
        verticalLayout_4->setStretch(4, 15);

        horizontalLayout_10->addLayout(verticalLayout_4);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        horizontalLayout_10->addWidget(listWidget);

        horizontalLayout_10->setStretch(0, 4);
        horizontalLayout_10->setStretch(1, 6);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 715, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider_min, &QSlider::valueChanged, lcdMin, qOverload<int>(&QLCDNumber::display));
        QObject::connect(horizontalSlider_max, &QSlider::valueChanged, lcdMax, qOverload<int>(&QLCDNumber::display));
        QObject::connect(horizontalSlider_timing, &QSlider::valueChanged, lcdNumber_timing, qOverload<int>(&QLCDNumber::display));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Produce Client", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        inputIp->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        button_connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        button_disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Timing (s)", nullptr));
        button_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        button_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
