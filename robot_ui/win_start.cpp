#include "win_start.h"

QString start_button_style = "QPushButton{border-image:url(:/image/image/start.png)}"
                             "QPushButton:pressed{border-image:url(:/image/image/start_pressed.png)}";

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800, 600);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    startAll = new QPushButton(this);
    startAll->setGeometry(300, 200, 200, 200);
    startAll->setStyleSheet(start_button_style);

    QObject::connect(startAll, SIGNAL(clicked(bool)), this, SLOT(login()));
}

StartWindow::~StartWindow()
{

}

//关闭起始界面时的操作
void StartWindow::login()
{
    this->close();
}
