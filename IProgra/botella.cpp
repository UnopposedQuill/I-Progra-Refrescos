#include "botella.h"

void ListaBotellas::agregar(NodoBotella* nodoAInsertar){
    if(nodoAInsertar != NULL){
        if(this->primerBotella == NULL){
            this->primerBotella = nodoAInsertar;
            nodoAInsertar->anterior = nodoAInsertar->siguiente = this->primerBotella;
        }
        else{
            if(this->primerBotella->siguiente == this->primerBotella){
                nodoAInsertar->siguiente = nodoAInsertar->anterior = this->primerBotella;
                this->primerBotella->siguiente = this->primerBotella->anterior = nodoAInsertar;
            }
            else{
                nodoAInsertar->siguiente = this->primerBotella->siguiente;
                this->primerBotella->siguiente->anterior = nodoAInsertar;
                nodoAInsertar->anterior = this->primerBotella;
                primerBotella->siguiente = nodoAInsertar;
            }
        }
    }
}

void ListaBotellas::imprimirTodo() {

    cout <<"Lista Circular: "<<endl;
    if(primerBotella != NULL){
        NodoBotella * recorreNodos = this->primerBotella;
        do{
            cout <<"Botella:" <<endl;
            cout <<"Cantidad de Refresco: " <<recorreNodos->botellaNodo->cantidadDeRefresco <<" ";
            cout <<"Probabilidad de ser colocada: " <<recorreNodos->botellaNodo->probabilidadDeColocar <<endl;
            recorreNodos = recorreNodos->siguiente;
        }while(recorreNodos != NULL && recorreNodos != this->primerBotella);
    }
    cout <<endl;
}

int ListaBotellas::largo() {
    return 0;
}

ListaBotellas::~ListaBotellas() {
    if(this->primerBotella != NULL){//si es diferente a NULL, la lista tiene algo que borrar
        if(this->primerBotella->siguiente == this->primerBotella){//si el siguiente es igual a primer nodo, sólo tengo que borrar un nodo
            delete this->primerBotella;
        }
        else{
            if(this->primerBotella->siguiente == this->primerBotella){
                delete this->primerBotella;
            }
            else{
                NodoBotella * recorreNodos = this->primerBotella;
                while (this->primerBotella != NULL) {
                    recorreNodos = recorreNodos->siguiente;
                    delete this->primerBotella;
                    this->primerBotella = recorreNodos;
                }
            }
        }
    }
}

NodoBotella* ListaBotellas::buscar(int valorABuscar) {
    if(this->primerBotella == NULL){//lista vacía
        return NULL;
    }
    NodoBotella * recorreNodos = this->primerBotella;//hay algo en la lista, recorro
    do{
        if(recorreNodos->botellaNodo->cantidadDeRefresco == valorABuscar){
            return recorreNodos;
        }
        recorreNodos = recorreNodos->siguiente;
    }while(recorreNodos != NULL && recorreNodos != this->primerBotella);
    return NULL;
}

NodoBotella* ListaBotellas::borrar(int valorABorrar) {
    NodoBotella * nodoBuscado = this->buscar(valorABorrar);
    if(nodoBuscado != NULL){//si encontró algo
        if(nodoBuscado->siguiente == nodoBuscado){//sólo un nodo en la lista
            this->primerBotella = NULL;
            nodoBuscado->anterior = nodoBuscado->siguiente = NULL;
            return nodoBuscado;
        }
        else{
            //más de 1 nodo en la lista
            nodoBuscado->siguiente->anterior = nodoBuscado->anterior;
            nodoBuscado->anterior->siguiente = nodoBuscado->siguiente;
            nodoBuscado->anterior = nodoBuscado->siguiente = NULL;
        }
    }
    return nodoBuscado;
}

/**
 * Esta función va a buscar un nodo que contenga un entero específicado
 * @param dato El entero que se va a buscar
 * @return Un entero que representa la posición donde está el nodo encontrado, o -1, si el nodo no fue encontrado
 */
int ListaBotellas::indexOf(int cantidadRefrescoABuscar) {
    if(this->primerBotella == NULL){
        return -1;
    }
    int contador = 0;
    NodoBotella * recorreNodos = this->primerBotella;
    do{
        if(recorreNodos->botellaNodo->cantidadDeRefresco == cantidadRefrescoABuscar){
            return contador;
        }
        contador++;
        recorreNodos = recorreNodos->siguiente;
    }while(recorreNodos->siguiente != this->primerBotella);
    return -1;
}

NodoBotella* ListaBotellas::get(int i) {
    if(i < 0 || i > this->largo()){
        return NULL;
    }
    if(i == 0){
        return this->primerBotella;
    }
    int cuentaPosiciones = 0;
    NodoBotella * recorreNodos = this->primerBotella;
    while(recorreNodos != NULL && cuentaPosiciones++ < i){
        recorreNodos = recorreNodos->siguiente;
    }
    return recorreNodos;
}

