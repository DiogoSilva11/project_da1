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
        getline(f, duracao, ' ');

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
        getline(f, custo, ' ');

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

template <class T>
void mergeSort(vector<T> &v);
template <class T>
void mergeSort(vector<T> &v, vector<T> &tmpArr, int left, int right);
template <class T>
void merge(vector<T> &v, vector<T> &tmpArr, int leftPos, int rightPos, int rightEnd);

template <class T>
void mergeSort(vector<T> &v) {
    vector<T> tmpArr(v.size());
    mergeSort(v, tmpArr, 0, v.size()-1);
}

template <class T>
void mergeSort(vector<T> &v, vector<T> &tmpArr, int left, int right) {
    if (left < right){
        int center = (left + right) / 2;
        mergeSort(v, tmpArr, left, center);
        mergeSort(v, tmpArr, center + 1, right);
        merge(v, tmpArr, left, center +1, right);
    }
}

template <class T>
void merge(vector<T> &v, vector<T> &tmpArr, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1, tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    while ( leftPos <= leftEnd && rightPos <= rightEnd )
        if ( v[leftPos] <= v[rightPos] )
            tmpArr[tmpPos++] = v[leftPos++];
        else
            tmpArr[tmpPos++] = v[rightPos++];
    while ( leftPos <= leftEnd )
        tmpArr[tmpPos++] = v[leftPos++];
    while ( rightPos <= rightEnd )
        tmpArr[tmpPos++] = v[rightPos++];
    for ( int i = 0; i < numElements; i++, rightEnd-- )
        v[rightEnd] = tmpArr[rightEnd];
}

// ---------------------------------------------------------------------------------------------------

unsigned Empresa::otimEstafetas(bool &tarefaCompleta, vector<Estafeta> &E, vector<Encomenda> &P) {
    mergeSort<Estafeta>(estafetas); // ordem descendente de capacidade
    mergeSort<Encomenda>(encomendas); // ordem descendente de carga

    // ir ocupando carrinhas ao maximo e ir contando as com um counter

    return 0;
}

double Empresa::otimLucro(bool &tarefaCompleta, vector<Estafeta> &E, vector<Encomenda> &P) {
    sort(estafetas.begin(), estafetas.end(),
         [](const Estafeta &e1, const Estafeta &e2)
         {
             return e1.getCusto() < e2.getCusto();
         });

    sort(encomendas.begin(), encomendas.end(),
         [](const Encomenda &e1, const Encomenda &e2)
         {
             return e1.getRecompensa() > e2.getRecompensa();
         });

    // to do

    return 0.0;
}

double Empresa::otimExpresso(bool &tarefaCompleta, vector<Encomenda> &P) {
    sort(encomendas.begin(), encomendas.end(),
         [](const Encomenda &e1, const Encomenda &e2)
         {
             return e1.getDuracao() < e2.getDuracao();
         });

    // to do

    return 0.0;
}

// ---------------------------------------------------------------------------------------------------