#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QPushButton>
#include <QToolBar>
#include <QAction>
#include <QDialog>

class BaseWindow : public QDialog
{
    Q_OBJECT

public:    
    QToolBar *topbar;
    QAction *closed;
    QAction *back;
    QWidget *spacer;

    BaseWindow(int Width = 800, int Height = 600, QWidget *parent = 0);
    ~BaseWindow();
    virtual void initwindow();
    void initToolBar();
};

#endif // BASEWINDOW_H
