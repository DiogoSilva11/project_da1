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
    int v, p, r, d;
    while (getline(f, vol, ' ')) {
        getline(f, peso, ' ');
        getline(f, recompensa, ' ');
        getline(f, duracao);

        v = stoi(vol);
        p = stoi(peso);
        r = stoi(recompensa);
        d = stoi(duracao);
        Encomenda e(v, p, r, d);
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

    string vol, peso, custo;
    int v, p, c;
    while (getline(f, vol, ' ')) {
        getline(f, peso, ' ');
        getline(f, custo);

        v = stoi(vol);
        p = stoi(peso);
        c = stoi(custo);
        Estafeta e(v, p, c);
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

template <typename T, class Comparable>
void mergeSort(vector<T> &v, Comparable comp);
template <typename T, class Comparable>
void mergeSort(vector<T> &v, vector<T> &tmpArr, int left, int right, Comparable comp);
template <typename T, class Comparable>
void merge(vector<T> &v, vector<T> &tmpArr, int leftPos, int rightPos, int rightEnd, Comparable comp);

template <typename T, class Comparable>
void mergeSort(vector<T> &v, Comparable comp) {
    vector<T> tmpArr(v.size());
    mergeSort(v, tmpArr, 0, v.size()-1, comp);
}

template <typename T, class Comparable>
void mergeSort(vector<T> &v, vector<T> &tmpArr, int left, int right, Comparable comp) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(v, tmpArr, left, center, comp);
        mergeSort(v, tmpArr, center + 1, right, comp);
        merge(v, tmpArr, left, center +1, right, comp);
    }
}

template <typename T, class Comparable>
void merge(vector<T> &v, vector<T> &tmpArr, int leftPos, int rightPos, int rightEnd, Comparable comp) {
    int leftEnd = rightPos - 1, tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    while ((leftPos <= leftEnd) && (rightPos <= rightEnd))
        if (comp(v[leftPos], v[rightPos])) // v[leftPos] <= v[rightPos]
            tmpArr[tmpPos++] = v[leftPos++];
        else
            tmpArr[tmpPos++] = v[rightPos++];
    while (leftPos <= leftEnd)
        tmpArr[tmpPos++] = v[leftPos++];
    while (rightPos <= rightEnd)
        tmpArr[tmpPos++] = v[rightPos++];
    for (int i = 0; i < numElements; i++, rightEnd--)
        v[rightEnd] = tmpArr[rightEnd];
}

// ---------------------------------------------------------------------------------------------------

bool compCapacidade(const Estafeta &e1, const Estafeta &e2) {
    return (e1.getVolMax() + e1.getPesoMax()) > (e2.getVolMax() + e2.getPesoMax());
}

bool compCarga(const Encomenda &e1, const Encomenda &e2) {
    return (e1.getVol() + e1.getPeso()) > (e2.getVol() + e2.getPeso());
}

unsigned Empresa::otimEstafetas(bool &tarefaCompleta) {
    for (auto e : estafetas)
        e.esvaziar();

    /* Best Fit Decreasing */

    mergeSort(estafetas, compCapacidade);
    mergeSort(encomendas, compCarga);

    tarefaCompleta = false;
    int num = 0, eTotal = (int)estafetas.size(), pTotal = (int)encomendas.size();

    for (int i = 0; i < pTotal; i++) {
        if (i == pTotal - 1)
            tarefaCompleta = true;

        if (num >= eTotal)
            break;
        else {
            int carrinha = 0, minVol = INT_MAX/2, minPeso = INT_MAX/2;
            int v = encomendas[i].getVol(), p = encomendas[i].getPeso();

            for (int j = 0; j < num; j++) {
                int restoV = estafetas[j].getRestoVol(), restoP = estafetas[j].getRestoPeso();
                if ((restoV >= v) && (restoP >= p) && (restoV - v < minVol) && (restoP - p < minPeso)) {
                    carrinha = j;
                    minVol = restoV - v;
                    minPeso = restoP - p;
                }
            }

            if ((minVol == INT_MAX/2) && (minPeso == INT_MAX/2)) {
                estafetas[num].addEncomenda(encomendas[i]);
                num++;
            }
            else
                estafetas[carrinha].addEncomenda(encomendas[i]);
        }
    }

    return num;
}

// ---------------------------------------------------------------------------------------------------

int Empresa::otimLucro(bool &tarefaCompleta) {
    for (auto e : estafetas)
        e.esvaziar();

    // to do

    return 0;
}

// ---------------------------------------------------------------------------------------------------

bool compDuracao(const Encomenda &e1, const Encomenda &e2) {
    return e1.getDuracao() <= e2.getDuracao();
}

double Empresa::otimExpresso(bool &tarefaCompleta, vector<Encomenda> &P) {
    P.clear();
    mergeSort(encomendas, compDuracao);

    tarefaCompleta = false;
    int total = 0, s = 0, m = 0;
    for (int i = 0; i < (int)encomendas.size(); i++) {
        if (i == (int)encomendas.size() - 1)
            tarefaCompleta = true;

        if (s + encomendas[i].getDuracao() > HOR_COMERCIAL)
            break;
        else {
            total++;
            s += encomendas[i].getDuracao();
            m += s;
            P.push_back(encomendas[i]);
        }
    }

    double r = m * 1.0, t = total * 1.0;
    return r / t;
}

// ---------------------------------------------------------------------------------------------------