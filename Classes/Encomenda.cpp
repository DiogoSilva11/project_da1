#include "Encomenda.h"

// ---------------------------------------------------------------------------------------------------

Encomenda::Encomenda() {
    vol = 0;
    peso = 0;
    recompensa = 0;
    duracao = 0;
}

Encomenda::Encomenda(int vol, int peso, int recompensa, int duracao) {
    this->vol = vol;
    this->peso = peso;
    this->recompensa = recompensa;
    this->duracao = duracao;
}

// ---------------------------------------------------------------------------------------------------

int Encomenda::getVol() const {
    return vol;
}

int Encomenda::getPeso() const {
    return peso;
}

int Encomenda::getRecompensa() const {
    return recompensa;
}

int Encomenda::getDuracao() const {
    return duracao;
}

// ---------------------------------------------------------------------------------------------------

bool Encomenda::operator<(const Encomenda &e) const {
    return vol > e.vol; // criterio de carga??
}

bool Encomenda::operator<=(const Encomenda &e) const {
    return vol >= e.vol; // criterio de carga??
}

ostream& operator<<(ostream& out, const Encomenda& e){
    string vol = to_string(e.vol), peso = to_string(e.peso);
    string recompensa = to_string(e.recompensa), d = to_string(e.duracao);

    string v = vol + string(abs(8 - (int)vol.length()), ' ');
    string p = peso + string(abs(6 - (int)peso.length()), ' ');
    string r = recompensa + string(abs(12 - (int)recompensa.length()), ' ');

    out << v << ' ' << p << ' ' << r << ' ' << d << '\n';
    return out;
}

// ---------------------------------------------------------------------------------------------------