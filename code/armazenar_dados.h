#ifndef ARMAZENAR_DADOS_H
#define ARMAZENAR_DADOS_H
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//classe para armazenar o perfil de DNA de um indivíduo
class PerfilDna{
  
    private:
        string nome; // Nome do indivíduo
        unordered_map<string, int> strContagens; // Contagens dos STRs

    public:
        // Construtor da classe
        PerfilDna(const string& nome);

        // Métodos para acessar e modificar os atributos
        void setAdicionarStr(const string& str, int contagem);
        string getObterNome() const;
        int obterContagemStr(const string& str) const;
        const unordered_map<string, int>& getObterContagens() const;


};

// Classe que representa a base de dados de DNA
class BaseDeDados {
    private:
    vector<PerfilDna> perfis; // Vetor que armazena todos os perfis de DNA
    vector<string> strs; // Vetor que armazena os nomes dos STRs

    public:
        // Método para carregar a base de dados de um arquivo CSV
        void carregarBaseDeDados(const string& nomeArquivo);

        // Método para obter o perfil de um indivíduo pelo nome
        PerfilDna obterPerfil(const string& nome) const;

        // Método para obter todos os perfis
        const vector<PerfilDna>& obterTodosPerfis() const;

};

#endif
