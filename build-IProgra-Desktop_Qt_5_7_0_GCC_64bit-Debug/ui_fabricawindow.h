/********************************************************************************
** Form generated from reading UI file 'fabricawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FABRICAWINDOW_H
#define UI_FABRICAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FabricaWindow
{
public:
    QWidget *centralwidget;
    QPushButton *iniciarSimulacion;
    QPushButton *reiniciarSimulacion;
    QPushButton *pararSimulacion;
    QPushButton *pausarSimulacion;
    QCheckBox *colocaBotellasActivo;
    QCheckBox *limpiaBotellasActivo;
    QCheckBox *llenaBotellasActivo1;
    QCheckBox *llenaBotellasActivo2;
    QCheckBox *entapaBotellasActivo;
    QPushButton *cambiarParametros;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *velocidadLlenador1;
    QLineEdit *velocidadLimpiador;
    QLineEdit *velocidadEntapador;
    QLineEdit *velocidadLlenador2;
    QLabel *label_7;
    QLineEdit *velocidadColocador;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QTableWidget *contadoresColocador;
    QTableWidget *contadoresLlenador1;
    QTableWidget *contadoresLimpiador;
    QTableWidget *contadoresEntapador;
    QTableWidget *contadoresLlenador2;
    QLabel *label_13;
    QTableWidget *infoBandaColocadas;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QCheckBox *inspeccionaBotellasActivo;
    QTableWidget *contadoresInspeccionador;
    QLabel *label_12;
    QLineEdit *velocidadInspeccionador;
    QLabel *label_6;
    QTableWidget *infoBandaLimpias1;
    QTableWidget *infoBandaLimpias2;
    QTableWidget *infoBandaLlenas;
    QTableWidget *infoBandaEntapadas;
    QLabel *bandaColocadas;
    QLabel *bandaLimpias1;
    QLabel *bandaLimpias2;
    QLabel *bandaLlenas;
    QLabel *bandaEntapadas;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FabricaWindow)
    {
        if (FabricaWindow->objectName().isEmpty())
            FabricaWindow->setObjectName(QStringLiteral("FabricaWindow"));
        FabricaWindow->resize(1366, 721);
        centralwidget = new QWidget(FabricaWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        iniciarSimulacion = new QPushButton(centralwidget);
        iniciarSimulacion->setObjectName(QStringLiteral("iniciarSimulacion"));
        iniciarSimulacion->setGeometry(QRect(40, 621, 51, 51));
        QFont font;
        font.setPointSize(9);
        iniciarSimulacion->setFont(font);
        iniciarSimulacion->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QStringLiteral(":/botones/botones/Flecha Derecha.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        iniciarSimulacion->setIcon(icon);
        iniciarSimulacion->setIconSize(QSize(50, 50));
        reiniciarSimulacion = new QPushButton(centralwidget);
        reiniciarSimulacion->setObjectName(QStringLiteral("reiniciarSimulacion"));
        reiniciarSimulacion->setGeometry(QRect(160, 620, 51, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/botones/botones/Flecha Reiniciar.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        reiniciarSimulacion->setIcon(icon1);
        reiniciarSimulacion->setIconSize(QSize(50, 50));
        pararSimulacion = new QPushButton(centralwidget);
        pararSimulacion->setObjectName(QStringLiteral("pararSimulacion"));
        pararSimulacion->setGeometry(QRect(220, 620, 51, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/botones/botones/Cuadro Parar.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pararSimulacion->setIcon(icon2);
        pararSimulacion->setIconSize(QSize(50, 50));
        pausarSimulacion = new QPushButton(centralwidget);
        pausarSimulacion->setObjectName(QStringLiteral("pausarSimulacion"));
        pausarSimulacion->setGeometry(QRect(100, 620, 51, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/botones/botones/pausa azul.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pausarSimulacion->setIcon(icon3);
        pausarSimulacion->setIconSize(QSize(50, 50));
        colocaBotellasActivo = new QCheckBox(centralwidget);
        colocaBotellasActivo->setObjectName(QStringLiteral("colocaBotellasActivo"));
        colocaBotellasActivo->setGeometry(QRect(30, 30, 121, 20));
        colocaBotellasActivo->setChecked(true);
        limpiaBotellasActivo = new QCheckBox(centralwidget);
        limpiaBotellasActivo->setObjectName(QStringLiteral("limpiaBotellasActivo"));
        limpiaBotellasActivo->setGeometry(QRect(910, 70, 121, 20));
        limpiaBotellasActivo->setChecked(true);
        llenaBotellasActivo1 = new QCheckBox(centralwidget);
        llenaBotellasActivo1->setObjectName(QStringLiteral("llenaBotellasActivo1"));
        llenaBotellasActivo1->setGeometry(QRect(770, 300, 121, 20));
        llenaBotellasActivo1->setChecked(true);
        llenaBotellasActivo2 = new QCheckBox(centralwidget);
        llenaBotellasActivo2->setObjectName(QStringLiteral("llenaBotellasActivo2"));
        llenaBotellasActivo2->setGeometry(QRect(1150, 300, 121, 20));
        llenaBotellasActivo2->setChecked(true);
        entapaBotellasActivo = new QCheckBox(centralwidget);
        entapaBotellasActivo->setObjectName(QStringLiteral("entapaBotellasActivo"));
        entapaBotellasActivo->setGeometry(QRect(960, 520, 121, 20));
        entapaBotellasActivo->setChecked(true);
        cambiarParametros = new QPushButton(centralwidget);
        cambiarParametros->setObjectName(QStringLiteral("cambiarParametros"));
        cambiarParametros->setGeometry(QRect(280, 620, 131, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 71, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(740, 330, 71, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(920, 100, 71, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(930, 550, 71, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1130, 330, 71, 21));
        velocidadLlenador1 = new QLineEdit(centralwidget);
        velocidadLlenador1->setObjectName(QStringLiteral("velocidadLlenador1"));
        velocidadLlenador1->setGeometry(QRect(810, 330, 41, 22));
        velocidadLimpiador = new QLineEdit(centralwidget);
        velocidadLimpiador->setObjectName(QStringLiteral("velocidadLimpiador"));
        velocidadLimpiador->setGeometry(QRect(990, 100, 41, 22));
        velocidadEntapador = new QLineEdit(centralwidget);
        velocidadEntapador->setObjectName(QStringLiteral("velocidadEntapador"));
        velocidadEntapador->setGeometry(QRect(1000, 550, 41, 22));
        velocidadLlenador2 = new QLineEdit(centralwidget);
        velocidadLlenador2->setObjectName(QStringLiteral("velocidadLlenador2"));
        velocidadLlenador2->setGeometry(QRect(1200, 330, 41, 22));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 70, 59, 20));
        velocidadColocador = new QLineEdit(centralwidget);
        velocidadColocador->setObjectName(QStringLiteral("velocidadColocador"));
        velocidadColocador->setGeometry(QRect(100, 70, 41, 22));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(860, 330, 59, 20));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1040, 100, 59, 20));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1050, 550, 59, 20));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1250, 330, 59, 20));
        contadoresColocador = new QTableWidget(centralwidget);
        if (contadoresColocador->columnCount() < 3)
            contadoresColocador->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        contadoresColocador->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        contadoresColocador->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        contadoresColocador->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        contadoresColocador->setObjectName(QStringLiteral("contadoresColocador"));
        contadoresColocador->setGeometry(QRect(20, 100, 301, 91));
        contadoresColocador->horizontalHeader()->setDefaultSectionSize(99);
        contadoresColocador->verticalHeader()->setVisible(false);
        contadoresLlenador1 = new QTableWidget(centralwidget);
        if (contadoresLlenador1->columnCount() < 2)
            contadoresLlenador1->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        contadoresLlenador1->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        contadoresLlenador1->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        contadoresLlenador1->setObjectName(QStringLiteral("contadoresLlenador1"));
        contadoresLlenador1->setGeometry(QRect(720, 360, 201, 91));
        contadoresLlenador1->horizontalHeader()->setDefaultSectionSize(99);
        contadoresLlenador1->verticalHeader()->setVisible(false);
        contadoresLimpiador = new QTableWidget(centralwidget);
        if (contadoresLimpiador->columnCount() < 2)
            contadoresLimpiador->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        contadoresLimpiador->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        contadoresLimpiador->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        contadoresLimpiador->setObjectName(QStringLiteral("contadoresLimpiador"));
        contadoresLimpiador->setGeometry(QRect(910, 130, 201, 91));
        contadoresLimpiador->horizontalHeader()->setDefaultSectionSize(99);
        contadoresLimpiador->verticalHeader()->setVisible(false);
        contadoresEntapador = new QTableWidget(centralwidget);
        if (contadoresEntapador->columnCount() < 2)
            contadoresEntapador->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        contadoresEntapador->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        contadoresEntapador->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        contadoresEntapador->setObjectName(QStringLiteral("contadoresEntapador"));
        contadoresEntapador->setGeometry(QRect(920, 580, 201, 91));
        contadoresEntapador->horizontalHeader()->setDefaultSectionSize(99);
        contadoresEntapador->verticalHeader()->setVisible(false);
        contadoresLlenador2 = new QTableWidget(centralwidget);
        if (contadoresLlenador2->columnCount() < 2)
            contadoresLlenador2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        contadoresLlenador2->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        contadoresLlenador2->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        contadoresLlenador2->setObjectName(QStringLiteral("contadoresLlenador2"));
        contadoresLlenador2->setGeometry(QRect(1110, 360, 201, 91));
        contadoresLlenador2->horizontalHeader()->setDefaultSectionSize(99);
        contadoresLlenador2->verticalHeader()->setVisible(false);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(550, 90, 161, 16));
        label_13->setAlignment(Qt::AlignCenter);
        infoBandaColocadas = new QTableWidget(centralwidget);
        if (infoBandaColocadas->columnCount() < 2)
            infoBandaColocadas->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        infoBandaColocadas->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        infoBandaColocadas->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        if (infoBandaColocadas->rowCount() < 1)
            infoBandaColocadas->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        infoBandaColocadas->setVerticalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        infoBandaColocadas->setItem(0, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        infoBandaColocadas->setItem(0, 1, __qtablewidgetitem15);
        infoBandaColocadas->setObjectName(QStringLiteral("infoBandaColocadas"));
        infoBandaColocadas->setGeometry(QRect(550, 110, 161, 51));
        infoBandaColocadas->horizontalHeader()->setDefaultSectionSize(79);
        infoBandaColocadas->verticalHeader()->setVisible(false);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(940, 440, 161, 16));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(740, 220, 161, 16));
        label_15->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(1130, 220, 161, 16));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(690, 570, 161, 16));
        label_17->setAlignment(Qt::AlignCenter);
        inspeccionaBotellasActivo = new QCheckBox(centralwidget);
        inspeccionaBotellasActivo->setObjectName(QStringLiteral("inspeccionaBotellasActivo"));
        inspeccionaBotellasActivo->setGeometry(QRect(280, 440, 161, 20));
        inspeccionaBotellasActivo->setChecked(true);
        contadoresInspeccionador = new QTableWidget(centralwidget);
        if (contadoresInspeccionador->columnCount() < 4)
            contadoresInspeccionador->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        contadoresInspeccionador->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        contadoresInspeccionador->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        contadoresInspeccionador->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        contadoresInspeccionador->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        contadoresInspeccionador->setObjectName(QStringLiteral("contadoresInspeccionador"));
        contadoresInspeccionador->setGeometry(QRect(200, 520, 401, 91));
        contadoresInspeccionador->horizontalHeader()->setDefaultSectionSize(99);
        contadoresInspeccionador->verticalHeader()->setVisible(false);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(390, 480, 59, 20));
        velocidadInspeccionador = new QLineEdit(centralwidget);
        velocidadInspeccionador->setObjectName(QStringLiteral("velocidadInspeccionador"));
        velocidadInspeccionador->setGeometry(QRect(340, 480, 41, 22));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(270, 480, 71, 21));
        infoBandaLimpias1 = new QTableWidget(centralwidget);
        if (infoBandaLimpias1->columnCount() < 2)
            infoBandaLimpias1->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        infoBandaLimpias1->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        infoBandaLimpias1->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        if (infoBandaLimpias1->rowCount() < 1)
            infoBandaLimpias1->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        infoBandaLimpias1->setVerticalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        infoBandaLimpias1->setItem(0, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        infoBandaLimpias1->setItem(0, 1, __qtablewidgetitem24);
        infoBandaLimpias1->setObjectName(QStringLiteral("infoBandaLimpias1"));
        infoBandaLimpias1->setGeometry(QRect(740, 240, 161, 51));
        infoBandaLimpias1->horizontalHeader()->setDefaultSectionSize(79);
        infoBandaLimpias1->verticalHeader()->setVisible(false);
        infoBandaLimpias2 = new QTableWidget(centralwidget);
        if (infoBandaLimpias2->columnCount() < 2)
            infoBandaLimpias2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        infoBandaLimpias2->setHorizontalHeaderItem(0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        infoBandaLimpias2->setHorizontalHeaderItem(1, __qtablewidgetitem26);
        if (infoBandaLimpias2->rowCount() < 1)
            infoBandaLimpias2->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        infoBandaLimpias2->setVerticalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        infoBandaLimpias2->setItem(0, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        infoBandaLimpias2->setItem(0, 1, __qtablewidgetitem29);
        infoBandaLimpias2->setObjectName(QStringLiteral("infoBandaLimpias2"));
        infoBandaLimpias2->setGeometry(QRect(1130, 240, 161, 51));
        infoBandaLimpias2->horizontalHeader()->setDefaultSectionSize(79);
        infoBandaLimpias2->verticalHeader()->setVisible(false);
        infoBandaLlenas = new QTableWidget(centralwidget);
        if (infoBandaLlenas->columnCount() < 2)
            infoBandaLlenas->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        infoBandaLlenas->setHorizontalHeaderItem(0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        infoBandaLlenas->setHorizontalHeaderItem(1, __qtablewidgetitem31);
        if (infoBandaLlenas->rowCount() < 1)
            infoBandaLlenas->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        infoBandaLlenas->setVerticalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        infoBandaLlenas->setItem(0, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        infoBandaLlenas->setItem(0, 1, __qtablewidgetitem34);
        infoBandaLlenas->setObjectName(QStringLiteral("infoBandaLlenas"));
        infoBandaLlenas->setGeometry(QRect(940, 460, 161, 51));
        infoBandaLlenas->horizontalHeader()->setDefaultSectionSize(79);
        infoBandaLlenas->verticalHeader()->setVisible(false);
        infoBandaEntapadas = new QTableWidget(centralwidget);
        if (infoBandaEntapadas->columnCount() < 2)
            infoBandaEntapadas->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        infoBandaEntapadas->setHorizontalHeaderItem(0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        infoBandaEntapadas->setHorizontalHeaderItem(1, __qtablewidgetitem36);
        if (infoBandaEntapadas->rowCount() < 1)
            infoBandaEntapadas->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        infoBandaEntapadas->setVerticalHeaderItem(0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        infoBandaEntapadas->setItem(0, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        infoBandaEntapadas->setItem(0, 1, __qtablewidgetitem39);
        infoBandaEntapadas->setObjectName(QStringLiteral("infoBandaEntapadas"));
        infoBandaEntapadas->setGeometry(QRect(690, 590, 161, 51));
        infoBandaEntapadas->horizontalHeader()->setDefaultSectionSize(79);
        infoBandaEntapadas->verticalHeader()->setVisible(false);
        bandaColocadas = new QLabel(centralwidget);
        bandaColocadas->setObjectName(QStringLiteral("bandaColocadas"));
        bandaColocadas->setGeometry(QRect(350, 100, 181, 50));
        bandaLimpias1 = new QLabel(centralwidget);
        bandaLimpias1->setObjectName(QStringLiteral("bandaLimpias1"));
        bandaLimpias1->setGeometry(QRect(730, 140, 181, 50));
        bandaLimpias2 = new QLabel(centralwidget);
        bandaLimpias2->setObjectName(QStringLiteral("bandaLimpias2"));
        bandaLimpias2->setGeometry(QRect(1120, 140, 181, 50));
        bandaLlenas = new QLabel(centralwidget);
        bandaLlenas->setObjectName(QStringLiteral("bandaLlenas"));
        bandaLlenas->setGeometry(QRect(920, 360, 181, 50));
        bandaEntapadas = new QLabel(centralwidget);
        bandaEntapadas->setObjectName(QStringLiteral("bandaEntapadas"));
        bandaEntapadas->setGeometry(QRect(670, 490, 181, 50));
        FabricaWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FabricaWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1366, 19));
        FabricaWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(FabricaWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FabricaWindow->setStatusBar(statusbar);

        retranslateUi(FabricaWindow);
        QObject::connect(iniciarSimulacion, SIGNAL(clicked()), FabricaWindow, SLOT(iniciarSimulacion()));
        QObject::connect(pausarSimulacion, SIGNAL(clicked()), FabricaWindow, SLOT(pausarSimulacion()));
        QObject::connect(reiniciarSimulacion, SIGNAL(clicked()), FabricaWindow, SLOT(reiniciarSimulacion()));
        QObject::connect(pararSimulacion, SIGNAL(clicked()), FabricaWindow, SLOT(pararSimulacion()));
        QObject::connect(cambiarParametros, SIGNAL(clicked()), FabricaWindow, SLOT(cambiarParametros()));
        QObject::connect(colocaBotellasActivo, SIGNAL(stateChanged(int)), FabricaWindow, SLOT(cambiarParametros()));
        QObject::connect(limpiaBotellasActivo, SIGNAL(stateChanged(int)), FabricaWindow, SLOT(cambiarParametros()));
        QObject::connect(llenaBotellasActivo2, SIGNAL(stateChanged(int)), FabricaWindow, SLOT(cambiarParametros()));
        QObject::connect(llenaBotellasActivo1, SIGNAL(stateChanged(int)), FabricaWindow, SLOT(cambiarParametros()));
        QObject::connect(entapaBotellasActivo, SIGNAL(stateChanged(int)), FabricaWindow, SLOT(cambiarParametros()));
        QObject::connect(inspeccionaBotellasActivo, SIGNAL(stateChanged(int)), FabricaWindow, SLOT(cambiarParametros()));

        QMetaObject::connectSlotsByName(FabricaWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FabricaWindow)
    {
        FabricaWindow->setWindowTitle(QApplication::translate("FabricaWindow", "F\303\241brica", 0));
        iniciarSimulacion->setText(QString());
        reiniciarSimulacion->setText(QString());
        pararSimulacion->setText(QString());
        pausarSimulacion->setText(QString());
        colocaBotellasActivo->setText(QApplication::translate("FabricaWindow", "Coloca Botellas", 0));
        limpiaBotellasActivo->setText(QApplication::translate("FabricaWindow", "Limpia Botellas", 0));
        llenaBotellasActivo1->setText(QApplication::translate("FabricaWindow", "Llena Botellas 1", 0));
        llenaBotellasActivo2->setText(QApplication::translate("FabricaWindow", "Llena Botellas 2", 0));
        entapaBotellasActivo->setText(QApplication::translate("FabricaWindow", "Entapa Botellas", 0));
        cambiarParametros->setText(QApplication::translate("FabricaWindow", "Cambiar Par\303\241metros", 0));
        label->setText(QApplication::translate("FabricaWindow", "Velocidad:", 0));
        label_2->setText(QApplication::translate("FabricaWindow", "Velocidad:", 0));
        label_3->setText(QApplication::translate("FabricaWindow", "Velocidad:", 0));
        label_4->setText(QApplication::translate("FabricaWindow", "Velocidad:", 0));
        label_5->setText(QApplication::translate("FabricaWindow", "Velocidad:", 0));
        velocidadLlenador1->setText(QApplication::translate("FabricaWindow", "2", 0));
        velocidadLimpiador->setText(QApplication::translate("FabricaWindow", "2", 0));
        velocidadEntapador->setText(QApplication::translate("FabricaWindow", "2", 0));
        velocidadLlenador2->setText(QApplication::translate("FabricaWindow", "2", 0));
        label_7->setText(QApplication::translate("FabricaWindow", "Segundos", 0));
        velocidadColocador->setText(QApplication::translate("FabricaWindow", "2", 0));
        label_8->setText(QApplication::translate("FabricaWindow", "Segundos", 0));
        label_9->setText(QApplication::translate("FabricaWindow", "Segundos", 0));
        label_10->setText(QApplication::translate("FabricaWindow", "Segundos", 0));
        label_11->setText(QApplication::translate("FabricaWindow", "Segundos", 0));
        QTableWidgetItem *___qtablewidgetitem = contadoresColocador->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FabricaWindow", "Tama\303\261os", 0));
        QTableWidgetItem *___qtablewidgetitem1 = contadoresColocador->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FabricaWindow", "Colocadas", 0));
        QTableWidgetItem *___qtablewidgetitem2 = contadoresColocador->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FabricaWindow", "Porcentaje", 0));
        QTableWidgetItem *___qtablewidgetitem3 = contadoresLlenador1->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("FabricaWindow", "Tama\303\261os", 0));
        QTableWidgetItem *___qtablewidgetitem4 = contadoresLlenador1->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("FabricaWindow", "Llenadas", 0));
        QTableWidgetItem *___qtablewidgetitem5 = contadoresLimpiador->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("FabricaWindow", "Tama\303\261os", 0));
        QTableWidgetItem *___qtablewidgetitem6 = contadoresLimpiador->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("FabricaWindow", "Limpiadas", 0));
        QTableWidgetItem *___qtablewidgetitem7 = contadoresEntapador->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("FabricaWindow", "Tama\303\261os", 0));
        QTableWidgetItem *___qtablewidgetitem8 = contadoresEntapador->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("FabricaWindow", "Entapadas", 0));
        QTableWidgetItem *___qtablewidgetitem9 = contadoresLlenador2->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("FabricaWindow", "Tama\303\261os", 0));
        QTableWidgetItem *___qtablewidgetitem10 = contadoresLlenador2->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("FabricaWindow", "Llenadas", 0));
        label_13->setText(QApplication::translate("FabricaWindow", "Banda Transportadora", 0));
        QTableWidgetItem *___qtablewidgetitem11 = infoBandaColocadas->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("FabricaWindow", "Actual", 0));
        QTableWidgetItem *___qtablewidgetitem12 = infoBandaColocadas->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("FabricaWindow", "M\303\241ximo", 0));
        QTableWidgetItem *___qtablewidgetitem13 = infoBandaColocadas->verticalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("FabricaWindow", "1", 0));

        const bool __sortingEnabled = infoBandaColocadas->isSortingEnabled();
        infoBandaColocadas->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem14 = infoBandaColocadas->item(0, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("FabricaWindow", "0", 0));
        QTableWidgetItem *___qtablewidgetitem15 = infoBandaColocadas->item(0, 1);
        ___qtablewidgetitem15->setText(QApplication::translate("FabricaWindow", "0", 0));
        infoBandaColocadas->setSortingEnabled(__sortingEnabled);

        label_14->setText(QApplication::translate("FabricaWindow", "Banda Transportadora", 0));
        label_15->setText(QApplication::translate("FabricaWindow", "Banda Transportadora", 0));
        label_16->setText(QApplication::translate("FabricaWindow", "Banda Transportadora", 0));
        label_17->setText(QApplication::translate("FabricaWindow", "Banda Transportadora", 0));
        inspeccionaBotellasActivo->setText(QApplication::translate("FabricaWindow", "Inspecciona Botellas", 0));
        QTableWidgetItem *___qtablewidgetitem16 = contadoresInspeccionador->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("FabricaWindow", "Tama\303\261os", 0));
        QTableWidgetItem *___qtablewidgetitem17 = contadoresInspeccionador->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("FabricaWindow", "Aprobadas", 0));
        QTableWidgetItem *___qtablewidgetitem18 = contadoresInspeccionador->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("FabricaWindow", "Rechazadas", 0));
        QTableWidgetItem *___qtablewidgetitem19 = contadoresInspeccionador->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("FabricaWindow", "Probabilidades", 0));
        label_12->setText(QApplication::translate("FabricaWindow", "Segundos", 0));
        velocidadInspeccionador->setText(QApplication::translate("FabricaWindow", "2", 0));
        label_6->setText(QApplication::translate("FabricaWindow", "Velocidad:", 0));
        QTableWidgetItem *___qtablewidgetitem20 = infoBandaLimpias1->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("FabricaWindow", "Actual", 0));
        QTableWidgetItem *___qtablewidgetitem21 = infoBandaLimpias1->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("FabricaWindow", "M\303\241ximo", 0));
        QTableWidgetItem *___qtablewidgetitem22 = infoBandaLimpias1->verticalHeaderItem(0);
        ___qtablewidgetitem22->setText(QApplication::translate("FabricaWindow", "1", 0));

        const bool __sortingEnabled1 = infoBandaLimpias1->isSortingEnabled();
        infoBandaLimpias1->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem23 = infoBandaLimpias1->item(0, 0);
        ___qtablewidgetitem23->setText(QApplication::translate("FabricaWindow", "0", 0));
        QTableWidgetItem *___qtablewidgetitem24 = infoBandaLimpias1->item(0, 1);
        ___qtablewidgetitem24->setText(QApplication::translate("FabricaWindow", "0", 0));
        infoBandaLimpias1->setSortingEnabled(__sortingEnabled1);

        QTableWidgetItem *___qtablewidgetitem25 = infoBandaLimpias2->horizontalHeaderItem(0);
        ___qtablewidgetitem25->setText(QApplication::translate("FabricaWindow", "Actual", 0));
        QTableWidgetItem *___qtablewidgetitem26 = infoBandaLimpias2->horizontalHeaderItem(1);
        ___qtablewidgetitem26->setText(QApplication::translate("FabricaWindow", "M\303\241ximo", 0));
        QTableWidgetItem *___qtablewidgetitem27 = infoBandaLimpias2->verticalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("FabricaWindow", "1", 0));

        const bool __sortingEnabled2 = infoBandaLimpias2->isSortingEnabled();
        infoBandaLimpias2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem28 = infoBandaLimpias2->item(0, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("FabricaWindow", "0", 0));
        QTableWidgetItem *___qtablewidgetitem29 = infoBandaLimpias2->item(0, 1);
        ___qtablewidgetitem29->setText(QApplication::translate("FabricaWindow", "0", 0));
        infoBandaLimpias2->setSortingEnabled(__sortingEnabled2);

        QTableWidgetItem *___qtablewidgetitem30 = infoBandaLlenas->horizontalHeaderItem(0);
        ___qtablewidgetitem30->setText(QApplication::translate("FabricaWindow", "Actual", 0));
        QTableWidgetItem *___qtablewidgetitem31 = infoBandaLlenas->horizontalHeaderItem(1);
        ___qtablewidgetitem31->setText(QApplication::translate("FabricaWindow", "M\303\241ximo", 0));
        QTableWidgetItem *___qtablewidgetitem32 = infoBandaLlenas->verticalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("FabricaWindow", "1", 0));

        const bool __sortingEnabled3 = infoBandaLlenas->isSortingEnabled();
        infoBandaLlenas->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem33 = infoBandaLlenas->item(0, 0);
        ___qtablewidgetitem33->setText(QApplication::translate("FabricaWindow", "0", 0));
        QTableWidgetItem *___qtablewidgetitem34 = infoBandaLlenas->item(0, 1);
        ___qtablewidgetitem34->setText(QApplication::translate("FabricaWindow", "0", 0));
        infoBandaLlenas->setSortingEnabled(__sortingEnabled3);

        QTableWidgetItem *___qtablewidgetitem35 = infoBandaEntapadas->horizontalHeaderItem(0);
        ___qtablewidgetitem35->setText(QApplication::translate("FabricaWindow", "Actual", 0));
        QTableWidgetItem *___qtablewidgetitem36 = infoBandaEntapadas->horizontalHeaderItem(1);
        ___qtablewidgetitem36->setText(QApplication::translate("FabricaWindow", "M\303\241ximo", 0));
        QTableWidgetItem *___qtablewidgetitem37 = infoBandaEntapadas->verticalHeaderItem(0);
        ___qtablewidgetitem37->setText(QApplication::translate("FabricaWindow", "1", 0));

        const bool __sortingEnabled4 = infoBandaEntapadas->isSortingEnabled();
        infoBandaEntapadas->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem38 = infoBandaEntapadas->item(0, 0);
        ___qtablewidgetitem38->setText(QApplication::translate("FabricaWindow", "0", 0));
        QTableWidgetItem *___qtablewidgetitem39 = infoBandaEntapadas->item(0, 1);
        ___qtablewidgetitem39->setText(QApplication::translate("FabricaWindow", "0", 0));
        infoBandaEntapadas->setSortingEnabled(__sortingEnabled4);

        bandaColocadas->setText(QString());
        bandaLimpias1->setText(QString());
        bandaLimpias2->setText(QString());
        bandaLlenas->setText(QString());
        bandaEntapadas->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FabricaWindow: public Ui_FabricaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FABRICAWINDOW_H
