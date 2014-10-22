#include "maingui.h"
#include "ui_maingui.h"

MainGui::MainGui(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::MainGui),
    _crossFootLeft(new CrossFoot),
    _crossFootRight(new CrossFoot)
{
    _ui->setupUi(this);

    //loop for translating
    connect(_ui->editInput, SIGNAL(textChanged(QString)), _crossFootLeft, SLOT(translate(QString)));
    connect(_crossFootLeft, SIGNAL(translated(QString)), _ui->editInput, SLOT(setText(QString)));

    connect(_ui->editInput, SIGNAL(textChanged(QString)), _crossFootLeft, SLOT(clearHistory(QString)));
    connect(_ui->editInput, SIGNAL(textChanged(QString)), _crossFootLeft, SLOT(setName(QString)));
    connect(_ui->editInput, SIGNAL(textChanged(QString)), _crossFootLeft, SLOT(calculate(QString)));

    connect(_crossFootLeft, SIGNAL(result(QString)), _ui->lcdResult, SLOT(display(QString)));

    // history
    connect(_ui->editInput, SIGNAL(returnPressed()), _crossFootLeft, SLOT(saveLastValue()));
    connect(_crossFootLeft, SIGNAL(addToList(QString)), _ui->plainTextEdit, SLOT(appendPlainText(QString)));

    //loop for translating
    connect(_ui->editInputRight, SIGNAL(textChanged(QString)), _crossFootRight, SLOT(translate(QString)));
    connect(_crossFootRight, SIGNAL(translated(QString)), _ui->editInputRight, SLOT(setText(QString)));

    connect(_ui->editInputRight, SIGNAL(textChanged(QString)), _crossFootRight, SLOT(clearHistory(QString)));
    connect(_ui->editInputRight, SIGNAL(textChanged(QString)), _crossFootRight, SLOT(setName(QString)));
    connect(_ui->editInputRight, SIGNAL(textChanged(QString)), _crossFootRight, SLOT(calculate(QString)));

    connect(_crossFootRight, SIGNAL(result(QString)), _ui->lcdResultRight, SLOT(display(QString)));

    // history
    connect(_ui->editInputRight, SIGNAL(returnPressed()), _crossFootRight, SLOT(saveLastValue()));
    connect(_crossFootRight, SIGNAL(addToList(QString)), _ui->plainTextEdit, SLOT(appendPlainText(QString)));

    // status bar
    connect(_crossFootLeft, SIGNAL(updateStatus(QString)), _ui->label, SLOT(setText(QString)));
    connect(_crossFootRight, SIGNAL(updateStatus(QString)), _ui->label, SLOT(setText(QString)));

}

MainGui::~MainGui()
{
    delete _ui;
    delete _crossFootLeft;
}

