#include "channelselect.h"
#include "ui_channelselect.h"

ChannelSelect::ChannelSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelSelect)
{
    ui->setupUi(this);
}

ChannelSelect::~ChannelSelect()
{
    delete ui;
}

void ChannelSelect::on_mConnectButton_clicked()
{
    //connect to channel
}
