#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

const int MAXI = 3;

struct Inimigo {
    std::string nome;
    int tipo;
    int hp;
    int queimando;
    bool congelado;
    int sangrando;
    bool pontofraco;
};

struct NoInimigo {
    int indice;
    NoInimigo *prox;
};

extern NoInimigo *inicioFila;
extern NoInimigo *fimFila;
extern Inimigo ini[MAXI];
extern int qntIni;

void enfilaIni(int indice);
void desenfilaIni();
void removerIni(int indice);
int escolherIni();
int alvoAleatorio();

#endif