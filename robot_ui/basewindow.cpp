#include "basewindow.h"

BaseWindow::BaseWindow(int Width, int Height, QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(Width, Height);
    this->setWindowFlags(Qt::FramelessWindowHint);
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
    closed = new QAction(QIcon(":/image/image/tool_close.png"), QString("关闭窗口"), this);
    QObject::connect(closed, SIGNAL(triggered(bool)), this, SLOT(close()));
    back = new QAction(QIcon(":/image/image/tool_back.png"), QString("返回"), this);
    QObject::connect(back, SIGNAL(triggered(bool)), this, SLOT(close()));
    spacer = new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    topbar = new QToolBar(this);
    topbar->setGeometry(0, 0, this->width(), 50);
    topbar->setMovable(false);
    topbar->setStyleSheet(QString("QToolBar{border-image:url(:/image/image/title.png);}"));
    topbar->addAction(back);
    topbar->addWidget(spacer);
    topbar->addAction(closed);
}
