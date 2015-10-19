#include "mainchatwindow.h"
#include "ui_mainchatwindow.h"
#include "login.h"
#include <thread>
#include "logindialogue.h"
MainChatWindow::MainChatWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainChatWindow)
{
    ui->setupUi(this);
    mShowDialogueWindow = false;
    mShowLoginWindow = true;
    login = new Login();
    dialogue = new loginDialogue();
    login->show();
    login->raise();
    login->activateWindow();
    mIsConnected = false;
    user = new User("guest", "temp");

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
        ui->mChatHistory->append(message);
        ui->mChatHistory->setFontItalic(true);
        ui->mChatHistory->append("You are offline");
        ui->mChatHistory->setFontItalic(false);
    }
}

void MainChatWindow::on_pushButton_clicked()
{

}


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
