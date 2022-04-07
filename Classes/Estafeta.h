#ifndef P1_DA_ESTAFETA_H
#define P1_DA_ESTAFETA_H

#include <iostream>

using namespace std;

class Estafeta {
private:
    int volMax, pesoMax, custo;
public:
    Estafeta();
    Estafeta(int volMax, int pesoMax, int custo);

    int getVolMax() const;
    int getPesoMax() const;
    int getCusto() const;

    bool operator<(const Estafeta& e) const;
    bool operator<=(const Estafeta& e) const;
    friend ostream& operator<<(ostream& out, const Estafeta& e);
};


#endif //P1_DA_ESTAFETA_H
