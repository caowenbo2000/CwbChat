#include "login.h"
#include "ui_login.h"
#include "contact.h"

#include <QDebug>
#include <QSqlError>
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
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
    if(yourdb.LoginCheck(TempId,TempPassWord)==1) // 成功登录
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
