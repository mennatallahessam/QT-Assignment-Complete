#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ui->labelError->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    bool sucessful_login = false;
    for(int i = 0; i < usersCount; i++)
    {
        if (username == usernames[i] && password == passwords[i])
        {
            sucessful_login=true;
            WelcomeWindow* welcomeWindow = new WelcomeWindow(username, ages[i]);
            welcomeWindow->show();
            this->close();
        }
    }

    if(!sucessful_login)
        ui->labelError->setVisible(true);

}


void LoginWindow::on_pushButtonRegister_clicked()
{
    RegisterWindow* registerWindow = new RegisterWindow();
    registerWindow->show();
    this->close();
}

