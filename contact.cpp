#include "contact.h"
#include "ui_contact.h"

Contact::Contact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Contact)
{
    this->setStyleSheet("background-color:#F5A6D9;");
    ui->setupUi(this);

    //ui->listView->setModel(model);
}

Contact::~Contact()
{
    delete ui;
}
