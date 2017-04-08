#include "fabricawindow.h"
#include "ui_fabricawindow.h"

FabricaWindow::FabricaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FabricaWindow)
{
    ui->setupUi(this);
}

FabricaWindow::~FabricaWindow()
{
    delete ui;
}
