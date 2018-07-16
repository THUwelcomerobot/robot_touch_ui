#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:

    QPushButton *startAll;
    QLabel *loading;

    StartWindow(QWidget *parent = 0);
    ~StartWindow();
signals:
    void login_success();
public slots:
    void openwindow();
    void login();
    void emit_success();
    void logout();

};

#endif // STARTWINDOW_H
