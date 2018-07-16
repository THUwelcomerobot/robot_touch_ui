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
    topbar = new QToolBar(this);
    topbar->setGeometry(0, 0, this->width(), 60);
    topbar->setMovable(false);
    topbar->setStyleSheet(QString("QToolBar{border-image:url(:/image/image/title.png);}"));

    closed = new QAction(QIcon(":/image/image/tool_close.png"), QString("关闭窗口"), this);
    QObject::connect(closed, SIGNAL(triggered(bool)), this, SLOT(quit()));
    back = new QAction(QIcon(":/image/image/tool_back.png"), QString("返回"), this);
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
}

void BaseWindow::quit()
{
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  QString("退出程序"),
                                                  QString("你确定要退出程序吗?"),
                                                  QMessageBox::Yes | QMessageBox::No,
                                                  QMessageBox::No))
    {
        this->close();
    }
}
