#include "win_ctrl.h"
#include <QDebug>
#include <QString>
#include <QThread>

QString ctrl_button_style = "QPushButton{border:4px groove gray; border-radius:60px; padding:2px 4px;"
                            "background-repeat:no-repeat; background-position:center;"
                            "font-size:50px; font-weight:bold;;}"
                            "QPushButton:hover{background-color:rgb(200,235,255);}"
                            "QPushButton:pressed{background-color:rgb(150,210,255);}";
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

CtrlWindow::CtrlWindow(int Width, int Height, QWidget *parent)
    : BaseWindow(Width, Height, parent)
{
    initwindow();
}

CtrlWindow::~CtrlWindow()
{

}

void CtrlWindow::initwindow()
{
    QPixmap back_image = QPixmap(":/image/image/background.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(back_image));
    this->setPalette(palette);

    ctrl_speed = new QSlider(Qt::Horizontal, this);
    ctrl_speed->setMinimum(0);
    ctrl_speed->setMaximum(100);
    ctrl_speed->setValue(30);
    ctrl_speed->setGeometry(400, 100, 320, 40);
    ctrl_speed->setStyleSheet(slider_style);
    watch_speed = new QSpinBox(this);
    watch_speed->setMinimum(0);
    watch_speed->setMaximum(100);
    watch_speed->setValue(30);
    watch_speed->setGeometry(610, 150, 80, 40);

    watch_speed->setStyleSheet(QString("QSpinBox{font-size:25px;}"));
    tip_speed = new QLabel(this);
    tip_speed->setText(QString("Current Speed:"));
    tip_speed->setGeometry(420, 150, 280, 40);
    tip_speed->setStyleSheet(QString("QLabel{font-size:25px;}"));

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
    exit->setText(QString("Back"));
    exit->setGeometry(60, 100, 120, 80);
    exit->setStyleSheet(QString(ctrl_button_style).append("QPushButton{border-radius:40px;"
                                                          "font-size:25px;}"));
    QObject::connect(ctrl_down, SIGNAL(pressed()), this, SLOT(run_down()));
    QObject::connect(ctrl_down, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(ctrl_up, SIGNAL(pressed()), this, SLOT(run_up()));
    QObject::connect(ctrl_up, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(ctrl_left, SIGNAL(pressed()), this, SLOT(run_left()));
    QObject::connect(ctrl_left, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(ctrl_right, SIGNAL(pressed()), this, SLOT(run_right()));
    QObject::connect(ctrl_right, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(ctrl_CW, SIGNAL(pressed()), this, SLOT(run_CW()));
    QObject::connect(ctrl_CW, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(ctrl_anti_CW, SIGNAL(pressed()), this, SLOT(run_anti_CW()));
    QObject::connect(ctrl_anti_CW, SIGNAL(released()), this, SLOT(stop_run()));
    QObject::connect(exit, SIGNAL(clicked(bool)), this, SLOT(myclose()));
    QObject::connect(back, SIGNAL(triggered(bool)), this, SLOT(myclose()));
    QObject::connect(ctrl_speed, SIGNAL(valueChanged(int)), watch_speed, SLOT(setValue(int)));
    QObject::connect(watch_speed, SIGNAL(valueChanged(int)), ctrl_speed, SLOT(setValue(int)));
    QObject::connect(ctrl_stop, SIGNAL(clicked(bool)), this, SLOT(stop_run()));
//    QObject::connect()
}

void CtrlWindow::openwindow()
{
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash; roslaunch wpb_home_bringup minimal.launch ;bash'&");
    this->show();
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
}
void CtrlWindow::run_down()
{
    QString a="gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-";
    QString b = ",0.0,0.0]' '[0.0,0.0,0.0]';bash'";
    system((a+QString::number(watch_speed->value()*0.002)+b).toStdString().c_str());
    QThread::sleep(2);
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-0.0,0.0,0.0]' '[0.0,0.0,0.0]';bash'");

}

void CtrlWindow::run_left()
{
    QString a = "gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-0.0,";
    QString b = ",0.0]' '[0.0,0.0,0.0]';bash'";
    system((a+QString::number(watch_speed->value()*0.002)+b).toStdString().c_str());
    QThread::sleep(2);
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-0.0,0.0,0.0]' '[0.0,0.0,0.0]';bash'");
}

void CtrlWindow::run_right()
{
    QString a = "gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-0.0,-";
    QString b = ",0.0]' '[0.0,0.0,0.0]';bash'";
    system((a+QString::number(watch_speed->value()*0.002)+b).toStdString().c_str());
    QThread::sleep(2);
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-0.0,0.0,0.0]' '[0.0,0.0,0.0]';bash'");
}

void CtrlWindow::run_up()
{
    QString a ="gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[";
    QString b = ",0.0,0.0]' '[0.0,0.0,0.0]';bash'";
    system((a+QString::number(watch_speed->value()*0.002)+b).toStdString().c_str());
    QThread::sleep(2);
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-0.0,0.0,0.0]' '[0.0,0.0,0.0]';bash'");
}

void CtrlWindow::run_CW()
{
    QString a ="gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[0.0,0.0,0.0]' '[0.0,0.0,-";
    QString b ="]';bash'";
    system((a+QString::number(watch_speed->value()*0.002)+b).toStdString().c_str());
    QThread::sleep(2);
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-0.0,0.0,0.0]' '[0.0,0.0,0.0]';bash'");
}

void CtrlWindow::run_anti_CW()
{
    QString a ="gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[0.0,0.0,0.0]' '[0.0,0.0,";
    QString b = "]';bash'";
    system((a+QString::number(watch_speed->value()*0.002)+b).toStdString().c_str());
    QThread::sleep(2);
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-0.0,0.0,0.0]' '[0.0,0.0,0.0]';bash'");
}

