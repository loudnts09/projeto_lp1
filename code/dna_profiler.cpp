#include <iostream>
#include <unordered_map>
#include "armazenar_dados.h"
#include "sequencia_dna.h"
#include "saida.h"

using namespace std;

// Função para comparar dois perfis de DNA
bool compararPerfis(const unordered_map<string, int>& perfil1, const unordered_map<string, int>& perfil2) {
    for (const auto& str : perfil1) {
        if (perfil2.find(str.first) == perfil2.end() || perfil2.at(str.first) != str.second) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    // Verifica se a quantidade de argumentos é a correta
    if (argc != 5) {
        cerr << "Uso: " << argv[0] << " -d <arquivo_base_dados> -s <arquivo_sequencia_dna>" << endl;
        return 1;
    }

    string arquivoBaseDados;
    string arquivoSequenciaDNA;

    // Lê os argumentos da linha de comando
    for (int i = 1; i < argc; i += 2) {
        string opcao = argv[i];
        string nomeArquivo = argv[i + 1];

        if (opcao == "-d") {
            arquivoBaseDados = nomeArquivo;
        } else if (opcao == "-s") {
            arquivoSequenciaDNA = nomeArquivo;
        } else {
            cerr << "Opção inválida: " << opcao << endl;
            return 1;
        }
    }

    // Instância da classe BaseDeDados
    BaseDeDados baseDeDados;

    // Carrega a base de dados de DNA a partir do arquivo
    baseDeDados.carregarBaseDeDados(arquivoBaseDados);

    // Carrega a sequência de DNA
    SequenciaDNA sequenciaDNA(arquivoSequenciaDNA);

    // Gera perfil da sequência de DNA
    unordered_map<string, int> perfilDNA;
    for (const auto& str : baseDeDados.obterTodosPerfis().front().getObterContagens()) {
        int contagem = sequenciaDNA.contarRepeticoes(str.first);
        perfilDNA[str.first] = contagem;
    }

    // Instância da classe Saida
    Saida saida;
    saida.exibirCabecalho(); // Exibe o cabeçalho

    // Procurar o perfil na base de dados
    bool encontrado = false;
    for (const auto& perfil : baseDeDados.obterTodosPerfis()) {
        if (compararPerfis(perfil.getObterContagens(), perfilDNA)) {
            saida.exibirResultadoMatch(perfil, sequenciaDNA.obterSequencia());
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        saida.exibirNoMatch();
    }

    return 0;
}
