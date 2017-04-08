#include "hiloentapador.h"

HiloEntapador::HiloEntapador(ListaBotellas * botellas,BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, int tiempoDeEntapado)
{
    this->activo = this->pausa = true;
    this->bandaEntrada = bandaEntrada;
    this->bandaColocar = bandaColocar;
    this->listaBotellas = botellas;
    this->tiempoDeEntapado = tiempoDeEntapado;
    int enteros[botellas->largo()];
    this->contadores = enteros;
    for (int i = 0; i < botellas->largo();i++){
        this->contadores[i] = 0;
    }
}

void HiloEntapador::run(){

    QMutex mutex;
    while(this->activo){

        mutex.lock();

        if(this->bandaEntrada->primerBotella != NULL && this->bandaColocar->largo() < this->bandaColocar->maximoBotellas){//si logra sacar algo de la cola entrante y puede insertar en la cola de salida
            Botella * botellaConseguida = this->bandaEntrada->removerRetornarPrimerBotella()->botellaCola;//consigo la botella
            this->bandaColocar->agregarNodoAlFinal(new NodoBotellaCola(botellaConseguida));//inserta la botella en la cola de salida
            this->contadores[this->listaBotellas->indexOf(botellaConseguida->cantidadDeRefresco)]++;//agrego 1 al contador correspondiente
        }
        mutex.unlock();
        sleep(this->tiempoDeEntapado);
        while(this->pausa){
            sleep(1);
        }
    }
}
