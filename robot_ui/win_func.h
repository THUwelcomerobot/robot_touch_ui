#ifndef FUNCWINDOW_H
#define FUNCWINDOW_H

#include "basewindow.h"

class FuncWindow : public BaseWindow
{
    Q_OBJECT

public:

    FuncWindow(int Width = 800, int Height = 600, QWidget *parent = 0);
    ~FuncWindow();
    void initwindow();

};

#endif // FUNCWINDOW_H
