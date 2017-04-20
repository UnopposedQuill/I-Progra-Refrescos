#include "hilotransportador.h"

HiloTransportador::HiloTransportador(ListaBotellas * botellas, BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, HiloInspeccionador *hiloInspeccionadorASustituir)
{
    this->activo = this->pausa = true;
    this->isWorking = false;
    this->bandaEntrada = bandaEntrada;
    this->bandaColocar = bandaColocar;
    this->listaBotellas = botellas;
    this->contadores =(int*) calloc(this->listaBotellas->largo(),sizeof(int));
    this->hiloInspeccionadorASustituir = hiloInspeccionadorASustituir;
}

void HiloTransportador::run(){
    QMutex mutex;
    while(this->activo){
        mutex.lock();

        //si el hilo inspeccionador está inactivo, o está en pausa, y se cumple que puede pasar una botella, entonces el hilo entra en acción
        if((!this->hiloInspeccionadorASustituir->activo || this->hiloInspeccionadorASustituir->pausa) && this->bandaEntrada->primerBotella != NULL && this->bandaColocar->largo() < this->bandaColocar->maximoBotellas){//si se puede realizar el proceso de inspección, entonces, inicia el proceso de inspección
            this->isWorking = true;//empezó a trabajar
            Botella * botellaNodo = this->bandaEntrada->removerRetornarPrimerBotella()->botellaCola;
            if(botellaNodo != NULL){//por si acaso
                //tengo que colocar la botella en la cola de salida
                this->bandaColocar->agregarNodoAlFinal(new NodoBotellaCola(botellaNodo));//agrego la botella
                //ahora sólo falta incrementar el contador respectivo
                this->contadores[this->listaBotellas->indexOf(botellaNodo->cantidadDeRefresco)]++;//este contador es para las botellas que no fueron inspeccionadas
            }
        }
        else{
            this->isWorking = false;//no logró empezar a trabajar
        }
        mutex.unlock();

        sleep(1);
        while(this->pausa){
            this->isWorking = false;//no está trabajando
            sleep(1);
        }
    }
    this->isWorking = false;//no está trabajando
}
