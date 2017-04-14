#include "fabricawindow.h"
#include "ui_fabricawindow.h"

FabricaWindow::FabricaWindow(QWidget *parent, Fabrica *fabrica) : QMainWindow(parent), ui(new Ui::FabricaWindow) {
    ui->setupUi(this);
    this->fabrica = fabrica;
    //ahora tengo que modificar todos los contadores y números dentro de la ventana

    //tengo que colocar la velocidad a la que va cada hilo
    this->ui->velocidadColocador->setText(QString::number(this->fabrica->hiloColocaBotellas->tiempoDeCarga));
    this->ui->velocidadLimpiador->setText(QString::number(this->fabrica->hiloLimpiaBotellas->tiempoDeLimpieza));
    this->ui->velocidadLlenador1->setText(QString::number(this->fabrica->hilollenaBotellas1->tiempoDeLlenado));
    this->ui->velocidadLlenador2->setText(QString::number(this->fabrica->hilollenaBotellas2->tiempoDeLlenado));
    this->ui->velocidadEntapador->setText(QString::number(this->fabrica->hiloEntapador->tiempoDeEntapado));
    this->ui->velocidadInspeccionador->setText(QString::number(this->fabrica->hiloInspeccionador->tiempoDeInspeccion));

    //tengo que agregar una cantidad N de filas a cada tabla de la ventana donde N es la cantidad de botellas
    this->ui->contadoresColocador->setRowCount(this->fabrica->listaBotellas->largo());
    this->ui->contadoresLimpiador->setRowCount(this->fabrica->listaBotellas->largo());
    this->ui->contadoresLlenador1->setRowCount(this->fabrica->listaBotellas->largo());
    this->ui->contadoresLlenador2->setRowCount(this->fabrica->listaBotellas->largo());
    this->ui->contadoresEntapador->setRowCount(this->fabrica->listaBotellas->largo());
    this->ui->contadoresInspeccionador->setRowCount(this->fabrica->listaBotellas->largo());

    //ahora tengo que colocar 0's en cada una de esas filas
    for(int i = 0; i < this->fabrica->listaBotellas->largo(); i++){
        //los contadores del colocador
        this->ui->contadoresColocador->setItem(i,0,new QTableWidgetItem(QString::number(this->fabrica->listaBotellas->get(i)->botellaNodo->cantidadDeRefresco)));//coloco las cantidades de refresco
        this->ui->contadoresColocador->setItem(i,1,new QTableWidgetItem(QString::number(this->fabrica->hiloColocaBotellas->contadores[i])));//establece la cantidad que ha colocado, que es 0
        this->ui->contadoresColocador->setItem(i,2,new QTableWidgetItem(QString::number(this->fabrica->listaBotellas->get(i)->botellaNodo->probabilidadDeColocar)));//coloco la probabilidad de que la botella sea colocada en la tabla

        //los contadores del limpiador
        this->ui->contadoresLimpiador->setItem(i,0,new QTableWidgetItem(QString::number(this->fabrica->listaBotellas->get(i)->botellaNodo->cantidadDeRefresco)));
        this->ui->contadoresLimpiador->setItem(i,1,new QTableWidgetItem(QString::number(this->fabrica->hiloLimpiaBotellas->contadores[i])));

        //los contadores de los llenadores
        this->ui->contadoresLlenador1->setItem(i,0,new QTableWidgetItem(QString::number(this->fabrica->listaBotellas->get(i)->botellaNodo->cantidadDeRefresco)));
        this->ui->contadoresLlenador1->setItem(i,1,new QTableWidgetItem(QString::number(this->fabrica->hilollenaBotellas1->contadores[i])));
        this->ui->contadoresLlenador2->setItem(i,0,new QTableWidgetItem(QString::number(this->fabrica->listaBotellas->get(i)->botellaNodo->cantidadDeRefresco)));
        this->ui->contadoresLlenador2->setItem(i,1,new QTableWidgetItem(QString::number(this->fabrica->hilollenaBotellas2->contadores[i])));

        //los contadores del entapador
        this->ui->contadoresEntapador->setItem(i,0,new QTableWidgetItem(QString::number(this->fabrica->listaBotellas->get(i)->botellaNodo->cantidadDeRefresco)));
        this->ui->contadoresEntapador->setItem(i,1,new QTableWidgetItem(QString::number(this->fabrica->hiloEntapador->contadores[i])));

        //los contadores del inspector
        this->ui->contadoresInspeccionador->setItem(i,0,new QTableWidgetItem(QString::number(this->fabrica->listaBotellas->get(i)->botellaNodo->cantidadDeRefresco)));
        this->ui->contadoresInspeccionador->setItem(i,1,new QTableWidgetItem(QString::number(this->fabrica->hiloInspeccionador->contadoresAprobadas[i])));
        this->ui->contadoresInspeccionador->setItem(i,2,new QTableWidgetItem(QString::number(this->fabrica->hiloInspeccionador->contadoresDesechadas[i])));
        this->ui->contadoresInspeccionador->setItem(i,3,new QTableWidgetItem(QString::number(this->fabrica->listaBotellas->get(i)->botellaNodo->probabilidadDeDesecho)));

        this->hiloActualizador = new HiloActualizador(this);
        this->hiloActualizador->activo = this->hiloActualizador->pausa = true;
    }
}

