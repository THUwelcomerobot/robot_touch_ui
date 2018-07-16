#include "ctrlwindow.h"
#include <QDebug>

int max_speed = 1;

QString ctrl_button_style = "QPushButton{border:4px groove gray; border-radius:60px; padding:2px 4px;"
                            "background-repeat:no-repeat; background-position:center;"
                            "font-size:50px; font-weight:bold;;}"
                            "QPushButton:hover{background-color:rgb(240,248,255);}"
                            "QPushButton:pressed{background-color:rgb(225,245,255);}";
QString slider_style = "QSlider::groove:horizontal{"
                       "border-image:url(:/image/image/slider_background.png);"
                       "border-radius:20px;"
                       "height:40px;}"
                       "QSlider::handle:horizontal{"
                       "border-image:url(:/image/image/slider_handle.png);"
                       "border-radius:20px;"
                       "width:40px;}"
                       "QSlider::handle:horizontal:pressed{"
                       "border-image:url(:/image/image/slider_handle_pressed.png);"
                       "border-radius:20px;"
                       "width:40px;}";

CtrlWindow::CtrlWindow(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(800, 600);
    this->setWindowTitle("Ctrl_UI");

    ctrl_up = new QPushButton(this);
    ctrl_up->setText(QString("↑"));
    ctrl_up->setGeometry(500, 200, 120, 120);
    ctrl_up->setStyleSheet(ctrl_button_style);

    ctrl_down = new QPushButton(this);
    ctrl_down->setText(QString("↓"));
    ctrl_down->setGeometry(500, 400, 120, 120);
    ctrl_down->setStyleSheet(ctrl_button_style);

    ctrl_left = new QPushButton(this);
    ctrl_left->setText(QString("←"));
    ctrl_left->setGeometry(400, 300, 120, 120);
    ctrl_left->setStyleSheet(ctrl_button_style);

    ctrl_right = new QPushButton(this);
    ctrl_right->setText(QString("→"));
    ctrl_right->setGeometry(600, 300, 120, 120);
    ctrl_right->setStyleSheet(ctrl_button_style);

    ctrl_speed = new QSlider(Qt::Horizontal, this);
    ctrl_speed->setMinimum(0);
    ctrl_speed->setMaximum(100);
    ctrl_speed->setValue(30);
    ctrl_speed->setGeometry(400, 60, 320, 40);
    ctrl_speed->setStyleSheet(slider_style);

    watch_speed = new QSpinBox(this);
    watch_speed->setMinimum(0);
    watch_speed->setMaximum(100);
    watch_speed->setValue(30);
    watch_speed->setGeometry(600, 110, 80, 40);
    watch_speed->setStyleSheet(QString("QSpinBox{font-size:25px;"
                                       "border:4px groove gray; border-radius:60px; padding:2px 4px;}"));

    tip_speed = new QLabel(this);
    tip_speed->setText(QStringLiteral("Current Speed:"));
    tip_speed->setGeometry(400, 110, 280, 40);
    tip_speed->setStyleSheet(QString("QLabel{font-size:25px;"
                                     "border:4px groove gray; border-radius:60px; padding:2px 4px;}"));

    ctrl_CW = new QPushButton(this);
    ctrl_CW->setGeometry(150, 220, 140, 140);
    ctrl_CW->setStyleSheet(QString(ctrl_button_style).append("QPushButton{background-image:url(:/image/image/CW.png);"
                                                             "border-radius:70px;}"));

    ctrl_anti_CW = new QPushButton(this);
    ctrl_anti_CW->setGeometry(240, 370, 140, 140);
    ctrl_anti_CW->setStyleSheet(QString(ctrl_button_style).append("QPushButton{background-image:url(:/image/image/anti_CW.png);"
                                                                  "border-radius:70px;}"));

    ctrl_stop = new QPushButton(this);
    ctrl_stop->setText(QString("■"));
    ctrl_stop->setGeometry(60, 370, 140, 140);
    ctrl_stop->setStyleSheet(QString(ctrl_button_style).append("QPushButton{border-radius:70px;"
                                                               "font-size:25px;}"));

    exit = new QPushButton(this);
    exit->setText(QStringLiteral("Back"));
    exit->setGeometry(60, 60, 120, 80);
    exit->setStyleSheet(QString(ctrl_button_style).append("QPushButton{border-radius:40px;"
                                                          "font-size:25px;}"));

//    QObject::connect(ctrl_down, SIGNAL(clicked(bool)), this, SLOT(run_down()));
//    QObject::connect(ctrl_up, SIGNAL(clicked(bool)), this, SLOT(run_up()));
//    QObject::connect(ctrl_left, SIGNAL(clicked(bool)), this, SLOT(run_left()));
//    QObject::connect(ctrl_right, SIGNAL(clicked(bool)), this, SLOT(run_right()));

    QObject::connect(ctrl_down, SIGNAL(pressed()), this, SLOT(run_down()));
    QObject::connect(ctrl_down, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(ctrl_up, SIGNAL(pressed()), this, SLOT(run_up()));
    QObject::connect(ctrl_up, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(ctrl_left, SIGNAL(pressed()), this, SLOT(run_left()));
    QObject::connect(ctrl_left, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(ctrl_right, SIGNAL(pressed()), this, SLOT(run_right()));
    QObject::connect(ctrl_right, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(exit, SIGNAL(clicked(bool)), this, SLOT(close_window()));
    QObject::connect(ctrl_speed, SIGNAL(valueChanged(int)), watch_speed, SLOT(setValue(int)));
    QObject::connect(ctrl_stop, SIGNAL(clicked(bool)), this, SLOT(stop_run()));
}

CtrlWindow::~CtrlWindow()
{

}

void CtrlWindow::close_window()
{
    this->close();
    system("gnome-terminal -x bash -c 'pkill -2 roslaunch'");
}

void CtrlWindow::run_down()
{
    QString ctrl;
//    ctrl.append("gnome-terminal -x bash -c 'rostopic pub  rostopic pub /cmd_vel geometry_msgs/Twist '[");
//    ctrl.append(QString::number(watch_speed->value()/100*max_speed));
    system("gnome-terminal -x bash -c 'rostopic pub  rostopic pub /cmd_vel geometry_msgs/Twist '[-0.2,0.0,0.0]' '[0.0,0.0,0.0]''");

}

void CtrlWindow::run_left()
{
//    system("gnome-terminal -x bash -c 'pkill -2 roscore'");
}

void CtrlWindow::run_right()
{

}

void CtrlWindow::run_up()
{

}

void CtrlWindow::stop_run()
{
    system("gnome-terminal -x bash -c 'pkill -2 rostopic'");
}
