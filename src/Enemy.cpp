#include "Enemy.h"
#include "Utils.h"
#include <iostream>
#include <cstdlib>

using namespace std;

NoInimigo *inicioFila = NULL;
NoInimigo *fimFila = NULL;
Inimigo ini[MAXI];
int qntIni = 0;

void enfilaIni(int indice) {
    NoInimigo *novo = new NoInimigo;
    novo->indice = indice;
    novo->prox = NULL;

    if (fimFila == NULL) {
        inicioFila = novo;
        fimFila = novo;
    } else {
        fimFila->prox = novo;
        fimFila = novo;
    }
}

void desenfilaIni() {
    if (inicioFila != NULL) {
        NoInimigo *temp = inicioFila;
        inicioFila = inicioFila->prox;
        if (inicioFila == NULL) fimFila = NULL;
        delete temp;
    }
}

void removerIni(int indice) {
    NoInimigo *atual = inicioFila;
    NoInimigo *ant = NULL;

    while (atual != NULL) {
        if (atual->indice == indice) {
            if (ant == NULL) inicioFila = atual->prox;
            else ant->prox = atual->prox;

            if (atual == fimFila) fimFila = ant;
            delete atual;
            return;
        }
        ant = atual;
        atual = atual->prox;
    }
}

int escolherIni() {
    int op, contador = 1;
    NoInimigo *atual = inicioFila;

    cout << "\nESCOLHA UM INIMIGO\n";
    while (atual != NULL) {
        int i = atual->indice;
        cout << contador << ". " << ini[i].nome << " (" << ini[i].hp << " HP)\n";
        atual = atual->prox;
        contador++;
    }

    cout << "Opção: ";
    cin >> op;
    cin.ignore();

    if (op <= 0 || op >= contador) return -1;

    atual = inicioFila;
    for (int j = 1; j < op; j++) atual = atual->prox;

    return (atual == NULL) ? -1 : atual->indice;
}

int alvoAleatorio() {
    if (qntIni <= 0) return -1;
    int sorteio = rand() % qntIni;
    NoInimigo *atual = inicioFila;
    for (int i = 0; i < sorteio; i++) atual = atual->prox;
    return atual->indice;
}