#ifndef P1_DA_MENU_H
#define P1_DA_MENU_H

#include "Empresa.h"

class Menu {
private:
    Empresa empresa;

    bool pass();
    void goBack();
    void mainMenu() const;
    void encomendas();
    void estafetas();
    void otimEstafetas();
    void otimLucro();
    void otimExpresso();
public:
    Menu();
    void run();
};

#endif //P1_DA_MENU_H
