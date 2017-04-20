#ifndef HILOACTUALIZADOR_H
#define HILOACTUALIZADOR_H

#include <cstdlib>
#include <iostream>
#include <QMutex>//para sincronizar el hilo con el resto
#include <QTableWidget>//para poder interactuar con las tablas de información
#include <QMovie>//para poder interactuar con los gifs de la simulación
#include <QSize>//para poder redimensionar con los gifs de la simulación
#include <QLabel>//para poder interactuar con los labels donde van los hilos
#include <QDebug>//los prints son importantes
#include "hilo.h"//para poder convertirse en un hilo
#include "fabricawindow.h"//para que pueda interactuar con la fábrica y la ventana de la fábrica y actualizar todo

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
