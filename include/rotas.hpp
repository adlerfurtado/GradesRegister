#ifndef ROTAS_HPP
#define ROTAS_HPP

#include <vector>
#include "httplib.h"
#include "aluno.hpp"

void rotaIndexHtml(httplib::Server& servidor);
void rotaCadastrarAluno(httplib::Server& servidor, std::vector<Aluno>& alunos);
void rotaListarAlunos(httplib::Server& servidor, std::vector<Aluno>& alunos);
void rotaAlunosAcimaMedia(httplib::Server& servidor, std::vector<Aluno>& alunos, float(*calculaMedia)(const std::vector<Aluno>&));
void rotaBaixaFrequencia(httplib::Server& servidor, std::vector<Aluno>& alunos);

#endif
