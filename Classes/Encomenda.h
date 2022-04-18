#ifndef P1_DA_ENCOMENDA_H
#define P1_DA_ENCOMENDA_H

#include <iostream>

using namespace std;

/**
 * Encomenda a ser entregue
 */
class Encomenda {
private:
    int id;         /**< @brief Identificador da encomenda */
    int vol;        /**< @brief Volume ocupado pela encomenda */
    int peso;       /**< @brief Peso da encomenda */
    int recompensa; /**< @brief Valor recebido pela entrega da encomenda */
    int duracao;    /**< @brief Tempo estimado de entrega (viagem, ida + volta) */
public:
    /**
     * @brief Construtor default (gera um objeto Encomenda)
     */
    Encomenda();

    /**
     * @brief Construtor (gera um objeto Encomenda)
     *
     * @param id Identificador da encomenda
     * @param vol Volume da encomenda
     * @param peso Peso da encomenda
     * @param recompensa Recompensa pela entrega da encomenda
     * @param duracao Tempo de entrega (ida + volta)
     */
    Encomenda(int id, int vol, int peso, int recompensa, int duracao);

    /**
     * @return Retorna o identificador da encomenda
     */
    int getId() const;

    /**
     * @return Retorna o volume ocupado pela encomenda
     */
    int getVol() const;

    /**
     * @return Retorna o peso da encomenda
     */
    int getPeso() const;

    /**
     * @return Retorna o valor recebido pela entrega da encomenda
     */
    int getRecompensa() const;

    /**
     * @return Retorna o tempo estimado de entrega
     */
    int getDuracao() const;

    /**
     * @brief Gera uma exibição coesa dos dados da encomenda
     *
     * @param out Objeto de output stream
     * @param e Encomenda
     * @return Objeto de output stream
     */
    friend ostream& operator<<(ostream& out, const Encomenda& e);
};

#endif //P1_DA_ENCOMENDA_H
