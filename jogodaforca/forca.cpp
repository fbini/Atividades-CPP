#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

const std::string PALAVRA_SECRETA = "LEONA" ;
std::map<char, bool> chutou;
std::vector<char> chute_errado;

bool letra_existe(char chute){
    for (char letra : PALAVRA_SECRETA) {
       if (chute == letra){
            return true;
       }   
    }
    return false;
}

bool nao_acertou(){
    for(char letra : PALAVRA_SECRETA) {
        if (!chutou[letra]) {
            return true;
        } 
    }
    return false;
}

bool nao_enforcou(){
    return chute_errado.size() <= 5;
}

void imprime_cabecalho(){
    std::cout << "***********************" << std::endl;
    std::cout << "**** Jogo da forca ****" <<std::endl;
    std::cout << "***********************" << std::endl;
    std::cout << std::endl;
}

void imprime_erros(){
    std::cout << "Chutes errados: ";
    for (char letra : chute_errado){
        std::cout << letra << " " ;
    }
    std::cout << std::endl;

}

void imprime_palavra(){
    for (char letra : PALAVRA_SECRETA) {
        if (chutou[letra]) {
            std::cout << letra << " ";
        } else{
            std::cout << "_";
        }        
    }
    std::cout << std::endl;
}


void chuta(){
    std::cout << "Seu chute: " << std::endl;
    char chute;
    std::cin >> chute;
       
    chutou[chute] = true;

    if (letra_existe(chute)){
        std::cout << "Você acertou! Seu chute está na palavra" << std::endl;
    } else{
        std::cout << "Você errou! Seu chute não está na palavra" << std::endl;
        chute_errado.push_back(chute);
    }   
    std::cout << std::endl;
}

void le_arquivo(){
    std::ifstream arquivo;
    arquivo.open("palavras.txt");

    int quatidade_palavras;
    arquivo >> quantidade_palavras;

    std::cout << "O arquivo possui " << quantidade_palavras << " palavras" << std::endl;

    for (int i = 0; i < quantidade_palavras; i++) {
       std::string palavra_lida;
       arquivo >> palavra_lida;
       std::cout << "Na linha " << i << " : " << palavra_lida << std::endl;
    }
    
}

// Utilizamos o "foreach" no lugar do for
/*
for (int i = 0; i < PALAVRA_SECRETA.size(); i++){
       if (chute == PALAVRA_SECRETA[i]){
            return true;
       }
    }
*/

int main () {
    imprime_cabecalho();

    le_arquivo();

    while (nao_acertou() && nao_enforcou()){
        imprime_erros();

        imprime_palavra();

        chuta();

    }

    std::cout << "Fim de jogo!" << std::endl;
    std::cout << "A palavra secreta era: " << PALAVRA_SECRETA << std::endl;

    if (nao_acertou()) {
        std::cout << "Você perdeu! Tente novamente! " << std::endl;
    }else {
        std::cout << "Parabéns! Você acertou a palavra secreta!" << std::endl;
    }   
}