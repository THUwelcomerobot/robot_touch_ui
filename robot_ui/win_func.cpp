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

    func1 = new QPushButton(this);
    func1->setGeometry(this->width()/2-250, this->height()/2-100, 200, 200);
    func1->setText(QString("跟着我"));
    func1->setStyleSheet("QPushButton{font-size:20px;}");
    func2 = new QPushButton(this);
    func2->setGeometry(this->width()/2+50, this->height()/2-100, 200, 200);
    func2->setText(QString("位置记忆"));
    func2->setStyleSheet("QPushButton{font-size:20px;}");
    QObject::connect(func1, SIGNAL(clicked(bool)), this, SLOT(function1()));
    QObject::connect(func2, SIGNAL(clicked(bool)), this, SLOT(function2()));

}

void FuncWindow::function1()
{
    system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;roslaunch wpb_home_tutorials follow.launch;bash'&");
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("正在跟随中..."),
                                                  tr("请在机器人前方0.5m-1m处慢行\n点击'确定'按钮退出跟随."),
                                                  QMessageBox::Yes, QMessageBox::Yes))
    {
       system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 roslaunch;bash'");
      system("gnome-terminal -x bash -c 'killall bash'");
    }
}

void FuncWindow::function2()
{
   system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;roslaunch wpb_home_apps goto_point.launch;bash'&");
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("位置记忆进行中..."),
                                                  tr("请选择地点：办公室/教室，告诉机器人\n点击'确定'按钮退出功能."),
                                                  QMessageBox::Yes, QMessageBox::Yes))
    {
        system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;source ~/catkin_ws/devel/setup.bash;pkill -2 roslaunch;bash'");
       system("gnome-terminal -x bash -c 'killall bash'");
    }
}
