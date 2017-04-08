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

    Fabrica(Configuracion * config){
        this->bandaColocadas = new BandaBotellas(config->capacidadColocadas);
        this->bandaLimpiadas1 = new BandaBotellas(config->capacidadLimpiadas1);
        this->bandaLimpiadas2 = new BandaBotellas(config->capacidadLimpiadas2);
        this->bandaLlenadas = new BandaBotellas(config->capacidadLlenas);
        this->bandaEntapadas = new BandaBotellas(config->capacidadEntapadas);
        this->bandaInspeccionadas = new BandaBotellas(50);//la capacidad de esta no es relevante

        this->listaBotellas = config->listaDeBotellas;//establece las botellas de la fábrica
        //ahora a configurar las máquinas
        this->hiloColocaBotellas = new HiloColocaBotellas(this->listaBotellas,this->bandaColocadas,config->tiempoColocado);
        this->hiloLimpiaBotellas = new HiloLimpiaBotellas(this->listaBotellas,this->bandaColocadas,this->bandaLimpiadas1,this->bandaLimpiadas2,config->tiempoLimpieza);
        this->hilollenaBotellas1 = new HiloLlenaBotellas(this->listaBotellas,this->bandaLimpiadas1,this->bandaLlenadas,config->tiempoLlenado1);
        this->hilollenaBotellas2 = new HiloLlenaBotellas(this->listaBotellas,this->bandaLimpiadas2,this->bandaLlenadas,config->tiempoLlenado2);
        this->hiloEntapador = new HiloEntapador(this->listaBotellas,this->bandaLlenadas,this->bandaEntapadas,config->tiempoEntapado);
        this->hiloInspeccionador = new HiloInspeccionador(this->listaBotellas,this->bandaEntapadas,this->bandaInspeccionadas,config->tiempoInspeccion);
        this->hiloTransportador = new HiloTransportador(this->listaBotellas,this->bandaEntapadas,this->bandaInspeccionadas,this->hiloInspeccionador);
        //ya creé y configuré todo
    }

    void arrancarTodo(){
        //primero me aseguro de que todos los hilos estén en posibilidad de arrancar y funcionar
        this->hiloColocaBotellas->activo = true;
        this->hiloColocaBotellas->pausa = false;
        this->hiloLimpiaBotellas->activo = true;
        this->hiloLimpiaBotellas->pausa = false;
        this->hilollenaBotellas1->activo = true;
        this->hilollenaBotellas1->pausa = false;
        this->hilollenaBotellas2->activo = true;
        this->hilollenaBotellas2->pausa = false;
        this->hiloEntapador->activo = true;
        this->hiloEntapador->pausa = false;
        this->hiloInspeccionador->activo = true;
        this->hiloInspeccionador->pausa = false;
        this->hiloTransportador->activo = true;
        this->hiloTransportador->pausa = false;

        //ahora inicio todos los hilos
        this->hiloColocaBotellas->start();
        this->hiloLimpiaBotellas->start();
        this->hilollenaBotellas1->start();
        this->hilollenaBotellas2->start();
        this->hiloEntapador->start();
        this->hiloInspeccionador->start();
        this->hiloTransportador->start();
    }

};

#endif // FABRICA_H
