#include "mainchatwindow.h"
#include "ui_mainchatwindow.h"
#include "login.h"
#include <thread>
#include "logindialogue.h"
#include "cstring"
#include "openssl/applink.c"

MainChatWindow::MainChatWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainChatWindow)
{
    crypt = Crypter();
    char* privKeyLocation = "C:/Users/Joe/Documents/build-ChatSec-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/debug/private_key.pem";
    char* pubKeyLocation = "C:/Users/Joe/Documents/build-ChatSec-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/debug/public_key.pem";
    crypt.CreateRSA(privKeyLocation, 0);
    crypt.CreateRSA(pubKeyLocation, 1);
    ui->setupUi(this);
    mShowDialogueWindow = false;
    mShowLoginWindow = true;
    login = new Login();
    dialogue = new loginDialogue();
    login->show();
    login->raise();
    login->activateWindow();
    mIsConnected = false;
    user = new User("guest");
    mChannelName = "Channel";
    channel =  new Channel(mChannelName);


    channel->UploadKeys(user->getName(), crypt.getKey(privKeyLocation), crypt.getKey(pubKeyLocation));
}

MainChatWindow::~MainChatWindow()
{
    delete ui;
}

void MainChatWindow::showDialogueWindow(){
    mShowDialogueWindow = true;
}

void MainChatWindow::hideDialogueWindow(){
    mShowDialogueWindow = false;
}

void MainChatWindow::showLoginWindow(){
    mShowLoginWindow = true;
}

void MainChatWindow::hideLoginWindow(){
    mShowLoginWindow = false;
}

void MainChatWindow::on_mSendButton_clicked()
{
    if(!mIsConnected){
        QString message = ui->mChatBox->toPlainText();

        unsigned char data[4096] = {};
        memcpy(data, message.toStdString().c_str(), message.toStdString().size() + 1);
        unsigned char encrypted[4096] = {};
        std::cout << "Work" << endl;
        int enc = crypt.public_encrypt(data, strlen((char *) data), encrypted);
        message = QString::fromStdString(std::string((char*)encrypted));
        ui->mChatHistory->append(message);
        ui->mChatHistory->setFontItalic(true);
        ui->mChatHistory->append("You are offline");
        ui->mChatHistory->setFontItalic(false);
    }
}

/*void MainChatWindow::on_pushButton_clicked()
{

}*/


void MainChatWindow::on_mLoginButton_clicked()
{
    if(mIsConnected == true){
        mShowDialogueWindow = true;
    }

}
//method for showing and hiding widgets to be run in a thread
void MainChatWindow::showHide(){
    while(true){
        if(mShowLoginWindow){
            login->show();
        }
        else{
            login->hide();
        }
        if(mShowDialogueWindow){
            dialogue->show();
        }
        else{
            dialogue->hide();
        }
    }
}
