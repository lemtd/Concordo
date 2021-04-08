#include "../include/System.h"
#include "../include/Extra.h"
#include "../include/Channel.h"
#include "../include/Text.h"
#include "../include/Voice.h"
#include "../include/Message.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <fstream>

#define BRT (-3)

//quit: sai do sistema
std::string System::quit() {
  return "Saindo do Concordo";
}

//create-user <user@email.com> <senha-user> <nome-user>: cria usuário
std::string System::create_user(const std::string email, const std::string password, const std::string name) {  
  int size = users.size() + 1;
  if(email == "" || name == "" || password == ""){
    return "Preencha todos os campos obrigatórios para poder concluir o cadastro";
  }
  if(searchingEmail(email) == false){
    User *user = new User(size, name, email, password);
    users.push_back(*user);
    return "Usuário criado";
  }else{
    return "Usuário já existe!";
  }
}

//login <user@email.com> <senha-user>: usuário faz login
std::string System::login(const std::string email, const std::string password) {
  serverConected = "";
  channelConected = "";
  if(userLogin != 0){
    if(searchingEmail(email)){
      for(std::vector<User>::iterator it = users.begin(); it != users.end(); it++){
        if(email == it->getEmail()){
          if(password == it->getPassword()){
            if(userLogin == it->getId()){
              return "Logado como " + it->getEmail();
            }
            userLogin = it->getId();
            return "Trocando de usuário... Logado como " + it->getEmail(); 
          }
        }
      }
    }
    return "Senha ou usuário inválidos!";
  }else{
    if(searchingEmail(email)){
      for(std::vector<User>::iterator it = users.begin(); it != users.end(); it++){
        if(email == it->getEmail()){
          if(password == it->getPassword()){
            userLogin = it->getId();
            return "Logado como " + it->getEmail(); 
          }
        }
      }
    }
    return "Senha ou usuário inválidos!";
  }        
}

//disconnect: usuário faz logoff
std::string System::disconnect() {
  if(userLogin != 0){
    for(std::vector<User>::iterator it = users.begin(); it != users.end(); it++){
      if(userLogin == it->getId()){
        userLogin = 0;
        serverConected = "";
        return "Desconectando usuário " + it->getEmail();
        break;        
      }
    }
  }
  return "Não está conectado";
}

//create-server <server-nome>: usuároi cria servidor
std::string System::create_server(const std::string name) {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder criar um Servidor";
  }else{
    if(name == ""){
      return "Preencha todos os campos obrigatórios para poder criar o Servidor";
    }
    serverConected = "";
    std::string code = "";
    std::string description = "";
    if(searchingServer(name) == false){
      Server *server = new Server(userLogin, name, code, description);
      servers.push_back(*server);
      for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
        if(name == it->getNameServer()){
          if(userLogin == it->getOwner()){
            it->ids.push_back(userLogin);
            serverConected = it->getNameServer();
          }
        }
      }
      return "Servidor criado";
    }else{
      return "Servidor com esse nome já existe";
    }
  }
}

//set-server-desc <server-nome> <descrição-server>: administrador modifica descrição do servidor
std::string System::set_server_desc(const std::string name, const std::string description) {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder modificar a descrição de um servidor";
  }else{
    if(servers.empty() == false){
      if(searchingServer(name)){
        for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
          if(name == it->getNameServer()){
            if(userLogin == it->getOwner()){
              it->setDescription('"' + description + '"');
              return "Descrição do servidor '" + it->getNameServer() + "' modificada!";
            }
          }
        }
        return "Você não pode alterar a descrição de um servidor que não foi criado por você";
      }else{
        return "Servidor '" + name + "' não encontrado";
      }
    }else{
      return "Servidor '" + name + "' não encontrado";
    }
  }
}

