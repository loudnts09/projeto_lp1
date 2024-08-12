#ifndef SAIDA_H
#define SAIDA_H
#include <string>
#include <unordered_map>
#include "armazenar_dados.h"

class Saida {
public:
    // Exibe o cabeçalho do programa
    void exibirCabecalho() const;

    // Exibe uma mensagem de status
    void exibirMensagemStatus(const std::string& mensagem) const;

    // Exibe o resultado do match
    void exibirResultadoMatch(const PerfilDna& perfil, const std::string& sequencia) const;

    // Exibe mensagem quando nenhum perfil é encontrado
    void exibirNoMatch() const;
};

#endif
