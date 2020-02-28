#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QString>
#include <string>
#include <QSqlQuery>
#include <QMessageBox>
#include "sqlconnect.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_button_log_released();

private:
    Ui::Login *ui;
    Sqlconnect yourdb;
};

#endif // LOGIN_H
