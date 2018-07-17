#include "win_image.h"

ImageWindow::ImageWindow(int Width, int Height, QWidget *parent)
    : BaseWindow(Width, Height, parent)
{
    initwindow();
}

ImageWindow::~ImageWindow()
{

}

void ImageWindow::initwindow()
{
    QPixmap back_image = QPixmap(":/image/image/background.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(back_image));
    this->setPalette(palette);

    button1 = new QPushButton(this);
    button1->setGeometry(50, 50, 100, 100);
    button2 = new QPushButton(this);
    button2->setGeometry(50, 200, 100, 100);
    button3 = new QPushButton(this);
    button3->setGeometry(50, 350, 100, 100);
    button4 = new QPushButton(this);
    button4->setGeometry(200, 50, 100, 100);
    button5 = new QPushButton(this);
    button5->setGeometry(200, 200, 100, 100);
    button6 = new QPushButton(this);
    button6->setGeometry(200, 350, 100, 100);

    image = new QLabel(this);
    image->setGeometry(350, 100, 200, 200);
    image->setText("image");
    text = new QLabel(this);
    text->setGeometry(350, 400, 200, 200);
    text->setText("text");

    QObject::connect(button1, SIGNAL(clicked(bool)), this, SLOT(face1()));
    QObject::connect(button2, SIGNAL(clicked(bool)), this, SLOT(face2()));
    QObject::connect(button3, SIGNAL(clicked(bool)), this, SLOT(face3()));
    QObject::connect(button4, SIGNAL(clicked(bool)), this, SLOT(face4()));
    QObject::connect(button5, SIGNAL(clicked(bool)), this, SLOT(face5()));
    QObject::connect(button6, SIGNAL(clicked(bool)), this, SLOT(face6()));
}

void ImageWindow::face1()
{

}

void ImageWindow::face2()
{

}

void ImageWindow::face3()
{

}

void ImageWindow::face4()
{

}

void ImageWindow::face5()
{

}

void ImageWindow::face6()
{

}
