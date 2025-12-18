#include <iostream>

double metrosParaCentimetros(double metros) {
    return metros * 100.0;
}

double centimetrosParaMetros(double centimetros) {
    return centimetros / 100.0;
}

double metrosParaQuilometros(double metros) {
    return metros / 1000.0;
}

double metrosParaMilhas(double metros) {
    const double FATOR_M_PARA_MILHA = 0.000621371;
    return metros * FATOR_M_PARA_MILHA;
}

double quilometrosParaMilhas(double quilometros) {
    double metros = quilometros * 1000.0;
    return metrosParaMilhas(metros);
}


int main() {
    int escolha;
    double valorEntrada;
    double valorSaida;

    std::cout << "Conversor de unidades de medidas" << std::endl;

    std::cout << "\nEscolha o tipo de conversão:" << std::endl;
    std::cout << "1: Metros (m) -> Centímetros (cm)" << std::endl;
    std::cout << "2: Centímetros (cm) -> Metros (m)" << std::endl;
    std::cout << "3: Metros (m) -> Quilômetros (km)" << std::endl;
    std::cout << "4: Metros (m) -> Milhas (mi)" << std::endl;
    std::cout << "5: Quilômetros (km) -> Milhas (mi)" << std::endl;

    std::cout << "Opção: ";
    std::cin >> escolha;

    std::cout << "Digite o valor a ser convertido: ";
    std::cin >> valorEntrada;

    switch (escolha) {
        case 1:
            valorSaida = metrosParaCentimetros(valorEntrada);
            std::cout << valorEntrada << " m equivalem a " << valorSaida << " cm." << std::endl;
            break;
        case 2:
            valorSaida = centimetrosParaMetros(valorEntrada);
            std::cout << valorEntrada << " cm equivalem a " << valorSaida << " m." << std::endl;
            break;
        case 3:
            valorSaida = metrosParaQuilometros(valorEntrada);
            std::cout << valorEntrada << " m equivalem a " << valorSaida << " km." << std::endl;
            break;
        case 4:
            valorSaida = metrosParaMilhas(valorEntrada);
            std::cout << valorEntrada << " m equivalem a " << valorSaida << " mi." << std::endl;
            break;
        case 5:
            valorSaida = quilometrosParaMilhas(valorEntrada);
            std::cout << valorEntrada << " km equivalem a " << valorSaida << " mi." << std::endl;
            break;
        default:
            std::cout << "\nOpção de conversão não reconhecida." << std::endl;
            break;
    }

    return 0;
}