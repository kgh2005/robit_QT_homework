/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *link1;
    QLabel *link2;
    QLabel *link3;
    QSpinBox *link1SpinBox;
    QSpinBox *link2SpinBox;
    QSpinBox *link3SpinBox;
    QPushButton *ArmButton;
    QLabel *joint1;
    QLabel *joint2;
    QLabel *joint3;
    QSlider *joint1Slider;
    QSlider *joint2Slider;
    QSlider *joint3Slider;
    QLabel *joint1Angle;
    QLabel *joint2Angle;
    QLabel *joint3Angle;
    QPushButton *RestButton;
    QGraphicsView *area;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        link1 = new QLabel(centralwidget);
        link1->setObjectName(QString::fromUtf8("link1"));
        link1->setGeometry(QRect(560, 30, 41, 17));
        link2 = new QLabel(centralwidget);
        link2->setObjectName(QString::fromUtf8("link2"));
        link2->setGeometry(QRect(560, 60, 41, 17));
        link3 = new QLabel(centralwidget);
        link3->setObjectName(QString::fromUtf8("link3"));
        link3->setGeometry(QRect(560, 90, 41, 17));
        link1SpinBox = new QSpinBox(centralwidget);
        link1SpinBox->setObjectName(QString::fromUtf8("link1SpinBox"));
        link1SpinBox->setGeometry(QRect(610, 25, 151, 26));
        link2SpinBox = new QSpinBox(centralwidget);
        link2SpinBox->setObjectName(QString::fromUtf8("link2SpinBox"));
        link2SpinBox->setGeometry(QRect(610, 55, 151, 26));
        link3SpinBox = new QSpinBox(centralwidget);
        link3SpinBox->setObjectName(QString::fromUtf8("link3SpinBox"));
        link3SpinBox->setGeometry(QRect(610, 85, 151, 26));
        ArmButton = new QPushButton(centralwidget);
        ArmButton->setObjectName(QString::fromUtf8("ArmButton"));
        ArmButton->setGeometry(QRect(560, 120, 211, 25));
        joint1 = new QLabel(centralwidget);
        joint1->setObjectName(QString::fromUtf8("joint1"));
        joint1->setGeometry(QRect(560, 150, 41, 17));
        joint2 = new QLabel(centralwidget);
        joint2->setObjectName(QString::fromUtf8("joint2"));
        joint2->setGeometry(QRect(560, 180, 41, 17));
        joint3 = new QLabel(centralwidget);
        joint3->setObjectName(QString::fromUtf8("joint3"));
        joint3->setGeometry(QRect(560, 210, 41, 17));
        joint1Slider = new QSlider(centralwidget);
        joint1Slider->setObjectName(QString::fromUtf8("joint1Slider"));
        joint1Slider->setGeometry(QRect(610, 150, 100, 16));
        joint1Slider->setOrientation(Qt::Horizontal);
        joint2Slider = new QSlider(centralwidget);
        joint2Slider->setObjectName(QString::fromUtf8("joint2Slider"));
        joint2Slider->setGeometry(QRect(610, 180, 100, 16));
        joint2Slider->setOrientation(Qt::Horizontal);
        joint3Slider = new QSlider(centralwidget);
        joint3Slider->setObjectName(QString::fromUtf8("joint3Slider"));
        joint3Slider->setGeometry(QRect(610, 210, 100, 16));
        joint3Slider->setOrientation(Qt::Horizontal);
        joint1Angle = new QLabel(centralwidget);
        joint1Angle->setObjectName(QString::fromUtf8("joint1Angle"));
        joint1Angle->setGeometry(QRect(720, 148, 51, 17));
        joint1Angle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        joint2Angle = new QLabel(centralwidget);
        joint2Angle->setObjectName(QString::fromUtf8("joint2Angle"));
        joint2Angle->setGeometry(QRect(720, 178, 51, 17));
        joint2Angle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        joint3Angle = new QLabel(centralwidget);
        joint3Angle->setObjectName(QString::fromUtf8("joint3Angle"));
        joint3Angle->setGeometry(QRect(720, 208, 51, 17));
        joint3Angle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        RestButton = new QPushButton(centralwidget);
        RestButton->setObjectName(QString::fromUtf8("RestButton"));
        RestButton->setGeometry(QRect(560, 240, 211, 25));
        area = new QGraphicsView(centralwidget);
        area->setObjectName(QString::fromUtf8("area"));
        area->setGeometry(QRect(10, 10, 531, 551));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        link1->setText(QCoreApplication::translate("MainWindow", "link1", nullptr));
        link2->setText(QCoreApplication::translate("MainWindow", "link2", nullptr));
        link3->setText(QCoreApplication::translate("MainWindow", "link3", nullptr));
        ArmButton->setText(QCoreApplication::translate("MainWindow", "Generate Arm", nullptr));
        joint1->setText(QCoreApplication::translate("MainWindow", "joint1", nullptr));
        joint2->setText(QCoreApplication::translate("MainWindow", "joint2", nullptr));
        joint3->setText(QCoreApplication::translate("MainWindow", "joint3", nullptr));
        joint1Angle->setText(QString());
        joint2Angle->setText(QString());
        joint3Angle->setText(QString());
        RestButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
