#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Utils.h"
#include "Enemy.h"
#include "Deck.h"
#include "Card.h"
#include "Combat.h"

using namespace std;

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);       
    #endif

    int op, i, j, rodadas = 0;
    
    srand(time(NULL));
    
    cout << "?: Não há tempo para perder, então vamos precisar correr um pouquinho.";
    esperarEnter();
    
    cout << "?: Primeiramente, quem é você? Ou melhor... quem nós somos?";
    esperarEnter();
    
    cout << endl << "ESCOLHA SEU DECK INICIAL\n1 - Guerreiro\n2 - Mago\n3 - Caçador\nOpção: ";
    cin >> op;
    cout << endl;
    
    switch (op) {
        case 1:
            cin.ignore();
            cout << "?: Um guerreiro. Sério? Não poderia ser mais básico do que isso!";
            esperarEnter();
            cout << "?: Enfim, vamos só seguir em frente, okay?";
            esperarEnter();
            
            for (i = 0; i < 3; i++) pushBaralho(1);
            for (i = 2; i <= 4; i++) {
                for (j = 0; j < 3; j++) pushBaralho(i);
            }
            cout << "*Você ganhou 12 cartas do tipo Guerreiro!*";
            esperarEnter();
            break;

        case 2:
            cin.ignore();
            cout << "?: Ótima escolha, meu camarada! Vamos nos divertir bastante.";
            esperarEnter();
            
            for (i = 0; i < 3; i++) pushBaralho(1);
            for (i = 5; i <= 7; i++) {
                for (j = 0; j < 3; j++) pushBaralho(i);
            }
            cout << "*Você ganhou 12 cartas do tipo Mago!*";
            esperarEnter();
            break;

        case 3:
            cin.ignore();
            cout << "?: Interessante. Vamos virar basicamente um canhão de vidro.";
            esperarEnter();
            
            for (i = 0; i < 3; i++) pushBaralho(1);
            for (i = 8; i <= 10; i++) {
                for (j = 0; j < 3; j++) pushBaralho(i);
            }
            cout << "*Você ganhou 12 cartas do tipo Caçador!*";
            esperarEnter();
            break;

        default:
            cin.ignore();
            cout << "?: Cê tá com algum problema? Eu te dei só 3 opções! Argh!";
            esperarEnter();
            cout << "?: Quer saber? Deixa que eu escolho!";
            esperarEnter();
            
            for (i = 0; i < 3; i++) pushBaralho(1);
            for (i = 11; i <= 13; i++) {
                for (j = 0; j < 3; j++) pushBaralho(i);
            }
            cout << "*Você ganhou 12 cartas do tipo Caótico!*";
            esperarEnter();
    }
    
    cout << "?: Agora... o que vamos fazer?";
    esperarEnter();
    
    do {
        cout << endl << "O ÚLTIMO DOMADOR DE CARTAS\n"
             << "1. Batalhar\n"
             << "2. Conferir Baralho\n"
             << "3. Checar Status\n"
             << "4. Ordenar Baralho\n"
             << "5. Tomar Poção (+25 HP)\n"
             << "6. Sair\n"
             << "Opção: ";
        
        cin >> op;
        
        switch (op) {
            case 1:
                cin.ignore();
                rodadas = 0;

                cout << "?: Como esse é o início da nossa aventura e ainda não temos trama ALGUMA para o jogo, o que acha de uma batalha de teste para pegar os macetes?";
                esperarEnter();
                cout << "*De repente, o limbo de trevas onde você se encontrava se dissipa, revelando o centro do que parecia ser um tipo de coliseu abandonado.";
                esperarEnter();
                cout << "*Esqueletos de incontáveis criaturas estavam espalhados ao seu redor e, de um instante para o outro, 3 deles começam a brilhar.";
                esperarEnter();
                cout << "*3 esqueletos com chifres e armaduras se erguem, brandindo suas armas em sua direção!*";
                esperarEnter();
                
                ini[0].hp = 5; ini[1].hp = 5; ini[2].hp = 5;
                ini[0].nome = "Esqueleto"; ini[1].nome = "Esqueletão"; ini[2].nome = "Esqueletinho";
                
                for (i = 0; i < 3; i++) ini[i].tipo = 0;
                
                qntIni = 3;

                for (i = 0; i < MAXI; i++) enfilaIni(i);

                for (i = 0; i < 3; i++) {
                    ini[i].tipo = 0;
                    ini[i].queimando = 0;
                    ini[i].congelado = false;
                    ini[i].sangrando = 0;
                    ini[i].pontofraco = false;
                }
                
                while ((topoBaralho >= 0 || !maoVazia()) && hp > 0 && qntIni > 0) {
                    rodadas++;
                    cout << endl << "RODADA " << rodadas << endl;
                    cout << "HP: " << hp << endl << endl;
                    
                    if (rodadas == 1) {
                        cout << "*Um baralho de " << topoBaralho + 1 << " cartas surge no ar e começa a se embaralhar sozinho.*";
                        esperarEnter();
                        embaralhar();
                        cout << "?: No início de todo combate, nosso deck é primeiro embaralhado para depois sacarmos as cartas. Ajuda a manter a imprevisibilidade.";
                        esperarEnter();

                        cout << "*Você ergue sua mão dominante e 3 cartas voam até ela.*";
                        esperarEnter();
                        
                        mao[0] = popBaralho();
                        mao[1] = popBaralho();
                        mao[2] = popBaralho();
                        
                        cout << "?: Na primeira rodada, você sempre começa sacando 3 cartas, mas, nas próximas, será 1 por vez.";
                        esperarEnter();
                        cout << "?: Agora, vamos começar a batalha!";
                        esperarEnter();
                    } else if (topoBaralho >= 0 && !maoCheia()) {
                        cout << "*Você ergue sua mão dominante e 1 nova carta voa até ela.*";
                        esperarEnter();
                        
                        for (i = 0; i < MAXM; i++) {
                            if (mao[i] < 0) {
                                mao[i] = popBaralho();
                                break;
                            }
                        }
                    }
                    
                    if (maoCheia()) {
                        cout << "?: Sua mão tá cheia! Você não pode sacar mais cartas.";
                        esperarEnter();
                    }
                    
                    cout << endl << "ESCOLHA SUA CARTA\n";
                    for (i = 0; i < 5; i++) {
                        if (mao[i] > 0) {
                            cout << i + 1 << ": " << opCartas(mao[i]);
                        }
                    }
                    
                    cout << "Opção: ";
                    cin >> op;
                    op--;
                    cin.ignore();
                    
                    if (mao[op] == -1 || op < 0 || op >= MAXM) {
                        cout << "?: Seu paspalho! Essa opção é inválida e, por causa disso, você perdeu seu turno!";
                        esperarEnter();
                    } else {
                        int cartaUsada = mao[op];
                        mao[op] = -1;
                        efeitoCartas(cartaUsada);
                    }

                    if (qntIni > 0 && hp > 0) {
                        cout << endl << "TURNO INIMIGO" << endl;
                        NoInimigo *atual = inicioFila;

                        while (atual != NULL && hp > 0) {
                            int idx = atual->indice;
                            NoInimigo *prox = atual->prox;

                            if (ini[idx].congelado) {
                                ini[idx].congelado = false;
                                cout << "*O " << ini[idx].nome << " quebra o gelo que o prendia, mas perde o turno!*";
                                esperarEnter();
                            } else {
                                cout << "*O " << ini[idx].nome << " avança contra você e o atinge com um golpe de espada!*";
                                esperarEnter();
                                atacarJog(idx);
                            }

                            if (ini[idx].queimando > 0 && ini[idx].hp > 0) {
                                ini[idx].queimando--;
                                ini[idx].hp--;
                                cout << "O " << ini[idx].nome << " tomou dano pelas chamas!";
                                esperarEnter();

                                if (ini[idx].hp <= 0) {
                                    cout << "O " << ini[idx].nome << " morreu carbonizado!";
                                    esperarEnter();
                                    qntIni--;
                                    removerIni(idx);
                                } else if (ini[idx].queimando == 0) {
                                    cout << "Mas... o fogo apagou!";
                                    esperarEnter();
                                }
                            }
                            atual = prox;
                        }
                    }
                }
                
                if (hp <= 0) {
                    cout << "Seu corpo cai inerte no chão.";
                    esperarEnter();
                    cout << "GAME OVER";
                    esperarEnter();
                    return 0;
                } else if (topoBaralho < 0 && maoVazia()) {
                    cout << "?: Você está sem cartas, tanto na mão quanto no baralho. Sinto te dizer que... acabou.";
                    esperarEnter();
                    cout << "*Sem nenhuma carta restante, você é presa fácil para o que sobrou dos inimigos.*";
                    esperarEnter();
                    cout << "GAME OVER";
                    esperarEnter();
                    return 0;
                } else {
                    while (topoDescarte >= 0) pushBaralho(popDescarte());
                    
                    for (i = 0; i < MAXM; i++) {
                        if (mao[i] > 0) {
                            pushBaralho(mao[i]);
                            mao[i] = -1;
                        }
                    }
                    
                    while (inicioFila != NULL) desenfilaIni();

                    cout << endl << "FIM DE BATALHA";
                    esperarEnter();
                    cout << "?: Meus parabéns! Esse foi o último.";
                    esperarEnter();
                    cout << "?: Foi fácil, não foi? Não se preocupe, isso tá longe de acabar.";
                    esperarEnter();
                    cout << "?: Nos vemos novamente em outro momento. Mas, se quiser, pode repetir a mesma batalha.";
                    esperarEnter();
                    cout << "?: Para não ser tão chato, leve essas cartas novas.";
                    esperarEnter();
                    
                    recompensa = sortearNumeroAleatorio(1, 13);
                    for (i = 0; i < 3; i++) pushBaralho(recompensa);
                    
                    cout << "*Você recebeu 3 cartas novas!*";
                    esperarEnter();
                    cout << endl;
                    op = 0;
                }
                break;

            case 2:
                cin.ignore();
                cout << endl;
                conferirBaralho();
                break; 

            case 3:
                cin.ignore();
                cout << "*Você tem " << hp << " pontos de vida e " << topoBaralho + 1 << " cartas no baralho.*";
                esperarEnter();
                break;

            case 4:
                cin.ignore();
                quickSort(0, topoBaralho);
                cout << "*As cartas do baralho foram organizadas em ordem crescente!*";
                esperarEnter();
                break;

            case 5:
                cin.ignore();
                if (pocao > 0 && hp < 50) {
                    hp += 25;
                    pocao--;
                    if (hp > 50) hp = 50;
                    cout << "*Você bebeu uma poção e recuperou 25 pontos de vida!";
                    esperarEnter();
                    if (pocao > 0) {
                        cout << "*Restam " << pocao << " poções no seu inventário.*";
                        esperarEnter();
                    } else {
                        cout << "*Acabaram todas as poções do seu inventário!*";
                        esperarEnter();
                    }
                } else if (pocao > 0 && hp >= 50) {
                    cout << "?: Ei, ei, ei! Você tá inteiro, não precisa beber poção alguma!";
                    esperarEnter();
                } else {
                    cout << "?: Por que tá tateando os bolsos? Não tem mais poção nenhuma!";
                    esperarEnter();
                }
                break;
        }

    } while (op != 6);
    
    return 0;
}