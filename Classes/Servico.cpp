#include "Servico.h"

Servico::Servico(unsigned id, double vol, double peso, double recompensa, double duracao) {
    this->id = id;
    entregaNormal = true;
    this->vol = vol;
    this->peso = peso;
    this->recompensa = recompensa;
    this->duracao = duracao;
}