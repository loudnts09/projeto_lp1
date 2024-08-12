#include "saida.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

using namespace std;

auto delay1 = chrono::milliseconds(5000);
auto delay2 = chrono::milliseconds(3000);


void Saida::exibirCabecalho() const {
    cout << "=======================================================" << endl;
    cout << "    Welcome to the Basic DNA Profiler, v1.0" << endl;
    cout << " Copyright (C) 2024, Lourrayni Feliph de A. A. Dantas" << endl;
    cout << "=======================================================" << endl << endl;
    this_thread::sleep_for(delay1);

    cout << "This program loads a DNA database and an unknown" << endl;
    cout << "DNA sequence and tries to find a match between" << endl;
    cout << "The input DNA sequence ad the DNA database." << endl << endl;
    this_thread::sleep_for(delay1);

}

void Saida::exibirMensagemStatus(const string& mensagem) const {
    cout << "[+] " << mensagem << endl;
}

void Saida::exibirResultadoMatch(const PerfilDna& perfil, const string& sequencia) const {
    // Mensagens de status com delay
    cout << "[+] Preparing to read the DNA file [data/data.csv]" << endl;
    this_thread::sleep_for(delay2);
    cout << "[+] Preparing to read the unknown DNA sequence file [data/sequence.csv]" << endl;
    this_thread::sleep_for(delay2);
    cout << "[+] Processing data, please wait." << endl << endl;
    this_thread::sleep_for(delay2);
    cout << "[+] Input files successfully read." << endl;
    this_thread::sleep_for(delay2);
    cout << "[+] Searching the database for a match... please wait." << endl << endl;
    this_thread::sleep_for(delay2);
    
    // Exibição do perfil
    cout << endl << "Match ID (99.9%): " << perfil.getObterNome() << endl;
    this_thread::sleep_for(delay2);
    cout << "DNA Profile:" << endl;
    this_thread::sleep_for(delay2);

    // Encontre o comprimento máximo do STR para alinhamento
    size_t maxLength = 0;
    for (const auto& str : perfil.getObterContagens()) {
        if (str.first.length() > maxLength) {
            maxLength = str.first.length();
        }
    }

    // Exiba as contagens e as setinhas
    stringstream linhaSetinhas;
    for (const auto& str : perfil.getObterContagens()) {
        cout << str.first << " [x" << str.second << "]" << endl;
        linhaSetinhas << string(maxLength - str.first.length(), ' ') << string(str.second, 'v') << endl;
    }

    // Exiba a sequência com as setinhas embaixo
    cout << endl << "[" << sequencia << "]" << endl;
    cout << linhaSetinhas.str();
}


void Saida::exibirNoMatch() const {
    cout << ">>> Sorry, no match in our database." << endl;
}
