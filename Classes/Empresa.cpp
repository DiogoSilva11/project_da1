#include "Empresa.h"

#include <fstream>

// ---------------------------------------------------------------------------------------------------

Empresa::Empresa() {
    encomendasListadas();
    estafetasRegistados();
}

// ---------------------------------------------------------------------------------------------------

void Empresa::encomendasListadas() {
    ifstream f;
    f.open("encomendas.txt");

    if (!f.is_open()) {
        cout << "Conjunto de encomendas não detetado" << endl;
        return;
    }

    string firstLine;
    getline(f, firstLine);

    string vol, peso, recompensa, duracao;
    double v, p, r, d;
    while (getline(f, vol, ' ')) {
        getline(f, peso, ' ');
        getline(f, recompensa, ' ');
        getline(f, duracao, ' ');

        v = stod(vol);
        p = stod(peso);
        r = stod(recompensa);
        d = stod(duracao);
        Encomenda e(v, p, r, d);
        encomendas.push_back(e);
    }

    f.close();
}

void Empresa::estafetasRegistados() {
    ifstream f;
    f.open("carrinhas.txt");

    if (!f.is_open()) {
        cout << "Conjunto de carrinhas não detetado" << endl;
        return;
    }

    string firstLine;
    getline(f, firstLine);

    string vol, peso, custo;
    double v, p, c;
    while (getline(f, vol, ' ')) {
        getline(f, peso, ' ');
        getline(f, custo, ' ');

        v = stod(vol);
        p = stod(peso);
        c = stod(custo);
        Estafeta e(v, p, c);
        estafetas.push_back(e);
    }

    f.close();
}

void Empresa::sortEncomendas() {
    // to do
}

void Empresa::sortEstafetas() {
    // to do
}

// ---------------------------------------------------------------------------------------------------

vector<Encomenda> Empresa::getEncomendas() const {
    return encomendas;
}

vector<Estafeta> Empresa::getEstafetas() const {
    return estafetas;
}

// ---------------------------------------------------------------------------------------------------

unsigned Empresa::otimEstafetas(bool &tarefaCompleta, vector<Estafeta> &E, vector<Encomenda> &P) {
    // ordenar estafetas por ordem descendente de capacidade

    // ordenar encomendas por ordem ascendente

    // ir ocupando carrinhas ao maximo e ir contando as com um counter

    return 0;
}

double Empresa::otimLucro(bool &tarefaCompleta, vector<Estafeta> &E, vector<Encomenda> &P) {
    // to do

    return 0.0;
}

double Empresa::otimExpresso(bool &tarefaCompleta, vector<Encomenda> &P) {
    // to do

    return 0.0;
}

// ---------------------------------------------------------------------------------------------------