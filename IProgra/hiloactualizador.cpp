#include "hiloactualizador.h"

HiloActualizador::HiloActualizador(FabricaWindow *ventanaAActualizar)
{
    this->activo = this->pausa = true;
    this->ventanaAActualizar = ventanaAActualizar;
}

void HiloActualizador::run(){
    while(this->activo){

        sleep(1);

        this->ventanaAActualizar->actualizarDatos();//le digo a la ventana que actualice sus datos

        sleep(1);
        while(this->pausa){
            sleep(1);
        }
    }
}
