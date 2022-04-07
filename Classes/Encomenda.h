#ifndef P1_DA_ENCOMENDA_H
#define P1_DA_ENCOMENDA_H

#include <iostream>

using namespace std;

class Encomenda {
private:
    double vol, peso, recompensa, duracao;
public:
    Encomenda(double vol, double peso, double recompensa, double duracao);

    double getVol() const;
    double getPeso() const;
    double getRecompensa() const;
    double getDuracao() const;

    friend ostream& operator<<(ostream& out, const Encomenda& e);
};

#endif //P1_DA_ENCOMENDA_H
