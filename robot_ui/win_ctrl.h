#ifndef CTRLWINDOW_H
#define CTRLWINDOW_H

#include "basewindow.h"
#include <QSlider>
#include <QLabel>
#include <QSpinBox>


class CtrlDialog : public BaseWindow
{
    Q_OBJECT

public:
    QPushButton *js_ctrl;
    QPushButton *scr_ctrl;

    CtrlDialog(int Width = 400, int Height = 400, QWidget *parent = 0);
    ~CtrlDialog();
    void initwindow();
public slots:
    void openwindow();
    void js_control();
    void scr_control();
};

class CtrlWindow : public BaseWindow
{
    Q_OBJECT

public:
    QPushButton *ctrl_down;
    QPushButton *ctrl_left;
    QPushButton *ctrl_right;
    QPushButton *ctrl_up;
    QPushButton *ctrl_CW;
    QPushButton *ctrl_anti_CW;
    QPushButton *ctrl_stop;
    QPushButton *exit;

    QSlider *ctrl_speed;
    QSpinBox *watch_speed;
    QLabel *tip_speed;

    CtrlWindow(int Width = 800, int Height = 600, QWidget *parent = 0);
    ~CtrlWindow();
    void initwindow();

public slots:
    void openwindow();
    void run_down();
    void run_left();
    void run_right();
    void run_up();
    void run_CW();
    void run_anti_CW();
    void stop_run();
    void myclose();
};


#endif // CTRLWINDOW_H
