#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include "basewindow.h"
#include <QLabel>

class ChatWindow : public BaseWindow
{
    Q_OBJECT

public:
    QLabel *support;
    QLabel *support_text;
    ChatWindow(int Width = 1500, int Height = 1200, QWidget *parent = 0);
    ~ChatWindow();
    void initwindow();

public slots:
    void openwindow();
    void myclose();
};

#endif // CHATWINDOW_H
