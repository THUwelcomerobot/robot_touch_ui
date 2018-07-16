#include "mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QTextCodec>

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

    person_icon = new QLabel(this);
    person_icon->setGeometry(250, 100, 60, 60);
    person_icon->setStyleSheet(QString("QLabel{border-image:url(:/image/image/icon_person.png)}"));
    person_name = new QLabel(this);
    person_name->setGeometry(320, 100, 400, 60);
    person_name->setText(QString("欢迎您，"));
    person_name->setStyleSheet("QLabel{font-size:28px;}");

    vel_ctrl = new QPushButton(this);
    vel_ctrl->setGeometry(40, 200, 200, 200);
    vel_ctrl->setStyleSheet(QString(button_style).append("QPushButton{background-image:"
                                                         "url(:/image/image/icon_ctrl.png);}"));
    image_handle = new QPushButton(this);
    image_handle->setGeometry(280, 200, 200, 200);
    image_handle->setStyleSheet(QString(button_style).append("QPushButton{background-image:"
                                                          "url(:/image/image/icon_image.png);}"));
    robot_chat = new QPushButton(this);
    robot_chat->setGeometry(520, 200, 200, 200);
    robot_chat->setStyleSheet(QString(button_style).append("QPushButton{background-image:"
                                                           "url(:/image/image/icon_chat.png);}"));
    select_func = new QPushButton(this);
    select_func->setGeometry(760, 200, 200, 200);
    select_func->setStyleSheet(QString(button_style).append("QPushButton{background-image:"
                                                           "url(:/image/image/icon_func.png);}"));
    QObject::connect(vel_ctrl, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(image_handle, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(robot_chat, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(select_func, SIGNAL(clicked(bool)), this, SLOT(close()));

    label1 = new QLabel(this);
    label1->setGeometry(40, 420, 200, 50);
    label1->setStyleSheet(QString("QLabel{background-image:url(:/image/image/text_ctrl.png)}"));
    label2 = new QLabel(this);
    label2->setGeometry(280, 420, 200, 50);
    label2->setStyleSheet(QString("QLabel{background-image:url(:/image/image/text_image.png)}"));
    label3 = new QLabel(this);
    label3->setGeometry(520, 420, 200, 50);
    label3->setStyleSheet(QString("QLabel{background-image:url(:/image/image/text_chat.png)}"));
    label4 = new QLabel(this);
    label4->setGeometry(760, 420, 200, 50);
    label4->setStyleSheet(QString("QLabel{background-image:url(:/image/image/text_func.png)}"));
}

void MainWindow::openwindow()
{
    this->show();

    QParallelAnimationGroup *moveall = new QParallelAnimationGroup;
    QPropertyAnimation *move1 = new QPropertyAnimation(vel_ctrl, "pos");
    move1->setStartValue(QPoint(this->width()/2, this->height()/2));
    move1->setKeyValueAt(0.5, QPoint(vel_ctrl->x(), this->height()/2));
    move1->setEndValue(QPoint(vel_ctrl->pos()));
    move1->setEasingCurve(QEasingCurve::Linear);
    move1->setDuration(1000);
    QPropertyAnimation *move2 = new QPropertyAnimation(image_handle, "pos");
    move2->setStartValue(QPoint(this->width()/2, this->height()/2));
    move2->setKeyValueAt(0.5, QPoint(image_handle->x(), this->height()/2));
    move2->setEndValue(QPoint(image_handle->pos()));
    move2->setEasingCurve(QEasingCurve::Linear);
    move2->setDuration(1000);
    QPropertyAnimation *move3 = new QPropertyAnimation(robot_chat, "pos");
    move3->setStartValue(QPoint(this->width()/2, this->height()/2));
    move3->setKeyValueAt(0.5, QPoint(robot_chat->x(), this->height()/2));
    move3->setEndValue(QPoint(robot_chat->pos()));
    move3->setEasingCurve(QEasingCurve::Linear);
    move3->setDuration(1000);
    QPropertyAnimation *move4 = new QPropertyAnimation(select_func, "pos");
    move4->setStartValue(QPoint(this->width()/2, this->height()/2));
    move4->setKeyValueAt(0.5, QPoint(select_func->x(), this->height()/2));
    move4->setEndValue(QPoint(select_func->pos()));
    move4->setEasingCurve(QEasingCurve::Linear);
    move4->setDuration(1000);
    moveall->addAnimation(move1);
    moveall->addAnimation(move2);
    moveall->addAnimation(move3);
    moveall->addAnimation(move4);
    QPropertyAnimation *text1 = new QPropertyAnimation(label1, "size");
    text1->setStartValue(QSize(0, label1->height()));
    text1->setKeyValueAt(0.66, QSize(0, label1->height()));
    text1->setEndValue(QSize(label1->size()));
    text1->setDuration(1500);
    QPropertyAnimation *text2 = new QPropertyAnimation(label2, "size");
    text2->setStartValue(QSize(0, label2->height()));
    text2->setKeyValueAt(0.66, QSize(0, label2->height()));
    text2->setEndValue(QSize(label2->size()));
    text2->setDuration(1500);
    QPropertyAnimation *text3 = new QPropertyAnimation(label3, "size");
    text3->setStartValue(QSize(0, label3->height()));
    text3->setKeyValueAt(0.66, QSize(0, label3->height()));
    text3->setEndValue(QSize(label3->size()));
    text3->setDuration(1500);
    QPropertyAnimation *text4 = new QPropertyAnimation(label4, "size");
    text4->setStartValue(QSize(0, label4->height()));
    text4->setKeyValueAt(0.66, QSize(0, label4->height()));
    text4->setEndValue(QSize(label4->size()));
    text4->setDuration(1500);
    moveall->addAnimation(text1);
    moveall->addAnimation(text2);
    moveall->addAnimation(text3);
    moveall->addAnimation(text4);
    moveall->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::login()
{
    QString filename = "C:/Practise/Python Program/robot_ui/robot_ui/txt/test.txt";
    QFile readfile(filename);
    if (!readfile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Can't open file!"<<endl;
    }
    QTextStream txtInput(&readfile);
    person_name->setText(QString("欢迎您，").append(txtInput.readAll()));
    this->update();
}

void MainWindow::logout()
{

}

