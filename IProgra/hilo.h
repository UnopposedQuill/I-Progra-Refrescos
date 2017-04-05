#ifndef HILO_H
#define HILO_H

#include <iostream>
#include <cstdlib>
#include <QThread>

using namespace std;

class Hilo : public QThread
{
public:
    bool activo, pausa;
    Hilo();
};

#endif // HILO_H
