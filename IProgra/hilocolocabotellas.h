#ifndef HILOCOLOCABOTELLAS_H
#define HILOCOLOCABOTELLAS_H

#include <cstdlib>
#include <iostream>
#include <QMutex>
#include <random>
#include <QDebug>
#include "hilo.h"
#include "botella.h"
#include "colas.h"

using namespace std;

class HiloColocaBotellas : public Hilo
{
public:
    HiloColocaBotellas(ListaBotellas * listaBotellas, BandaBotellas * bandaColocar, int tiempoDeCarga);
    ListaBotellas * listaBotellas;
    BandaBotellas * bandaColocar;
    int tiempoDeCarga;
    int * contadores/*[]*/;
    void run();
};

#endif // HILOCOLOCABOTELLAS_H
