#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "System.h"
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

class Executor {
  private:
    System* system;
    std::stringstream ss;
    bool exit = false;

  public:
    // Função de apoio que recebe um istringstream e
    // ler todo texto restante até o fim da linha
    std::string restOf(std::istringstream &ss);

    // Construtor. Recebe uma referência ao sistema que vai operar
    // Guarda o seu endereço para executar as operações.
    Executor(System &system);

    // Inicia o processamento dos comentos.
    // Esse método recebe por exemplo o "cin" e o "cout" no main
    // Dessa forma ele faz o necessário para ler 1 comando por linha e
    // o processar corretamente, colocando no stream de saída o resultado de cada um.
    void start(std::istream &inputStream, std::ostream &outputStream);

    // Método responsável por processar cada linha, capturando o nome do comando
    // e seus parâmetros em variáveis e executar o método correspondente no sistema
    std::string processLine(std::string linha);
};

#endif