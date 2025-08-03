#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "json.hpp"
#include "httplib.h"
#include "aluno.hpp"

using json = nlohmann::json;

// Função para calcular a média da turma
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

    // Servir o index.html
    servidor.Get("/", [](const httplib::Request&, httplib::Response& res) {
        std::ifstream file("index.html");
        if (!file.is_open()) {
            res.status = 404;
            res.set_content("Arquivo index.html não encontrado!", "text/plain");
            return;
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        res.set_content(buffer.str(), "text/html");
    });

    // Cadastrar aluno
    servidor.Post("/api/aluno", [&](const httplib::Request& req, httplib::Response& res) {
        try {
            json j = json::parse(req.body);

            Aluno a;
            a.setNome(j["nome"].get<std::string>());
            a.setD1(j["d1"].get<int>());
            a.setD2(j["d2"].get<int>());
            a.setD3(j["d3"].get<int>());
            a.setD4(j["d4"].get<int>());
            a.setD5(j["d5"].get<int>());
            a.setFrequencia(j["frequencia"].get<int>());
            a.calculaMedia();

            if (a.getD1() < 0 || a.getD1() > 10 || 
    a.getD2() < 0 || a.getD2() > 10 || 
    a.getD3() < 0 || a.getD3() > 10 || 
    a.getD4() < 0 || a.getD4() > 10 || 
    a.getD5() < 0 || a.getD5() > 10 || 
    a.getFrequencia() < 0 || a.getFrequencia() > 100) {
    res.status = 400;
    res.set_content("Erro: As notas devem estar entre 0 e 10, e a frequência entre 0 e 100.", "text/plain");
    return;
}

            alunos.push_back(a);

            std::string resposta = "Aluno " + a.getNome() +
                                   " cadastrado com média " +
                                   std::to_string(a.getMedia());
            res.set_content(resposta, "text/plain");
        } 
        catch (std::exception& e) {
            res.status = 400;
            res.set_content(std::string("Erro ao processar JSON: ") + e.what(), "text/plain");
        }
    });

    // Retornar todos os alunos
    servidor.Get("/api/alunos", [&](const httplib::Request&, httplib::Response& res) {
        json lista = json::array();
        for (const auto& a : alunos) {
            lista.push_back({
                {"nome", a.getNome()},
                {"media", a.getMedia()},
                {"frequencia", a.getFrequencia()}
            });
        }
        res.set_content(lista.dump(), "application/json");
    });

    // Retornar alunos acima da média da turma
servidor.Get("/api/acimaMedia", [&](const httplib::Request&, httplib::Response& res) {
    float mediaTurma = calculaMediaTurma(alunos);
    json lista = json::array();
    for (const auto& a : alunos) {
        if (a.getMedia() > mediaTurma) {
            lista.push_back({
                {"nome", a.getNome()},
                {"media", a.getMedia()}
            });
        }
    }
    res.set_content(lista.dump(), "application/json");
});

// Retornar alunos com frequência abaixo de 75%
servidor.Get("/api/baixaFrequencia", [&](const httplib::Request&, httplib::Response& res) {
    json lista = json::array();
    for (const auto& a : alunos) {
        if (a.getFrequencia() < 75) {
            lista.push_back({
                {"nome", a.getNome()},
                {"frequencia", a.getFrequencia()}
            });
        }
    }
    res.set_content(lista.dump(), "application/json");
});

    std::cout << "Servidor rodando em http://localhost:8080\n";
    servidor.listen("0.0.0.0", 8080);
}
