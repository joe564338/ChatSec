#ifndef CHANNELSELECT_H
#define CHANNELSELECT_H

#include <QWidget>
//UI for typing in Channel name
namespace Ui {
class ChannelSelect;
}

class ChannelSelect : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelSelect(QWidget *parent = 0);
    ~ChannelSelect();

private slots:
    void on_mConnectButton_clicked();

private:
    Ui::ChannelSelect *ui;
};

#endif // CHANNELSELECT_H
