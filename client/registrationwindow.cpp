#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include <autentificationwindow.h>
#include <QSqlQuery>
#include <QMessageBox>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("Логин");
    ui->lineEdit_2->setPlaceholderText("Пароль");
    ui->lineEdit_3->setPlaceholderText("Повторите пароль");
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_pushButton_clicked()
{
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString repeat_password = ui->lineEdit_3->text();
    QSqlQuery query;
    Creat_Acc creat(login);
    if (login != nullptr) {
        if (creat.Creat() == false) {
            if (password.length() >= 5 && password.length() <= 13) {
                 if (password == repeat_password) {
                    query = QSqlQuery("INSERT INTO user_info (login, password) VALUES('" + login + "', '" + password + "')");

                    QMessageBox::about(this, tr("Справка"), tr("Аккаунт успешно создан!"));
                    auto w = new AutentificationWindow();
                    w->setAttribute(Qt::WA_DeleteOnClose);
                    w->show();
                    deleteLater();
                 }
                 else {
                     QMessageBox::warning(this, tr("Ошибка"), tr("Пароли не совпадают!"));
                 }
            }
            else {
                QMessageBox::warning(this, tr("Ошибка"), tr("Длинна пароля должна быть неменьше 5 и небольше 13!"));
            }
        }
        else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Аккаунт с таким имнем уже существует!"));
        }
    }
    else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Поле логин должно быть заполненно!"));
    }
}


void RegistrationWindow::on_action_triggered()
{
    auto w = new AutentificationWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    deleteLater();
}


