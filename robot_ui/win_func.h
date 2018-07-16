#ifndef FUNCWINDOW_H
#define FUNCWINDOW_H

#include "basewindow.h"

class FuncWindow : public BaseWindow
{
    Q_OBJECT

public:

    QPushButton *func1;
    QPushButton *func2;
    QPushButton *func3;

    FuncWindow(int Width = 800, int Height = 600, QWidget *parent = 0);
    ~FuncWindow();
    void initwindow();

};

#endif // FUNCWINDOW_H