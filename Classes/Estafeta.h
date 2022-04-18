#ifndef P1_DA_ESTAFETA_H
#define P1_DA_ESTAFETA_H

#include <iostream>
#include <list>

#include "Encomenda.h"

using namespace std;

/**
 * @brief Estafeta, faz entregas por meio da sua viatura (carrinha)
 */
class Estafeta {
private:
    string matricula;      /**< @brief Matricula da carrinha */
    int volMax;            /**< @brief Valor máximo de volume que a carrinha suporta */
    int pesoMax;           /**< @brief Valor máximo de peso que a carrinha suporta */
    int custo;             /**< @brief Custo do serviço feito pelo estafeta */
    int restoVol;          /**< @brief Valor que falta até se atingir o limite de volume da carrinha */
    int restoPeso;         /**< @brief Valor que falta até se atingir o limite de peso da carrinha */
    int profit;            /**< @brief Lucro (recompensas - custo) na carrinha de momento */
    list<Encomenda> carga; /**< @brief Conjunto de encomendas na carrinha de momento */
public:
    /**
     * @brief Construtor default (gera um objeto Estafeta)
     */
    Estafeta();

    /**
     * @brief Construtor (gera um objeto Estafeta)
     *
     * @param matricula Matrícula da carrinha
     * @param volMax Volume máximo da carrinha
     * @param pesoMax Peso máximo da carrinha
     * @param custo Custo do serviço feito pelo estafeta
     */
    Estafeta(string matricula, int volMax, int pesoMax, int custo);

    /**
     * @return Retorna a matrícula da carrinha
     */
    string getMatricula() const;

    /**
     * @return Retorna o volume máximo da carrinha
     */
    int getVolMax() const;

    /**
     * @return Retorna o peso máximo da carrinha
     */
    int getPesoMax() const;

    /**
     * @return Retorna o custo do serviço feito pelo estafeta
     */
    int getCusto() const;

    /**
     * @return Retorna o volume restante na carrinha
     */
    int getRestoVol() const;

    /**
     * @return Retorna o peso restante na carrinha
     */
    int getRestoPeso() const;

    /**
     * @return Retorna o lucro (recompensas - custo) na carrinha de momento
     */
    int getProfit() const;

    /**
     * @return Retorna o conjunto de encomendas na carrinha de momento
     */
    list<Encomenda> getCarga() const;

    /**
     * @brief Adiciona uma encomenda ao conjunto de encomendas da carrinha
     *
     * @param e Encomenda a adicionar
     */
    void addEncomenda(const Encomenda &e);

    /**
     * @brief Esvazia a carrinha (retira todas as encomendas)
     */
    void esvaziar();

    /**
     * @brief Gera uma exibição coesa dos dados do estafeta
     *
     * @param out Objeto de output stream
     * @param e Estafeta
     * @return Objeto de output stream
     */
    friend ostream& operator<<(ostream& out, const Estafeta& e);
};


#endif //P1_DA_ESTAFETA_H
