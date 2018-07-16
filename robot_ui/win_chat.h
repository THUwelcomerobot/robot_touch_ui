#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include "basewindow.h"

class ChatWindow : public BaseWindow
{
    Q_OBJECT

public:
    ChatWindow(int Width = 800, int Height = 600, QWidget *parent = 0);
    ~ChatWindow();
    void initwindow();
};

#endif // CHATWINDOW_H
