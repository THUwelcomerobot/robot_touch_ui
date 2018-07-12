#include "ctrlwindow.h"
#include <QDebug>

QString ctrl_button_style = "QPushButton{border:2px groove gray; border-radius:30px; padding:2px 4px; font-size:30px; font-weight:30px;}"
                            "QPushButton:hover{background-color:rgb(240,248,255);}"
                            "QPushButton:pressed{background-color:rgb(225,245,255);}";

CtrlWindow::CtrlWindow(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(400, 300);
    this->setWindowTitle("Ctrl_UI");

    ctrl_up = new QPushButton(this);
    ctrl_up->setText(QStringLiteral("↑"));
    ctrl_up->setGeometry(250, 100, 60, 60);
    ctrl_up->setStyleSheet(ctrl_button_style);

    ctrl_down = new QPushButton(this);
    ctrl_down->setText(QStringLiteral("↓"));
    ctrl_down->setGeometry(250, 200, 60, 60);
    ctrl_down->setStyleSheet(ctrl_button_style);

    ctrl_left = new QPushButton(this);
    ctrl_left->setText(QStringLiteral("←"));
    ctrl_left->setGeometry(200, 150, 60, 60);
    ctrl_left->setStyleSheet(ctrl_button_style);

    ctrl_right = new QPushButton(this);
    ctrl_right->setText(QStringLiteral("→"));
    ctrl_right->setGeometry(300, 150, 60, 60);
    ctrl_right->setStyleSheet(ctrl_button_style);

    ctrl_speed = new QSlider(Qt::Horizontal, this);
    ctrl_speed->setMinimum(0);
    ctrl_speed->setMaximum(100);
    ctrl_speed->setValue(30);
    ctrl_speed->setGeometry(200, 40, 140, 20);

    watch_speed = new QSpinBox(this);
    watch_speed->setMinimum(0);
    watch_speed->setMaximum(100);
    watch_speed->setValue(30);
    watch_speed->setGeometry(330, 65, 40, 20);

    tip_speed = new QLabel(this);
    tip_speed->setText(QStringLiteral("机器人当前速度："));
    tip_speed->setGeometry(180, 65, 140, 20);

    ctrl_CW = new QPushButton(this);
    ctrl_CW->setGeometry(50, 180, 80, 80);
    ctrl_CW->setStyleSheet(tr("border-image: url(:/image/image/anti_CW.jpg);"));
    ctrl_anti_CW = new QPushButton(this);

    exit = new QPushButton(this);
    exit->setText(QStringLiteral("返回"));
    exit->setGeometry(40, 40, 50, 50);

    QObject::connect(ctrl_down, SIGNAL(clicked(bool)), this, SLOT(run_down()));
    QObject::connect(ctrl_up, SIGNAL(clicked(bool)), this, SLOT(run_up()));
    QObject::connect(ctrl_left, SIGNAL(clicked(bool)), this, SLOT(run_left()));
    QObject::connect(ctrl_right, SIGNAL(clicked(bool)), this, SLOT(run_right()));
    QObject::connect(exit, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(ctrl_speed, SIGNAL(valueChanged(int)), watch_speed, SLOT(setValue(int)));
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

