#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>

class Aluno {
private:
    std::string nome;
    int d1, d2, d3, d4, d5;
    int frequencia;
    float media;

public:
    // Construtores
    Aluno();
    Aluno(std::string nome, int d1, int d2, int d3, int d4, int d5, int frequencia);

    // Métodos
    void calculaMedia();

    // Getters
    std::string getNome() const;
    int getD1() const; 
    int getD2() const; 
    int getD3() const; 
    int getD4() const; 
    int getD5() const; 
    int getFrequencia() const;
    float getMedia() const;

    // Setters
    void setNome(const std::string& nome);
    void setD1(int d1);
    void setD2(int d2);
    void setD3(int d3);
    void setD4(int d4);
    void setD5(int d5);
    void setFrequencia(int frequencia);
};

#endif
