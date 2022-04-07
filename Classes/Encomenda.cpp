#include "Encomenda.h"

// ---------------------------------------------------------------------------------------------------

Encomenda::Encomenda(double vol, double peso, double recompensa, double duracao) {
    this->vol = vol;
    this->peso = peso;
    this->recompensa = recompensa;
    this->duracao = duracao;
}

// ---------------------------------------------------------------------------------------------------

double Encomenda::getVol() const {
    return vol;
}

double Encomenda::getPeso() const {
    return peso;
}

double Encomenda::getRecompensa() const {
    return recompensa;
}

double Encomenda::getDuracao() const {
    return duracao;
}

// ---------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& out, const Encomenda& e){
    out << e.vol << ' ' << e.peso << ' ' << e.recompensa << ' ' << e.duracao << '\n';
    return out;
}

// ---------------------------------------------------------------------------------------------------