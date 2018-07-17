#include "basewindow.h"

BaseWindow::BaseWindow(int Width, int Height, QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(Width, Height);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    initwindow();
    initToolBar();
}

BaseWindow::~BaseWindow()
{

}

void BaseWindow::initwindow()
{

}

void BaseWindow::initToolBar()
{
    topbar = new QToolBar(this);
    topbar->setGeometry(0, 0, this->width(), 60);
    topbar->setMovable(false);
    topbar->setStyleSheet(QString("QToolBar{border-image:url(:/image/image/title.png);}"));

    closed = new QAction(QIcon(":/image/image/tool_close.png"), tr("关闭窗口"), this);
    QObject::connect(closed, SIGNAL(triggered(bool)), this, SLOT(quit()));
    back = new QAction(QIcon(":/image/image/tool_back.png"), tr("返回"), this);
    QObject::connect(back, SIGNAL(triggered(bool)), this, SLOT(close()));
    spacer = new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    topbar->addAction(back);
    topbar->addWidget(spacer);
    topbar->addAction(closed);
}

void BaseWindow::openwindow()
{
    this->show();
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
}

void BaseWindow::quit()
{
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("退出程序"),
                                                  tr("你确定要退出程序吗?"),
                                                  QMessageBox::Yes | QMessageBox::No,
                                                  QMessageBox::No))
    {
       system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 roslaunch;pkill -2 rosrun;pkill -2 gnome-terminal;bash'");
     system("gnome-terminal -x bash -c 'killall bash'");
        this->close();

    }

}
