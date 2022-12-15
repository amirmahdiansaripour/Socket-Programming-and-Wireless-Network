#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include "../header/user.hpp"
#include <string>
#include <vector>

#define USER_SIGNIN "user"
#define PASS_SIGNIN "pass"

class MessageHandler{
public:
    MessageHandler(int id_);
    std::string handle(std::string message);
private:
    int id;
    int loginUsername(std::string username);
    int loginPassword(std::string password);
    std::vector<User> users;
    User* incompleteLoginUser;
    bool loggedIn;
    bool incompleteLogin;
    User* currentUser;
    
};

#endif