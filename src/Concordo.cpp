#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/Extra.h"
#include "../include/User.h"
#include "../include/Message.h"
#include "../include/Channel.h"
#include "../include/Text.h"
#include "../include/Voice.h"
#include "../include/Server.h"
#include "../include/System.h"
#include "../include/Executor.h"

char charRandom[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz" "0123456789";

int sizeCharRandom = sizeof(charRandom) - 1;


int main() {
  srand(time(0));

  // inicialização do sistema
  System system;
  Executor Executor(system);
  // o executor recebe o cin e o cout. Ele irá os utilizar para ler as linhas
  // de comando, executar o método correto em "sistema" e exibir as mensagens
  Executor.start(std::cin, std::cout);
  system.save();
  return 0;
}