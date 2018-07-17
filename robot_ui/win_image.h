#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include "basewindow.h"
#include <QLabel>

class ImageWindow : public BaseWindow
{
    Q_OBJECT

public:
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;

    QLabel *filter;
    QLabel *makeup;
    QLabel *similarity;
    QLabel *image;
    QLabel *text;

    ImageWindow(int Width = 1600, int Height = 1200, QWidget *parent = 0);
    ~ImageWindow();
    void initwindow();
public slots:
    void face1();
    void face2();
    void face3();
    void face4();
    void face5();
    void face6();
};

#endif // IMAGEWINDOW_H
