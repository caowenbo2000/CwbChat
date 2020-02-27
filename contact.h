#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class Contact;
}

class Contact : public QWidget
{
    Q_OBJECT

public:
    explicit Contact(QWidget *parent = nullptr);
    ~Contact();
    void test();
public slots:
    void prin(QString CurrentSelectText);
    void Switch(QString UserName);
private:
    Ui::Contact *ui;
};

#endif // CONTACT_H
