#include "../include/Voice.h"
#include <vector>

Voice::Voice() {} //Construtor da classe Voice
Voice::~Voice() {} //Destrutor da classe Voice

//Setter do atributo da classe Voice
void Voice::setLast(Message one) {
  last = one;
}

//Getter do atributo da classe Voice
std::string Voice::getLast() {
  return last.getContent();
}
