#ifndef SYSTEM_H
#define SYSTEM_H

#include "User.h"
#include "Server.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <time.h>

class System {
  //Atributos da classe System
  private:
    std::vector<User> users;
    std::vector<Server> servers;
    int userLogin;
    std::string serverConected;
    std::string channelConected;
    void saveUsers();
    void saveServers();

  public:
    //quit: sai do sistema
    std::string quit();
    //create-user <user@email.com> <senha-user> <nome-user>: cria usuário
    std::string create_user(const std::string email, const std::string password, const std::string name);
    //login <user@email.com> <senha-user>: usuário faz login
    std::string login(const std::string email, const std::string password);
    //disconnect: usuário faz logoff
    std::string disconnect();
    //create-server <server-nome>: usuároi cria servidor
    std::string create_server(const std::string name);
    //set-server-desc <server-nome> <descrição-server>: administrador modifica descrição do servidor
    std::string set_server_desc(const std::string name, const std::string description);
    //set-server-invite-code <server-nome> <novo-código>: administrador modifica código de convite do servidor
    std::string set_server_invite_code(const std::string name, const std::string invite);
    //list-servers: usuário lista servidores
    std::string list_servers();
    //remove-server <server-nome>: usuário remove servidores
    std::string remove_server(const std::string name);
    //enter-server <server-nome> <código-server>: usuário entra no servidor
    std::string enter_server(const std::string name, const std::string invite);
    //leave-server: usuário sai do servidor
    std::string leave_server();
    //list-participants: usuário lista os participantes do servidor
    std::string list_participants();
    std::string list_channels();
    std::string create_channel(const std::string nome, const std::string tipo);
    std::string enter_channel(const std::string nome);
    std::string leave_channel();
    std::string send_message(const std::string mensagem);
    std::string list_messages();
    
    //Métodos auxiliares
    //verifica se email já existe no sistema
    bool searchingEmail(std::string email); //verifica se servidor já existe no sistema 
    bool searchingServer(std::string name); //verifica se o canal já existe no sistema 
    bool searchingChannel(std::string name, std::string type);
    //méétodo que retorna data e hora atual
    std::string timeNow();
};

#endif