//set-server-invite-code <server-nome> <novo-código>: administrador modifica código de convite do servidor
std::string System::set_server_invite_code(const std::string name, const std::string invite) {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder modificar o código de convite para o servidor";
  }
  if(servers.empty() == false){
    for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
      if(name == it->getNameServer()){
        if(userLogin == it->getOwner()){
          it->setInvite(invite);
          if(invite == ""){
            return "Código de convite do servidor '" + it->getNameServer() + "' removido!";
          }else{
            return "Código de convite do servidor '" + it->getNameServer() + "' modificado!";
          }
        }
        return "Você não pode alterar o código de convite de um servidor que não foi criado por você";
      }
    }
    return "Servidor '" + name + "' não encontrado";
  }else{
    return "Servidor '" + name + "' não encontrado";
  }
}

//list-servers: usuário lista servidores
std::string System::list_servers() {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder listar os servidores disponíveis.";
  }else{
    if(servers.empty() == false){
      for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
        std::cout << it->getNameServer() << std::endl;
        std::cout << it->getDescription() << std::endl;
        if(it->getInvite() == ""){
          std::cout << "Servidor aberto" << std::endl;
        }else{
          std::cout << it->getInvite() << std::endl;
        }
      }
    }else{
      return "Não há servidores no sistema ainda";
    }
  }
  return "Lista de servidores finalizada";
}

//remove-server <server-nome>: usuário remove servidores
std::string System::remove_server(const std::string name) {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder remover servidores do sistema";
  }else{
    if(servers.empty() == false){
      if(searchingServer(name)){
        for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
          if(name == it->getNameServer()){
            if(userLogin == it->getOwner()){
              servers.erase(it);
              return "Servidor '" + name + "' removido";
            }
          }
        }
        return "Você não é o dono do servidor '" + name + "'";
      }else{
        return "Servidor '" + name + "' não encontrado";
      }
    }else{
      return "Servidor '" + name + "' não encontrado";
    }
  }
}

//enter-server <server-nome> <código-server>: usuário entra no servidor
std::string System::enter_server(const std::string name, const std::string invite) {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder acessar os servidores do sistema";
  }
  if(serverConected == name){
    return "Usuário já está no servidor";
  }else{
    for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
      if(name == it->getNameServer()){
        if(userLogin == it->getOwner()){
          for(std::vector<int>::iterator i = (*it).ids.begin(); i != (*it).ids.end(); i++){
            if(userLogin == *i){
              serverConected = it->getNameServer();
              return "Entrou no servidor com sucesso";
            }
          }
        }
        for(std::vector<int>::iterator i = (*it).ids.begin(); i != (*it).ids.end(); i++){
          if(userLogin == *i){
            serverConected = it->getNameServer();
            return "Entrou no servidor com sucesso";
          }
        }
        if(it->getInvite() == ""){
          it->ids.push_back(userLogin);
          serverConected = it->getNameServer();
          return "Entrou no servidor com sucesso";
        }
        if(invite == it->getInvite()){
          it->ids.push_back(userLogin);
          serverConected = it->getNameServer();
          return "Entrou no servidor com sucesso";
        }else{
          return "Servidor requer código de convite";
        }
      }
    }
    return "Servidor '" + name + "' não encontrado";
  }
}

//leave-server: usuário sai do servidor
std::string System::leave_server() {
  std::string out = serverConected;
  if(serverConected == ""){
    return "Usuário não está conectado a nenhum servidor";
  }
  serverConected = "";
  return "Saindo do servidor '" + out + "'";
}

//list-participants: usuário lista os participantes do servidor
std::string System::list_participants() {
  if(serverConected == "") {
    return "Usuário não está conectado em nenhum servidor";
  }else{
    for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
      if(serverConected == it->getNameServer()){
        for(std::vector<int>::iterator iv = it->ids.begin(); iv != it->ids.end(); iv++){
          for(std::vector<User>::iterator iu = users.begin(); iu != users.end(); iu++){
            if(*iv == iu->getId()){
              std::cout << iu->getName() << std::endl;
            }
          }
        }
      }
    }
    return "";
  }
}

