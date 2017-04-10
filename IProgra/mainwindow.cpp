#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::agregarBotella
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la MainWindow
 * Lo que hace es que agrega una nueva botella dentro de la tabla preliminar de botellas
 */
void MainWindow::agregarBotella(){
    if(this->ui->cantidadRefresco->text().compare("") != 0 && this->ui->probabilidadColocar->text().compare("") != 0 && this->ui->probabilidadDesecho->text().compare("")){//si los tres poseen texto dentro de ellos

        int filaAInsertar = this->ui->botellas->rowCount();//consigue el número de la fila que se va a insertar
        this->ui->botellas->insertRow(filaAInsertar);//inserta la nueva fila en la QTable
        //ahora lo que falta es modificar el item
        this->ui->botellas->setItem(filaAInsertar,0,new QTableWidgetItem(this->ui->cantidadRefresco->text()));//coloca la cantidad de refresco en la QTable
        this->ui->botellas->setItem(filaAInsertar,1,new QTableWidgetItem(this->ui->probabilidadColocar->text()));//coloca la probabilidad de colocar en la QTable
        this->ui->botellas->setItem(filaAInsertar,2,new QTableWidgetItem(this->ui->probabilidadDesecho->text()));//coloca la probabilidad de desecho en la QTable
        //ahora por estética limpio los line edits
        this->ui->cantidadRefresco->setText("");
        this->ui->probabilidadColocar->setText("");
        this->ui->probabilidadDesecho->setText("");
    }
}

/**
 * @brief MainWindow::eliminarBotella
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la MainWindow
 * Lo que hace es que elimina una botella en la posición i de la tabla preliminar de botellas
 */
void MainWindow::eliminarBotella(){
    if(this->ui->spinEliminar->value() < this->ui->botellas->rowCount()){//si el índice del spinner de eliminación cabe en el QTable
        this->ui->botellas->removeRow(this->ui->spinEliminar->value());//elimina el row en la posición del spinner
    }
}

/**
 * @brief MainWindow::iniciarSimulacion
 * Esta es la función llamada por el public slot del mismo nombre perteneciente a la MainWindow
 * Lo que hace es recopilar todos los datos de la ventana configuradora dentro de un paquete para configurar la Fábrica
 */
void MainWindow::iniciarSimulacion(){

    //primero tengo que validar los porcentajes de colocación de las botellas
    int porcentajeTotal = 0;
    for(int i = 0; i < this->ui->botellas->rowCount(); i++){
        porcentajeTotal += this->ui->botellas->item(i,1)->text().toInt();
    }

    if(porcentajeTotal == 100){//si el porcentaje fue correcto, entonces arranca la nueva simulación
        //primero tengo que tomar todos los datos de la QTable y unirlos todos en la misma lista de botellas
        ListaBotellas * listaBotellas = new ListaBotellas();//nueva lista
        for(int i = 0; i < this->ui->botellas->rowCount(); i++){//para cada una de las filas dentro de la QTable
            //tengo que agregar cada botella
            listaBotellas->agregar(new NodoBotella(new Botella(this->ui->botellas->item(i,0)->text().toInt(),this->ui->botellas->item(i,1)->text().toInt(),this->ui->botellas->item(i,2)->text().toInt())));
        }
        //ahora agrego todos los datos a la configuración
        Configuracion * config = new Configuracion(listaBotellas,this->ui->tiempoColocacion->text().toInt(),this->ui->tiempoLimpieza->text().toInt(),this->ui->tiempoLlenado1->text().toInt(),this->ui->tiempoLlenado2->text().toInt(), this->ui->tiempoEntapado->text().toInt(), this->ui->tiempoInspeccion->text().toInt(), this->ui->capacidadColocadas->text().toInt(), this->ui->capacidadLimpias1->text().toInt(), this->ui->capacidadLimpias2->text().toInt(), this->ui->capacidadLlenas->text().toInt(), this->ui->capacidadEntapadas->text().toInt());
        Fabrica * fabrica = new Fabrica(config);
        FabricaWindow * ventanaSimulacion = new FabricaWindow(NULL, fabrica);
        ventanaSimulacion->show();
        this->close();
    }
}
