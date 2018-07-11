#ifndef CTRLWINDOW_H
#define CTRLWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QStringLiteral>
#include <QDialog>
#include <QProcess>
#include <QSlider>

class CtrlWindow : public QDialog
{
    Q_OBJECT

public:

    QPushButton *ctrl_down;
    QPushButton *ctrl_left;
    QPushButton *ctrl_right;
    QPushButton *ctrl_up;
    QPushButton *exit;

    QSlider *ctrl_speed;

    CtrlWindow(QWidget *parent = 0);
    ~CtrlWindow();


public slots:
    void run_down();
    void run_left();
    void run_right();
    void run_up();

};

#endif // CTRLWINDOW_H
