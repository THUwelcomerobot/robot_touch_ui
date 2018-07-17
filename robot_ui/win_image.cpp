#include "win_image.h"
#include <QFile>
#include <QDebug>
#include <QPainter>

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
    image->setGeometry(600, 200, 900, 500);
//    image->setText("image");
    text = new QLabel(this);
    text->setGeometry(600, 800, 900, 200);
//    text->setText("text");
    text->setStyleSheet("QLabel{font-size:40px;}");
    QObject::connect(back, SIGNAL(triggered(bool)), this, SLOT(myclose()));
    QObject::connect(button1, SIGNAL(clicked(bool)), this, SLOT(face1()));
    QObject::connect(button2, SIGNAL(clicked(bool)), this, SLOT(face2()));
    QObject::connect(button3, SIGNAL(clicked(bool)), this, SLOT(face3()));
    QObject::connect(button4, SIGNAL(clicked(bool)), this, SLOT(face4()));
    QObject::connect(button5, SIGNAL(clicked(bool)), this, SLOT(face5()));
    QObject::connect(button6, SIGNAL(clicked(bool)), this, SLOT(face6()));
}

void ImageWindow::openwindow()
{
    this->show();
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
    system("gnome-terminal -x bash -c 'cp /home/robot/share/img/0.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;"
           "cp /home/robot/share/img/1.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;"
           "cp /home/robot/share/img/2.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;"
           "cp /home/robot/share/img/3.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;"
           "cp /home/robot/share/img/makeup.png /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;"
           "cp /home/robot/share/img/likely_face.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;bash'&");
}

void ImageWindow::face1()
{
//    system("gnome-terminal -x bash -c 'cp /home/robot/share/img/0.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;bash'&");
    QPainter painter(image);
    QString filepath = "/home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/0.jpg";
    QPixmap face_image = QPixmap(filepath).scaled(image->size());
    image->setPixmap(face_image);
//    QPalette palette(image->palette());
//    palette.setBrush(QPalette::Background, QBrush(face_image));
//    image->setPalette(palette);
//    image->setStyleSheet(QString("background-repeat:no-repeat; background-position:center;"
//                                 "background-image:url(").append(filepath).append(");"));
    text->setText("");
    update();
}

void ImageWindow::face2()
{
//    system("gnome-terminal -x bash -c 'cp /home/robot/share/img/1.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;bash'&");
    QPainter painter(image);
    QString filepath = "/home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/1.jpg";
    QPixmap face_image = QPixmap(filepath).scaled(image->size());
    image->setPixmap(face_image);
    text->setText("");
    update();
}

void ImageWindow::face3()
{
//    system("gnome-terminal -x bash -c 'cp /home/robot/share/img/2.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;bash'&");
    QPainter painter(image);
    QString filepath = "/home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/2.jpg";
    QPixmap face_image = QPixmap(filepath).scaled(image->size());
    image->setPixmap(face_image);
    text->setText("");
    update();
}

void ImageWindow::face4()
{
//    system("gnome-terminal -x bash -c 'cp /home/robot/share/img/3.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;bash'&");
    QPainter painter(image);
    QString filepath = "/home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/3.jpg";
    QPixmap face_image = QPixmap(filepath).scaled(image->size());
    image->setPixmap(face_image);
    text->setText("");
    update();
}

void ImageWindow::face5()
{
//    system("gnome-terminal -x bash -c 'cp /home/robot/share/makeup.png /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;bash'&");
    QPainter painter(image);
    QString filepath = "/home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/makeup.png";
    QPixmap face_image = QPixmap(filepath).scaled(350, 400);
    image->setPixmap(face_image);
    image->setAlignment(Qt::AlignCenter);
    text->setText("");
    update();
}

void ImageWindow::face6()
{
//    system("gnome-terminal -x bash -c 'cp /home/robot/share/likely_face.jpg /home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/;bash'&");
    //读取良缘照片(资源文件中)
    QPainter painter(image);
    QString filepath = "/home/robot/touchpad_gui/robot_touch_ui/robot_ui/image/likely_face.jpg";
    QPixmap face_image = QPixmap(filepath).scaled(300, 400);
    image->setPixmap(face_image);
    image->setAlignment(Qt::AlignCenter);
    //读取良缘姓名
    QString filename = "/home/robot/share/result_2.txt";
    QFile readfile(filename);
    if (!readfile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Can't open file!"<<endl;
    }
    QTextStream txtInput(&readfile);
    text->setText(QString("与您脸缘最好的老师/同学是：").append(txtInput.readAll()));
    update();
}

void ImageWindow::myclose()
{
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 roslaunch;pkill -2 rostopic;bash'");
    system("gnome-terminal -x bash -c 'killall bash'");
    this->close();
}
