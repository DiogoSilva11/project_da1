#include "Estafeta.h"

// ---------------------------------------------------------------------------------------------------

Estafeta::Estafeta(double volMax, double pesoMax, double custo) {
    this->volMax = volMax;
    this->pesoMax = pesoMax;
    this->custo = custo;
}

// ---------------------------------------------------------------------------------------------------

double Estafeta::getVolMax() const {
    return volMax;
}

double Estafeta::getPesoMax() const {
    return pesoMax;
}

double Estafeta::getCusto() const {
    return custo;
}

// ---------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& out, const Estafeta& e){
    out << e.volMax << ' ' << e.pesoMax << ' ' << e.custo << '\n';
    return out;
}

// ---------------------------------------------------------------------------------------------------