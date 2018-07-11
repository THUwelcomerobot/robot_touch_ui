#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ctrlwindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QPushButton *vel_ctrl;
    QPushButton *voice_func;
    QPushButton *face_func;

    CtrlWindow *ctrl_window;

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void open_ctrl_window();

};

#endif // MAINWINDOW_H
