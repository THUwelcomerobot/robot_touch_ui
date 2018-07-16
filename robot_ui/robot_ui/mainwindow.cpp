#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(400, 300);
    this->setWindowTitle("Robot_UI");

    vel_ctrl = new QPushButton(this);
    vel_ctrl->setText(QStringLiteral("运动控制"));
    vel_ctrl->setGeometry(150, 50, 100, 40);

    voice_func = new QPushButton(this);
    voice_func->setText(QStringLiteral("语音对话"));
    voice_func->setGeometry(150, 110, 100, 40);

    face_func = new QPushButton(this);
    face_func->setText(QStringLiteral("人脸识别"));
    face_func->setGeometry(150, 170, 100, 40);

    QObject::connect(vel_ctrl, SIGNAL(clicked(bool)), this, SLOT(open_ctrl_window()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::open_ctrl_window()
{
    system("gnome-terminal -x bash -c 'source ~/.bashrc;roscore'&");
    ctrl_window = new CtrlWindow(this);
    ctrl_window->show();
//    system("gnome-terminal -x bash -c 'source ~/.bashrc;roslaunch wpb_home_bringup touch_pad_ctrl.launch '");


}
