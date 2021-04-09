#ifndef VOICE_H
#define VOICE_H

#include "Message.h"
#include "Channel.h"

//Classe canal de voz
class Voice : public Channel{
  //Atributo da classe derivada Voice
  private:
    Message last;
  
  public:
    Voice(); //Construtor da classe Voice
    ~Voice(); //Destrutor da classe Voice

    //Setter do atributo da classe Voice
    void setLast(Message one);
    
    //Getter do atributo da classe Voice
    std::string getLast();
};

#endif