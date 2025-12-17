#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

std::string palavra_secreta = "LEONA" ;
std::map<char, bool> chutou;
std::vector<char> chute_errado;

bool letra_existe(char chute){
    for (char letra : palavra_secreta) {
       if (chute == letra){
            return true;
       }   
    }
    return false;
}

bool nao_acertou(){
    for(char letra : palavra_secreta) {
        if (!chutou[letra]) {
            return true;
        } 
    }
    return false;
}

bool nao_enforcou(){
    return chute_errado.size() < 5;
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
    for (char letra : palavra_secreta) {
        if (chutou[letra]) {
            std::cout << letra << " ";
        } else{
            std::cout << " _ ";
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

    std::vector<std::string> le_arquivo(){
        std::ifstream arquivo;
        arquivo.open("palavras.txt");
    
        int quantidade_palavras;
        arquivo >> quantidade_palavras;
    
        std::vector<std::string> palavras_do_arquivo;
    
        for (int i = 0; i < quantidade_palavras; i++) {
            std::string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida); 
    }
    arquivo.close();
    return palavras_do_arquivo;
}

void sorteia_palavra(){
    std::vector<std::string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];

}

// Utilizamos o "foreach" no lugar do for
/*
for (int i = 0; i < palavra_secreta.size(); i++){
       if (chute == palavra_secreta[i]){
            return true;
       }
    }
*/

int main () {
    imprime_cabecalho();

    le_arquivo();
    sorteia_palavra();

    while (nao_acertou() && nao_enforcou()){
        imprime_erros();

        imprime_palavra();

        chuta();

    }

    std::cout << "Fim de jogo!" << std::endl;
    std::cout << "A palavra secreta era: " << palavra_secreta << std::endl;

    if (nao_acertou()) {
        std::cout << "Você perdeu! Tente novamente! " << std::endl;
    }else {
        std::cout << "Parabéns! Você acertou a palavra secreta!" << std::endl;
    }   
}