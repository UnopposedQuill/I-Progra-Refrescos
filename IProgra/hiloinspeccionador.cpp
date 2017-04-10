#include "hiloinspeccionador.h"

HiloInspeccionador::HiloInspeccionador(ListaBotellas * botellas, BandaBotellas * bandaEntrada, BandaBotellas* bandaColocar, int tiempoDeInspeccion)
{
    this->activo = this->pausa = true;
    this->bandaEntrada = bandaEntrada;
    this->bandaColocar = bandaColocar;
    this->listaBotellas = botellas;
    this->tiempoDeInspeccion = tiempoDeInspeccion;
    this->contadoresAprobadas =(int*) calloc(this->listaBotellas->largo(),sizeof(int));
    this->contadoresDesechadas =(int*) calloc(this->listaBotellas->largo(),sizeof(int));
}

void HiloInspeccionador::run(){
    QMutex mutex;
    while(this->activo){
        mutex.lock();

        if(this->bandaEntrada->primerBotella != NULL){//si se puede realizar el proceso de inspección, entonces, inicia el proceso de inspección
            Botella * botellaNodo = this->bandaEntrada->removerRetornarPrimerBotella()->botellaCola;
            if(botellaNodo != NULL){//por si acaso
                //ahora tiene que evaluar si desecha o no la botella conseguida
                std::mt19937_64 generadorDeNumeros;//un generador de números
                std::uniform_int_distribution<int> aleatorizadorEnteros(0, 100);//una clase que sabe ordenar números
                int aleatorio = aleatorizadorEnteros(generadorDeNumeros);//hago que el generador le pase un número al aleatorizador, para que
                //pueda retornar un número aleatorio
                if(aleatorio > botellaNodo->probabilidadDeDesecho){//si el aleatorio es mayor o igual a la probabilidad, que estaba de 0 a N;N < 100, significa que la probabilidad no se desecha
                    //así que tengo que colocar la botella en la cola de salida
                    this->bandaColocar->agregarNodoAlFinal(new NodoBotellaCola(botellaNodo));//agrego la botella
                    //ahora sólo falta incrementar el contador respectivo
                    this->contadoresAprobadas[this->listaBotellas->indexOf(botellaNodo->cantidadDeRefresco)]++;
                }
                else{//la desechó :(
                    //solo incremento el contador, sin mover la botella
                    this->contadoresDesechadas[this->listaBotellas->indexOf(botellaNodo->cantidadDeRefresco)]++;
                    delete botellaNodo;//borro la botella
                }
            }
        }
        mutex.unlock();

        sleep(this->tiempoDeInspeccion);
        while(this->pausa){
            sleep(1);
        }
    }
}
