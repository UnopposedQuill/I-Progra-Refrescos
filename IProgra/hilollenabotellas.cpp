#include "hilollenabotellas.h"

HiloLlenaBotellas::HiloLlenaBotellas(ListaBotellas * botellas,BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, int tiempoDeLlenado)
{
    this->activo = this->pausa = true;
    this->bandaEntrada = bandaEntrada;
    this->bandaColocar = bandaColocar;
    this->listaBotellas = botellas;
    this->tiempoDeLlenado = tiempoDeLlenado;
    int enteros[botellas->largo()];
    this->contadores = enteros;
    for (int i = 0; i < botellas->largo();i++){
        enteros[i] = 0;
    }
}

void HiloLlenaBotellas::run(){

    QMutex mutex;
    while(this->activo){

        mutex.lock();

        if(this->bandaEntrada->primerBotella != NULL && this->bandaColocar->largo() < this->bandaColocar->maximoBotellas){//si logra sacar algo de la cola entrante y puede insertar en la cola de salida
            Botella * botellaConseguida = this->bandaEntrada->removerRetornarPrimerBotella()->botellaCola;//consigo la botella
            this->bandaColocar->agregarNodoAlFinal(new NodoBotellaCola(botellaConseguida));//inserta la botella en la cola de salida
            this->contadores[this->listaBotellas->indexOf(botellaConseguida->cantidadDeRefresco)]++;//agrego 1 al contador correspondiente
        }
        mutex.unlock();
        while(this->pausa){
            sleep(1);
        }
    }
}
