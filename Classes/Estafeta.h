#ifndef P1_DA_ESTAFETA_H
#define P1_DA_ESTAFETA_H

#include <iostream>
#include <list>

#include "Encomenda.h"

using namespace std;

class Estafeta {
private:
    string matricula;
    int volMax, pesoMax, custo;
    int restoVol, restoPeso;
    list<Encomenda> carga;
public:
    Estafeta();
    Estafeta(int volMax, int pesoMax, int custo);

    string getMatricula() const;
    int getVolMax() const;
    int getPesoMax() const;
    int getCusto() const;
    int getRestoVol() const;
    int getRestoPeso() const;
    list<Encomenda> getCarga() const;

    void addEncomenda(const Encomenda &e);
    void esvaziar();

    friend ostream& operator<<(ostream& out, const Estafeta& e);
};


#endif //P1_DA_ESTAFETA_H
