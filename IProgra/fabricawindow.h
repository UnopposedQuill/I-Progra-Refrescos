#ifndef FABRICAWINDOW_H
#define FABRICAWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <iostream>
#include <cstdlib>
#include "fabrica.h"//para que pueda trabajar con una fábrica

class MainWindow;

namespace Ui {
class FabricaWindow;
}

class FabricaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FabricaWindow(QWidget * parent = 0, Fabrica * fabrica = NULL);
    ~FabricaWindow();
    Fabrica * fabrica;

private:
    Ui::FabricaWindow *ui;
};

#endif // FABRICAWINDOW_H
