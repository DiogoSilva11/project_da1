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

    cout << " Escolha uma opcao:" << endl;
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
    cout << "[Encomendas]\n\n";
    cout << "volume   peso   recompensa   duracao" << endl;
    for (const auto &e : empresa.getEncomendas())
        cout << e;

    goBack();
}

void Menu::estafetas() {
    cout << endl;
    cout << "[Estafetas]\n\n";
    cout << "volMax   pesoMax   custo" << endl;
    for (const auto &e : empresa.getEstafetas())
        cout << e;

    goBack();
}

void Menu::otimEstafetas() {
    cout << endl;

    bool tarefa = false;
    unsigned numEstafetas = empresa.otimEstafetas(tarefa);

    cout << "Numero minimo de estafetas: " << numEstafetas << endl;
    string completo = tarefa ? "sim" : "nao";
    cout << "Pedidos todos entregues: " << completo << endl;

    cout << "\n[Estafetas]\n";
    for (const auto &e : empresa.getEstafetas()) {
        if (!e.getCarga().empty()) {
            cout << "\n[" << e.getVolMax() << ", " << e.getPesoMax() << "]\n";
            for (const auto &c : e.getCarga())
                cout << "(" << c.getVol() << ", " << c.getPeso() << ") ";
            cout << endl;
        }
    }

    goBack();
}

void Menu::otimLucro() {
    double lucro;
    bool tarefa = false;
    vector<Estafeta> estafetasUsados;
    vector<Encomenda> encomendasEntregues;
    lucro = empresa.otimLucro(tarefa, estafetasUsados, encomendasEntregues);

    cout << endl << "Valor maximo de lucro: " << lucro << endl;

    goBack();
}

void Menu::otimExpresso() {
    double tempo;
    bool tarefa = false;
    vector<Encomenda> encomendasEntregues;
    tempo = empresa.otimExpresso(tarefa, encomendasEntregues);

    cout << endl << "Tempo medio minimo para entregas expresso: " << tempo << endl;

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