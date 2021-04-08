#include "../include/User.h"

//Construtor com parâmetros da classe User
User::User(int valueId, std::string valueName, std::string valueEmail, std::string valuePassword) {
  id = valueId;
  name = valueName;
  email = valueEmail;
  password = valuePassword;
} 
User::User() {} //Construtor sem parâmetros da classe User
User::~User() {} //Destrutor da classe User

//Setters dos atributos da classe User
void User::setId (int value) {
  id = value;
}
void User::setName(std::string n) {
  name = n;
}
void User::setEmail(std::string e) {
  email = e;
}
void User::setPassword(std::string p) {
  password = p;
}

//Getters dos atributos da classe User
int User::getId() {
  return id;
}
std::string User::getName() {
  return name;
}
std::string User::getEmail() {
  return email;
}
std::string User::getPassword() {
  return password;
}