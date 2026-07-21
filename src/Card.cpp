#include "Card.h"
#include "Deck.h"
#include "Enemy.h"
#include "Combat.h"
#include "Utils.h"
#include <iostream>

using namespace std;

void conferirBaralho() {
    cout << "LISTA DE CARTAS\n";
    for (int i = 0; i <= topoBaralho; i++) {
        switch (baralho[i]) {
            case 1: cout << "001. Atacar\nEscolha um inimigo para tomar 1-2 de dano.\n"; break;
            case 2: cout << "002. Erguer Escudo\nCria um escudo que defende até 4 de dano. Não acumula.\n"; break;
            case 3: cout << "003. Arremessar Escudo\nAtinja dois inimigos aleatoriamente, dando 1-2 de dano em cada.\n"; break;
            case 4: cout << "004. Vontade Inabalável\nAumenta o dano dos próximos 3 ataques em 1. Não acumula.\n"; break;
            case 5: cout << "005. Bola de Fogo\nEscolha um inimigo para tomar 1-2 de dano. 50% de chance de congelamento.\n"; break;
            case 6: cout << "006. Bola de Gelo\nEscolha um inimigo para tomar 1-2 de dano. 50% de chance de queimadura.\n"; break;
            case 7: cout << "007. Autocura\nCure a si mesmo entre 2 a 5 de HP.\n"; break;
            case 8: cout << "008. Ponto Fraco\nAnalise um inimigo e até o fim da batalha dobre o dano recebido por ele.\n"; break;
            case 9: cout << "009. Ataque Duplo\nEscolha até dois inimigos e distribua dois ataques de 1-2 de dano.\n"; break;
            case 10: cout << "010. Infligir Sangramento\nEscolha um inimigo para dar 1-2 de dano. 50% de chance de sangramento.\n"; break;
            case 11: cout << "011. Troca de Vida\nTroque seu HP com o do inimigo.\n"; break;
            case 12: cout << "012. Roubar Essência\nEscolha um inimigo para dar 1-2 de dano e recuperar vida.\n"; break;
            case 13: cout << "013. Recuperar Ação\nRecupere uma carta já utilizada para sua mão.\n"; break;
            case 14: cout << "014. Arremessar Osso\nAcerte um inimigo aleatoriamente para dar 1-2 de dano.\n"; break;
        }
    }
}

string opCartas(int numcarta) {
    switch (numcarta) {
        case 1: return "Atacar (Escolha um inimigo para tomar 1-2 de dano.)\n";
        case 2: return "Erguer Escudo (Cria um escudo que defende até 4 de dano. Não acumula.)\n";
        case 3: return "Arremessar Escudo (Atinja dois inimigos aleatoriamente, dando 1-2 de dano em cada.)\n";
        case 4: return "Vontade Inabalável (Aumenta o dano dos próximos 3 ataques em 1. Não acumula)\n";
        case 5: return "Bola de Fogo (Escolha um inimigo para tomar 1-2 de dano. 50% de chance de congelamento.)\n";
        case 6: return "Bola de Gelo (Escolha um inimigo para tomar 1-2 de dano. 50% de chance de queimadura.)\n";
        case 7: return "Autocura (Cure a si mesmo entre 2 a 5 de HP.)\n";
        case 8: return "Ponto Fraco (Analise um inimigo e até o fim da batalha dobre o dano recebido por ele.)\n";
        case 9: return "Ataque Duplo (Escolha até dois inimigos e distribua dois ataques de 1-2 de dano.)\n";
        case 10: return "Infligir Sangramento (Escolha um inimigo para dar 1-2 de dano. 50% de chance de sangramento.)\n";
        case 11: return "Troca de Vida (Troque seu HP com o do inimigo.)\n";
        case 12: return "Roubar Essência (Escolha um inimigo para dar 1-2 de dano e recuperar a mesma quantidade de vida.)\n";
        case 13: return "Recuperar Ação (Recupere uma carta já utilizada para sua mão.)\n";
        case 14: return "Arremessar Osso (Acerte um inimigo aleatoriamente para dar 1-2 de dano.)\n";
    }
    return "";
}

