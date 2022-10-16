#ifndef CREATE_ACC_H
#define CREATE_ACC_H

#include <QString>
#include <QSqlQuery>

class Creat_Acc
{
private:
    QString user_login;
public:
    Creat_Acc() {}
    Creat_Acc(QString a)
    {
        user_login = a;
    }

    bool Creat();
};

#endif // CREATE_ACC_H
