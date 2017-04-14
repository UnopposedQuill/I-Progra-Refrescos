#ifndef FABRICAWINDOW_H
#define FABRICAWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <iostream>
#include <cstdlib>
#include "fabrica.h"//para que pueda trabajar con una fábrica
#include "hiloactualizador.h"//para que pueda actualizar los contadores visuales

class MainWindow;
class HiloActualizador;

namespace Ui {
class FabricaWindow;
}

class FabricaWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void iniciarSimulacion();
    void pausarSimulacion();
    void reiniciarSimulacion();
    void pararSimulacion();
    void actualizarDatos();
    void cambiarParametros();

public:
    explicit FabricaWindow(QWidget * parent = 0, Fabrica * fabrica = NULL);
    ~FabricaWindow();
    Fabrica * fabrica;
    HiloActualizador * hiloActualizador;

private:
    Ui::FabricaWindow *ui;
};

#endif // FABRICAWINDOW_H
