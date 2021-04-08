#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>
class Text;
class Voice;

class Channel {
  //Atributo da classe Channel
  protected:
    std::string nameCh;

  public:
    Channel(); //Construtor da classe Channel
    ~Channel(); //Destrutor da classe Channel

    //Setter do atributo da classe Channel
    virtual void setNameCh(std::string n);

    //Getter do atributo da classe Channel
    virtual std::string getNameCh();
};

#endif