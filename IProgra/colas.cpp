
#include "colas.h"

/**
 * Esta función es para agregar un nuevo nodo completo al final de la lista cuyo <siguiente> será reiniciado a NULL
 * No hay problema si el nodoAInsertar es NULL
 * @param nodoAInsertar El nodo que se desea insertar
 * @return True si el dato fue correctamente insertado, False en el otro caso
 */
bool BandaBotellas::agregarNodoAlFinal(NodoBotellaCola * nodoAInsertar){
    if(nodoAInsertar != NULL){
        nodoAInsertar->siguiente = NULL;//para desencadenar el nodo de cualquier otro nodo al que hubiera apuntado
        NodoBotellaCola * recorreNodos = this->primerBotella;
        if(this->primerBotella != NULL){//hay nodos dentro de la lista?
            while(recorreNodos->siguiente != NULL){
                recorreNodos = recorreNodos->siguiente;
            }
            recorreNodos->siguiente = nodoAInsertar;
        }
        else{
            this->primerBotella = nodoAInsertar;
        }
        return true;
    }
    return false;
}

/**
 * Esta función es para agregar un nuevo nodo completo al inicio de la lista cuyo <siguiente> será reiniciado a NULL
 * No hay problema si el nodoAInsertar es NULL
 * @param nodoAInsertar El nodo que se desea insertar
 * @return True si el dato fue correctamente insertado, False en el otro caso
 */
bool BandaBotellas::agregarNodoAlInicio(NodoBotellaCola * nodoAInsertar){
    if(nodoAInsertar != NULL){
        nodoAInsertar->siguiente = NULL;
        if (this->primerBotella == NULL) {
            this->primerBotella = nodoAInsertar;
        }
        else {
            nodoAInsertar->siguiente = this->primerBotella;
            this->primerBotella = nodoAInsertar;
        }
        return true;
    }
    return false;
}

/**
 * Esta función remueve el primer nodo de la lista, y retorna un puntero a este nodo
 * @return Un puntero al nodo removido de la lista, o NULL en caso de que no hayan nodos
 */
NodoBotellaCola * BandaBotellas::removerRetornarPrimerBotella() {
    if (this->primerBotella == NULL) {
        return this->primerBotella;//return NULL;
    } else {
        NodoBotellaCola * nodoABorrar = this->primerBotella;
        this->primerBotella = nodoABorrar->siguiente;
        nodoABorrar->siguiente = NULL;
        return nodoABorrar;
    }
}

/**
 * Esta función es como la de arriba, remueve el primer nodo, sólo que no retorna un puntero al nodo removido
 * @return True si el nodo fue correctamente removido, False si la lista no poseía nada o no pudo ser removido correctamente
 */
bool BandaBotellas::removerPrimerBotella() {
    NodoBotellaCola * nodoABorrar = this->removerRetornarPrimerBotella();
    if(nodoABorrar == NULL){
        return false;
    }
    delete nodoABorrar;//el operador "delete" lo que hace es que reinicia con 0's los bits de lo que borra, y luego deja el puntero
    //apuntando a NULL
    return true;
}

/**
 * Esta función retorna la cantidad de Nodos como entero que contiene la lista
 * @return La cantidad de Nodos que contiene la lista
 */
int BandaBotellas::largo() {
    int cantidadNodos = 0;
    NodoBotellaCola * recorreNodos = this->primerBotella;
    while(recorreNodos != NULL){
        recorreNodos = recorreNodos->siguiente;
        cantidadNodos++;
    }
    return cantidadNodos;
}

/**
 * Esta función elimina todos los nodos de la lista, para luego destruirla
 */
BandaBotellas::~BandaBotellas() {
    NodoBotellaCola * recorreNodos = this->primerBotella;
    while(recorreNodos != NULL){
        primerBotella = primerBotella->siguiente;
        delete recorreNodos;
        recorreNodos = primerBotella;
    }
}
