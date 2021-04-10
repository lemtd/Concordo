#include "../include/Message.h"

Message::Message(std::string date, int id, std::string c) {
  time = date;
  sentBy = id;
  content = c;
} //Construtor da classe Message

Message::Message() {} //Construtor da classe Message
Message::~Message() {} //Destrutor da classe Message

//Setters dos atributos da classe Message
void Message::setTime(std::string date) {
  time = date;
}
void Message::setSentBy(int id) {
  sentBy = id;
}
void Message::setContent(std::string c) {
  content = c;
}

//Getters dos atributos da classe Message
std::string Message::getTime() {
  return time;
}
int Message::getSentBy() {
  return sentBy;
}
std::string Message::getContent() {
  return content;
}