#ifndef P1_DA_ESTAFETA_H
#define P1_DA_ESTAFETA_H

#include <iostream>

using namespace std;

class Estafeta {
private:
    double volMax, pesoMax, custo;
public:
    Estafeta(double volMax, double pesoMax, double custo);

    double getVolMax() const;
    double getPesoMax() const;
    double getCusto() const;

    friend ostream& operator<<(ostream& out, const Estafeta& e);
};


#endif //P1_DA_ESTAFETA_H
