#include "autentificationwindow.h"
#include "ui_autentificationwindow.h"
#include <QMessageBox>

AutentificationWindow::AutentificationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AutentificationWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("Логин");
    ui->lineEdit_2->setPlaceholderText("Пароль");
}

AutentificationWindow::~AutentificationWindow()
{
    delete ui;
}

void AutentificationWindow::on_pushButton_2_clicked()
{
    registration = new RegistrationWindow(this);
    registration->show();
    this->hide();
}

void AutentificationWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()) {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }
    else {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
}


void AutentificationWindow::on_pushButton_clicked()
{
     QString user_login = ui->lineEdit->text();
     QString user_password = ui->lineEdit_2->text();
     QString login, password;

     QSqlQuery query ("SELECT login, password FROM user_info");
     while (query.next())
     {
         login = query.value(0).toString();
         password = query.value(1).toString();

         if (user_login == login && user_password == password) {
             main = new MainWindow(this);
             main->setWindowTitle(login);
             main->show();
             this->hide();
             break;
         }
     }

     if (user_login == "Admin" && user_password == "123") {
        admin = new Admin(this);
        admin->show();
        this->hide();
     }
     else if (user_login != login || user_password != password) {
         QMessageBox::warning(this, tr("Ошибка"), tr("Неверное имя или пароль!"));
     }
}



