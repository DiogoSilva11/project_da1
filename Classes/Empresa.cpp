#include "Empresa.h"

#include <fstream>
#include <algorithm>

// ---------------------------------------------------------------------------------------------------

Empresa::Empresa() {
    encomendasListadas();
    estafetasRegistados();
}

// ---------------------------------------------------------------------------------------------------

void Empresa::encomendasListadas() {
    ifstream f;
    f.open("encomendas.txt");

    if (!f.is_open()) {
        cout << "Conjunto de encomendas não detetado" << endl;
        return;
    }

    string firstLine;
    getline(f, firstLine);

    string vol, peso, recompensa, duracao;
    int v, p, r, d, id = 0;
    while (getline(f, vol, ' ')) {
        getline(f, peso, ' ');
        getline(f, recompensa, ' ');
        getline(f, duracao);

        id++;
        v = stoi(vol);
        p = stoi(peso);
        r = stoi(recompensa);
        d = stoi(duracao);
        Encomenda e(id, v, p, r, d);
        encomendas.push_back(e);
    }

    f.close();
}

void Empresa::estafetasRegistados() {
    ifstream f;
    f.open("carrinhas.txt");

    if (!f.is_open()) {
        cout << "Conjunto de carrinhas não detetado" << endl;
        return;
    }

    string firstLine;
    getline(f, firstLine);

    string matricula, vol, peso, custo;
    int v, p, c;
    while (getline(f, matricula, ' ')) {
        getline(f, vol, ' ');
        getline(f, peso, ' ');
        getline(f, custo);

        v = stoi(vol);
        p = stoi(peso);
        c = stoi(custo);
        Estafeta e(matricula, v, p, c);
        estafetas.push_back(e);
    }

    f.close();
}

// ---------------------------------------------------------------------------------------------------

vector<Encomenda> Empresa::getEncomendas() const {
    return encomendas;
}

vector<Estafeta> Empresa::getEstafetas() const {
    return estafetas;
}

// ---------------------------------------------------------------------------------------------------

/* ordenação recorrendo ao algoritmo de merge sort */

/**
 * @brief Função (externa), geradora da ordenação
 *
 * @tparam T Objeto de uma determinada classe
 * @tparam Comparable Função de comparação de elementos T
 * @param v Vetor a ser ordenado
 * @param comp Função de comparação
 */
template <typename T, class Comparable>
void mergeSort(vector<T> &v, Comparable comp);

/**
 * @brief Método interno, faz chamadas recursivas
 *
 * @tparam T Objeto de uma determinada classe
 * @tparam Comparable Função de comparação de elementos T
 * @param v Vetor a ser ordenado
 * @param tmp Vetor auxiliar
 * @param left Posição mais à esquerda
 * @param right Posição mais à direita
 * @param comp Função de comparação
 */
template <typename T, class Comparable>
void mergeSort(vector<T> &v, vector<T> &tmp, int left, int right, Comparable comp);

/**
 * @brief Junção de partes ordenadas do vetor
 *
 * @tparam T Objeto de uma determinada classe
 * @tparam Comparable Função de comparação de elementos T
 * @param v Vetor a ser ordenado
 * @param tmp Vetor auxiliar
 * @param leftPos Posição mais à esquerda
 * @param rightPos Posição onde se inicia a secção direita
 * @param rightEnd Posição mais à direita
 * @param comp Função de comparação
 */
template <typename T, class Comparable>
void merge(vector<T> &v, vector<T> &tmp, int leftPos, int rightPos, int rightEnd, Comparable comp);

template <typename T, class Comparable>
void mergeSort(vector<T> &v, Comparable comp) {
    vector<T> tmp(v.size());
    mergeSort(v, tmp, 0, v.size()-1, comp); // chamar método interno
}

template <typename T, class Comparable>
void mergeSort(vector<T> &v, vector<T> &tmp, int left, int right, Comparable comp) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(v, tmp, left, center, comp); // ordenar secção esquerda
        mergeSort(v, tmp, center + 1, right, comp); // ordenar secção direita
        merge(v, tmp, left, center +1, right, comp); // juntar as duas secções ordenadas
    }
}

template <typename T, class Comparable>
void merge(vector<T> &v, vector<T> &tmp, int leftPos, int rightPos, int rightEnd, Comparable comp) {
    int leftEnd = rightPos - 1, tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    /* comparar elementos da esquerda com os da direita */
    while ((leftPos <= leftEnd) && (rightPos <= rightEnd)) {
        if (comp(v[leftPos], v[rightPos])) // v[leftPos] <= v[rightPos]
            tmp[tmpPos++] = v[leftPos++];
        else
            tmp[tmpPos++] = v[rightPos++];
    }

    /* acabar de percorrer elementos */
    while (leftPos <= leftEnd)
        tmp[tmpPos++] = v[leftPos++];
    while (rightPos <= rightEnd)
        tmp[tmpPos++] = v[rightPos++];

    /* atualizar valores do vetor principal */
    for (int i = 0; i < numElements; i++, rightEnd--)
        v[rightEnd] = tmp[rightEnd];
}