FabricaWindow::~FabricaWindow()
{
    delete ui;
}

/**
 * @brief FabricaWindow::iniciarSimulacion
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la FabricaWindow
 * Lo que hace es que le pasa una señal a la fábrica propia para que arranque su funcionamiento
 */
void FabricaWindow::iniciarSimulacion(){
    this->fabrica->arrancarTodo();
    this->hiloActualizador->activo = true;
    this->hiloActualizador->pausa = false;
    this->hiloActualizador->start();
}

/**
 * @brief FabricaWindow::pausarSimulacion
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la FabricaWindow
 * Lo que hace es que le pasa una señal a la fábrica propia para que pause su funcionamiento
 */
void FabricaWindow::pausarSimulacion(){
    this->fabrica->pausarTodo();
    this->hiloActualizador->activo = this->hiloActualizador->pausa = true;
}

/**
 * @brief FabricaWindow::reiniciarSimulacion
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la FabricaWindow
 * Lo que hace es que le pasa una señal a la fábrica propia para que reinicie los contadores, y que quede en pausa su funcionamiento
 */
void FabricaWindow::reiniciarSimulacion(){
    this->fabrica->pausarTodo();//pauso todos los hilos para que no modifiquen nada
    this->hiloActualizador->activo = true;
    this->hiloActualizador->pausa = false;
    this->fabrica->reiniciarTodo();//luego reinicio los contadores
}

/**
 * @brief FabricaWindow::pararSimulacion
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la FabricaWindow
 * Lo que hace es que le pasa una señal a la fábrica propia para que pare su funcionamiento
 */
void FabricaWindow::pararSimulacion(){
    this->fabrica->pararTodo();
    this->hiloActualizador->activo = this->hiloActualizador->pausa = false;
}

/**
 * @brief FabricaWindow::actualizarDatos
 * Esta función lo que hace es enviarle una señal para que la ventana actualice sus propios datos
 */
void FabricaWindow::actualizarDatos(){

    //coloco todos los contadores
    for(int i = 0; i < this->fabrica->listaBotellas->largo(); i++){
        this->ui->contadoresColocador->item(i,1)->setText(QString::number(this->fabrica->hiloColocaBotellas->contadores[i]));//coloco la cantidad de botellas colocadas respectivas
        this->ui->infoBandaColocadas->item(0,0)->setText(QString::number(this->fabrica->bandaColocadas->largo()));//coloco la cantidad de botellas actualmente en la banda
        this->ui->infoBandaColocadas->item(0,1)->setText(QString::number(this->fabrica->bandaColocadas->maximoBotellas));//coloco el máximo de botellas de la banda
        this->ui->contadoresLimpiador->item(i,1)->setText(QString::number(this->fabrica->hiloLimpiaBotellas->contadores[i]));//coloco la cantidad de botellas limpiadas respectivas
        this->ui->infoBandaLimpias1->item(0,0)->setText(QString::number(this->fabrica->bandaLimpiadas1->largo()));//coloco la cantidad de botellas actualmente en la banda
        this->ui->infoBandaLimpias1->item(0,1)->setText(QString::number(this->fabrica->bandaLimpiadas1->maximoBotellas));//coloco el máximo de botellas de la banda
        this->ui->infoBandaLimpias2->item(0,0)->setText(QString::number(this->fabrica->bandaLimpiadas2->largo()));//coloco la cantidad de botellas actualmente en la banda
        this->ui->infoBandaLimpias2->item(0,1)->setText(QString::number(this->fabrica->bandaLimpiadas2->maximoBotellas));//coloco el máximo de botellas de la banda
        this->ui->contadoresLlenador1->item(i,1)->setText(QString::number(this->fabrica->hilollenaBotellas1->contadores[i]));//coloco la cantidad de botellas llenas respectivas
        this->ui->contadoresLlenador2->item(i,1)->setText(QString::number(this->fabrica->hilollenaBotellas2->contadores[i]));//coloco la cantidad de botellas llenas respectivas
        this->ui->infoBandaLlenas->item(0,0)->setText(QString::number(this->fabrica->bandaLlenadas->largo()));
        this->ui->infoBandaLlenas->item(0,1)->setText(QString::number(this->fabrica->bandaLlenadas->maximoBotellas));
        this->ui->contadoresEntapador->item(i,1)->setText(QString::number(this->fabrica->hiloEntapador->contadores[i]));//coloco la cantidad de botellas entapadas respectivas
        this->ui->infoBandaEntapadas->item(0,0)->setText(QString::number(this->fabrica->bandaEntapadas->largo()));
        this->ui->infoBandaEntapadas->item(0,1)->setText(QString::number(this->fabrica->bandaEntapadas->maximoBotellas));
        this->ui->contadoresInspeccionador->item(i,1)->setText(QString::number(this->fabrica->hiloInspeccionador->contadoresAprobadas[i]));
        this->ui->contadoresInspeccionador->item(i,2)->setText(QString::number(this->fabrica->hiloInspeccionador->contadoresDesechadas[i]));
    }
}

void FabricaWindow::cambiarParametros(){

}