std::string System::list_channels() {
  std::string chText = "";
  std::string chVoice = "";
  if(serverConected == "") {
    return "Usuário não está conectado em nenhum servidor";
  }else{
    chText = chText + "#canais de texto";
    chVoice = chVoice + "#canais de voz";
    for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
      if(it->getNameServer() == serverConected){
        for(std::vector<Channel*>::iterator ic = it->channels.begin(); ic != it->channels.end(); ic++){
          Text *chT = dynamic_cast<Text*>(*ic);
          Voice *chV = dynamic_cast<Voice*>(*ic);
          if(chT != nullptr){
            chText = chText + "\n" + chT->getNameCh();
          }else if(chV != nullptr){
            chVoice = chVoice + "\n" + chV->getNameCh();
          }
        }
      }
    }
  }
  return chText + "\n" + chVoice;
}

std::string System::create_channel(const std::string name, const std::string type) {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder criar canais em algum servidor do sistema";
  }
  if(serverConected == "") {
    return "Usuário não está conectado em nenhum servidor";
  }
  if(name == "" || type == ""){
    return "Preencha todos os campos obrigatórios para poder criar o Canal";
  }
  if(searchingChannel(name, type)){
    if(type == "texto" || type == "Texto"){
      return "Canal de texto '" + name + "' já existe!";
    }
    return "Canal de voz '" + name + "' já existe!";
  }
  for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
    if(it->getNameServer() == serverConected){
      if(it->getOwner() == userLogin){
        if(type == "texto" || type == "Texto"){
          Channel *channel = new Text;
          channel->setNameCh(name);
          it->channels.push_back(channel);
          channelConected = name;
          //channelTypeConected = type;
          return "Canal de texto '" + name + "' criado";
        }else if(type == "voz" || type == "Voz"){
          Channel *channel = new Voice;
          channel->setNameCh(name);
          it->channels.push_back(channel);
          channelConected = name;
          //channelTypeConected = type;
          return "Canal de voz '" + name + "' criado";
        }
      }
    }
  }
  return "";
}

std::string System::enter_channel(const std::string name) {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder acessar os canais dos servidores";
  }
  if(serverConected == "") {
    return "Usuário não está conectado em nenhum servidor";
  }
  if(channelConected == name){
    return "Usuário já está no canal";
  }else{
    for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
      if(serverConected == it->getNameServer()){
        for(std::vector<Channel*>::iterator ic = it->channels.begin(); ic != it->channels.end(); ic++){
          if((*ic)->getNameCh() == name){
            channelConected = (*ic)->getNameCh();
            return "Entrou no canal '" + name + "'";
          }
        }
      }
    }
    return "Canal '" + name + "' não existe";
  }
}

std::string System::leave_channel() {
  std::string out = channelConected;
  if(channelConected == ""){
    return "Usuário não está conectado a nenhum canal";
  }
  channelConected = "";
  return "Saindo do canal";
}

std::string System::send_message(const std::string message) {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder enviar mensagens nos canais de algum servidor do sistema";
  }
  if(serverConected == "") {
    return "Usuário não está conectado em nenhum servidor";
  }
  if(channelConected == "") {
    return "Usuário não está conectado em nenhum canal";
  }
  for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
    if(it->getNameServer() == serverConected){
      for(std::vector<Channel*>::iterator ic = it->channels.begin(); ic != it->channels.end(); ic++){
        if((*ic)->getNameCh() == channelConected){
          Text *t = dynamic_cast<Text*>(*ic);
          Voice *v = dynamic_cast<Voice*>(*ic);
          if(t != nullptr){
            Message sms(timetime(), userLogin, message);
            t->text.push_back(sms);
            return "Mensagem de texto enviada";
          }else if(v != nullptr){
            std::string print;
            for(std::vector<User>::iterator iu = users.begin(); iu != users.end(); iu++){
              if(iu->getId() == userLogin){
                print = iu->getName() + timetime() + ": " + message; 
              }
            }
            Message sms(print);
            v->setLast(sms);
            return "Mensagem de voz enviada";
          }
        }
      }
    }
  }
  return "";
}

