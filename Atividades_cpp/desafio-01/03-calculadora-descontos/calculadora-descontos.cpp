#include <iostream>

class CalculadoraDesconto{
public:
    double calcularPrecoFinal(double precoOriginal, double percentualDesconto) {

        double fatorDesconto = percentualDesconto / 100.0;
        double valorDesconto = precoOriginal * fatorDesconto;

        return precoOriginal - valorDesconto;
    }

    void imprimirResultado(double precoOriginal, double percentualDesconto, double precoFinal) {

        double valorDescontados = precoOriginal - precoFinal;

        std::cout << "Resumo descontos" << std::endl;
        std::cout << "Preço original: R$ " 
                  << precoOriginal 
                  << "\nPercentual de desconto: " 
                  << percentualDesconto 
                  << "%\n" 
                  << "Valor descontado: R$ " 
                  << valorDescontados 
                  << "\n" 
                  << "Preço final a pagar: R$ " 
                  << precoFinal 
                  << std::endl;

    }
};

int main() {
    double preco;
    double desconto;
    double precoAposDesconto;

    CalculadoraDesconto calculadora;

    std::cout << "Calculadora de descontos" << std::endl;

    std::cout << "Digite o preço original do produto: ";
    std::cin >> preco;

    std::cout << "Digite o desconto percentual: ";
    std::cin >> desconto;

    precoAposDesconto = calculadora.calcularPrecoFinal(preco, desconto);

    calculadora.imprimirResultado(preco, desconto, precoAposDesconto);

    return 0;
}