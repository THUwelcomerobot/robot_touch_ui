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
    ChatWindow(int Width = 800, int Height = 600, QWidget *parent = 0);
    ~ChatWindow();
    void initwindow();
public slots:
    void openwindow();
};

#endif // CHATWINDOW_H
