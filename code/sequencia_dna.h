#ifndef SEQUENCIA_DNA_H
#define SEQUENCIA_DNA_H
#include <string>
#include <unordered_map>

using namespace std;

class SequenciaDNA {

    private:
        string sequencia;
        
    public:
        // Construtor que recebe o arquivo de sequência de DNA
        explicit SequenciaDNA(const string& nomeArquivo);

        // Método para obter a sequência de DNA
        const string& obterSequencia() const;

        // Método para contar a repetição de uma sequência de STR
        int contarRepeticoes(const string& str) const;

};

#endif
