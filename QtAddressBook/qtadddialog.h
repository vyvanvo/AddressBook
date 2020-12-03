#pragma once

#include <QDialog>
#include "ui_qtadddialog.h"

class QtAddDialog : public QDialog, public Ui::QtAddDialog
{
	Q_OBJECT

public:
	QtAddDialog(QWidget *parent = Q_NULLPTR);
	~QtAddDialog();
};
