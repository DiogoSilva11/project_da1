#ifndef P1_DA_ENCOMENDA_H
#define P1_DA_ENCOMENDA_H

#include <iostream>

using namespace std;

class Encomenda {
private:
    int id, vol, peso, recompensa, duracao;
public:
    Encomenda();
    Encomenda(int id, int vol, int peso, int recompensa, int duracao);

    int getId() const;
    int getVol() const;
    int getPeso() const;
    int getRecompensa() const;
    int getDuracao() const;

    friend ostream& operator<<(ostream& out, const Encomenda& e);
};

#endif //P1_DA_ENCOMENDA_H
