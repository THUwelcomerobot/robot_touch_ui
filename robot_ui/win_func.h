#ifndef FUNCWINDOW_H
#define FUNCWINDOW_H

#include "basewindow.h"

class FuncWindow : public BaseWindow
{
    Q_OBJECT

public:

    QPushButton *func1;
    QPushButton *func2;

    FuncWindow(int Width = 800, int Height = 600, QWidget *parent = 0);
    ~FuncWindow();
    void initwindow();

public slots:
    void function1();
    void function2();

};

#endif // FUNCWINDOW_H
