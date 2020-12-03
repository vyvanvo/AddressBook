#pragma once

#include <QtWidgets/QWidget>
#include "ui_qtaddressbook.h"

class QtAddressBook : public QWidget
{
    Q_OBJECT

public:
    QtAddressBook(QWidget *parent = Q_NULLPTR);

private slots:
    void on_add_btn_clicked();
    void on_address_list_currentItemChanged();
    void on_delete_btn_clicked();

private:
    Ui::QtAddressBookClass ui;
};
