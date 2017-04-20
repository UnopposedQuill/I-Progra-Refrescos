#include "fabrica.h"

/**
 * @brief Fabrica
 * Este es el constructor oficial de la estructura, este recibe un paquete de parámetros, los cuales lee y toma como propios
 * @param config El paquete de parámetros con el cual se creará la fábrica
 */
Fabrica::Fabrica(Configuracion * config){
    this->bandaColocadas = new BandaBotellas(config->capacidadColocadas);
    this->bandaLimpiadas1 = new BandaBotellas(config->capacidadLimpiadas1);
    this->bandaLimpiadas2 = new BandaBotellas(config->capacidadLimpiadas2);
    this->bandaLlenadas = new BandaBotellas(config->capacidadLlenas);
    this->bandaEntapadas = new BandaBotellas(config->capacidadEntapadas);
    this->bandaInspeccionadas = new BandaBotellas(50);//la capacidad de esta no es relevante

    this->listaBotellas = config->listaDeBotellas;//establece las botellas de la fábrica
    //ahora a configurar las máquinas
    this->hiloColocaBotellas = new HiloColocaBotellas(this->listaBotellas,this->bandaColocadas,config->tiempoColocado);
    this->hiloLimpiaBotellas = new HiloLimpiaBotellas(this->listaBotellas,this->bandaColocadas,this->bandaLimpiadas1,this->bandaLimpiadas2,config->tiempoLimpieza);
    this->hilollenaBotellas1 = new HiloLlenaBotellas(this->listaBotellas,this->bandaLimpiadas1,this->bandaLlenadas,config->tiempoLlenado1);
    this->hilollenaBotellas2 = new HiloLlenaBotellas(this->listaBotellas,this->bandaLimpiadas2,this->bandaLlenadas,config->tiempoLlenado2);
    this->hiloEntapador = new HiloEntapador(this->listaBotellas,this->bandaLlenadas,this->bandaEntapadas,config->tiempoEntapado);
    this->hiloInspeccionador = new HiloInspeccionador(this->listaBotellas,this->bandaEntapadas,this->bandaInspeccionadas,config->tiempoInspeccion);
    this->hiloTransportador = new HiloTransportador(this->listaBotellas,this->bandaEntapadas,this->bandaInspeccionadas,this->hiloInspeccionador);
    //ya creé y configuré todo
}

/**
 * @brief arrancarTodo
 * Esta función se encarga de poner todos los hilos en capacidad de arrancar y luego los inicia
 */
void Fabrica::arrancarTodo(){
    //primero me aseguro de que todos los hilos estén en posibilidad de arrancar y funcionar
    this->hiloColocaBotellas->activo = true;
    this->hiloColocaBotellas->pausa = false;
    this->hiloLimpiaBotellas->activo = true;
    this->hiloLimpiaBotellas->pausa = false;
    this->hilollenaBotellas1->activo = true;
    this->hilollenaBotellas1->pausa = false;
    this->hilollenaBotellas2->activo = true;
    this->hilollenaBotellas2->pausa = false;
    this->hiloEntapador->activo = true;
    this->hiloEntapador->pausa = false;
    this->hiloInspeccionador->activo = true;
    this->hiloInspeccionador->pausa = false;
    this->hiloTransportador->activo = true;
    this->hiloTransportador->pausa = false;

    //ahora inicio todos los hilos
    this->hiloColocaBotellas->start();
    this->hiloLimpiaBotellas->start();
    this->hilollenaBotellas1->start();
    this->hilollenaBotellas2->start();
    this->hiloEntapador->start();
    this->hiloInspeccionador->start();
    this->hiloTransportador->start();
}

/**
 * @brief pausarTodo
 * Esta función coloca a todos los hilos en un sólo estado de pausa
 */
void Fabrica::pausarTodo(){
    //pongo todos los hilos con activo = pausa = true
    this->hiloColocaBotellas->activo = this->hiloColocaBotellas->pausa = true;
    this->hiloLimpiaBotellas->activo = this->hiloLimpiaBotellas->pausa = true;
    this->hilollenaBotellas1->activo = this->hilollenaBotellas1->pausa = true;
    this->hilollenaBotellas2->activo = this->hilollenaBotellas2->pausa = true;
    this->hiloEntapador->activo = this->hiloEntapador->pausa = true;
    this->hiloTransportador->activo = this->hiloTransportador->pausa = true;//recordar que si este no lo pauso, las botellas "se inspeccionan"
    this->hiloInspeccionador->activo = this->hiloInspeccionador->pausa = true;//ahora pauso este

}

/**
 * @brief reiniciarTodo
 * Esta función reinicia los contadores únicamente
 */
void Fabrica::reiniciarTodo(){
    //reinicio todos los contadores
    QMutex mutex;//por si acaso

    mutex.lock();//los bloqueos nunca están de más
    for(int i = 0; i < this->hiloColocaBotellas->listaBotellas->largo();i++){//necesito recorrer los contadores para cada una de las botellas en la lista de botellas
        this->hiloColocaBotellas->contadores[i] = 0;//limpio todos los contadores de la estructura
        this->hiloLimpiaBotellas->contadores[i] = 0;
        this->hilollenaBotellas1->contadores[i] = 0;
        this->hilollenaBotellas2->contadores[i] = 0;
        this->hiloEntapador->contadores[i] = 0;
        this->hiloInspeccionador->contadoresAprobadas[i] = 0;
        this->hiloInspeccionador->contadoresDesechadas[i] = 0;
        this->hiloTransportador->contadores[i] = 0;
    }
    mutex.unlock();
}

/**
 * @brief pararTodo
 * Esta función pone a todos los hilos en un solo estado de inactividad
 */
void Fabrica::pararTodo(){
    //pongo todos los hilos con activo = pausa = true
    this->hiloColocaBotellas->activo = this->hiloColocaBotellas->pausa = false;
    this->hiloLimpiaBotellas->activo = this->hiloLimpiaBotellas->pausa = false;
    this->hilollenaBotellas1->activo = this->hilollenaBotellas1->pausa = false;
    this->hilollenaBotellas2->activo = this->hilollenaBotellas2->pausa = false;
    this->hiloEntapador->activo = this->hiloEntapador->pausa = false;
    this->hiloTransportador->activo = this->hiloTransportador->pausa = false;//recordar que si este no lo pauso, las botellas "se inspeccionan"
    this->hiloInspeccionador->activo = this->hiloInspeccionador->pausa = false;
}
