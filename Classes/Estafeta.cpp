#include "Estafeta.h"

// ---------------------------------------------------------------------------------------------------

Estafeta::Estafeta() {
    matricula = "";
    volMax = 0;
    pesoMax = 0;
    custo = 0;
    restoVol = volMax;
    restoPeso = pesoMax;
    carga.clear();
}

Estafeta::Estafeta(int volMax, int pesoMax, int custo) {
    matricula = "";
    this->volMax = volMax;
    this->pesoMax = pesoMax;
    this->custo = custo;
    restoVol = volMax;
    restoPeso = pesoMax;
    carga.clear();
}

// ---------------------------------------------------------------------------------------------------

string Estafeta::getMatricula() const {
    return matricula;
}

int Estafeta::getVolMax() const {
    return volMax;
}

int Estafeta::getPesoMax() const {
    return pesoMax;
}

int Estafeta::getCusto() const {
    return custo;
}

int Estafeta::getRestoVol() const {
    return restoVol;
}

int Estafeta::getRestoPeso() const {
    return restoPeso;
}

list<Encomenda> Estafeta::getCarga() const {
    return carga;
}

// ---------------------------------------------------------------------------------------------------

void Estafeta::addEncomenda(const Encomenda &e) {
    restoVol -= e.getVol();
    restoPeso -= e.getPeso();
    carga.push_back(e);
}

void Estafeta::esvaziar() {
    carga.clear();
}

// ---------------------------------------------------------------------------------------------------
/*
bool Estafeta::operator<(const Estafeta &e) const {
    return volMax > e.volMax; // criterio de capacidade??
}
*/
bool Estafeta::operator<=(const Estafeta &e) const {
    return volMax >= e.volMax; // criterio de capacidade??
}

ostream& operator<<(ostream& out, const Estafeta& e){
    string vol = to_string(e.volMax), peso = to_string(e.pesoMax), custo = to_string(e.custo);

    string v = vol + string(abs(8 - (int)vol.length()), ' ');
    string p = peso + string(abs(9 - (int)peso.length()), ' ');
    string c = custo + string(abs(5 - (int)custo.length()), ' ');

    out << v << ' ' << p << ' ' << c << '\n';
    return out;
}

// ---------------------------------------------------------------------------------------------------