#include "win_image.h"
#include <QFile>
#include <QDebug>

QString facebutton_style = "QPushButton{border-radius:100px; background-repeat:no-repeat; background-position:center;}"
                           "QPushButton:hover{background-color:rgb(225,245,255);}"
                           "QPushButton:pressed{background-color:rgb(180,240,255);}";

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
    button1->setGeometry(100, 200, 200, 200);
    button1->setStyleSheet(QString(facebutton_style).append("QPushButton{background-image:url(:/image/image/icon_face1.png);}"));
    button2 = new QPushButton(this);
    button2->setGeometry(320, 200, 200, 200);
    button2->setStyleSheet(QString(facebutton_style).append("QPushButton{background-image:url(:/image/image/icon_face2.png);}"));
    button3 = new QPushButton(this);
    button3->setGeometry(100, 420, 200, 200);
    button3->setStyleSheet(QString(facebutton_style).append("QPushButton{background-image:url(:/image/image/icon_face3.png);}"));
    button4 = new QPushButton(this);
    button4->setGeometry(320, 420, 200, 200);
    button4->setStyleSheet(QString(facebutton_style).append("QPushButton{background-image:url(:/image/image/icon_face4.png);}"));
    button5 = new QPushButton(this);
    button5->setGeometry(100, 690, 200, 200);
    button5->setStyleSheet(QString(facebutton_style).append("QPushButton{background-image:url(:/image/image/icon_face5.png);}"));
    button6 = new QPushButton(this);
    button6->setGeometry(100, 950, 200, 200);
    button6->setStyleSheet(QString(facebutton_style).append("QPushButton{background-image:url(:/image/image/icon_face6.png);}"));

    filter = new QLabel(this);
    filter->setGeometry(100, 150, 200, 50);
    filter->setStyleSheet(QString("background-image:url(:/image/image/text_image_func1);"));
    makeup = new QLabel(this);
    makeup->setGeometry(100, 630, 200, 50);
    makeup->setStyleSheet(QString("background-image:url(:/image/image/text_image_func2);"));
    similarity = new QLabel(this);
    similarity->setGeometry(100, 900, 200, 50);
    similarity->setStyleSheet(QString("background-image:url(:/image/image/text_image_func3);"));

    image = new QLabel(this);
    image->setGeometry(600, 200, 900, 700);
    image->setText("image");
    text = new QLabel(this);
    text->setGeometry(600, 800, 900, 200);
    text->setText("text");
    text->setStyleSheet("QLabel{font-size:40px;}");

    QObject::connect(button1, SIGNAL(clicked(bool)), this, SLOT(face1()));
    QObject::connect(button2, SIGNAL(clicked(bool)), this, SLOT(face2()));
    QObject::connect(button3, SIGNAL(clicked(bool)), this, SLOT(face3()));
    QObject::connect(button4, SIGNAL(clicked(bool)), this, SLOT(face4()));
    QObject::connect(button5, SIGNAL(clicked(bool)), this, SLOT(face5()));
    QObject::connect(button6, SIGNAL(clicked(bool)), this, SLOT(face6()));
}

void ImageWindow::face1()
{
    QString filepath = ":/image/image/icon_face1.png";
    image->setStyleSheet(QString("background-repeat:no-repeat; background-position:center;"
                                 "background-image:url(").append(filepath).append(");"));
    update();
}

void ImageWindow::face2()
{
    QString filepath = ":/image/image/icon_face2.png";
    image->setStyleSheet(QString("background-repeat:no-repeat; background-position:center;"
                                 "background-image:url(").append(filepath).append(");"));
    update();
}

void ImageWindow::face3()
{
    QString filepath = ":/image/image/icon_face3.png";
    image->setStyleSheet(QString("background-repeat:no-repeat; background-position:center;"
                                 "background-image:url(").append(filepath).append(");"));
    update();
}

void ImageWindow::face4()
{
    QString filepath = ":/image/image/icon_face4.png";
    image->setStyleSheet(QString("background-repeat:no-repeat; background-position:center;"
                                 "background-image:url(").append(filepath).append(");"));
    update();
}

void ImageWindow::face5()
{
    QString filepath = ":/image/image/icon_face5.png";
    image->setStyleSheet(QString("background-repeat:no-repeat; background-position:center;"
                                 "background-image:url(").append(filepath).append(");"));
    update();
}

void ImageWindow::face6()
{
    //读取良缘照片(资源文件中)
    QString filepath = ":/image/image/icon_face6.png";
    image->setStyleSheet(QString("background-repeat:no-repeat; background-position:center;"
                                 "background-image:url(").append(filepath).append(");"));
    //读取良缘姓名
    QString filename = "/home/robot/share/result.txt";
    QFile readfile(filename);
    if (!readfile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Can't open file!"<<endl;
    }
    QTextStream txtInput(&readfile);
    text->setText(QString("与您脸缘最好的老师/同学是：").append(txtInput.readAll()));
    update();
}
