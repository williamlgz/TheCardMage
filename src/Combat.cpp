#include "Combat.h"
#include "Enemy.h"
#include "Utils.h"
#include <iostream>

using namespace std;

int dano = 0;
int defesa = 0;
int cura = 0;
int buff = 0;
int hp = 50;
int chance = 0;
int temp = 0;
int recompensa = 0;
int pocao = 3;

void atacarIni(int op) {
    dano = sortearNumeroAleatorio(1, 2);
    if (ini[op].pontofraco) dano *= 2;
    ini[op].hp -= dano;

    if (dano > 1) {
        cout << "*O ataque foi crítico!*";
        esperarEnter();
    }

    if (buff > 0) {
        ini[op].hp -= 1;
        cout << "*O ataque deu dano extra!*";
        esperarEnter();
        buff--;
    }

    if (ini[op].hp <= 0) {
        cout << "*O " << ini[op].nome << " morreu!*";
        qntIni--;
        removerIni(op);
        esperarEnter();
    }
}

void atacarJog(int op) {
    dano = sortearNumeroAleatorio(1, 2);

    if (defesa > 0) {
        defesa -= dano;
        cout << "O escudo bloqueou o ataque!";
        esperarEnter();

        if (defesa <= 0) {
            cout << "Mas ele se partiu!";
            esperarEnter();
            hp += defesa;
        }
    } else {
        hp -= dano;
    }

    if (dano > 1) {
        cout << "*O ataque foi crítico!*";
        esperarEnter();
    }

    if (ini[op].sangrando > 0) {
        hp += 1;
        cout << "*Porém, o ataque foi mais fraco do que deveria por conta do sangramento dele!*";
        esperarEnter();
        ini[op].sangrando--;

        if (ini[op].sangrando == 0) {
            cout << "*O inimigo parou de sangrar!";
            esperarEnter();
        }
    }
}