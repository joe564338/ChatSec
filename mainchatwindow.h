#ifndef MAINCHATWINDOW_H
#define MAINCHATWINDOW_H
#include "openssl/ssl.h"
#include "openssl/err.h"
#include "openssl/bio.h"
#include <QMainWindow>
#include "login.h"
#include "user.h"
#include "logindialogue.h"
#include <thread>
#include "crypter.h"
#include <iostream>
#include "channel.h"

using namespace::std;
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
    bool mShowLoginWindow;
    bool mShowDialogueWindow;
    void showLoginWindow();
    void showDialogueWindow();
    void hideLoginWindow();
    void hideDialogueWindow();
    void showHide();
private slots:
    void on_mSendButton_clicked();

    //void on_pushButton_clicked();

    void on_mLoginButton_clicked();

private:
    Ui::MainChatWindow *ui;
    Login* login;
    Channel *channel;
    std::string mChannelName;
    User *user;
    Crypter crypt;
    loginDialogue *dialogue;
    //void OnNewMessage(std::string const& name,message::ptr const& data,bool hasAck,message::ptr &ack_resp);
};

#endif // MAINCHATWINDOW_H
