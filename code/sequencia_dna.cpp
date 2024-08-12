#include "sequencia_dna.h"
#include <fstream>
#include <iostream>

using namespace std;

SequenciaDNA::SequenciaDNA(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    getline(arquivo, sequencia);
    arquivo.close();
}

const string& SequenciaDNA::obterSequencia() const {
    return sequencia;
}

int SequenciaDNA::contarRepeticoes(const string& str) const {
    int contagemMax = 0;
    int comprimentoSTR = str.length();
    int tamanhoSequencia = sequencia.length();
    
    for (int i = 0; i < tamanhoSequencia; ++i) {
        int contagemAtual = 0;
        
        while (sequencia.substr(i, comprimentoSTR) == str) {
            contagemAtual++;
            i += comprimentoSTR;
        }
        
        if (contagemAtual > contagemMax) {
            contagemMax = contagemAtual;
        }
    }
    
    return contagemMax;
}
