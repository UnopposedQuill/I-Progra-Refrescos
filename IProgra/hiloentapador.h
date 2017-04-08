#ifndef HILOENTAPADOR_H
#define HILOENTAPADOR_H

#include <cstdlib>
#include <iostream>
#include <QMutex>
#include "hilo.h"
#include "botella.h"
#include "colas.h"

using namespace std;

class HiloEntapador : public Hilo
{
public:
    HiloEntapador(ListaBotellas * botellas,BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, int tiempoDeEntapado);
    BandaBotellas * bandaEntrada;
    BandaBotellas * bandaColocar;
    ListaBotellas * listaBotellas;
    int tiempoDeEntapado;
    int * contadores;
    void run();
};

#endif // HILOENTAPADOR_H