void efeitoCartas(int numcarta) {
    int op, alvo1, alvo2;

    switch (numcarta) {
        case 1:
            op = escolherIni();
            if (op < 0 || op >= MAXI) {
                cout << "?: Seu paspalho! Essa opção é inválida e, por causa disso, você perdeu seu turno!";
                esperarEnter();
            } else {
                cout << "*Você arremessa uma carta contra o " << ini[op].nome << "!";
                esperarEnter();
                atacarIni(op);
            }
            break;

        case 2:
            defesa = 4;
            cout << "*A carta voa da sua mão e se transforma em um escudo de energia que o cerca.* (Vida do Escudo: 4)";
            esperarEnter();
            break;

        case 3: {
            int inimigosAntes = qntIni;
            alvo1 = alvoAleatorio();
            cout << "*A carta voa da sua mão e vira um escudo giratório que avança contra os inimigos, acertando o " << ini[alvo1].nome << "!*";
            esperarEnter();
            atacarIni(alvo1);

            if (inimigosAntes > 1) {
                do {
                    alvo2 = alvoAleatorio();
                } while (alvo2 == alvo1 && qntIni > 1);

                cout << "O escudo rebate e acerta o " << ini[alvo2].nome << " também!";
                esperarEnter();
                atacarIni(alvo2);
            } else {
                cout << "O escudo voa para longe e desaparece!";
                esperarEnter();
            }
            break;
        }

        case 4:
            cout << "*A carta se dissipa em suas mãos e você se sente capaz de ultrapassar por qualquer desafio!*";
            esperarEnter();
            buff = 3;
            break;

        case 5:
            op = escolherIni();
            if (op < 0 || op >= MAXI) {
                cout << "?: Seu paspalho! Essa opção é inválida e, por causa disso, você perdeu seu turno!";
                esperarEnter();
            } else {
                cout << "*A carta se transforma numa bola de fogo que avança contra o " << ini[op].nome << "!*";
                esperarEnter();
                atacarIni(op);
                chance = sortearNumeroAleatorio(0, 1);
                if (chance > 0) {
                    ini[op].queimando = 3;
                    cout << "?: Ele tá pegando fogo, bicho!";
                    esperarEnter();
                }
            }
            break;

        case 6:
            op = escolherIni();
            if (op < 0 || op >= MAXI) {
                cout << "?: Seu paspalho! Essa opção é inválida e, por causa disso, você perdeu seu turno!";
                esperarEnter();
            } else {
                cout << "*A carta se transforma numa bola de gelo que avança contra o " << ini[op].nome << "!*";
                esperarEnter();
                atacarIni(op);
                chance = sortearNumeroAleatorio(0, 1);
                if (chance > 0) {
                    ini[op].congelado = true;
                    cout << "?: Ele foi congelado! Você pareceu o Sub-Zero agora!";
                    esperarEnter();
                }
            }
            break;

        case 7:
            cura = sortearNumeroAleatorio(2, 5);
            hp += cura;
            if (hp > 50) hp = 50;
            cout << "*A carta voa na sua direção, atravessando o seu peito, mas você sente uma sensação revigorante ao invés da dor.*";
            esperarEnter();
            cout << "*Você recuperou " << cura << " pontos de vida!*";
            esperarEnter();
            break;

        case 8:
            op = escolherIni();
            if (op < 0 || op >= MAXI) {
                cout << "?: Seu paspalho! Essa opção é inválida e, por causa disso, você perdeu seu turno!";
                esperarEnter();
            } else {
                cout << "*A carta voa na direção do " << ini[op].nome << " e o atravessa, emitindo um brilho em seu ponto fraco!*";
                esperarEnter();
                ini[op].pontofraco = true;
            }
            break;

        case 9:
            op = escolherIni();
            if (op < 0 || op >= MAXI) {
                cout << "?: Esse inimigo já morreu. Normalmente, você perderia o turno por isso, mas... você ainda tem mais um ataque.";
                esperarEnter();
            } else {
                cout << "*Da carta, sai uma flecha que atinge o " << ini[op].nome << "!";
                esperarEnter();
                atacarIni(op);
            }

            op = escolherIni();
            if (op < 0 || op >= MAXI) {
                cout << "?: Seu paspalho! Essa opção é inválida e, por causa disso, você perdeu seu turno!";
                esperarEnter();
            } else {
                cout << "*A própria carta se transforma em uma flecha que atinge o " << ini[op].nome << "!";
                esperarEnter();
                atacarIni(op);
            }
            break;

        case 10:
            op = escolherIni();
            if (op < 0 || op >= MAXI) {
                cout << "?: Seu paspalho! Essa opção é inválida e, por causa disso, você perdeu seu turno!";
                esperarEnter();
            } else {
                cout << "*A carta se transforma numa adaga que avança contra o " << ini[op].nome << "!*";
                esperarEnter();
                atacarIni(op);
                chance = sortearNumeroAleatorio(0, 1);
                if (chance > 0) {
                    ini[op].sangrando = 3;
                    cout << "?: Ele tá sangrando!";
                    esperarEnter();
                    if (ini[op].tipo == 0) {
                        cout << "?: Mas, espera aí! Ele é um esqueleto! Isso não tá errado não?";
                        esperarEnter();
                    }
                }
            }
            break;

        case 11:
            op = escolherIni();
            cout << "*A carta desaparece e algo começa a escapar de dentro de você, era sua energia vital.*";
            esperarEnter();

            if (ini[op].hp <= 0) {
                cout << "*Porém, o " << ini[op].nome << " não estava mais vivo, então sua energia sai do seu corpo e nenhuma outra vem para substituí-la!";
                esperarEnter();
                hp = ini[op].hp;
                cout << "?: Você foi muito burro, sabia? Tsc. Preste atenção no que escolhe na próxima vez!";
                esperarEnter();
            } else {
                cout << "*O mesmo acontece com o " << ini[op].nome << ", e logo as duas energias saem de seus respectivos ex-donos e entram nos novos.*";
                temp = hp;
                hp = ini[op].hp;
                ini[op].hp = temp;
            }
            break;

        case 12:
            op = escolherIni();
            if (ini[op].hp <= 0 || op < 0 || op >= MAXM) {
                cout << "?: Seu paspalho! Essa opção é inválida e, por causa disso, você perdeu seu turno!";
                esperarEnter();
            } else {
                cout << "*A carta desaparece e uma parte da energia vital do " << ini[op].nome << " escapa dele e se une a você!";
                esperarEnter();
                atacarIni(op);

                if (ini[op].hp > 0) {
                    hp += dano;
                    if (hp > 50) hp = 50;
                    cout << "*Você recupera " << dano << " pontos de vida!*";
                    esperarEnter();
                } else {
                    hp = hp + dano + ini[op].hp;
                    if (hp > 50) hp = 50;
                    cout << "*Você recupera " << dano + ini[op].hp << " pontos de vida!";
                    esperarEnter();

                    if (!maoCheia()) {
                        cout << "*O cadáver do inimigo se transformou em uma carta que vai para sua mão!";
                        esperarEnter();
                        cout << "?: Eca! Cê vai mesmo pegar nisso?";
                        esperarEnter();

                        for (int i = 0; i < MAXM; i++) {
                            if (mao[i] < 0) {
                                mao[i] = 14;
                                break;
                            }
                        }
                    } else {
                        cout << "O cadáver do inimigo se transformou em uma carta... que continuou no chão.";
                        esperarEnter();
                        cout << "?: Que droga! Tua mão tá cheia demais pra receber aquela cartinha ali, uma pena!";
                        esperarEnter();
                    }
                }
            }
            break;

        case 13:
            for (int i = 0; i < MAXM; i++) {
                if (mao[i] < 0 && !maoCheia()) {
                    mao[i] = popDescarte();
                    if (mao[i] > 0) {
                        cout << "*Você recuperou a última carta utilizada!*";
                        esperarEnter();
                    } else {
                        cout << "*?: Nada aconteceu. Ou tua mão tá cheia ou você não usou nenhuma carta ainda!";
                        esperarEnter();
                    }
                    break;
                }
            }
            break;

        case 14:
            alvo1 = alvoAleatorio();
            cout << "*A carta voa da sua mão e vira um osso que atinge o " << ini[alvo1].nome << "!*";
            esperarEnter();
            atacarIni(alvo1);
            break;
    }

    pushDescarte(numcarta);
}