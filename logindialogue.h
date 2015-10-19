#ifndef LOGINDIALOGUE_H
#define LOGINDIALOGUE_H

#include <QDialog>

namespace Ui {
class loginDialogue;
}

class loginDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialogue(QWidget *parent = 0);
    ~loginDialogue();

private slots:
    void on_mYesButton_clicked();

    void on_mNoButton_clicked();

private:
    Ui::loginDialogue *ui;
};

#endif // LOGINDIALOGUE_H
