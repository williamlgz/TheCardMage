#ifndef DECK_H
#define DECK_H

const int MAXB = 50;
const int MAXM = 5;

extern int topoBaralho;
extern int baralho[MAXB];
extern int topoDescarte;
extern int descarte[MAXB];
extern int mao[MAXM];

void pushBaralho(int elemento);
int popBaralho();
void pushDescarte(int elemento);
int popDescarte();
void embaralhar();
bool maoVazia();
bool maoCheia();

int particao(int inicio, int fim);
void quickSort(int inicio, int fim);

#endif