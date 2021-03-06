#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "basewindow.h"
#include <QLabel>

class MainWindow : public BaseWindow
{
    Q_OBJECT

public:
    QPushButton *vel_ctrl;
    QPushButton *image_handle;
    QPushButton *robot_chat;
    QPushButton *select_func;

    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *person_icon;
    QLabel *person_name;
    QLabel *info_icon;
    QLabel *info_text;

    MainWindow(int Width = 1600, int Height = 1200, QWidget *parent = 0);

    ~MainWindow();
    void initwindow();

public slots:
    void openwindow();
    void login();
    void logout();

};


#endif // MAINWINDOW_H
