#ifndef P1_DA_SERVICO_H
#define P1_DA_SERVICO_H

using namespace std;

class Servico {
private:
    unsigned id;
    bool entregaNormal;
    double vol, peso, recompensa, duracao;
public:
    Servico(unsigned id, double vol, double peso, double recompensa, double duracao);
};


#endif //P1_DA_SERVICO_H
