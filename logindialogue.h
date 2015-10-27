#ifndef LOGINDIALOGUE_H
#define LOGINDIALOGUE_H

#include <QDialog>

namespace Ui {
/** Window for confirming decision to re-login if the user is already connected*/
class loginDialogue;
}

class loginDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialogue(QWidget *parent = 0);//constructor
    ~loginDialogue();//destructor

private slots:
    void on_mYesButton_clicked();//yes button listener

    void on_mNoButton_clicked();//no button listener

private:
    Ui::loginDialogue *ui;//ui for the dialogue window
};

#endif // LOGINDIALOGUE_H
