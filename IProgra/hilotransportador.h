#ifndef HILOTRANSPORTADOR_H
#define HILOTRANSPORTADOR_H

#include <cstdlib>
#include <iostream>
#include <QMutex>
#include <random>
#include "hilomaquina.h"
#include "botella.h"
#include "colas.h"
#include "hiloinspeccionador.h"

using namespace std;

/**
 * @brief The HiloTransportador class
 * Como la banda transportadora que tiene el inspector está divida en 2 tengo que hacer que actúe como una sola banda, para eso existe este hilo
 * Este hilo entra en acción cuando el inspector está en pausa o está apagado, moviendo las botellas de una banda a otra
 */
class HiloTransportador : public HiloMaquina
{
public:
    HiloTransportador(ListaBotellas * botellas,BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, HiloInspeccionador * hiloInspeccionadorASustituir);
    HiloInspeccionador * hiloInspeccionadorASustituir;
    BandaBotellas * bandaEntrada;
    BandaBotellas * bandaColocar;
    ListaBotellas * listaBotellas;
    int * contadores;
    void run();
};

#endif // HILOTRANSPORTADOR_H
