#include "fabricawindow.h"
#include "ui_fabricawindow.h"

FabricaWindow::FabricaWindow(QWidget *parent, Fabrica *fabrica) : QMainWindow(parent), ui(new Ui::FabricaWindow) {
    ui->setupUi(this);
    this->fabrica = fabrica;
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
