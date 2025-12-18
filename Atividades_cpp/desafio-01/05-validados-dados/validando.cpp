#include <iostream>

class ValidadorDeDados {
public:

    std::string verificarParOuImpar(int numero) {
  
        if (numero % 2 == 0) {
            return "Par";
        } else {
            return "Ímpar";
        }
    }

    std::string verificarSinal(int numero) {
        if (numero > 0) {
            return "Positivo";
        } else if (numero < 0) {
            return "Negativo";
        } else {
            return "Zero";
        }
    }

    bool verificarAnoBissexto(int ano) {
        return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    }
};

int main() {
    ValidadorDeDados validador;
    int numero, ano;

    std::cout << "Validador de número" << std::endl;
    std::cout << "Digite um número: " << std::endl;
    std::cin >> numero;

    std::cout << "O número " << numero << " é " 
              << validador.verificarParOuImpar(numero) 
              << " e é classificado como " 
              << validador.verificarSinal(numero) << "." << std::endl;

    std::cout << "Validador de Ano Bissexto" << std::endl;
    std::cout << "Digite um ano: ";
    std::cin >> ano;

    std::cout << "O ano " << ano 
              << (validador.verificarAnoBissexto(ano) ? " é Bissexto." : " não é Bissexto.")
              << std::endl;

}