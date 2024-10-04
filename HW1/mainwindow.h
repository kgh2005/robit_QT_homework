#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>      // QGraphicsScene 포함
#include <QGraphicsLineItem>   // QGraphicsLineItem 포함
#include <QPen>                // QPen 포함

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_link1SpinBox_valueChanged(int arg1);
    void on_link2SpinBox_valueChanged(int arg1);
    void on_link3SpinBox_valueChanged(int arg1);
    void on_ArmButton_clicked();
    void on_RestButton_clicked();
    void on_joint1Slider_valueChanged(int value);
    void on_joint2Slider_valueChanged(int value);
    void on_joint3Slider_valueChanged(int value);
    void drawArm();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene; // QGraphicsScene 포인터 멤버 변수 추가
};

#endif // MAINWINDOW_H
