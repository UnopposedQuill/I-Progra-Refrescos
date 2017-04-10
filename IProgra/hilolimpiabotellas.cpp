#include "hilolimpiabotellas.h"

HiloLimpiaBotellas::HiloLimpiaBotellas(ListaBotellas *botellas, BandaBotellas * bandaEntrada, BandaBotellas * bandaColocar1, BandaBotellas *bandaColocar2, int tiempoDeLimpieza)
{
    this->activo = this->pausa = true;
    this->bandaEntrada = bandaEntrada;
    this->bandaColocar1 = bandaColocar1;
    this->bandaColocar2 = bandaColocar2;
    this->listaBotellas = botellas;
    this->tiempoDeLimpieza = tiempoDeLimpieza;
    this->contadores =(int*) calloc(this->listaBotellas->largo(),sizeof(int));
}

void HiloLimpiaBotellas::run(){

    QMutex mutex;
    while(this->activo){

        mutex.lock();//bloquea el cpu para que ningún otro hilo se ejecute hasta que este se desbloquee
        if(this->bandaEntrada->primerBotella != NULL && (this->bandaColocar1->largo() < this->bandaColocar1->maximoBotellas || (this->bandaColocar2->largo() < this->bandaColocar2->maximoBotellas))){//hay algo en la banda transportadora de entrada, y el máximo de la banda de salida no ha sido alcanzado

            Botella * botellaEntrada = this->bandaEntrada->removerRetornarPrimerBotella()->botellaCola;
            if(botellaEntrada != NULL){//por si acaso

                std::mt19937_64 generadorDeNumeros;//un generador de números
                std::uniform_int_distribution<int> aleatorizadorEnteros(0, 1);//una clase que sabe ordenar números
                int aleatorio = aleatorizadorEnteros(generadorDeNumeros);//hago que el generador le pase un número al aleatorizador, para que
                if(aleatorio == 0){
                    this->bandaColocar1->agregarNodoAlFinal(new NodoBotellaCola(botellaEntrada));//agrego la botella a la primera cola de salida
                }
                else{
                    this->bandaColocar2->agregarNodoAlFinal(new NodoBotellaCola(botellaEntrada));//agrego la botella a la segunda cola de salida
                }
                this->contadores[this->listaBotellas->indexOf(botellaEntrada->cantidadDeRefresco)]++;//agrego 1 al contador correspondiente
            }
        }
        mutex.unlock();//desbloquea

        sleep(this->tiempoDeLimpieza);

        while(this->pausa){
            sleep(1);
        }
    }
}
