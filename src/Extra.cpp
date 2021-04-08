#include "../include/Extra.h"

//Funções extras para gerar um código aleatório (ia ser utilizado ao criar um servidor, porém o servidor deve ser criado sem código)

//Função que retornará um caracter aleatório
char stringRandom(){
  return charRandom[rand() % sizeCharRandom];
}

//Função que formará uma string aleatória (o código de convite do servidor)
std::string randomCode(){
  std::string code;
  for(int i = 0; i < 15; i++){
    code = code + stringRandom();
  }
  return code;
}