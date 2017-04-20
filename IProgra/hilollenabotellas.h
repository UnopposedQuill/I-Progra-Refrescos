#ifndef HILOLLENABOTELLAS_H
#define HILOLLENABOTELLAS_H

#include <cstdlib>
#include <iostream>
#include <QMutex>
#include "hilomaquina.h"
#include "botella.h"
#include "colas.h"

using namespace std;

class HiloLlenaBotellas : public HiloMaquina
{
public:
    HiloLlenaBotellas(ListaBotellas * botellas,BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, int tiempoDeLlenado);
    BandaBotellas * bandaEntrada;
    BandaBotellas * bandaColocar;
    ListaBotellas * listaBotellas;
    int tiempoDeLlenado;
    int * contadores;
    void run();
};

#endif // HILOLLENABOTELLAS_H
