#include "maingui.h"
#include "ui_maingui.h"

MainGui::MainGui(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::MainGui),
    _cf(new CrossFoot)
{
    _ui->setupUi(this);

    connect(_ui->editInput, SIGNAL(textChanged(QString)), _cf, SLOT(clearHistory(QString)));
    connect(_ui->editInput, SIGNAL(textChanged(QString)), _cf, SLOT(setName(QString)));
    connect(_ui->editInput, SIGNAL(textChanged(QString)), _cf, SLOT(calculate(QString)));

    connect(_cf, SIGNAL(result(QString)), _ui->lcdResult, SLOT(display(QString)));

    connect(_ui->editInput, SIGNAL(returnPressed()), _cf, SLOT(saveLastValue()));
    connect(_cf, SIGNAL(addToList(QString)), _ui->plainTextEdit, SLOT(appendPlainText(QString)));

    connect(_cf, SIGNAL(updateStatus(QString)), _ui->label, SLOT(setText(QString)));

}

MainGui::~MainGui()
{
    delete _ui;
    delete _cf;
}

