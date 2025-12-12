#include <iostream>
#include <string>

void cadastro(int& senha, std::string& usuario) {
    std::cout << "Bem vindo ao sistema de login" << std::endl;
    std::cout << "Defina seu usuário: " << std::endl;
    std::cin >> usuario;

    std::cout << "Defina sua senha: " << std::endl;
    std::cin >> senha;

    std::cout << "Cadastro realizado com sucesso! " << std::endl;
}

void tentativas(int senhaSalva, std::string& usuarioSalvo) {
    if (usuarioSalvo.empty()) {
        std::cout << "Usuário não cadastrado\nFaça o cadastro primeiro!";
        return;

    }

    int tentativaSenha = 0;
    std::string tentativaUsuario;
    int tentativasRestantes = 3;

    std::cout << "Bem vindo ao sistema de login, faça seu login" << std::endl;

    while (tentativasRestantes > 0) {
        std::cout << "Tentativas restantes: " << tentativasRestantes << std::endl;
    
        std::cout << "Seu usuário: " << std::endl;
        std::cin >> tentativaUsuario;

        std::cout << "Sua senha: " << std::endl;
        std::cin >> tentativaSenha;
    
         if (senhaSalva == tentativaSenha && usuarioSalvo == tentativaUsuario) {
                std::cout << "Acesso liberado!" << std::endl;
            } else {
                tentativasRestantes--;
                std::cout << "Senha ou usuário incorreto" << std::endl;
            }
    }
           
};

int main() {
    int senhaSalva = 0;
    std::string usuarioSalvo;

    int opcao;
do {
    std::cout << "Bem vindo ao sistema de login" << std::endl;
    std::cout << "1: Para cadastrar no sistema" << std::endl;
    std::cout << "2: Para logar" << std::endl;
    std::cout << "3: Sair" << std::endl;
    std::cout << "Opção: " << std::endl;
    std::cin >> opcao;

    switch (opcao)
    {
    case 1:
        cadastro(senhaSalva, usuarioSalvo);
        break;

    case 2:
        tentativas(senhaSalva, usuarioSalvo);
        break;
    case 3:
        std::cout << "Saindo do sistema..";
        break;
    
    default:
         std::cout << "Não foi possível acessar" << std::endl;
        break;
    }
    
} while (opcao != 3);

return 0;
   
}