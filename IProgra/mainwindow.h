#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "configuracion.h"//para poder crear el paquete de parámetros
#include "fabrica.h"//para poder crear una nueva fábrica
#include "fabricawindow.h"//para que pueda crear una nueva ventana

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void agregarBotella();
    void eliminarBotella();
    void iniciarSimulacion();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
