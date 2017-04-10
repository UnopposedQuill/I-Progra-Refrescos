#ifndef HILOACTUALIZADOR_H
#define HILOACTUALIZADOR_H

#include <cstdlib>
#include <iostream>
#include <QMutex>
#include "hilo.h"
//#include "fabrica.h"
#include "fabricawindow.h"//para que pueda interactuar con la fábrica y la ventana de la fábrica y actualizar todo
#include <QTableWidget>

using namespace std;

class FabricaWindow;

class HiloActualizador : public Hilo
{
public:
    HiloActualizador(FabricaWindow * ventanaAActualizar);
    FabricaWindow * ventanaAActualizar;
    void run();
};

#endif // HILOACTUALIZADOR_H
