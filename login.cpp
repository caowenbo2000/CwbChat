#include "login.h"
#include "ui_login.h"
#include "sqlconnect.h"
#include "contact.h"

#include <QDebug>
#include <QSqlError>
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    Sqlconnect:: MySqlConnect();
    this->setStyleSheet("background-color:#C0EAFC;");
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

void Login::on_button_log_released()
{
    int TempId = ui->lineEdit_id->text().toInt();
    std::string cTempPassWord = ui->lineEdit_password->text().toStdString();
    QString TempPassWord = QString::fromStdString(cTempPassWord);
    QSqlQuery query;
    //QString QueryStr = QString("SELECT * FROM User WHERE Id = '%1' and PassWord = '%2'").arg(TempPassWord).arg(TempId);
    query.exec("use ChatTest;");
    query.exec(QString("SELECT * FROM User WHERE Id = '%1' and PassWord = '%2';").arg(TempPassWord).arg(TempId));
    if(query.last()==1)
    {
        qDebug()<<"login success";
        Contact *w2= new Contact();
        w2->show();
        this->hide();
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("login failed"), QString("用户名或密码错误"));
    }
}
