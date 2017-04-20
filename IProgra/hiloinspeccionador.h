#ifndef HILOINSPECCIONADOR_H
#define HILOINSPECCIONADOR_H

#include <cstdlib>
#include <iostream>
#include <QMutex>
#include <random>
#include "hilomaquina.h"
#include "botella.h"
#include "colas.h"

using namespace std;

class HiloInspeccionador : public HiloMaquina
{
public:
    HiloInspeccionador(ListaBotellas * botellas,BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, int tiempoDeInspeccion);
    BandaBotellas * bandaEntrada;
    BandaBotellas * bandaColocar;
    ListaBotellas * listaBotellas;
    int tiempoDeInspeccion;
    int * contadoresAprobadas, * contadoresDesechadas;
    void run();
};

#endif // HILOINSPECCIONADOR_H
