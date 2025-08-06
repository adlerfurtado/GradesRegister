#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "json.hpp"
#include "httplib.h"
#include "aluno.hpp"
#include "rotas.hpp"

using json = nlohmann::json;

// Função auxiliar no main mesmo
float calculaMediaTurma(const std::vector<Aluno>& alunos) {
    if (alunos.empty()) return 0.0f;
    float soma = 0.0f;
    for (const auto& a : alunos) {
        soma += a.getMedia();
    }
    return soma / alunos.size();
}

int main() {
    std::vector<Aluno> alunos;
    httplib::Server servidor;
    
    servidor.set_mount_point("/", "./");            // index.html
    servidor.set_mount_point("/css", "./css");      // style.css
    servidor.set_mount_point("/js", "./js");        // script.js

    // Rotas principais da aplicação
    rotaIndexHtml(servidor);
    rotaCadastrarAluno(servidor, alunos);
    rotaListarAlunos(servidor, alunos);
    rotaAlunosAcimaMedia(servidor, alunos, calculaMediaTurma);
    rotaBaixaFrequencia(servidor, alunos);

    std::cout << "Servidor rodando em http://localhost:8080\n";
    servidor.listen("0.0.0.0", 8080);
}