std::string System::list_messages() {
  if(userLogin == 0){
    return "Usuário precisa estar logado para poder visualizar as mensagens dos canais em algum servidor do sistema";
  }
  if(serverConected == "") {
    return "Usuário não está conectado em nenhum servidor";
  }
  if(channelConected == "") {
    return "Usuário não está conectado em nenhum canal";
  }
  std::string print = "";
  for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
    if(it->getNameServer() == serverConected){
      for(std::vector<Channel*>::iterator ic = it->channels.begin(); ic != it->channels.end(); ic++){
        if((**ic).getNameCh() == channelConected){
          Text *t = dynamic_cast<Text*>(*ic);
          Voice *v = dynamic_cast<Voice*>(*ic);
          if(t != nullptr){
            for(std::vector<Message>::iterator itt = t->text.begin(); itt != t->text.end(); itt++){
              for(std::vector<User>::iterator iter = users.begin(); iter != users.end(); iter++){
                if((*itt).getSentBy() == iter->getId()){
                  if(print == ""){
                    print = iter->getName() + (*itt).getTime() + ": " + (*itt).getContent();
                  }else{
                    print = print + "\n" + iter->getName() + (*itt).getTime() + ": " + (*itt).getContent();
                  }
                }
              }
            }
            if(print == ""){
              return "Sem mensagens de texto para exibir";
            }
          }else if(v != nullptr){
            print = v->getLast();
            if(print == ""){
              return "Sem mensagens de voz para exibir";
            }
          }
        }
      }
    }
  }
  return print;
}

void System::save(){
  std::ofstream myfile;
  myfile.open("saveUsers.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
}


//Métodos auxiliares
//Função que percorre o vector users para ver se email se repete
bool System::searchingEmail(std::string email){
  if(users.empty() == false){
    for(std::vector<User>::iterator it = users.begin(); it != users.end(); it++){
      if(email == it->getEmail()){
        return true;
      }
    }
  }
  return false;
}

//Função que percorre o vector servers para ver se nome se repete
bool System::searchingServer(std::string name){
  if(servers.empty() == false){
    for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
      if(name == it->getNameServer()){
        return true;
      }
    }
  }
  return false;
}

//Função que percorre o vector channels para ver se canal se repete
bool System::searchingChannel(std::string name, std::string type){
  for(std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++){
    if(it->getNameServer() == serverConected){
      for(std::vector<Channel*>::iterator ic = it->channels.begin(); ic != it->channels.end(); ic++){
        Text *chText = dynamic_cast<Text*>(*ic);
        Voice *chVoice = dynamic_cast<Voice*>(*ic);
        if(type == "texto" || type == "Texto"){
          if(chText != nullptr){
            if(chText->getNameCh() == name){
              return true;
            }
          }
        }else if(type == "voz" || type == "Voz"){
          if(chVoice != nullptr){
            if(chVoice->getNameCh() == name){
              return true;
            }
          }
        }        
      }
    }
  }
  return false;
}

//Funçāo que retorna data e hora atual
std::string System::timetime(){
  struct tm *timeNow;
  int convert;
  std::string timeNowIs = "<";
  time_t seconds;
  time(&seconds);
  timeNow = gmtime(&seconds);
  if(timeNow->tm_hour == 00 || timeNow->tm_hour == 01 || timeNow->tm_hour == 02){
    convert = timeNow->tm_mday - 1;
  }else{
    convert = timeNow->tm_mday;
  }
  timeNowIs = timeNowIs + std::to_string(convert) + "/";
  convert = timeNow->tm_mon + 1;
  timeNowIs = timeNowIs + std::to_string(convert) + "/";
  convert = timeNow->tm_year + 1900;
  timeNowIs = timeNowIs + std::to_string(convert) + " - ";
  convert = timeNow->tm_hour;
  convert = (convert + BRT) % 24;
  if(convert == -1){
    convert = 23;
  }else if(convert == -2){
    convert = 22;
  }else if(convert == -3){
    convert = 21;
  }
  timeNowIs = timeNowIs + std::to_string(convert) + ":";
  convert = timeNow->tm_min;
  timeNowIs = timeNowIs + std::to_string(convert) + ":";
  convert = timeNow->tm_sec;
  timeNowIs = timeNowIs + std::to_string(convert) + ">";
  return timeNowIs;
}