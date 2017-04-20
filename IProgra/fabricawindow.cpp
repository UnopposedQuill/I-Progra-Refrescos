#include "fabricawindow.h"
#include "ui_fabricawindow.h"

FabricaWindow::FabricaWindow(QWidget *parent, Fabrica *fabrica) : QMainWindow(parent), ui(new Ui::FabricaWindow) {
    ui->setupUi(this);
    this->fabrica = fabrica;
    this->imagen = false;
    //coloco imágenes sin moverse dentro de la fábrica

    QSize tamano(181,50);//creo una nueva referencia de tamaño
    QMovie * bandaColocar = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif
    QMovie * bandaLimpias1 = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif
    QMovie * bandaLimpias2 = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif
    QMovie * bandaLlenas = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif
    QMovie * bandaEntapadas = new QMovie(":/gifs/gifs/banda.gif");//creo una nueva película, que guardará los datos del gif
    if(bandaColocar->isValid()){//si logró crear la película en memoria
        bandaColocar->setScaledSize(tamano);//le coloco el tamaño a la película para cambiarle el tamaño
        this->ui->bandaColocadas->setMovie(bandaColocar);//luego coloco la película dentro del label donde tiene que ir
        this->ui->bandaColocadas->movie()->start();
    }
    if(bandaLimpias1->isValid()){
        bandaLimpias1->setScaledSize(tamano);
        this->ui->bandaLimpias1->setMovie(bandaLimpias1);
        this->ui->bandaColocadas->movie()->start();
    }
    if(bandaLimpias2->isValid()){
        bandaLimpias2->setScaledSize(tamano);
        this->ui->bandaLimpias2->setMovie(bandaLimpias2);
        this->ui->bandaColocadas->movie()->start();
    }
    if(bandaLlenas->isValid()){
        bandaLlenas->setScaledSize(tamano);
        this->ui->bandaLlenas->setMovie(bandaLlenas);
        this->ui->bandaColocadas->movie()->start();
    }
    if(bandaEntapadas->isValid()){
        bandaEntapadas->setScaledSize(tamano);
        this->ui->bandaEntapadas->setMovie(bandaEntapadas);
        this->ui->bandaColocadas->movie()->start();
    }
    //todos los gifs colocados quedaron sin movimiento

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

    this->ui->infoBandaColocadas->item(0,1)->setText(QString::number(this->fabrica->bandaColocadas->maximoBotellas));//coloco el máximo de botellas de la banda
    this->ui->infoBandaLimpias1->item(0,1)->setText(QString::number(this->fabrica->bandaLimpiadas1->maximoBotellas));//coloco el máximo de botellas de la banda
    this->ui->infoBandaLimpias2->item(0,1)->setText(QString::number(this->fabrica->bandaLimpiadas2->maximoBotellas));//coloco el máximo de botellas de la banda
    this->ui->infoBandaLlenas->item(0,1)->setText(QString::number(this->fabrica->bandaLlenadas->maximoBotellas));
    this->ui->infoBandaEntapadas->item(0,1)->setText(QString::number(this->fabrica->bandaEntapadas->maximoBotellas));

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

    //modifico todos los gifs acorde a cómo va la simulación
    //todos los gifs y datos necesarios
    if(this->fabrica->hiloLimpiaBotellas->isWorking){
        this->ui->bandaColocadas->movie()->setPaused(this->fabrica->bandaColocadas->primerBotella == NULL);//pausa el gif si es necesario
    }
    if(this->fabrica->hilollenaBotellas1->isWorking){
        this->ui->bandaLimpias1->movie()->setPaused(this->fabrica->bandaLimpiadas1->primerBotella == NULL);//pausa el gif si es necesario
    }
    if(this->fabrica->hilollenaBotellas2->isWorking){
        this->ui->bandaLimpias2->movie()->setPaused(this->fabrica->bandaLimpiadas2->primerBotella == NULL);//pausa el gif si es necesario
    }
    if(this->fabrica->hiloEntapador->isWorking){
        this->ui->bandaEntapadas->movie()->setPaused(this->fabrica->bandaEntapadas->primerBotella == NULL);//pausa el gif si es necesario
    }

    this->ui->infoBandaColocadas->item(0,0)->setText(QString::number(this->fabrica->bandaColocadas->largo()));//coloco la cantidad de botellas actualmente en la banda
    this->ui->infoBandaLimpias1->item(0,0)->setText(QString::number(this->fabrica->bandaLimpiadas1->largo()));//coloco la cantidad de botellas actualmente en la banda
    this->ui->infoBandaLimpias2->item(0,0)->setText(QString::number(this->fabrica->bandaLimpiadas2->largo()));//coloco la cantidad de botellas actualmente en la banda
    this->ui->infoBandaLlenas->item(0,0)->setText(QString::number(this->fabrica->bandaLlenadas->largo()));
    this->ui->infoBandaEntapadas->item(0,0)->setText(QString::number(this->fabrica->bandaEntapadas->largo()));


    //coloco todos los contadores
    for(int i = 0; i < this->fabrica->listaBotellas->largo(); i++){
        this->ui->contadoresColocador->item(i,1)->setText(QString::number(this->fabrica->hiloColocaBotellas->contadores[i]));//coloco la cantidad de botellas colocadas respectivas
        this->ui->contadoresLimpiador->item(i,1)->setText(QString::number(this->fabrica->hiloLimpiaBotellas->contadores[i]));//coloco la cantidad de botellas limpiadas respectivas
        this->ui->contadoresLlenador1->item(i,1)->setText(QString::number(this->fabrica->hilollenaBotellas1->contadores[i]));//coloco la cantidad de botellas llenas respectivas
        this->ui->contadoresLlenador2->item(i,1)->setText(QString::number(this->fabrica->hilollenaBotellas2->contadores[i]));//coloco la cantidad de botellas llenas respectivas
        this->ui->contadoresEntapador->item(i,1)->setText(QString::number(this->fabrica->hiloEntapador->contadores[i]));//coloco la cantidad de botellas entapadas respectivas
        this->ui->contadoresInspeccionador->item(i,1)->setText(QString::number(this->fabrica->hiloInspeccionador->contadoresAprobadas[i]));
        this->ui->contadoresInspeccionador->item(i,2)->setText(QString::number(this->fabrica->hiloInspeccionador->contadoresDesechadas[i]));
    }
}

