#ifndef CTRLWINDOW_H
#define CTRLWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QDialog>
#include <QProcess>
#include <QSlider>
#include <QLabel>
#include <QSpinBox>

class CtrlWindow : public QDialog
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

    CtrlWindow(QWidget *parent = 0);
    ~CtrlWindow();


public slots:
    void close_window();

    void run_down();
    void run_left();
    void run_right();
    void run_up();
    void stop_run();

};

#endif // CTRLWINDOW_H
