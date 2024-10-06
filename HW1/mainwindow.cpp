#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QGraphicsScene 생성 및 설정
    scene = new QGraphicsScene(this);
    ui->area->setScene(scene);

    // QSpinBox 범위 설정
    ui->link1SpinBox->setRange(1, 100);
    ui->link2SpinBox->setRange(1, 100);
    ui->link3SpinBox->setRange(1, 100);

    // QSlider 범위 설정
    ui->joint1Slider->setRange(0, 360);
    ui->joint2Slider->setRange(0, 360);
    ui->joint3Slider->setRange(0, 360);

    // 시작할 때 QSlider의 값을 QLabel에 출력
    ui->joint1Angle->setText(QString::number(ui->joint1Slider->value()));
    ui->joint2Angle->setText(QString::number(ui->joint2Slider->value()));
    ui->joint3Angle->setText(QString::number(ui->joint3Slider->value()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawArm()
{
    // QGraphicsScene 가져오기
    QGraphicsScene *scene = ui->area->scene(); // 이미 생성된 scene을 가져옴

    // scene 초기화
    scene->clear(); // 기존의 선과 점을 모두 지움

    // 각 SpinBox 값 가져오기
    int length1 = ui->link1SpinBox->value();
    int length2 = ui->link2SpinBox->value();
    int length3 = ui->link3SpinBox->value();

    // Pen 설정 (흰색 선)
    QPen pen(Qt::white);
    pen.setWidth(3);

    // 고정할 왼쪽 꼭짓점 좌표 설정
    static int fixedX = 100; // 고정된 x 좌표
    static int fixedY = ui->area->height() / 2; // 고정된 y 좌표, 세로 중앙

    // 각 슬라이더의 값을 각도로 가져오기
    double angle1 = static_cast<double>(ui->joint1Slider->value()) * M_PI / 180.0;
    double angle2 = static_cast<double>(ui->joint2Slider->value()) * M_PI / 180.0;
    double angle3 = static_cast<double>(ui->joint3Slider->value()) * M_PI / 180.0;

    // 첫 번째 선: 흰색 (고정된 좌표에서 시작)
    double x1 = fixedX + length1 * cos(angle1);
    double y1 = fixedY - length1 * sin(angle1);
    QGraphicsLineItem *line1 = new QGraphicsLineItem(fixedX, fixedY, x1, y1);
    line1->setPen(pen);
    scene->addItem(line1);

    // 첫 번째 꼭짓점에 파란색 점 추가
    QGraphicsEllipseItem *point1 = new QGraphicsEllipseItem(x1 - 3, y1 - 3, 6, 6); // 점 크기 조정
    point1->setBrush(Qt::blue);
    point1->setZValue(1); // 점을 선보다 위에 표시
    scene->addItem(point1);

    // 두 번째 선: 흰색, 첫 번째 선 끝에서 시작
    double x2 = x1 + length2 * cos(angle1 + angle2);
    double y2 = y1 - length2 * sin(angle1 + angle2);
    QGraphicsLineItem *line2 = new QGraphicsLineItem(x1, y1, x2, y2);
    line2->setPen(pen);
    scene->addItem(line2);

    // 두 번째 꼭짓점에 파란색 점 추가
    QGraphicsEllipseItem *point2 = new QGraphicsEllipseItem(x2 - 3, y2 - 3, 6, 6); // 점 크기 조정
    point2->setBrush(Qt::blue);
    point2->setZValue(1); // 점을 선보다 위에 표시
    scene->addItem(point2);

    // 세 번째 선: 흰색, 두 번째 선 끝에서 시작
    double x3 = x2 + length3 * cos(angle1 + angle2 + angle3);
    double y3 = y2 - length3 * sin(angle1 + angle2 + angle3);
    QGraphicsLineItem *line3 = new QGraphicsLineItem(x2, y2, x3, y3);
    line3->setPen(pen);
    scene->addItem(line3);

    // 세 번째 꼭짓점에 파란색 점 추가 (크기 6으로 증가)
    QGraphicsEllipseItem *point3 = new QGraphicsEllipseItem(x3 - 3, y3 - 3, 6, 6); // 점 크기 조정
    point3->setBrush(Qt::red);
    point3->setZValue(1); // 점을 선보다 위에 표시
    scene->addItem(point3);
}

// Generate Arm 클릭 시 QGraphicsView에 선을 출력
void MainWindow::on_ArmButton_clicked()
{
    drawArm(); // 선을 그리는 함수 호출
}


void MainWindow::on_RestButton_clicked()
{
    // 슬라이더 초기화
    ui->joint1Slider->setValue(0);
    ui->joint2Slider->setValue(0);
    ui->joint3Slider->setValue(0);

    // 각도 표시 QLabel 초기화
    ui->joint1Angle->setText("0");
    ui->joint2Angle->setText("0");
    ui->joint3Angle->setText("0");

    // SpinBox 값을 1로 설정
    ui->link1SpinBox->setValue(1);
    ui->link2SpinBox->setValue(1);
    ui->link3SpinBox->setValue(1);


    scene->clear();
}


// joint1Slider 값 변경 시 QLabel에 출력 및 Arm 그리기
void MainWindow::on_joint1Slider_valueChanged(int value)
{
    ui->joint1Angle->setText(QString::number(value));
    drawArm(); // 각도 변경 시 Arm 다시 그리기
}

// joint2Slider 값 변경 시 QLabel에 출력 및 Arm 그리기
void MainWindow::on_joint2Slider_valueChanged(int value)
{
    ui->joint2Angle->setText(QString::number(value));
    drawArm(); // 각도 변경 시 Arm 다시 그리기
}

// joint3Slider 값 변경 시 QLabel에 출력 및 Arm 그리기
void MainWindow::on_joint3Slider_valueChanged(int value)
{
    ui->joint3Angle->setText(QString::number(value));
    drawArm(); // 각도 변경 시 Arm 다시 그리기
}

void MainWindow::on_link1SpinBox_valueChanged(int arg1) {}
void MainWindow::on_link2SpinBox_valueChanged(int arg1) {}
void MainWindow::on_link3SpinBox_valueChanged(int arg1) {}
