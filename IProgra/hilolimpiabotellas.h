#ifndef HILOLIMPIABOTELLAS_H
#define HILOLIMPIABOTELLAS_H

#include <cstdlib>
#include <iostream>
#include <QMutex>
#include <random>
#include <QDebug>
#include "hilo.h"
#include "botella.h"
#include "colas.h"


using namespace std;

class HiloLimpiaBotellas : public Hilo
{
public:
    HiloLimpiaBotellas(ListaBotellas * botellas,BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar1, BandaBotellas * bandaColocar2, int tiempoDeLimpieza);
    BandaBotellas * bandaEntrada;
    BandaBotellas * bandaColocar1;
    BandaBotellas * bandaColocar2;
    ListaBotellas * listaBotellas;
    int tiempoDeLimpieza;
    int * contadores;
    void run();
};

#endif // HILOLIMPIABOTELLAS_H
