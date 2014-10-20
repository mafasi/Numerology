#ifndef MAINGUI_H
#define MAINGUI_H

#include <QWidget>
#include "crossfoot.h"


namespace Ui {
class MainGui;
}

class MainGui : public QWidget
{
    Q_OBJECT

public:
    explicit MainGui(QWidget *parent = 0);
    ~MainGui();

private:
    Ui::MainGui *_ui;
    CrossFoot *_cf;
};

#endif // MAINGUI_H
