#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "basewindow.h"

class MainWindow : public BaseWindow
{
    Q_OBJECT

public:

    QPushButton *vel_ctrl;
    QPushButton *image_handle;
    QPushButton *robot_chat;
    QPushButton *select_func;

    MainWindow(int Width = 800, int Height = 600, QWidget *parent = 0);
    ~MainWindow();
    void initwindow();

};


#endif // MAINWINDOW_H
