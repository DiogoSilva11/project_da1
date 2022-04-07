#include "Menu.h"

// ---------------------------------------------------------------------------------------------------

Menu::Menu() {}

// ---------------------------------------------------------------------------------------------------

bool Menu::pass() {
    if (cin.good())
        return true;
    else {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\n Input invalido!\n";
        return false;
    }
}

void Menu::goBack() {
    while (true) {
        cout << endl;
        cout << " [0 para voltar ao menu]" << endl;
        cout << " >";

        int leave;
        cin >> leave;

        if (pass()) {
            if (leave == 0)
                break;
            else
                cout << "\n Input invalido!\n";
        }
    }
}

void Menu::mainMenu() const {
    cout << endl;
    cout << " ========================================" << endl;
    cout << " ||          Logistica Urbana          ||" << endl;
    cout << " ||            para Entrega            ||" << endl;
    cout << " ||           de Mercadorias           ||" << endl;
    cout << " ========================================" << endl;
    cout << endl;

    cout << " Escolhe uma opcao:" << endl;
    cout << " [1] Ver encomendas" << endl;
    cout << " [2] Ver estafetas" << endl;
    cout << " [3] Otimizacao do numero de estafetas" << endl;
    cout << " [4] Otimizacao do lucro da empresa" << endl;
    cout << " [5] Otimizacao das entregas expresso" << endl;
    cout << " [0] Sair" << endl;
    cout << endl;
}

void Menu::encomendas() {
    cout << endl;
    cout << "Encomendas:" << endl;
    cout << "(vol peso recompensa duracao)" << endl;
    for (const auto &e : empresa.getEncomendas())
        cout << e;

    goBack();
}

void Menu::estafetas() {
    cout << endl;
    cout << "Estafetas:" << endl;
    cout << "(volMax pesoMax custo)" << endl;
    for (const auto &e : empresa.getEstafetas())
        cout << e;

    goBack();
}

void Menu::otimEstafetas() {
    unsigned numEstafetas;
    bool tarefa = false;
    vector<Estafeta> estafetasUsados;
    vector<Encomenda> encomendasEntregues;
    numEstafetas = empresa.otimEstafetas(tarefa, estafetasUsados, encomendasEntregues);

    // to do

    goBack();
}

void Menu::otimLucro() {
    double lucro;
    bool tarefa = false;
    vector<Estafeta> estafetasUsados;
    vector<Encomenda> encomendasEntregues;
    lucro = empresa.otimLucro(tarefa, estafetasUsados, encomendasEntregues);

    // to do

    goBack();
}

void Menu::otimExpresso() {
    double tempo;
    bool tarefa = false;
    vector<Encomenda> encomendasEntregues;
    tempo = empresa.otimExpresso(tarefa, encomendasEntregues);

    // to do

    goBack();
}

// ---------------------------------------------------------------------------------------------------

void Menu::run() {
    while (true) {
        mainMenu();
        cout << " >";

        int option;
        cin >> option;

        if (pass()) {
            switch (option) {
                case 1:
                    encomendas();
                    break;
                case 2:
                    estafetas();
                    break;
                case 3:
                    otimEstafetas();
                    break;
                case 4:
                    otimLucro();
                    break;
                case 5:
                    otimExpresso();
                    break;
                case 0:
                    exit(1);
                default:
                    cout << "\n Input invalido!\n";
            }
        }
    }
}

// ---------------------------------------------------------------------------------------------------