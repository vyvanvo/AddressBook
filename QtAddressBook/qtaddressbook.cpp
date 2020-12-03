#include "qtaddressbook.h"
#include "qtadddialog.h"
#include "stdafx.h"

QtAddressBook::QtAddressBook(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

void QtAddressBook::on_add_btn_clicked() {
    QtAddDialog dialog(this);
    if (dialog.exec()) {
        QString name = dialog.name_edit->text();
        QString email = dialog.email_edit->text();

        if (!name.isEmpty() && !email.isEmpty()) {
            QListWidgetItem* item = new QListWidgetItem(name, ui.address_list);
            item->setData(Qt::UserRole, email);
            ui.address_list->setCurrentItem(item);
        }
    }
}

void QtAddressBook::on_address_list_currentItemChanged() {
    QListWidgetItem* curItem = ui.address_list->currentItem();
    
    if (curItem) {
        ui.name_label->setText("Name: " + curItem->text());
        ui.email_label->setText("Email: " + curItem->data(Qt::UserRole).toString());
    }
    else {
        ui.name_label->setText("<No item selected>");
        ui.email_label->clear();
    }
}

void QtAddressBook::on_delete_btn_clicked() {
    QListWidgetItem* curItem = ui.address_list->currentItem();

    if (curItem) {
        int row = ui.address_list->row(curItem);
        ui.address_list->takeItem(row); 
        delete curItem;

        if (ui.address_list->count() > 0) {
            ui.address_list->setCurrentRow(0);
        }
        else {
            on_address_list_currentItemChanged();
        }
    }
}