// ---------------------------------------------------------------------------------------------------

/**
 * @brief Compara estafetas de acordo com a capacidade das carrinhas
 *
 * @param e1 Estafeta
 * @param e2 Estafeta
 * @return Retorna true se o primeiro estafeta tiver um maior valor
 *         para a variável onde surge uma maior discrepância entre
 *         os dois elementos, false em caso contrário
 */
bool compCapacidade(const Estafeta &e1, const Estafeta &e2) {
    int volDif = abs(e1.getVolMax() - e2.getVolMax()); // diferença de volumes
    int pesoDif = abs(e1.getPesoMax() - e2.getPesoMax()); // diferença de pesos

    if (volDif >= pesoDif)
        return e1.getVolMax() > e2.getVolMax(); // compara pelo volume
    else
        return e1.getPesoMax() > e2.getPesoMax(); // compara pelo peso
}

/**
 * @brief Compara encomendas de acordo com os seus volumes e pesos
 *
 * @param e1 Encomenda
 * @param e2 Encomenda
 * @return Retorna true se a primeira encomenda tiver um maior valor
 *         para a variável onde surge uma maior discrepância entre
 *         os dois elementos, false em caso contrário
 */
bool compCarga(const Encomenda &e1, const Encomenda &e2) {
    int volDif = abs(e1.getVol() - e2.getVol()); // diferença de volumes
    int pesoDif = abs(e1.getPeso() - e2.getPeso()); // diferença de pesos

    if (volDif >= pesoDif)
        return e1.getVol() > e2.getVol(); // compara pelo volume
    else
        return e1.getPeso() > e2.getPeso(); // compara pelo peso
}

unsigned Empresa::otimEstafetas(bool &tarefaCompleta) {
    for (auto &e : estafetas)
        e.esvaziar(); // retirar todas as encomendas das carrinhas (reset geral)

    mergeSort(estafetas, compCapacidade); // ordem decrescente de capacidade
    mergeSort(encomendas, compCarga); // ordem decrescente de carga

    tarefaCompleta = false;
    // num -> número mínimo de estafetas requeridos para o cenário
    int num = 0, eTotal = (int)estafetas.size(), pTotal = (int)encomendas.size();

    for (int i = 0; i < pTotal; i++) {
        if (i == pTotal - 1)
            tarefaCompleta = true; // todas as encomendas serão entregues

        if (num >= eTotal) // não restam mais carrinhas
            break;
        else {
            // minVol, minPeso representam os "espaços" mais apertados
            // das carrinhas onde encomendas podem ser colocadas
            int carrinha = 0, minVol = INT_MAX/2, minPeso = INT_MAX/2;
            int v = encomendas[i].getVol(), p = encomendas[i].getPeso();

            /* percorrer carrinhas que já começaram a ser ocupadas */
            for (int j = 0; j < num; j++) {
                int restoV = estafetas[j].getRestoVol(), restoP = estafetas[j].getRestoPeso();
                if ((restoV >= v) && (restoP >= p) && (restoV - v < minVol) && (restoP - p < minPeso)) {
                    carrinha = j; // carrinha ideal atualizada
                    minVol = restoV - v; // valor mais apertado atualizado
                    minPeso = restoP - p; // valor mais apertado atualizado
                }
            }

            if ((minVol == INT_MAX/2) && (minPeso == INT_MAX/2)) {
                estafetas[num].addEncomenda(encomendas[i]);
                num++; // nova carrinha usada
            }
            else
                estafetas[carrinha].addEncomenda(encomendas[i]); // encomenda colocada na vaga mais apertada
        }
    }

    return num;
}

// ---------------------------------------------------------------------------------------------------

/**
 * @brief Compara estafetas de acordo com os seus custos
 *
 * @param e1 Estafeta
 * @param e2 Estafeta
 * @return Retorna true se o primeiro estafeta tiver um
 *         valor menor ou igual de custo em relação ao
 *         segundo, false em caso contrário
 */
bool compCusto(const Estafeta &e1, const Estafeta &e2) {
    return e1.getCusto() <= e2.getCusto();
}

/**
 * @brief Compara encomendas de acordo com as respetivas recompensas
 *
 * @param e1 Encomenda
 * @param e2 Encomenda
 * @return Retorna true se a recompensa da primeira encomenda
 *         for superior à da segunda, false em caso contrário
 */
bool compRecompensa(const Encomenda &e1, const Encomenda &e2) {
    return e1.getRecompensa() > e2.getRecompensa();
}

