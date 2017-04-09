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
