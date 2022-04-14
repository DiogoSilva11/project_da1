#include "Menu.h"

#include <cmath>

// ---------------------------------------------------------------------------------------------------

Menu::Menu() = default;

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
    cout << endl << string(120, '=') << endl;
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
    cout << endl << string(120, '=') << endl;
    cout << "[Encomendas]\n";
    cout << endl << string(120, '-') << endl;
    cout << "id      volume   peso   recompensa   duracao\n\n";
    for (const auto &e : empresa.getEncomendas())
        cout << e;

    goBack();
}

void Menu::estafetas() {
    cout << endl << string(120, '=') << endl;
    cout << "[Estafetas]\n";
    cout << endl << string(120, '-') << endl;
    cout << "volMax   pesoMax   custo\n\n";
    for (const auto &e : empresa.getEstafetas())
        cout << e;

    goBack();
}

void Menu::otimEstafetas() {
    bool tarefa = false;
    unsigned numEstafetas = empresa.otimEstafetas(tarefa);

    cout << endl << string(120, '=') << endl;
    cout << "[Estafetas]\n";
    for (const auto &e : empresa.getEstafetas()) {
        if (!e.getCarga().empty()) {
            cout << endl << string(120, '-') << endl;
            cout << "CapacidadeMax: [" << e.getVolMax() << ", " << e.getPesoMax() << "]\n";
            cout << "Resto: [" << e.getRestoVol() << ", " << e.getRestoPeso() << "]\n";
            cout << "\n(id, vol, peso)\n\n";
            for (const auto &c : e.getCarga())
                cout << "(" << c.getId() << ", " << c.getVol() << ", " << c.getPeso() << ") ";
            cout << endl;
        }
    }

    cout << endl << string(120, '-') << endl;
    cout << "Numero minimo de estafetas: " << numEstafetas << endl;
    string completo = tarefa ? "sim" : "nao";
    cout << "Pedidos todos entregues: " << completo << endl;

    goBack();
}

void Menu::otimLucro() {
    cout << "\nA processar...\n";

    double lucro;
    bool tarefa = false;
    lucro = empresa.otimLucro(tarefa);

    int num = 0;

    cout << endl << string(120, '=') << endl;
    cout << "[Estafetas]\n";
    for (const auto &e : empresa.getEstafetas()) {
        if (!e.getCarga().empty()) {
            num++;
            cout << endl << string(120, '-') << endl;
            cout << "CapacidadeMax: [" << e.getVolMax() << ", " << e.getPesoMax() << "]\n";
            cout << "Resto: [" << e.getRestoVol() << ", " << e.getRestoPeso() << "]\n";
            cout << "Custo do estafeta: [" << e.getCusto() << "]\n";
            cout << "Lucro feito: [" << e.getProfit() << "]\n";
            cout << "\n(id, recompensa)\n\n";
            for (const auto &c : e.getCarga())
                cout << "(" << c.getId() << ", " << c.getRecompensa() << ") ";
            cout << endl;
        }
    }

    cout << endl << string(120, '-') << endl;
    cout << "Valor maximo de lucro: " << lucro << endl;
    cout << "Numero de estafetas: " << num << endl;
    string completo = tarefa ? "sim" : "nao";
    cout << "Pedidos todos entregues: " << completo << endl;

    goBack();
}

void Menu::otimExpresso() {
    double tempo;
    bool tarefa = false;
    vector<Encomenda> encomendasEntregues;
    tempo = empresa.otimExpresso(tarefa, encomendasEntregues);

    cout << endl << string(120, '=') << endl;
    cout << "[Encomendas]\n";
    cout << endl << string(120, '-') << endl;
    cout << "(id, duracao)\n\n";
    for (const auto &e : encomendasEntregues)
        cout << "(" << e.getId() << ", " << e.getDuracao() << ")\n";

    int seg, hrs, min;
    seg = (int)(round(tempo));
    min = seg / 60;
    hrs = min / 60;

    cout << endl << string(120, '-') << endl;
    cout << "Tempo medio minimo de entregas expresso: " << tempo;
    cout << " (" << (int)(hrs) << ":" << (int)(min % 60) << ":" << (int)(seg % 60) << ")" << endl;
    string completo = tarefa ? "sim" : "nao";
    cout << "Pedidos todos entregues: " << completo << endl;

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