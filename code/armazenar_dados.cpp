#include "armazenar_dados.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Construtor da classe PerfilDna
PerfilDna::PerfilDna(const string& nome) : nome(nome) {}

// Adiciona uma contagem de STR ao perfil
void PerfilDna::setAdicionarStr(const string& str, int contagem) {
    strContagens[str] = contagem;
}

// Obtém o nome do indivíduo
string PerfilDna::getObterNome() const {
    return nome;
}

// Obtém a contagem de um STR específico
int PerfilDna::obterContagemStr(const string& str) const {
    auto it = strContagens.find(str);
    if (it != strContagens.end()) {
        return it->second;
    }
    return 0;
}

const unordered_map<string, int>& PerfilDna::getObterContagens() const {
    return strContagens;
}

// Carrega a base de dados a partir de um arquivo CSV
void BaseDeDados::carregarBaseDeDados(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string linha;

    // Verifica se o arquivo foi aberto corretamente
    if(!arquivo.is_open()){
        cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    // Lê a primeira linha (cabeçalho) e armazena os nomes dos STRs
    if(getline(arquivo, linha)){
        stringstream ss(linha);
        string str;
        bool primeiro = true;
        
        while (getline(ss, str, ',')) {
            if (primeiro) {
                primeiro = false; // Ignora a primeira coluna ("name")
            }
            else{
                strs.push_back(str); // Armazena o nome dos STRs
            }
        }
    }

    // Lê cada linha subsequente e armazena os perfis de DNA
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string celula;
        string nome;
        PerfilDna perfil("");

        // Lê o nome do indivíduo
        getline(ss, nome, ',');
        perfil = PerfilDna(nome);

        // Lê as contagens dos STRs e as armazena no perfil
        for (const auto& str : strs) {
            getline(ss, celula, ',');
            perfil.setAdicionarStr(str, stoi(celula));
        }

        perfis.push_back(perfil); // Adiciona o perfil ao vetor de perfis
    }

    arquivo.close(); // Fecha o arquivo após a leitura
}

// Obtém o perfil de um indivíduo pelo nome
PerfilDna BaseDeDados::obterPerfil(const string& nome) const {
    for (const auto& perfil : perfis) {
        if (perfil.getObterNome() == nome) {
            return perfil;
        }
    }
    return PerfilDna(""); // Retorna um perfil vazio se não for encontrado
}

// Obtém todos os perfis
const vector<PerfilDna>& BaseDeDados::obterTodosPerfis() const {
    return perfis;
}
