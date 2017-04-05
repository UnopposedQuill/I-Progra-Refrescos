#ifndef COLAS_H
#define COLAS_H

#include <iostream>
#include <cstdlib>
#include "botella.h"

using namespace std;

struct NodoBotellaCola{
    Botella * botellaCola;
    NodoBotellaCola * siguiente;

    NodoBotellaCola(Botella * botella){
        this->botellaCola = botella;
        this->siguiente = NULL;
    }
};

struct BandaBotellas{

    NodoBotellaCola * primerBotella;
    int maximoBotellas;

    /**
     * Este es un constructor simple que inicializa la cola como una lista vacía
     * sin nodos asociados a ella
     */
    BandaBotellas(int maximoBotellas){
        this->primerBotella = NULL;
        this->maximoBotellas = maximoBotellas;

    }

    ~BandaBotellas();
    int largo();
    bool agregarNodoAlFinal(NodoBotellaCola * nodoAInsertar);
    bool agregarNodoAlInicio(NodoBotellaCola * nodoAInsertar);
    bool removerPrimerBotella();
    NodoBotellaCola * removerRetornarPrimerBotella();
};

#endif // COLAS_H
