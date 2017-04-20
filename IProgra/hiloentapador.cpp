#include "hiloentapador.h"

HiloEntapador::HiloEntapador(ListaBotellas * botellas,BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, int tiempoDeEntapado)
{
    this->activo = this->pausa = true;
    this->isWorking = false;
    this->bandaEntrada = bandaEntrada;
    this->bandaColocar = bandaColocar;
    this->listaBotellas = botellas;
    this->tiempoDeEntapado = tiempoDeEntapado;
    this->contadores =(int*) calloc(this->listaBotellas->largo(),sizeof(int));
}

void HiloEntapador::run(){

    QMutex mutex;
    while(this->activo){

        mutex.lock();

        if(this->bandaEntrada->primerBotella != NULL && this->bandaColocar->largo() < this->bandaColocar->maximoBotellas){//si logra sacar algo de la cola entrante y puede insertar en la cola de salida
            this->isWorking = true;//logró empezar a trabajar, así que lo marco
            Botella * botellaConseguida = this->bandaEntrada->removerRetornarPrimerBotella()->botellaCola;//consigo la botella
            this->bandaColocar->agregarNodoAlFinal(new NodoBotellaCola(botellaConseguida));//inserta la botella en la cola de salida
            this->contadores[this->listaBotellas->indexOf(botellaConseguida->cantidadDeRefresco)]++;//agrego 1 al contador correspondiente
        }
        else{
            this->isWorking = false;//no logró empezar a trabajar
        }
        mutex.unlock();
        sleep(this->tiempoDeEntapado);
        while(this->pausa){
            this->isWorking = false;//no está trabajando
            sleep(1);
        }
    }
    this->isWorking = false;//no está trabajando
}
