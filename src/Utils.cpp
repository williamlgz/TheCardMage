#include "Utils.hpp"
#include <cstdlib>

using namespace std;

void esperarEnter() {
    cout << " (Pressione Enter para continuar...)";
    string enter;
    getline(cin, enter);
}

int sortearNumeroAleatorio(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}