void FabricaWindow::cambiarParametros(){
    //tengo que actualizar las máquinas que se desea que estén en marcha ahora mismo
    this->fabrica->hiloColocaBotellas->pausa = !this->ui->colocaBotellasActivo->isChecked();
    this->fabrica->hiloLimpiaBotellas->pausa = !this->ui->limpiaBotellasActivo->isChecked();
    this->fabrica->hilollenaBotellas1->pausa = !this->ui->llenaBotellasActivo1->isChecked();
    this->fabrica->hilollenaBotellas2->pausa = !this->ui->llenaBotellasActivo2->isChecked();
    this->fabrica->hiloEntapador->pausa = !this->ui->entapaBotellasActivo->isChecked();
    this->fabrica->hiloInspeccionador->pausa = !this->ui->inspeccionaBotellasActivo->isChecked();

    int probabilidadActual = 0;//si esto se vuelve diferente a 100, entonces los nuevos porcentajes de colocación
    //no son apropiados, así que no actualiza los valores internos
    for(int i = 0; i < this->fabrica->listaBotellas->largo(); i++){//tengo que revisar todas las filas de la tabla del colocador
        if(probabilidadActual > 100 || this->ui->contadoresColocador->item(i,2)->text().compare("") == 0){//si se pasó de 100 o si no fue colocada información en una casilla entonces los valores no son apropiados
            probabilidadActual = 0;//señal de error
            break;//termina de recorrer
        }
        probabilidadActual+= this->ui->contadoresColocador->item(i,2)->text().toInt();//sigue sumando revisando los valores
    }
    //ahora tengo que revisar si dio menor a 100
    if(probabilidadActual != 100){//no se deben actualizar los valores internos de la fábrica
        //así que reinicio los contadores
        for(int i = 0; i< this->fabrica->listaBotellas->largo();i++){
            this->ui->contadoresColocador->item(i,2)->setText(QString::number(this->fabrica->listaBotellas->get(this->fabrica->listaBotellas->indexOf(this->ui->contadoresColocador->item(i,0)->text().toInt()))->botellaNodo->cantidadDeRefresco));
        }
    }
    else{
        //actualizo los valores internos de la fábrica, pues los datos son correctos
        for(int i = 0; i < this->fabrica->listaBotellas->largo();i++){
            this->fabrica->listaBotellas->get(this->fabrica->listaBotellas->indexOf(this->ui->contadoresColocador->item(i,0)->text().toInt()))->botellaNodo->probabilidadDeColocar = this->ui->contadoresColocador->item(i,2)->text().toInt();
        }
    }

    //ahora los máximos de las bandas transportadoras
    if(this->ui->infoBandaColocadas->item(0,1)->text().compare("") != 0){//hay algún cambio en el text edit
        this->fabrica->bandaColocadas->maximoBotellas = this->ui->infoBandaColocadas->item(0,1)->text().toInt();//hace el campo en la fábrica igual al text edit
    }
    else{
        //reinicio los valores externos al valor interno de la fábrica
        this->ui->infoBandaColocadas->item(0,1)->setText(QString::number(this->fabrica->bandaColocadas->maximoBotellas));
    }
    if(this->ui->infoBandaLimpias1->item(0,1)->text().compare("") != 0){//hay algún cambio en el text edit
        this->fabrica->bandaLimpiadas1->maximoBotellas = this->ui->infoBandaLimpias1->item(0,1)->text().toInt();//hace el campo en la fábrica igual al text edit
    }
    else{
        //reinicio los valores externos al valor interno de la fábrica
        this->ui->infoBandaLimpias1->item(0,1)->setText(QString::number(this->fabrica->bandaLimpiadas1->maximoBotellas));
    }
    if(this->ui->infoBandaLimpias2->item(0,1)->text().compare("") != 0){//hay algún cambio en el text edit
        this->fabrica->bandaLimpiadas2->maximoBotellas = this->ui->infoBandaLimpias2->item(0,1)->text().toInt();//hace el campo en la fábrica igual al text edit
    }
    else{
        //reinicio los valores externos al valor interno de la fábrica
        this->ui->infoBandaLimpias2->item(0,1)->setText(QString::number(this->fabrica->bandaLimpiadas2->maximoBotellas));
    }
    if(this->ui->infoBandaLlenas->item(0,1)->text().compare("") != 0){//hay algún cambio en el text edit
        this->fabrica->bandaLlenadas->maximoBotellas = this->ui->infoBandaLlenas->item(0,1)->text().toInt();//hace el campo en la fábrica igual al text edit
    }
    else{
        //reinicio los valores externos al valor interno de la fábrica
        this->ui->infoBandaLlenas->item(0,1)->setText(QString::number(this->fabrica->bandaLlenadas->maximoBotellas));
    }
    if(this->ui->infoBandaEntapadas->item(0,1)->text().compare("") != 0){//hay algún cambio en el text edit
        this->fabrica->bandaEntapadas->maximoBotellas = this->ui->infoBandaEntapadas->item(0,1)->text().toInt();//hace el campo en la fábrica igual al text edit
    }
    else{
        //reinicio los valores externos al valor interno de la fábrica
        this->ui->infoBandaEntapadas->item(0,1)->setText(QString::number(this->fabrica->bandaEntapadas->maximoBotellas));
    }


}
