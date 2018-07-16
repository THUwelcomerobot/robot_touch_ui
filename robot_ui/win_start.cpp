#include "win_start.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QPropertyAnimation>

QString start_button_style = "QPushButton{border-image:url(:/image/image/start.png)}"
                             "QPushButton:pressed{border-image:url(:/image/image/start_pressed.png)}";

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800, 600);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    startAll = new QPushButton(this);
    startAll->setGeometry(300, 200, 200, 200);
    startAll->setStyleSheet(start_button_style);

    loading = new QLabel(this);
    loading->setGeometry(150, 450, 0, 10);
    loading->setStyleSheet(QString("QLabel{border-image:url(:/image/image/title.png)}"));

    QObject::connect(startAll, SIGNAL(clicked(bool)), this, SLOT(login()));
}

StartWindow::~StartWindow()
{

}

//登录
void StartWindow::login()
{
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;roslaunch wpb_home_tutorials face_detect.launch ;bash'&");
    QPropertyAnimation *loadanime = new QPropertyAnimation(loading, "size");
    loadanime->setStartValue(loading->size());
    loadanime->setEndValue(QSize(500, loading->height()));
    loadanime->setDuration(25000);//25000
    loadanime->start(QAbstractAnimation::DeleteWhenStopped);
    QObject::connect(loadanime, SIGNAL(finished()), this, SLOT(emit_success()));

}

void StartWindow::emit_success()
{
    this->close();
    emit login_success();
}

void StartWindow::logout()
{
    loading->setGeometry(150, 450, 0, 10);
    this->update();
}

void StartWindow::openwindow()
{
    this->show();
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
}
