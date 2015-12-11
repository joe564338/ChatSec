#include "login.h"
#include "ui_login.h"
#include "mainchatwindow.h"

Login::Login(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}
//inits login vars
void Login::on_mLoginButton_clicked()
{
    mUserName = ui->mUserNameText->text().toUtf8();
    mChannel = ui->mPasswordText->text().toUtf8();
    this->hide();
}
