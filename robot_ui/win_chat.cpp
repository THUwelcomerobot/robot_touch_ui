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
