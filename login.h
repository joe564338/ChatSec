#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <QWidget>
/** Class for the login window. Only one instance is created at the start of the application
 * The window is shown at start of application. show() and hide() manipulate the window.
*/
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0); //constructor
    std::string mUserName;
    std::string mChannel;
    ~Login();//destructor

private slots:
    void on_mLoginButton_clicked();//login button listener

private:
    Ui::Login *ui;//ui

};

#endif // LOGIN_H
