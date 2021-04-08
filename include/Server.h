#ifndef SERVER_H
#define SERVER_H

#include "Channel.h"
#include <string>
#include <vector>

class Server {
  //Atributos da classe Server
  private:
    int owner;
    std::string nameServer;
    std::string description;
    std::string invite;

  public:
    //Atributos da classe Server (não soube colocar como privado e utilizar seus setters e getters, por isso está como público)
    std::vector<Channel*> channels;
    std::vector<int> ids;

    //Construtor com parâmetros da classe Server
    Server(int id, std::string nServer, std::string code, std::string txt);
    Server(); //Construtor sem parâmetros da classe Server
    ~Server(); //Destrutor da classe Server

    //Setters da classe Server
    void setOwner(int id);
    void setNameServer(std::string serverName);
    void setDescription(std::string txt);
    void setInvite(std::string code);
    /*void setCh(std::vector<Channel> ch);
    void setIds(std::vector<int> userIds);*/

    //Getters da classe Server
    int getOwner();
    std::string getNameServer();
    std::string getDescription();
    std::string getInvite();
    /*std::vector<Channel> getCh();
    std::vector<int> getIds();*/
};

#endif