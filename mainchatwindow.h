#ifndef MAINCHATWINDOW_H
#define MAINCHATWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainChatWindow;
}

class MainChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainChatWindow(QWidget *parent = 0);
    ~MainChatWindow();
    bool mIsConnected;

private slots:
    void on_mSendButton_clicked();

private:
    Ui::MainChatWindow *ui;
};

#endif // MAINCHATWINDOW_H
