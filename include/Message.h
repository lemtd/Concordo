#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
  private:
    //Atributos da classe Message    
    std::string time;
    int sentBy;
    std::string content;
  
  public:
    Message(std::string date, int id, std::string c); //Construtor da classe Message
    Message(std::string c); //Construtor da classe Message
    Message(); //Construtor da classe Message
    ~Message(); //Destrutor da classe Message

    //Setters dos atributos da classe Message
    void setTime(std::string date);
    void setSentBy(int id);
    void setContent(std::string c);
    
    //Getters dos atributos da classe Message
    std::string getTime();
    int getSentBy();
    std::string getContent();
};

#endif