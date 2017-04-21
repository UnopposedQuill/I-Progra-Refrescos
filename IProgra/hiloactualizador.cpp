#include "hiloactualizador.h"

HiloActualizador::HiloActualizador(FabricaWindow *ventanaAActualizar)
{
    this->activo = this->pausa = true;
    this->ventanaAActualizar = ventanaAActualizar;
}

void HiloActualizador::run(){

    //esto es para poder conectarlo con los slots de la ventana actualizar
    qRegisterMetaType<QVector<int>>("QVector<int>");//esto es para poder conectarse bien con la ventana de la fábrica

    //ahora tengo que colocar los gifs dentro de la ventana
    QSize tamano(181,50);//creo una nueva referencia de tamaño
    QMovie * bandaColocar = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif
    QMovie * bandaLimpias1 = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif
    QMovie * bandaLimpias2 = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif
    QMovie * bandaLlenas = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif
    QMovie * bandaEntapadas = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif

    if(bandaColocar->isValid()){//si logró crear la película en memoria
        bandaColocar->setScaledSize(tamano);//le coloco el tamaño a la película para cambiarle el tamaño
        QLabel * labelColocadas = this->ventanaAActualizar->findChild<QLabel*>("bandaColocadas");//busca el label donde tiene que colocar el gif
        if(labelColocadas != NULL){//por si acaso
            labelColocadas->setMovie(bandaColocar);//coloca la película en el label
            labelColocadas->movie()->start();//inicia la película,
            labelColocadas->movie()->setPaused(true);//pero la deja en pausa
        }
    }
    if(bandaLimpias1->isValid()){
        bandaLimpias1->setScaledSize(tamano);
        QLabel * labelLimpias1 = this->ventanaAActualizar->findChild<QLabel*>("bandaLimpias1");//busca el label donde tiene que colocar el gif
        if(labelLimpias1 != NULL){//por si acaso
            labelLimpias1->setMovie(bandaColocar);//coloca la película en el label
            labelLimpias1->movie()->start();//inicia la película,
            labelLimpias1->movie()->setPaused(true);//pero la deja en pausa
        }
    }
    if(bandaLimpias2->isValid()){
        bandaLimpias2->setScaledSize(tamano);
        QLabel * labelLimpias2 = this->ventanaAActualizar->findChild<QLabel*>("bandaLimpias2");//busca el label donde tiene que colocar el gif
        if(labelLimpias2 != NULL){//por si acaso
            labelLimpias2->setMovie(bandaColocar);//coloca la película en el label
            labelLimpias2->movie()->start();//inicia la película,
            labelLimpias2->movie()->setPaused(true);//pero la deja en pausa
        }
    }
    if(bandaLlenas->isValid()){
        bandaLlenas->setScaledSize(tamano);
        QLabel * labelLlenas = this->ventanaAActualizar->findChild<QLabel*>("bandaLlenas");//busca el label donde tiene que colocar el gif
        if(labelLlenas != NULL){//por si acaso
            labelLlenas->setMovie(bandaColocar);//coloca la película en el label
            labelLlenas->movie()->start();//inicia la película,
            labelLlenas->movie()->setPaused(true);//pero la deja en pausa
        }
    }
    if(bandaEntapadas->isValid()){
        bandaEntapadas->setScaledSize(tamano);
        QLabel * labelEntapadas = this->ventanaAActualizar->findChild<QLabel*>("bandaEntapadas");//busca el label donde tiene que colocar el gif
        if(labelEntapadas != NULL){//por si acaso
            labelEntapadas->setMovie(bandaColocar);//coloca la película en el label
            labelEntapadas->movie()->start();//inicia la película,
            labelEntapadas->movie()->setPaused(true);//pero la deja en pausa
        }
    }

    while(this->activo){
        sleep(1);

        this->ventanaAActualizar->actualizarDatos();//le digo a la ventana que actualice sus datos

        sleep(1);
        while(this->pausa){
            sleep(1);
        }
    }
}
