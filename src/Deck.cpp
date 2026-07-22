#include "Deck.hpp"
#include <cstdlib>

int topoBaralho = -1;
int baralho[MAXB];
int topoDescarte = -1;
int descarte[MAXB];
int mao[MAXM] = {-1, -1, -1, -1, -1};

void pushBaralho(int elemento) {
    if (topoBaralho < MAXB - 1) {
        topoBaralho++;
        baralho[topoBaralho] = elemento;
    }
}

int popBaralho() {
    if (topoBaralho >= 0) {
        int elemento = baralho[topoBaralho];
        topoBaralho--;
        return elemento;
    }
    return -1;
}

void pushDescarte(int elemento) {
    if (topoDescarte < MAXB - 1) {
        topoDescarte++;
        descarte[topoDescarte] = elemento;
    }
}

int popDescarte() {
    if (topoDescarte >= 0) {
        int elemento = descarte[topoDescarte];
        topoDescarte--;
        return elemento;
    }
    return -1;
}

void embaralhar() {
    for (int i = topoBaralho; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

bool maoVazia() {
    for (int i = 0; i < MAXM; i++) {
        if (mao[i] > 0) return false;
    }
    return true;
}

bool maoCheia() {
    for (int i = 0; i < MAXM; i++) {
        if (mao[i] <= 0) return false;
    }
    return true;
}

int particao(int inicio, int fim) {
    int ref = baralho[inicio];
    int aux, i = inicio, j = fim;

    while (i < j) {
        while (baralho[i] <= ref && i < j) i++;
        while (baralho[j] > ref) j--;
        if (i < j) {
            aux = baralho[i];
            baralho[i] = baralho[j];
            baralho[j] = aux;
        }
    }
    baralho[inicio] = baralho[j];
    baralho[j] = ref;
    return j;
}

void quickSort(int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particao(inicio, fim);
        quickSort(inicio, pivo - 1);
        quickSort(pivo + 1, fim);
    }
}