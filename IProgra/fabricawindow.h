#ifndef FABRICAWINDOW_H
#define FABRICAWINDOW_H

#include <QMainWindow>

namespace Ui {
class FabricaWindow;
}

class FabricaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FabricaWindow(QWidget *parent = 0);
    ~FabricaWindow();

private:
    Ui::FabricaWindow *ui;
};

#endif // FABRICAWINDOW_H
