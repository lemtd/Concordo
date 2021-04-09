#include "../include/Channel.h"

Channel::Channel() {} //Construtor da classe Channel
Channel::~Channel() {} //Destrutor da classe Channel

//Setter do atributo da classe Channel
void Channel::setNameCh(std::string n) {
  nameCh = n;
}

//Getter do atributo da classe Channel
std::string Channel::getNameCh() {
  return nameCh;
}