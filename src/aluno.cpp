#include "aluno.hpp"

// Construtores
Aluno::Aluno() 
    : nome(""), d1(0), d2(0), d3(0), d4(0), d5(0), frequencia(0), media(0.0f) {}

Aluno::Aluno(std::string nome, int d1, int d2, int d3, int d4, int d5, int frequencia)
    : nome(nome), d1(d1), d2(d2), d3(d3), d4(d4), d5(d5), frequencia(frequencia), media(0.0f) {}

//Métodos
void Aluno::calculaMedia() {
    media = (d1 + d2 + d3 + d4 + d5) / 5.0f;
}

// Getters
std::string Aluno::getNome() const {
    return nome;
}

int Aluno::getD1() const {
    return d1; 
}

int Aluno::getD2() const {
    return d2; 
}

int Aluno::getD3() const {
    return d3; 
}

int Aluno::getD4() const {
    return d4; 
}

int Aluno::getD5() const {
    return d5; 
}

int Aluno::getFrequencia() const {
    return frequencia;
}

float Aluno::getMedia() const {
    return media;
}


// Setters
void Aluno::setNome(const std::string& nome) {
    this->nome = nome;
}

void Aluno::setD1(int d1) {
    this->d1 = d1;
}

void Aluno::setD2(int d2) {
    this->d2 = d2;
}

void Aluno::setD3(int d3) {
    this->d3 = d3;
}

void Aluno::setD4(int d4) {
    this->d4 = d4;
}

void Aluno::setD5(int d5) {
    this->d5 = d5;
}

void Aluno::setFrequencia(int frequencia) {
    this->frequencia = frequencia;
}
