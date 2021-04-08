#ifndef TEXT_H
#define TEXT_H

#include "Message.h"
#include "Channel.h"
#include <vector>

class Text : public Channel{
  public:
    std::vector<Message> text; //Atributo da classe derivada Text

    Text(); //Construtor da classe Text
    ~Text(); //Destrutor da classe text

    /*//Setter do atributo da classe Text
    void setText(std::vector<Message> txt);

    //Getter do atributo da classe Text
    std::vector<Message> getText();*/
};

#endif