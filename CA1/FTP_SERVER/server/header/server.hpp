#ifndef __SERVER_H__
#define __SERVER_H__

#include "user.hpp"
#include "configReader.hpp"

#include <string>
#include <vector>
#include <sys/socket.h>
#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CLIENTS 10

class Server{
public:
    Server(const std::string);
    void run();
    int setupServer(int);
    int acceptClient(int);
private:
    ConfigReader configReader;
    std::vector<std::string> adminFiles;
    std::vector<User*> users;
    int commandPort;
    int dataPort;
};

#endif