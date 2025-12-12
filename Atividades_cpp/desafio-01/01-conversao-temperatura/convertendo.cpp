#include <iostream>

double converterCelsiusParaFahrenheit(double temperaturaCelsius) {
    return (temperaturaCelsius * 9.0 / 5.0) + 32.0;
}

int main() {
    double temperaturaCelsius;
    double temperaturaFahrenheit;

    std::cout << "Digite a temperatura em celsius para a conversão" << std::endl;
    std::cin >> temperaturaCelsius;

    temperaturaFahrenheit = converterCelsiusParaFahrenheit(temperaturaCelsius);

    std::cout << temperaturaCelsius 
              << "°C equivale a " 
              << temperaturaFahrenheit 
              << "°F" 
              << std::endl;

    return 0;

}

