#include "hilollenabotellas.h"

HiloLlenaBotellas::HiloLlenaBotellas(ListaBotellas * botellas,BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, int tiempoDeLlenado)
{
    this->activo = this->pausa = true;
    this->isWorking = false;
    this->bandaEntrada = bandaEntrada;
    this->bandaColocar = bandaColocar;
    this->listaBotellas = botellas;
    this->tiempoDeLlenado = tiempoDeLlenado;
    this->contadores =(int*) calloc(this->listaBotellas->largo(),sizeof(int));
}

void HiloLlenaBotellas::run(){

    QMutex mutex;
    while(this->activo){

        mutex.lock();

        if(this->bandaEntrada->primerBotella != NULL && this->bandaColocar->largo() < this->bandaColocar->maximoBotellas){//si logra sacar algo de la cola entrante y puede insertar en la cola de salida
            this->isWorking = true;//empezó a trabajar
            Botella * botellaConseguida = this->bandaEntrada->removerRetornarPrimerBotella()->botellaCola;//consigo la botella
            this->bandaColocar->agregarNodoAlFinal(new NodoBotellaCola(botellaConseguida));//inserta la botella en la cola de salida
            this->contadores[this->listaBotellas->indexOf(botellaConseguida->cantidadDeRefresco)]++;//agrego 1 al contador correspondiente
        }
        else{
            this->isWorking = false;//no logró trabajar
        }
        mutex.unlock();

        sleep(this->tiempoDeLlenado);
        while(this->pausa){
            this->isWorking = false;//no está trabajando
            sleep(1);
        }
    }
    this->isWorking = false;//no está trabajando
}
