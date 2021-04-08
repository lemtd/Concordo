#ifndef USER_H
#define USER_H

#include <string>

class User {
  private:
    //Atributos da classe User
    int id;
    std::string name;
    std::string email;
    std::string password;

  public:
    User(int valueId, std::string valueName, std::string valueEmail, std::string valuePassword); //Construtor com parâmetros da classe User
    User(); //Construtor sem parâmetros da classe User
    ~User(); //Destrutor da classe User

    //Setters dos atributos da classe User
    void setId (int value);
    void setName(std::string n);
    void setEmail(std::string e);
    void setPassword(std::string p);

    //Getters dos atributos da classe User
    int getId();
    std::string getName();
    std::string getEmail();
    std::string getPassword();
};

#endif