#ifndef REFRESCO_H
#define REFRESCO_H

#include <cstdlib>
#include <iostream>

using namespace std;

struct Botella{

    int cantidadDeRefresco;
    int probabilidadDeColocar;

};

struct NodoBotella{

    Botella * botellaNodo;
    NodoBotella * anterior, * siguiente;

    NodoBotella(Botella * botella){
        this->botellaNodo = botella;
        this->anterior = this->siguiente = NULL;
    }
};

struct ListaBotellas{

    NodoBotella * primerBotella;

    ListaBotellas(){
        this->primerBotella = NULL;
    }

    ~ListaBotellas();
        int largo();
        int indexOf(int dato);
        void agregar(NodoBotella * nodoAInsertar);
        void imprimirTodo();
        NodoBotella * get(int i);
        NodoBotella * buscar(int valorABuscar);
        NodoBotella * borrar(int valorABorrar);
};

#endif // REFRESCO_H
