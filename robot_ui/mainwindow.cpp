#include "mainwindow.h"
#include <QPixmap>
#include <QPalette>

QString button_style = "QPushButton{border-radius:100px; background-repeat:no-repeat; background-position:center;}"
                       "QPushButton:hover{background-color:rgb(225,245,255);}"
                       "QPushButton:pressed{background-color:rgb(210,240,255);}";

MainWindow::MainWindow(int Width, int Height, QWidget *parent)
    : BaseWindow(Width, Height, parent)
{
    initwindow();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initwindow()
{
    QPixmap back_image = QPixmap(":/image/image/background.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(back_image));
    this->setPalette(palette);

    vel_ctrl = new QPushButton(this);
    vel_ctrl->setGeometry(40, 100, 200, 200);
    vel_ctrl->setStyleSheet(QString(button_style).append("QPushButton{background-image:"
                                                         "url(:/image/image/icon_ctrl.png);}"));
    image_handle = new QPushButton(this);
    image_handle->setGeometry(280, 100, 200, 200);
    image_handle->setStyleSheet(QString(button_style).append("QPushButton{background-image:"
                                                          "url(:/image/image/icon_image.png);}"));
    robot_chat = new QPushButton(this);
    robot_chat->setGeometry(520, 100, 200, 200);
    robot_chat->setStyleSheet(QString(button_style).append("QPushButton{background-image:"
                                                           "url(:/image/image/icon_chat.png);}"));
    select_func = new QPushButton(this);
    select_func->setGeometry(760, 100, 200, 200);
    select_func->setStyleSheet(QString(button_style).append("QPushButton{background-image:"
                                                           "url(:/image/image/icon_func.png);}"));
    QObject::connect(vel_ctrl, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(image_handle, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(robot_chat, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(select_func, SIGNAL(clicked(bool)), this, SLOT(close()));
}

