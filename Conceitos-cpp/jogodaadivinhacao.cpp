#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    std::cout << "*****************************"<<std::endl;
    std::cout << "**** Jogo da adivinhação ****"<<std::endl;
    std::cout << "*****************************"<<std::endl;

    std::cout << "Escolha seu nível de dificuldade: " <<std::endl;
    std::cout << "Fácil(F), Médio(M), Difícil(D)";

    char dificuldade;
    std::cin >> dificuldade;

    int numero_de_tentativas;

    if (dificuldade == "F"){
        numero_de_tentativas = 15;
        std::cout << "Voçê possui 15 tentativas" << std::endl;
        
    } else if (dificuldade == "M"){
        numero_de_tentativas = 10;
        std::cout << "Voçê possui 10 tentativas" << std::endl;

    } else if (dificuldade == "D"){
        numero_de_tentativas = 5;
        std::cout << "Voçê possui 5 tentativas" << std::endl;
        
    } else {
        std::cou << "Escolha uma opção válida";
    }

    // srand() para determinar a semente dos valores aleatórios
    srand(time(NULL));
    const int NUMERO_SECRETO = 10 ;//rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0; 

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <=  numero_de_tentativas; tentativas++){
        int chute;
        std::cout << "Tentativas: " << tentativas << std::endl;
        std::cout << "Qual seu chute?: ";
        std::cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;

        std::count << "O valor do seu chute é: " << chute << std::endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou){
            std::cout << "Parabéns! Você acertou o número secreto!" << std::endl;
            nao_acertou = false;
            break;
        }
        else if (maior){
            std::cout << "Seu chute foi maior que o número secreto!" << std::endl;
        } else {
            std::cout << "Seu chute foi menor que o número secreto!" << std::endl;
        }

    }
    if (nao_acertou){
         cout << "Você perdeu! Tente novamente!" << endl;
        
    } else {
        std::cout << "Você acertou o número secreto em " << tentativas << " tentativas" << std::endl;
        srd::cout.precision(2);
        std::cout << fixed;
        std::cout << "VocÊ acertou o número secreto em " << tentativas << "tentativas" << std::endl;
    }
    



}
