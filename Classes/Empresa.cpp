#include "Empresa.h"

#include <fstream>

// ---------------------------------------------------------------------------------------------------

Empresa::Empresa() {
    pedidosRecebidos();
    estafetasRegistados();
}

// ---------------------------------------------------------------------------------------------------

void Empresa::pedidosRecebidos() {
    ifstream f;
    f.open("encomendas.txt");

    if (!f.is_open()) {
        cout << "Conjunto de encomendas não detetado" << endl;
        return;
    }

    string firstLine;
    getline(f, firstLine);

    unsigned id = 0;
    string vol, peso, recompensa, duracao;
    double v, p, r, d;
    while (getline(f, vol, ' ')) {
        getline(f, peso, ' ');
        getline(f, recompensa, ' ');
        getline(f, duracao, ' ');

        id++;
        v = stod(vol);
        p = stod(peso);
        r = stod(recompensa);
        d = stod(duracao);
        Servico s(id, v, p, r, d);
        pedidos.push_back(s);
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
    string m;
    double v, p, c;
    while (getline(f, vol, ' ')) {
        getline(f, peso, ' ');
        getline(f, custo, ' ');

        m = "56-PT-08"; // to do: atribuir matriculas unicas a cada elemento
        v = stod(vol);
        p = stod(peso);
        c = stod(custo);
        Estafeta e(m, v, p, c);
        estafetas.push_back(e);
    }

    f.close();
}

// ---------------------------------------------------------------------------------------------------

unsigned Empresa::otimEstafetas(bool &tarefaCompleta, vector<Estafeta> &e, list<Servico> &s) {
    /*
    return do menor numero de estafetas para a entrega de todos os pedidos
    ou do maior numero de pedidos num dia
     */

    // nao considerar o custo dos estafetas

    // cada estafeta so pode fazer uma jornada por dia

    // maximizar encomendar entregues em cada jornada

    // checkar quando a duracao somada das entregas ultrapassar a macro DIA (> 86400)

    return 0;
}

double Empresa::otimLucro(bool &tarefaCompleta, vector<Estafeta> &E, list<Servico> &P) {
    // return do lucro feito num dia

    return 0.0;
}

double Empresa::otimExpresso(list<Servico> &P) {
    // return do tempo medio minimo das entregas num dia

    return 0.0;
}

// ---------------------------------------------------------------------------------------------------