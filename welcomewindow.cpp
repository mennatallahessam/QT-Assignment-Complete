#include "welcomewindow.h"
#include "ui_welcomewindow.h"

#include <QPixmap>
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QPixmap pix ("F:\\AUC\\Trials\\QT\\CinemaProject\\welcome2.jpg");
    int w = ui->labelWelcomePic->width();
    int h = ui->labelWelcomePic->height();
    ui->labelWelcomePic->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    ui->labelUsername->setText("Hello " + username + " "+ QString::number(age) + ", ");
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButton_clicked()
{
    hide();
    LoginWindow* loginWindow = new LoginWindow(this);
    loginWindow->show();
}

