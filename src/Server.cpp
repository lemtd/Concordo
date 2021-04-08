#include "../include/Server.h"

//Construtor com parâmetros da classe Server
Server::Server(int id, std::string serverName, std::string code, std::string txt) {
  nameServer = serverName;
  owner = id;
  invite = code;
  description = txt;
} 
Server::Server() {} //Construtor sem parâmetros da classe Server
Server::~Server() {} //Destrutor da classe Server

//Setters da classe Server
void Server::setOwner(int id) {
  owner = id;
}
void Server::setNameServer(std::string serverName) {
  nameServer = serverName;
}
void Server::setDescription(std::string txt) {
  description = txt;
}
void Server::setInvite(std::string code) {
  invite = code;
}
/*void Server::setCh(std::vector<Channel> ch){
  channels = ch;
}
void Server::setIds(std::vector<int> userIds){
  ids = userIds;
}*/

//Getters da classe Server
int Server::getOwner() {
  return owner;
}
std::string Server::getNameServer() {
  return nameServer;
}
std::string Server::getDescription() {
  return description;
}
std::string Server::getInvite() {
  return invite;
}
/*std::vector<Channel> Server::getCh(){
  return channels;
}
std::vector<int> Server::getIds(){
  return ids;
}*/