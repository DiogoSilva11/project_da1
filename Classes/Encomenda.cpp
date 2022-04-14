#include "Encomenda.h"

// ---------------------------------------------------------------------------------------------------

Encomenda::Encomenda() {
    id = 0;
    vol = 0;
    peso = 0;
    recompensa = 0;
    duracao = 0;
}

Encomenda::Encomenda(int id, int vol, int peso, int recompensa, int duracao) {
    this->id = id;
    this->vol = vol;
    this->peso = peso;
    this->recompensa = recompensa;
    this->duracao = duracao;
}

// ---------------------------------------------------------------------------------------------------

int Encomenda::getId() const {
    return id;
}

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

ostream& operator<<(ostream& out, const Encomenda& e){
    string id = to_string(e.id), vol = to_string(e.vol), peso = to_string(e.peso);
    string recompensa = to_string(e.recompensa), d = to_string(e.duracao);

    string i = id + string(abs(7 - (int)id.length()), ' ');
    string v = vol + string(abs(8 - (int)vol.length()), ' ');
    string p = peso + string(abs(6 - (int)peso.length()), ' ');
    string r = recompensa + string(abs(12 - (int)recompensa.length()), ' ');

    out << i << ' ' << v << ' ' << p << ' ' << r << ' ' << d << '\n';
    return out;
}

// ---------------------------------------------------------------------------------------------------