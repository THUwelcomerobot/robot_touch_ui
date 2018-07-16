#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include "basewindow.h"

class ImageWindow : public BaseWindow
{
    Q_OBJECT

public:

    ImageWindow(int Width = 800, int Height = 600, QWidget *parent = 0);
    ~ImageWindow();
    void initwindow();
};

#endif // IMAGEWINDOW_H
