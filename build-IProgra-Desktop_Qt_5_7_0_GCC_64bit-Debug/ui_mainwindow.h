/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *botellas;
    QLineEdit *cantidadRefresco;
    QPushButton *nuevaBotella;
    QLineEdit *probabilidadDesecho;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *probabilidadColocar;
    QLabel *label_4;
    QLineEdit *tiempoColocacion;
    QLabel *label_5;
    QLineEdit *tiempoLimpieza;
    QLineEdit *tiempoLlenado1;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *tiempoEntapado;
    QLabel *label_8;
    QLineEdit *tiempoInspeccion;
    QLabel *label_9;
    QLineEdit *capacidadColocadas;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *capacidadLimpias1;
    QLineEdit *capacidadLlenas;
    QLineEdit *capacidadEntapadas;
    QPushButton *Inicio;
    QLabel *label_13;
    QSpinBox *spinEliminar;
    QPushButton *eliminarBotella;
    QLabel *label_14;
    QLineEdit *capacidadLimpias2;
    QLabel *label_15;
    QLineEdit *tiempoLlenado2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(922, 475);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        botellas = new QTableWidget(centralWidget);
        if (botellas->columnCount() < 3)
            botellas->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        botellas->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        botellas->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        botellas->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        botellas->setObjectName(QStringLiteral("botellas"));
        botellas->setGeometry(QRect(20, 150, 481, 221));
        botellas->horizontalHeader()->setDefaultSectionSize(155);
        cantidadRefresco = new QLineEdit(centralWidget);
        cantidadRefresco->setObjectName(QStringLiteral("cantidadRefresco"));
        cantidadRefresco->setGeometry(QRect(20, 70, 151, 22));
        nuevaBotella = new QPushButton(centralWidget);
        nuevaBotella->setObjectName(QStringLiteral("nuevaBotella"));
        nuevaBotella->setGeometry(QRect(200, 110, 111, 22));
        probabilidadDesecho = new QLineEdit(centralWidget);
        probabilidadDesecho->setObjectName(QStringLiteral("probabilidadDesecho"));
        probabilidadDesecho->setGeometry(QRect(340, 70, 161, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 151, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 50, 161, 16));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 50, 151, 16));
        label_3->setAlignment(Qt::AlignCenter);
        probabilidadColocar = new QLineEdit(centralWidget);
        probabilidadColocar->setObjectName(QStringLiteral("probabilidadColocar"));
        probabilidadColocar->setGeometry(QRect(180, 70, 151, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(540, 50, 141, 16));
        tiempoColocacion = new QLineEdit(centralWidget);
        tiempoColocacion->setObjectName(QStringLiteral("tiempoColocacion"));
        tiempoColocacion->setGeometry(QRect(540, 70, 141, 22));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(540, 110, 141, 16));
        label_5->setAlignment(Qt::AlignCenter);
        tiempoLimpieza = new QLineEdit(centralWidget);
        tiempoLimpieza->setObjectName(QStringLiteral("tiempoLimpieza"));
        tiempoLimpieza->setGeometry(QRect(540, 130, 141, 22));
        tiempoLlenado1 = new QLineEdit(centralWidget);
        tiempoLlenado1->setObjectName(QStringLiteral("tiempoLlenado1"));
        tiempoLlenado1->setGeometry(QRect(540, 190, 141, 22));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(540, 170, 141, 16));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(540, 290, 141, 16));
        label_7->setAlignment(Qt::AlignCenter);
        tiempoEntapado = new QLineEdit(centralWidget);
        tiempoEntapado->setObjectName(QStringLiteral("tiempoEntapado"));
        tiempoEntapado->setGeometry(QRect(540, 310, 141, 22));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(540, 350, 141, 16));
        label_8->setAlignment(Qt::AlignCenter);
        tiempoInspeccion = new QLineEdit(centralWidget);
        tiempoInspeccion->setObjectName(QStringLiteral("tiempoInspeccion"));
        tiempoInspeccion->setGeometry(QRect(540, 370, 141, 22));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(700, 50, 181, 16));
        capacidadColocadas = new QLineEdit(centralWidget);
        capacidadColocadas->setObjectName(QStringLiteral("capacidadColocadas"));
        capacidadColocadas->setGeometry(QRect(700, 70, 181, 22));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(700, 110, 181, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(700, 230, 181, 16));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(700, 290, 181, 16));
        capacidadLimpias1 = new QLineEdit(centralWidget);
        capacidadLimpias1->setObjectName(QStringLiteral("capacidadLimpias1"));
        capacidadLimpias1->setGeometry(QRect(700, 130, 181, 22));
        capacidadLlenas = new QLineEdit(centralWidget);
        capacidadLlenas->setObjectName(QStringLiteral("capacidadLlenas"));
        capacidadLlenas->setGeometry(QRect(700, 250, 181, 22));
        capacidadEntapadas = new QLineEdit(centralWidget);
        capacidadEntapadas->setObjectName(QStringLiteral("capacidadEntapadas"));
        capacidadEntapadas->setGeometry(QRect(700, 310, 181, 22));
        Inicio = new QPushButton(centralWidget);
        Inicio->setObjectName(QStringLiteral("Inicio"));
        Inicio->setGeometry(QRect(700, 340, 161, 61));
        QIcon icon;
        icon.addFile(QStringLiteral(":/botones/botones/Flecha Derecha.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Inicio->setIcon(icon);
        Inicio->setIconSize(QSize(30, 30));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(190, 10, 541, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_13->setFont(font1);
        spinEliminar = new QSpinBox(centralWidget);
        spinEliminar->setObjectName(QStringLiteral("spinEliminar"));
        spinEliminar->setGeometry(QRect(170, 380, 61, 23));
        eliminarBotella = new QPushButton(centralWidget);
        eliminarBotella->setObjectName(QStringLiteral("eliminarBotella"));
        eliminarBotella->setGeometry(QRect(250, 380, 111, 22));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(700, 170, 181, 16));
        capacidadLimpias2 = new QLineEdit(centralWidget);
        capacidadLimpias2->setObjectName(QStringLiteral("capacidadLimpias2"));
        capacidadLimpias2->setGeometry(QRect(700, 190, 181, 22));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(540, 230, 141, 16));
        label_15->setAlignment(Qt::AlignCenter);
        tiempoLlenado2 = new QLineEdit(centralWidget);
        tiempoLlenado2->setObjectName(QStringLiteral("tiempoLlenado2"));
        tiempoLlenado2->setGeometry(QRect(540, 250, 141, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 922, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(cantidadRefresco, probabilidadColocar);
        QWidget::setTabOrder(probabilidadColocar, probabilidadDesecho);
        QWidget::setTabOrder(probabilidadDesecho, nuevaBotella);
        QWidget::setTabOrder(nuevaBotella, botellas);

        retranslateUi(MainWindow);
        QObject::connect(nuevaBotella, SIGNAL(clicked()), MainWindow, SLOT(agregarBotella()));
        QObject::connect(eliminarBotella, SIGNAL(clicked()), MainWindow, SLOT(eliminarBotella()));
        QObject::connect(Inicio, SIGNAL(clicked()), MainWindow, SLOT(iniciarSimulacion()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Configurar Simulaci\303\263n", 0));
        QTableWidgetItem *___qtablewidgetitem = botellas->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Cantidad de Refresco", 0));
        QTableWidgetItem *___qtablewidgetitem1 = botellas->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Probabilidad de Colocar", 0));
        QTableWidgetItem *___qtablewidgetitem2 = botellas->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Probabilidad de Desecho", 0));
        nuevaBotella->setText(QApplication::translate("MainWindow", "Insertar Botella", 0));
        label->setText(QApplication::translate("MainWindow", "Cantidad Refresco", 0));
        label_2->setText(QApplication::translate("MainWindow", "Probabilidad de Desecho", 0));
        label_3->setText(QApplication::translate("MainWindow", "Probabilidad de Colocar", 0));
        label_4->setText(QApplication::translate("MainWindow", "Tiempo de Colocaci\303\263n", 0));
        tiempoColocacion->setText(QApplication::translate("MainWindow", "2", 0));
        label_5->setText(QApplication::translate("MainWindow", "Tiempo de Limpieza", 0));
        tiempoLimpieza->setText(QApplication::translate("MainWindow", "2", 0));
        tiempoLlenado1->setText(QApplication::translate("MainWindow", "2", 0));
        label_6->setText(QApplication::translate("MainWindow", "Tiempo de Llenado 1", 0));
        label_7->setText(QApplication::translate("MainWindow", "Tiempo de Entapado", 0));
        tiempoEntapado->setText(QApplication::translate("MainWindow", "2", 0));
        label_8->setText(QApplication::translate("MainWindow", "Tiempo de Inspecci\303\263n", 0));
        tiempoInspeccion->setText(QApplication::translate("MainWindow", "2", 0));
        label_9->setText(QApplication::translate("MainWindow", "Capacidad Banda Colocadas", 0));
        capacidadColocadas->setText(QApplication::translate("MainWindow", "50", 0));
        label_10->setText(QApplication::translate("MainWindow", "Capacidad Banda Limpias 1", 0));
        label_11->setText(QApplication::translate("MainWindow", "Capacidad Banda Llenas", 0));
        label_12->setText(QApplication::translate("MainWindow", "Capacidad Banda Entapadas", 0));
        capacidadLimpias1->setText(QApplication::translate("MainWindow", "50", 0));
        capacidadLlenas->setText(QApplication::translate("MainWindow", "50", 0));
        capacidadEntapadas->setText(QApplication::translate("MainWindow", "50", 0));
        Inicio->setText(QApplication::translate("MainWindow", "Iniciar Simulaci\303\263n", 0));
        label_13->setText(QApplication::translate("MainWindow", "Ingrese los par\303\241metros que utilizar\303\241 la simulaci\303\263n", 0));
        eliminarBotella->setText(QApplication::translate("MainWindow", "Eliminar Botella", 0));
        label_14->setText(QApplication::translate("MainWindow", "Capacidad Banda Limpias 2", 0));
        capacidadLimpias2->setText(QApplication::translate("MainWindow", "50", 0));
        label_15->setText(QApplication::translate("MainWindow", "Tiempo de Llenado 2", 0));
        tiempoLlenado2->setText(QApplication::translate("MainWindow", "2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
