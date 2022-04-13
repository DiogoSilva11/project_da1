#ifndef P1_DA_EMPRESA_H
#define P1_DA_EMPRESA_H

#include "Encomenda.h"
#include "Estafeta.h"

#include <iostream>
#include <vector>

using namespace std;

#define HOR_COMERCIAL 28800 // segundos em 8h (9:00 - 17:00)

class Empresa {
private:
    vector<Encomenda> encomendas;
    vector<Estafeta> estafetas;

    void encomendasListadas();
    void estafetasRegistados();

    int profit(int ci, vector<Encomenda> &e);
public:
    Empresa();

    vector<Encomenda> getEncomendas() const;
    vector<Estafeta> getEstafetas() const;

    unsigned otimEstafetas(bool &tarefaCompleta);
    int otimLucro(bool &tarefaCompleta);
    double otimExpresso(bool &tarefaCompleta, vector<Encomenda> &P);
};


#endif //P1_DA_EMPRESA_H