int Empresa::profit(int ci, vector<Encomenda> &e) {
    /* determinar lucro máximo no caso desta carrinha */

    int pTotal = (int)e.size(), vol = estafetas[ci].getVolMax(), peso = estafetas[ci].getPesoMax();
    // vetor 3D (número de encomendas, valores de volume, valores de peso)
    vector<vector<vector<int>>> K(pTotal + 1,vector<vector<int>>(vol + 1, vector<int>(peso + 1)));

    /* percorrer linhas das encomendas */
    for (int i = 0; i <= pTotal; i++) {
        /* percorrer valores do volume */
        for (int v = 0; v <= vol; v++) {
            /* percorrer valores do peso */
            for (int p = 0; p <= peso; p++) {
                if (i == 0 || v == 0 || p == 0) // casos base
                    K[i][v][p] = 0;
                else if ((v < e[i - 1].getVol()) || (p < e[i - 1].getPeso())) // volume ou peso menores do que valores respetivos da encomenda
                    K[i][v][p] = K[i - 1][v][p]; // valor em cima (na linha anterior de encomenda)
                else
                    K[i][v][p] = max(e[i - 1].getRecompensa() + K[i - 1][v - e[i - 1].getVol()][p - e[i - 1].getPeso()], K[i - 1][v][p]);
                // máximo(soma da recompensa da encomenda com valor na linha anterior (nas colunas subtraídas pelo volume e peso);
                // ...... valor em cima (na linha anterior de encomenda))
            }
        }
    }

    int res = K[pTotal][vol][peso]; // valor na última "célula" do vetor 3D = lucro das encomendas
    int lucro = res - estafetas[ci].getCusto();
    if (lucro < 0) // prejuízo (encomendas não chegam a ser colocadas na carrinha)
        return 0;

    /* colocar encomendas na carrinha */
    int wv = vol, wp = peso;
    vector<int> aux; // vetor com índices das encomendas atribuídas à carrinha

    for (int i = pTotal; i > 0 && res > 0; i--) {
        if (res == K[i - 1][wv][wp])
            continue;
        else { // valor veio do primeiro membro do máximo (soma das duas células) ao preencher o vetor
            estafetas[ci].addEncomenda(e[i - 1]); // encomenda atribuída
            aux.push_back(i - 1);
            res -= e[i - 1].getRecompensa();
            wv -= e[i - 1].getVol();
            wp -= e[i - 1].getPeso();
        }
    }

    for (const auto &i : aux)
        e.erase(e.begin() + i); // retirar estas encomendas do conjunto das encomendas que faltam ser distribuídas

    return lucro;
}

int Empresa::otimLucro(bool &tarefaCompleta) {
    for (auto &e : estafetas)
        e.esvaziar(); // retirar todas as encomendas das carrinhas (reset geral)

    mergeSort(estafetas, compCusto); // ordem crescente de custo
    mergeSort(encomendas, compRecompensa); // ordem decrescente de recompensa

    vector<Encomenda> aux = encomendas; // encomendas que faltam ser distribuídas pelas carrinhas
    int lucroTotal = 0;

    /* percorrer cada uma das carrinhas */
    for (int c = 0; c < (int)estafetas.size(); c++) {
        if (aux.empty()) { // todas as encomendas atribuídas
            tarefaCompleta = true;
            break;
        }

        lucroTotal += profit(c, aux); // adicionar lucro feito no caso dessa carrinha
    }

    return lucroTotal;
}

// ---------------------------------------------------------------------------------------------------

/**
 * Compara encomendas de acorda com os seus tempos de entrega
 *
 * @param e1 Encomenda
 * @param e2 Encomenda
 * @return Retorna true se o tempo da primeira encomenda for
 *         menor ou igual ao tempo da segunda, false em caso contrário
 */
bool compDuracao(const Encomenda &e1, const Encomenda &e2) {
    return e1.getDuracao() <= e2.getDuracao();
}

double Empresa::otimExpresso(bool &tarefaCompleta, vector<Encomenda> &P) {
    P.clear();
    mergeSort(encomendas, compDuracao); // ordem crescente de duração

    tarefaCompleta = false;
    int total = 0, s = 0, m = 0; // total: número de encomendas; s: soma das durações; m: soma acumulada

    /* percorrer conjunto das encomendas */
    for (int i = 0; i < (int)encomendas.size(); i++) {
        if (i == (int)encomendas.size() - 1) // todas as encomendas entregues
            tarefaCompleta = true;

        if (s + encomendas[i].getDuracao() > HOR_COMERCIAL) // com esta encomenda, tempo limite será ultrapassado
            break;
        else {
            total++;
            s += encomendas[i].getDuracao();
            m += s;
            P.push_back(encomendas[i]);
        }
    }

    double tempo = (double)(m) / (double)(total); // tempo médio mínimo
    return tempo;
}

// ---------------------------------------------------------------------------------------------------