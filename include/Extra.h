#ifndef EXTRA_H
#define EXTRA_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Array do tipo char com as opções de caracteres para formar um código aleatório de convite do servidor ao criá-lo
extern char charRandom[];

//Armazenando a quantidade de carcateres
extern int sizeCharRandom;

//Função que retornará um caracter aleatório
char stringRandom();

//Função formando uma string aleatória (o código de convite do servidor)
std::string randomCode();

#endif