#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:

    QPushButton *startAll;

    StartWindow(QWidget *parent = 0);
    ~StartWindow();

public slots:
    void login();

};

#endif // STARTWINDOW_H
