# Курсовая работа "_Клиент-серверное приложение_"

## Описание
Это desktop приложения под ОС Linux Ubuntu 20.04 и выше. Целью курсового проекта было разработать чатик для передачи текстовых сообщений.
___

## Инструменты
+ С++ 17
+ Qt/QT Creator
+ Standard Template Library (STL)
+ Figma
+ TCP/IP
+ SQLite
___

## Функционал приложения
Приложение имеет 2 вида ролей:
1. Администратор
  
Администратор имеет доступ к БД и соответственно может изменять, удалять, добавлять и блокировать пользователей.

2. Пользователь

При загрузке приложения пользователь может войти в аккаунт или если таковой отсутствует, то может пройти регистрацию. Плсле того как пользователь вошел в аккаунт, он может подключиться к общей группе и начать общение со всеми остальными подключеннными пользователями
___

## Запуск 

Для запуска приложения необходимо иметь ОС Linux Ubuntu 20.04 и выше, а также установленный Qt Creator с версией Qt 5 и выше.
___

## Пример реализации передачи сообщения на сервер

```C++
void MainWindow::SendToServer(QString str)
{
    if (ui->lineEdit->text() != "") {
        Data.clear();
        QDataStream out(&Data,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_1);
        out << quint16(0) << windowTitle() + ":\n" + str + "\n";
        out.device()->seek(0);
        out << quint16(Data.size() - sizeof (quint16));
        socket->write(Data);
        ui->lineEdit->clear();
    }
}
```

