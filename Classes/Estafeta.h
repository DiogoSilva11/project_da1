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
    list<Encomenda> carga;
public:
    Estafeta();
    Estafeta(int volMax, int pesoMax, int custo);

    string getMatricula() const;
    int getVolMax() const;
    int getPesoMax() const;
    int getCusto() const;
    list<Encomenda> getCarga() const;

    void addEncomenda(const Encomenda &e);
    void esvaziar();

    //bool operator<(const Estafeta& e) const;
    bool operator<=(const Estafeta& e) const;
    friend ostream& operator<<(ostream& out, const Estafeta& e);
};


#endif //P1_DA_ESTAFETA_H
