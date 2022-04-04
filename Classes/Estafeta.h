#ifndef P1_DA_ESTAFETA_H
#define P1_DA_ESTAFETA_H

#include <string>

using namespace std;

class Estafeta {
private:
    string matricula;
    double volMax, pesoMax, custo;
public:
    Estafeta(string matricula, double volMax, double pesoMax, double custo);
};


#endif //P1_DA_ESTAFETA_H
