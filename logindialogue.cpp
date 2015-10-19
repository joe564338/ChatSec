#include "logindialogue.h"
#include "ui_logindialogue.h"
#include "mainchatwindow.h"
loginDialogue::loginDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialogue)
{
    ui->setupUi(this);
}

loginDialogue::~loginDialogue()
{
    delete ui;
}

void loginDialogue::on_mYesButton_clicked()
{

}


void loginDialogue::on_mNoButton_clicked()
{

}
