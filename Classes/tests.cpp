#include <gtest/gtest.h>
#include <fstream>
#include <time.h>
#include <sys/timeb.h>
#include <random>
#include <stdlib.h>

#include "Empresa.h"

using namespace std;

// ---------------------------------------------------------------------------------------------------

/**
 * Auxiliary functions to obtain current time and time elapsed
 * in milliseconds.
 * Something like GetTickCount but portable.
 * It rolls over every ~ 12.1 days (0x100000/24/60/60)
 * Use GetMilliSpan to correct for rollover
 */
int GetMilliCount() {
    timeb tb;
    ftime( &tb );
    int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
    return nCount;
}

int GetMilliSpan(int nTimeStart) {
    int nSpan = GetMilliCount() - nTimeStart;
    if (nSpan < 0)
        nSpan += 0x100000 * 1000;
    return nSpan;
}

// ---------------------------------------------------------------------------------------------------

TEST(test1, cenario1) {
    Empresa empresa;

    bool tarefa = false;
    unsigned numEstafetas;

    int nTimeStart = GetMilliCount();
    numEstafetas = empresa.otimEstafetas(tarefa);
    int nTimeElapsed = GetMilliSpan(nTimeStart);

    cout << "\ntestNP > otimEstafetas(): " << nTimeElapsed << " ms\n";
    cout << "numEstafetas: " << numEstafetas << endl << endl;

    EXPECT_TRUE(numEstafetas <= 22);
    EXPECT_TRUE(tarefa);
}

TEST(test2, cenario2) {
    Empresa empresa;

    bool tarefa = false;
    double lucro;

    int nTimeStart = GetMilliCount();
    lucro = empresa.otimLucro(tarefa);
    int nTimeElapsed = GetMilliSpan(nTimeStart);

    cout << "\ntestNP > otimLucro(): " << nTimeElapsed << " ms\n";
    cout << "lucro: " << lucro << endl << endl;

    EXPECT_TRUE(lucro >= 220000);
    EXPECT_FALSE(tarefa);
}

TEST(test3, cenario3) {
    Empresa empresa;

    bool tarefa = false;
    vector<Encomenda> encomendasEntregues;
    double tempo;

    int nTimeStart = GetMilliCount();
    tempo = empresa.otimExpresso(tarefa, encomendasEntregues);
    int nTimeElapsed = GetMilliSpan(nTimeStart);

    cout << "\ntestNP > otimExpresso(): " << nTimeElapsed << " ms\n";
    cout << "tempo: " << tempo << endl << endl;

    EXPECT_TRUE(tempo < 11730.0);
    EXPECT_FALSE(tarefa);
    EXPECT_TRUE((int)encomendasEntregues.size() <= 450);
}

// ---------------------------------------------------------------------------------------------------