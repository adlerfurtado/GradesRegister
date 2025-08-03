# GradesRegister
Uma simples aplicação desenvolvida em C++, usando um servidor HTTP local, que permite aos usuários registrar e visualizar informações dos alunos, incluindo notas e frequência, por meio de uma interface web ou terminais de API.

Instruções para execução:
- Certifique-se de estar em um ambiente Linux (preferencialmente WSL com Ubuntu, como usado no desenvolvimento).
- No terminal, execute os seguintes comandos na pasta do projeto:

   make
   ./servidor.out

  -> O comando make compila o código-fonte em C++.
  -> O executável servidor.out inicia um servidor HTTP local.
- Em seguida, abra o arquivo index.html no seu navegador. Ele irá direcioná-lo para uma interface onde a aplicação pode ser utilizada normalmente.

Lista de Premissas Assumidas
- Cada aluno possui exatamente 5 notas em que variam de 0 à 10.
- A frequência é dada em percentual (0 a 100%).
- A média calculada se refere a uma média aritmética simples.
- A frequência é considerada baixa quando inferior à 75%.

Decisões de Projeto
- A linguagem escolhida foi C++ devido à minha maior familiaridade com a mesma.
- Utilizei da biblioteca cpp-httplib para realizar as requisições HTTP locais, pois acreditei ser a mais simples para realizar as mesmas, devido ao pouco tempo de realização do programa.}
- O projeto possui uma estrutura modular pois acredito ser indispensável em qualquer código, visto que melhora a visibilidade e organização do mesmo:
  -> aluno.hpp / aluno.cpp: definem e implementam a classe Aluno, com seus atributos e métodos necessários.
  -> main.cpp: concentra a lógica do servidor, controle de requisições e integração com o frontend.
- Interface desenvolvida em HTML com auxilio da biblioteca JSON para requisições e comunicação com o backend.
- Utilização do formato JSON para troca de dados entre frontend e backend foi escolhida devido minha maior familiaridae com esse formato, visto que já tive muito contato com banco de dados NOSQL (como o MongoDB) que também utilizam desse formato.
- Tentei ser o mais claro possível na separação entre backend e frontend, concentrando toda a lógica no back e interações no front.
- O projeto foi desenvolvido visando facilidade de leitura e manutenção, com estrutura simples e direta, ideal para aprendizado de quem possuiu pouco contato com tecnologias de frontend.
- Execução e testes foram feitos exclusivamente em ambiente Linux (Ubuntu via WSL).
