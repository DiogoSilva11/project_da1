#ifndef P1_DA_MENU_H
#define P1_DA_MENU_H

#include "Empresa.h"

/**
 * @brief Menu, interface com a qual o utilizador interage
 */
class Menu {
private:
    Empresa empresa; /**< @brief Empresa onde se aplicam os algoritmos de otimização */

    /**
     * @brief Verifica se um input é válido (checka flags)
     *
     * @return Retorna true se o input for válido e falso em caso contrário
     */
    bool pass();

    /**
     * @brief Apresenta ao utilizador a opção de voltar a uma secção anterior
     */
    void goBack();

    /**
     * @brief Exibe o menu principal da aplicação
     */
    void mainMenu() const;

    /**
     * @brief Mostra o conjunto das encomendas listadas na empresa
     */
    void encomendas();

    /**
     * @brief Mostra o conjunto dos estafetas registados na empresa
     */
    void estafetas();

    /**
     * @brief Aplica o algoritmo do primeiro cenário e apresenta os resultados
     */
    void otimEstafetas();

    /**
     * @brief Aplica o algoritmo do segundo cenário e apresenta os resultados
     */
    void otimLucro();

    /**
     * @brief Aplica o algoritmo do terceiro cenário e apresenta os resultados
     */
    void otimExpresso();
public:
    /**
     * @brief Construtor default (gera um objeto Menu)
     */
    Menu();

    /**
     * @brief Loop geral da aplicação
     */
    void run();
};

#endif //P1_DA_MENU_H
