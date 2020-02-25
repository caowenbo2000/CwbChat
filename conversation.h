#ifndef CONVERSATION_H
#define CONVERSATION_H

#include <QWidget>

namespace Ui {
class Conversation;
}

class Conversation : public QWidget
{
    Q_OBJECT

public:
    explicit Conversation(QWidget *parent = nullptr);
    ~Conversation();

private:
    Ui::Conversation *ui;
};

#endif // CONVERSATION_H
