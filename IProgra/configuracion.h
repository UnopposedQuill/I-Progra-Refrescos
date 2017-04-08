#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <iostream>
#include <cstdlib>

#include "botella.h"//para la lista de botellas

using namespace std;

/**
 * @brief The Configuracion struct
 * Esta estructura va a contener un set de parámetros, que van a ser leídos por el constructor de la fábrica a la
 * hora de inicializarla con los valores
 * Esta estructura se crea con la ventana configuradora
 */
struct Configuracion{

    ListaBotellas * listaDeBotellas;//la lista de botellas de la fábrica
    int tiempoColocado, tiempoLimpieza, tiempoLlenado1, tiempoLlenado2, tiempoEntapado, tiempoInspeccion;//los tiempos de los hilos
    int capacidadColocadas, capacidadLimpiadas1, capacidadLimpiadas2, capacidadLlenas, capacidadEntapadas;//las capacidades de las bandas transportadoras

    Configuracion(ListaBotellas * listaDeBotellas, int tiempoColocado,int tiempoLimpieza,int tiempoLlenado1, int tiempoLlenado2,int tiempoEntapado,int tiempoInspeccion,int capacidadColocadas,int capacidadLimpiadas1,int capacidadLimpiadas2,int capacidadLlenas,int capacidadEntapadas){
        this->listaDeBotellas = listaDeBotellas;
        this->tiempoColocado = tiempoColocado;
        this->tiempoLimpieza = tiempoLimpieza;
        this->tiempoLlenado1 = tiempoLlenado1;
        this->tiempoLlenado2 = tiempoLlenado2;
        this->tiempoEntapado = tiempoEntapado;
        this->tiempoInspeccion = tiempoInspeccion;
        this->capacidadColocadas = capacidadColocadas;
        this->capacidadLimpiadas1 = capacidadLimpiadas1;
        this->capacidadLimpiadas2 = capacidadLimpiadas2;
        this->capacidadLlenas = capacidadLlenas;
        this->capacidadEntapadas = capacidadEntapadas;
    }
};

#endif // CONFIGURACION_H
