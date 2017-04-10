#include "fabricawindow.h"
#include "ui_fabricawindow.h"

FabricaWindow::FabricaWindow(QWidget *parent, Fabrica *fabrica) : QMainWindow(parent), ui(new Ui::FabricaWindow) {
    ui->setupUi(this);
    this->fabrica = fabrica;
    //ahora tengo que modificar todos los contadores y números dentro de la ventana

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
}

/**
 * @brief FabricaWindow::pausarSimulacion
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la FabricaWindow
 * Lo que hace es que le pasa una señal a la fábrica propia para que pause su funcionamiento
 */
void FabricaWindow::pausarSimulacion(){
    this->fabrica->pausarTodo();
}

/**
 * @brief FabricaWindow::reiniciarSimulacion
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la FabricaWindow
 * Lo que hace es que le pasa una señal a la fábrica propia para que reinicie los contadores, y que quede en pausa su funcionamiento
 */
void FabricaWindow::reiniciarSimulacion(){
    this->fabrica->pausarTodo();//pauso todos los hilos para que no modifiquen nada
    this->fabrica->reiniciarTodo();//luego reinicio los contadores
}

/**
 * @brief FabricaWindow::pararSimulacion
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la FabricaWindow
 * Lo que hace es que le pasa una señal a la fábrica propia para que pare su funcionamiento
 */
void FabricaWindow::pararSimulacion(){
    this->fabrica->pararTodo();
}
