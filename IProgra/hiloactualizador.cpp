#include "hiloactualizador.h"

HiloActualizador::HiloActualizador(FabricaWindow *ventanaAActualizar)
{
    this->activo = this->pausa = true;
    this->ventanaAActualizar = ventanaAActualizar;
}

void HiloActualizador::run(){
    qRegisterMetaType<QVector<int> >("QVector<int>");//esto es para poder conectarse bien con la ventana de la fábrica

    while(this->activo){

        sleep(1);

        this->ventanaAActualizar->actualizarDatos();//le digo a la ventana que actualice sus datos

        sleep(1);
        while(this->pausa){
            sleep(1);
        }
    }
}