void CtrlWindow::stop_run()
{
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 rostopic;rostopic pub -r 1  /cmd_vel geometry_msgs/Twist '[-0.0,0.0,0.0]' '[0.0,0.0,0.0]';bash'");
}

void CtrlWindow::myclose()
{
     system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 roslaunch;pkill -2 rostopic;bash'");
     system("gnome-terminal -x bash -c 'killall bash'");
     this->close();
}

CtrlDialog::CtrlDialog(int Width, int Height, QWidget *parent)
    : BaseWindow(Width, Height, parent)
{
    initwindow();
}

CtrlDialog::~CtrlDialog()
{

}

void CtrlDialog::initwindow()
{
    QPixmap back_image = QPixmap(":/image/image/background.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(back_image));
    this->setPalette(palette);

    js_ctrl = new QPushButton(this);
    js_ctrl->setGeometry(this->width()/2-225, this->height()/2-150, 450, 150);
    js_ctrl->setStyleSheet(QString("QPushButton{border-image:url(:/image/image/icon_js_ctrl.png);}"
                                 "QPushButton:hover{border-image:url(:/image/image/icon_js_hover.png);}"
                                 "QPushButton:pressed{border-image:url(:/image/image/icon_js_pressed.png);}"));
    scr_ctrl = new QPushButton(this);
    scr_ctrl->setGeometry(this->width()/2-225, this->height()/2+75, 450, 150);
    scr_ctrl->setStyleSheet(QString("QPushButton{border-image:url(:/image/image/icon_scr_ctrl.png);}"
                                    "QPushButton:hover{border-image:url(:/image/image/icon_scr_hover.png);}"
                                    "QPushButton:pressed{border-image:url(:/image/image/icon_scr_pressed.png);}"));
    QObject::connect(js_ctrl, SIGNAL(clicked(bool)), this, SLOT(js_control()));
    QObject::connect(scr_ctrl, SIGNAL(clicked(bool)), this, SLOT(scr_control()));
}

void CtrlDialog::openwindow()
{
    this->show();
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
}

void CtrlDialog::js_control()
{
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;roslaunch wpb_home_bringup js_ctrl.launch;bash'&");
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("手柄控制进行中..."),
                                                  tr("请用手柄进行控制\n点击确定按钮退出手柄控制"),
                                                  QMessageBox::Yes, QMessageBox::Yes))
    {
        system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 roslaunch;pkill -2 rostopic;bash'");
        system("gnome-terminal -x bash -c 'killall bash'");
    }
}

void CtrlDialog::scr_control()
{
    this->close();
}
