#include "hilocolocabotellas.h"

HiloColocaBotellas::HiloColocaBotellas(ListaBotellas *listaBotellas, BandaBotellas *bandaColocar, int tiempoDeCarga)
{
    this->activo = this->pausa = true;
    this->isWorking = false;
    this->listaBotellas = listaBotellas;
    this->tiempoDeCarga = tiempoDeCarga;
    this->bandaColocar = bandaColocar;

    this->contadores =(int*) calloc(this->listaBotellas->largo(),sizeof(int));
}

void HiloColocaBotellas::run(){
    QMutex mutex;
    while(this->activo){

        mutex.lock();//bloquea el cpu para que ningún otro hilo se ejecute hasta que este se desbloquee
        this->isWorking = true;//empieza el trabajo
        std::mt19937_64 generadorDeNumeros;//un generador de números
        generadorDeNumeros.seed(time(NULL));
        std::uniform_int_distribution<int> aleatorizadorEnteros(0, 99);//una clase que sabe ordenar números
        int aleatorio = aleatorizadorEnteros(generadorDeNumeros);//hago que el generador le pase un número al aleatorizador, para que
        //pueda retornar un número aleatorio
        Botella * botellaAColocar = NULL;//la botella que se va a insertar
        int probabilidadActual = 0, indiceBotella = 0;//el primero es la probabilidad acumulada de las botellas, el segundo guarda el índice donde estaba la botella
        for(indiceBotella = 0; indiceBotella < this->listaBotellas->largo(); indiceBotella++){
            probabilidadActual += this->listaBotellas->get(indiceBotella)->botellaNodo->probabilidadDeColocar;//consigue la probabilidad de la botella comparada en el momento
            if(aleatorio <= probabilidadActual){//se cumplió la probabilidad
                botellaAColocar = this->listaBotellas->get(indiceBotella)->botellaNodo;//toma la botella a colocar
                break;
            }
        }
        this->bandaColocar->agregarNodoAlFinal(new NodoBotellaCola(botellaAColocar));//agrega la botella a la cola
        this->contadores[indiceBotella]++;//aumenta el contador correspondiente a la botella tomada
        mutex.unlock();//desbloquea

        sleep(this->tiempoDeCarga);
        while(this->pausa){
            this->isWorking = false;//cuando no está trabajando debo colocar esto en false
            sleep(1);
        }
    }
    this->isWorking = false;//cuando no está trabajando debo colocar esto en false, eso también incluye si está activo, pero no puede trabajar
}
