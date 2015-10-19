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

void Login::on_mLoginButton_clicked()
{
    this->hide();
}
