#ifndef P1_DA_ENCOMENDA_H
#define P1_DA_ENCOMENDA_H

#include <iostream>

using namespace std;

class Encomenda {
private:
    int vol, peso, recompensa, duracao;
public:
    Encomenda();
    Encomenda(int vol, int peso, int recompensa, int duracao);

    int getVol() const;
    int getPeso() const;
    int getRecompensa() const;
    int getDuracao() const;

    bool operator<(const Encomenda& e) const;
    bool operator<=(const Encomenda& e) const;
    friend ostream& operator<<(ostream& out, const Encomenda& e);
};

#endif //P1_DA_ENCOMENDA_H
