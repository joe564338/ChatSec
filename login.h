#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
/** Class for the login window. Only one instance is created at the start of the application
 * The window is shown and hidden when needed by show() and hide()
*/
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0); //constructor
    ~Login();//destructor

private slots:
    void on_mLoginButton_clicked();//login button listener

private:
    Ui::Login *ui;//ui

};

#endif // LOGIN_H
