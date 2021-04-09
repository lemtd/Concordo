#include "../include/Executor.h"

std::string Executor::restOf(std::istringstream &ss) {
  std::string resto;
  getline(ss, resto, '\0'); // ler o resto da linha
  if (resto != "" && (resto[0] == ' ' || resto[0] == '\t')) {
    resto = resto.substr(1); // o primeiro caractere é um espaço, descartar
  }
  return resto;
}

Executor::Executor(System &sistema) {
  this->exit = false;
  this->system = &sistema;
}

void Executor::start(std::istream &inputStream, std::ostream &outputStream) {
  std::string linha, saida;
  this->exit = false;
  while (! this->exit)
  {
    if (std::getline(inputStream, linha)) {
      saida = processLine(linha);
      outputStream << saida << std::endl;
    }
  }
}

std::string Executor::processLine(std::string linha) {
  std::istringstream buf(linha);
  std::string nomeComando;
  buf >> nomeComando;

  if (nomeComando.empty()) {
    return "Comando inválido <vazio>";
  }

  if (nomeComando == "quit" ) {
    this->exit = true;
    return system->quit();
  }

  else if (nomeComando == "create-user") {
    std::string email, senha, nome;
    buf >> email;
    buf >> senha;
    nome = restOf(buf);
    return system->create_user(email, senha, nome);
  }

  else if (nomeComando == "login") {
    std::string email, senha;
    buf >> email;
    buf >> senha;
    return system->login(email, senha);
  }

  else if (nomeComando == "disconnect") {
    return system->disconnect();
  }

  else if (nomeComando == "create-server") {
    std::string name;
    buf >> name;
    return system->create_server(name);
  }

  else if (nomeComando == "set-server-desc") {
    std::string nome, descricao;
    buf >> nome;
    descricao = restOf(buf);;
    return system->set_server_desc(nome, descricao);
  }

  else if (nomeComando == "set-server-invite-code") {
    std::string nome, codigo;
    buf >> nome;
    buf >> codigo;
    return system->set_server_invite_code(nome, codigo);
  }

  else if (nomeComando == "list-servers") {
    return system->list_servers();
  }

  else if (nomeComando == "remove-server") {
    std::string nome;
    buf >> nome;
    return system->remove_server(nome);
  }

  else if (nomeComando == "enter-server") {
    std::string nome, codigo;
    buf >> nome;
    buf >> codigo;
    return system->enter_server(nome, codigo);
  }

  else if (nomeComando == "leave-server") {
    return system->leave_server();
  }

  else if (nomeComando == "list-participants") {
    return system->list_participants();
  }

  else if (nomeComando == "list-channels") {
    return system->list_channels();
  }

  else if (nomeComando == "create-channel") {
    std::string nome, tipo;
    buf >> nome;
    buf >> tipo;
    return system->create_channel(nome, tipo);
  }

  else if (nomeComando == "enter-channel") {
    std::string nome;
    buf >> nome;
    return system->enter_channel(nome);
  }

  else if (nomeComando == "leave-channel") {
    return system->leave_channel();
  }
  
  else if (nomeComando == "send-message") {
    std::string mensagem;
    mensagem = restOf(buf);
    return system->send_message(mensagem);
  }
  
  else if (nomeComando == "list-messages") {
    return system->list_messages();
  }

  else {
    return "Comando não reconhecido [" + nomeComando + "]";
  }
}