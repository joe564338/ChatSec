#include "mainchatwindow.h"
#include "ui_mainchatwindow.h"
#include "login.h"
MainChatWindow::MainChatWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainChatWindow)
{
    /*Login *w = new Login(this);
    w->show();
    w->raise();
    w->activateWindow();*/
    ui->setupUi(this);
    mIsConnected = false;
}

MainChatWindow::~MainChatWindow()
{
    delete ui;
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
