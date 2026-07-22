# 🃏 The Card Mage

Um RPG de cartas para terminal desenvolvido em C++, focado na aplicação prática de **Estruturas de Dados** e **Algoritmos de Ordenação**.

> 🎓 **Projeto Acadêmico:** Desenvolvido durante a disciplina de **Estrutura de Dados I** no **Cefet/RJ** (Unidade Maria da Graça).

---

## 🎯 Sobre o Projeto

*The Card Mage* é um jogo de estratégia em turno em que o jogador enfrenta hordas de inimigos utilizando um baralho customizável por classe (Guerreiro, Mago, Caçador ou Caótico). Cada ação, ataque, cura e manipulação de deck foi construída utilizando conceitos fundamentais de estrutura de dados aprendidos ao longo da graduação.

---

## 📌 Status do Projeto

> ⚠️ **Nota:** O jogo está em **fase de desenvolvimento / protótipo funcional (Alpha)**. 

Atualmente, o projeto conta com **1 horda de batalha (batalha de teste no coliseu)** para demonstrar todas as mecânicas de combate, gerenciamento de baralho e manipulação de fila de inimigos.

---

## 🛠️ Estruturas de Dados e Algoritmos Utilizados

O grande diferencial deste projeto é a implementação manual das estruturas e algoritmos necessários para a mecânica de jogo:

### 1. 🥞 Pilhas (Stacks)
- **Baralho e Descarte:** O baralho do jogador e a pilha de descarte foram estruturados com o conceito LIFO (*Last In, First Out*).
- **Mecânicas:** Compra de cartas (`popBaralho`), descarte (`pushDescarte`) e a carta de utilidade *Recuperar Ação*, que desempilha do descarte para a mão.

### 2. 🚶‍♂️ Fila Dinâmica (Queue with Linked List)
- **Gerenciamento de Inimigos:** Os inimigos ativos na batalha são organizados em uma **fila encadeada** (*Ponteiros*).
- **Mecânicas:** Os inimigos realizam ações por ordem de chegada na fila. Inimigos derrotados são removidos dinamicamente com manipulação de ponteiros (`NoInimigo*`).

### 3. ⚡ QuickSort (Divide and Conquer)
- **Ordenação do Baralho:** O jogador possui uma opção no menu para organizar o baralho. O algoritmo de ordenação escolhido foi o **QuickSort**, utilizando o esquema de partição para ordenar o ID das cartas em ordem crescente.

---

## 🚀 Como Compilar e Executar

### Pré-requisitos
- Compilador C++ com suporte a C++11 (`g++`, `clang++` ou `MSVC`)
- `CMake` (v3.10 ou superior)

### Via CMake (Recomendado)

**No Linux / macOS:**
```bash
mkdir build && cd build
cmake ..
cmake --build .
./TheCardMage
```

**No Windows:**
- Se estiver usando MinGW (GCC / g++):
```powershell
mkdir build; cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
.\TheCardMage.exe
```
- Se estiver usando Visual Studio (MSVC):
```powershell
mkdir build; cd build
cmake ..
cmake --build .
.\Debug\TheCardMage.exe
```

### Via Terminal Direto (g++)
```bash
g++ -I include src/*.cpp -o TheCardMage
./TheCardMage
```

---

## 📂 Estrutura do Projeto

```text
TheCardMage/
├── include/
│   ├── Card.hpp
│   ├── Combat.hpp
│   ├── Deck.hpp
│   ├── Enemy.hpp
│   └── Utils.hpp
├── src/
│   ├── Card.cpp
│   ├── Combat.cpp
│   ├── Deck.cpp
│   ├── Enemy.cpp
│   ├── Utils.cpp
│   └── main.cpp
├── .gitignore
├── CMakeLists.txt
└── README.md
```

---

## 🗺️ Roadmap (Próximos Passos)

O projeto continua em evolução! As próximas atualizações planejadas incluem:

- [x] Implementação do combate base e gerenciamento de cartas
- [x] Estrutura de dados para Fila de Inimigos e Pilha de Baralho/Descarte
- [x] Algoritmo QuickSort para ordenação do deck
- [x] Modularização do código C++ e configuração CMake
- [ ] Refatoração do código fonte para Inglês (*Clean Code*)
- [ ] Novas hordas de inimigos com comportamentos variados
- [ ] Sistema de progressão de fases/mapa e chefões (Bosses)
- [ ] Salvamento e carregamento de progresso (*Save System*)
- [ ] Suporte a cores no terminal (Códigos ANSI) e ASCII Art
- [ ] Módulos de internacionalização (i18n) para diálogos em PT/EN