#ifndef FABRICA_H
#define FABRICA_H

#include <cstdlib>
#include <iostream>

//include's de las estructuras de fábrica
#include "colas.h"
#include "hilocolocabotellas.h"
#include "hilolimpiabotellas.h"
#include "hilollenabotellas.h"
#include "hiloentapador.h"
#include "hiloinspeccionador.h"
#include "hilotransportador.h" //la explicación de la existencia de este está más abajo
#include "configuracion.h"//para poder configurar la fábrica

using namespace std;

/**
 * @brief The Fabrica struct
 * Esta estructura conforma todos las estructuras del proyecto y las encapsula en una sola estructura fácil de controlar
 */
struct Fabrica{

    ListaBotellas * listaBotellas;//la lista de las botellas

    //las bandas-transportadoras-colas de la fábrica
    BandaBotellas * bandaColocadas;     //la banda de botellas en la que se colocan al inicio
    BandaBotellas * bandaLimpiadas1;    //la primera banda de botellas que ya fueron limpiadas
    BandaBotellas * bandaLimpiadas2;    //la segunda banda de botellas que ya fueron limpiadas
    BandaBotellas * bandaLlenadas;      //la banda de botellas que ya fueron llenadas
    BandaBotellas * bandaEntapadas;     //la banda de botellas que ya fueron tapadas
    BandaBotellas * bandaInspeccionadas;//la banda de botellas que ya fueron inspeccionadas

    //las máquinas-hilos de la fábrica
    HiloColocaBotellas * hiloColocaBotellas;
    HiloLimpiaBotellas * hiloLimpiaBotellas;
    HiloLlenaBotellas * hilollenaBotellas1;
    HiloLlenaBotellas * hilollenaBotellas2;
    HiloEntapador * hiloEntapador;
    HiloInspeccionador * hiloInspeccionador;
    /*
    La banda transportadora en la cual está el inspector está dividida en dos, una en la que entran las botellas
    para ser inspeccionadas y la otra en la que ya fueron inspeccionadas, cuando el inspector está en pausa entra otro hilo en
    acción, este se va a encargar de mover las botellas sin inspeccionarlas y sin tiempo de espera. Su nombre es HiloTransportador
    */
    HiloTransportador * hiloTransportador;

    Fabrica(Configuracion * config);
    void arrancarTodo();
    void pausarTodo();
    void reiniciarTodo();
    void pararTodo();

};

#endif // FABRICA_H
