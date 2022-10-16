#include "admin.h"
#include "ui_admin.h"
#include <autentificationwindow.h>

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");

    if (db.open()) {
         qDebug("open");
    }
    else {
        qDebug("no open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE user_info(login TEXT NOT NULL, password TEXT NOT NULL);");

    model = new QSqlTableModel(this, db);
    model->setTable("user_info");
    model->select();

    ui->tableView->setModel(model);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
     model->insertRow(model->rowCount());
}

void Admin::on_pushButton_2_clicked()
{
    model->removeRow(row);
}

void Admin::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void Admin::on_action_triggered()
{
    auto w = new AutentificationWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    deleteLater();
}


