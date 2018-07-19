#include "win_chat.h"

ChatWindow::ChatWindow(int Width, int Height, QWidget *parent)
    : BaseWindow(Width, Height, parent)
{
    initwindow();
}

ChatWindow::~ChatWindow()
{

}

void ChatWindow::initwindow()
{
    QPixmap back_image = QPixmap(":/image/image/background.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(back_image));
    this->setPalette(palette);
    QObject::connect(back, SIGNAL(triggered(bool)), this, SLOT(myclose()));

    chat_text = new QLabel(this);
    chat_text->setGeometry(this->width()/2-220, 300, 440, 100);
    chat_text->setStyleSheet(""
                             "background-image:url(:/image/image/chat__text.png);");
    anime = new QPropertyAnimation(chat_text, "size");
    anime->setLoopCount(-1);
    anime->setDuration(2000);
    anime->setStartValue(QSize(chat_text->width()-160, chat_text->height()));
    anime->setEndValue(QSize(chat_text->size()));
    anime->start();
    support = new QLabel(this);
    support->setGeometry(this->width()/2-340, this->height()/2-100, 680, 200);
    support->setStyleSheet("background-repeat:no-repeat; background-position:center;"
                           "background-image:url(:/image/image/chat_support.png);");
    support_text = new QLabel(this);
    support_text->setGeometry(this->width()/2-380, this->height()/2+350, 760, 100);
    support_text->setStyleSheet("background-repeat:no-repeat; background-position:center;"
                                "background-image:url(:/image/image/chat_support_text.png);");
}

void ChatWindow::openwindow()
{
    this->show();
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
    system(" gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;roslaunch xbchat xbchatter.launch;bash'& ");//启动语言对话
}

void ChatWindow::myclose()
{
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 roslaunch;pkill -2 rostopic;bash'");
    system("gnome-terminal -x bash -c 'killall bash'");
    this->close();
}
