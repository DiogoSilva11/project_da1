#ifndef P1_DA_EMPRESA_H
#define P1_DA_EMPRESA_H

#include "Encomenda.h"
#include "Estafeta.h"

#include <iostream>
#include <vector>

using namespace std;

class Empresa {
private:
    vector<Encomenda> encomendas;
    vector<Estafeta> estafetas;

    void encomendasListadas();
    void estafetasRegistados();
public:
    Empresa();

    vector<Encomenda> getEncomendas() const;
    vector<Estafeta> getEstafetas() const;

    unsigned otimEstafetas(bool &tarefaCompleta, vector<Estafeta> &E, vector<Encomenda> &P);
    double otimLucro(bool &tarefaCompleta, vector<Estafeta> &E, vector<Encomenda> &P);
    double otimExpresso(bool &tarefaCompleta, vector<Encomenda> &P);
};


#endif //P1_DA_EMPRESA_H
