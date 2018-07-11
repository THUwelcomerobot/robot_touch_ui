#include "ctrlwindow.h"

CtrlWindow::CtrlWindow(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(400, 300);
    this->setWindowTitle("Ctrl_UI");

    ctrl_up = new QPushButton(this);
    ctrl_up->setText(QStringLiteral("上"));
    ctrl_up->setGeometry(250, 100, 50, 50);

    ctrl_down = new QPushButton(this);
    ctrl_down->setText(QStringLiteral("下"));
    ctrl_down->setGeometry(250, 200, 50, 50);

    ctrl_left = new QPushButton(this);
    ctrl_left->setText(QStringLiteral("左"));
    ctrl_left->setGeometry(200, 150, 50, 50);

    ctrl_right = new QPushButton(this);
    ctrl_right->setText(QStringLiteral("右"));
    ctrl_right->setGeometry(300, 150, 50, 50);

    ctrl_speed = new QSlider(Qt::Horizontal, this);
    ctrl_speed->setMinimum(0);
    ctrl_speed->setMaximum(100);
    ctrl_speed->setValue(30);
    ctrl_speed->setGeometry(20, 150, 140, 20);

    exit = new QPushButton(this);
    exit->setText(QStringLiteral("返回"));
    exit->setGeometry(40, 40, 50, 50);

    QObject::connect(ctrl_down, SIGNAL(clicked(bool)), this, SLOT(run_down()));
    QObject::connect(ctrl_up, SIGNAL(clicked(bool)), this, SLOT(run_up()));
    QObject::connect(ctrl_left, SIGNAL(clicked(bool)), this, SLOT(run_left()));
    QObject::connect(ctrl_right, SIGNAL(clicked(bool)), this, SLOT(run_right()));
    QObject::connect(exit, SIGNAL(clicked(bool)), this, SLOT(close()));
}

CtrlWindow::~CtrlWindow()
{

}

void CtrlWindow::run_down()
{
    QProcess *process = new QProcess;
    process->start("C:/Practise/Python Program/robot_ui/robot_ui/exec_prog/test.exe",
                   QStringList("C:/Practise/Python Program/robot_ui/robot_ui/exec_prog/test.exe"));
}

void CtrlWindow::run_left()
{
    QProcess *process = new QProcess;
    process->start("C:/Practise/Python Program/robot_ui/robot_ui/exec_prog/test.exe",
                   QStringList("C:/Practise/Python Program/robot_ui/robot_ui/exec_prog/test.exe"));
}

void CtrlWindow::run_right()
{
    QProcess *process = new QProcess;
    process->start("C:/Practise/Python Program/robot_ui/robot_ui/exec_prog/test.exe",
                   QStringList("C:/Practise/Python Program/robot_ui/robot_ui/exec_prog/test.exe"));
}

void CtrlWindow::run_up()
{
    QProcess *process = new QProcess;
    process->start("C:/Practise/Python Program/robot_ui/robot_ui/exec_prog/test.exe",
                   QStringList("C:/Practise/Python Program/robot_ui/robot_ui/exec_prog/test.exe"));
}

