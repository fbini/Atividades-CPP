#include <iostream>


void tabuada(double numero) {
    for (int i = 0; i <= 10; i++) {
        int resultado = numero * i;
        std::cout << numero << "X" << i << "=" << resultado << std::endl;

    }

};

int main() {
    double numero;

    std::cout << "Digite um número para a tabuada: ";
    std::cin >> numero;

    tabuada(numero);
    return 0;

}