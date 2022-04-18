#ifndef P1_DA_EMPRESA_H
#define P1_DA_EMPRESA_H

#include "Encomenda.h"
#include "Estafeta.h"

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define HOR_COMERCIAL 28800 /**< Segundos em 8h (9:00 - 17:00) */

/**
 * Empresa com encomendas a entregar e estafetas registados
 */
class Empresa {
private:
    vector<Encomenda> encomendas; /**< @brief Conjunto das encomendas armazenadas a serem entregues pela empresa */
    vector<Estafeta> estafetas;   /**< @brief Conjunto dos estafetas registados na empresa */

    /**
     * @brief Recolhe os dados do dataset com as encomendas
     */
    void encomendasListadas();

    /**
     * @brief Recolhe os dados do dataset com os estafetas
     */
    void estafetasRegistados();

    /**
     * @brief Determinar encomendas a colocar numa carrinha de modo a otimizar o lucro (desde
     *        que não haja prejuízo) e removê-las do conjunto das encomendas restantes
     *
     * @param ci Index da carrinha no conjunto de estafetas da empresa
     * @param e Conjunto das encomendas por entregar
     * @return Retorna o valor de lucro (não negativo) feito na carrinha em questão
     */
    int profit(int ci, vector<Encomenda> &e);
public:
    /**
     * Construtor default (gera um objeto Empresa)
     */
    Empresa();

    /**
     * @return Retorna o conjunto de encomendas da empresa
     */
    vector<Encomenda> getEncomendas() const;

    /**
     * @return Retorna o conjunto de estafetas da empresa
     */
    vector<Estafeta> getEstafetas() const;

    /**
     * @brief Minimizar número de estafetas para a entrega de todos os pedidos ou
     *        do maior número de pedidos, num dia
     *
     * @param tarefaCompleta Indica se é possível entregar a totalidade das encomendas armazenadas
     *                       neste cenário
     * @return Número mínimo de estafetas necessários neste cenário
     */
    unsigned otimEstafetas(bool &tarefaCompleta);

    /**
     * @brief Maximizar o lucro da empresa para a entrega de todos os pedidos ou
     *        do maior número de pedidos, num dia
     *
     * @param tarefaCompleta Indica se é possível entregar a totalidade das encomendas armazenadas
     *                       neste cenário
     * @return Valor máximo de lucro feito
     */
    int otimLucro(bool &tarefaCompleta);

    /**
     * @brief Minimizar o tempo médio previsto das entregas expresso a serem
     *        realizadas num dia
     *
     * @param tarefaCompleta Indica se é possível entregar a totalidade das encomendas armazenadas
     *                       neste cenário
     * @param P Conjunto das encomendas entregues dentro do horário comercial
     * @return Tempo médio mínimo das entregas expresso
     */
    double otimExpresso(bool &tarefaCompleta, vector<Encomenda> &P);
};


#endif //P1_DA_EMPRESA_H
