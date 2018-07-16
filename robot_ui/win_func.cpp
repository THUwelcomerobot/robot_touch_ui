#include "win_func.h"

FuncWindow::FuncWindow(int Width, int Height, QWidget *parent)
    : BaseWindow(Width, Height, parent)
{
    initwindow();
}

FuncWindow::~FuncWindow()
{

}

void FuncWindow::initwindow()
{
    QPixmap back_image = QPixmap(":/image/image/background.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(back_image));
    this->setPalette(palette);
}

