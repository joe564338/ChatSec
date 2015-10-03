#include "login.h"
#include "ui_login.h"

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
