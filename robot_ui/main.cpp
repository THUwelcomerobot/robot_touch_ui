#include "win_start.h"
#include "mainwindow.h"
#include "win_ctrl.h"
#include "win_image.h"
#include "win_chat.h"
#include "win_func.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindow *w_start = new StartWindow;
    MainWindow *w_main = new MainWindow(1000, 600);
    CtrlWindow *w_ctrl = new CtrlWindow;
    ImageWindow *w_image = new ImageWindow;
    ChatWindow *w_chat = new ChatWindow;
    FuncWindow *w_func = new FuncWindow;

    QObject::connect(w_start->startAll, SIGNAL(clicked(bool)), w_main, SLOT(show()));

    QObject::connect(w_main->back, SIGNAL(triggered(bool)), w_start, SLOT(show()));
    QObject::connect(w_main->vel_ctrl, SIGNAL(clicked(bool)), w_ctrl, SLOT(show()));
    QObject::connect(w_main->image_handle, SIGNAL(clicked(bool)), w_image, SLOT(show()));
    QObject::connect(w_main->robot_chat, SIGNAL(clicked(bool)), w_chat, SLOT(show()));
    QObject::connect(w_main->select_func, SIGNAL(clicked(bool)), w_func, SLOT(show()));

    QObject::connect(w_ctrl->exit, SIGNAL(clicked(bool)), w_main, SLOT(show()));
    QObject::connect(w_ctrl->back, SIGNAL(triggered(bool)), w_main, SLOT(show()));
    QObject::connect(w_image->back, SIGNAL(triggered(bool)), w_main, SLOT(show()));
    QObject::connect(w_chat->back, SIGNAL(triggered(bool)), w_main, SLOT(show()));
    QObject::connect(w_func->back, SIGNAL(triggered(bool)), w_main, SLOT(show()));

    w_start->show();

    return a.exec();
}
