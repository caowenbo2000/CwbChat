#include "conversation.h"
#include "ui_conversation.h"

Conversation::Conversation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Conversation)
{
    ui->setupUi(this);
}

Conversation::~Conversation()
{
    delete ui;
}
