#ifndef P1_DA_EMPRESA_H
#define P1_DA_EMPRESA_H

#include "Servico.h"
#include "Estafeta.h"

#include <iostream>
#include <list>
#include <vector>

using namespace std;

#define DIA 86400 // number of seconds in a day

class Empresa {
private:
    list<Servico> pedidos;
    vector<Estafeta> estafetas;

    void pedidosRecebidos();
    void estafetasRegistados();
public:
    Empresa();

    unsigned otimEstafetas(bool &tarefaCompleta, vector<Estafeta> &E, list<Servico> &P);
    double otimLucro(bool &tarefaCompleta, vector<Estafeta> &E, list<Servico> &P);
    double otimExpresso(list<Servico> &P);
};


#endif //P1_DA_EMPRESA_H
