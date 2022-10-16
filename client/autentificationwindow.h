#ifndef AUTENTIFICATIONWINDOW_H
#define AUTENTIFICATIONWINDOW_H

#include <QMainWindow>
#include <registrationwindow.h>
#include <QSqlDatabase>
#include <admin.h>
#include <mainwindow.h>

namespace Ui {
class AutentificationWindow;
}

class AutentificationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AutentificationWindow(QWidget *parent = nullptr);
    ~AutentificationWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_checkBox_clicked();

private:
    Ui::AutentificationWindow *ui;
    RegistrationWindow *registration;
    QSqlDatabase db;
    Admin* admin;
    MainWindow* main;
};

#endif // AUTENTIFICATIONWINDOW_H
