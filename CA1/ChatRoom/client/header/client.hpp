#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <sys/socket.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netinet/in.h>

const std::vector<std::string> messageID = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", 
"1110", "1111"};

const std::string LISTCOMMAND       = "list";
const std::string INFOCOMMAND       = "info";
const std::string SENDCOMMAND       = "send";
const std::string RECEIVECOMMAND    = "receive";
const std::string QUITCOMMAND       = "quit";

const std::string CONNECT   = "0001";      //1
const std::string LIST      = "0011";      //3
const std::string INFO      = "0101";      //5
const std::string SEND      = "0111";      //7
const std::string RECEIVE   = "1001";      //9

class Client{
public:
    Client(int, std::string);
    void run();
    int connectServer(int);
    void sendInitData();
    void infoReq(std::string);
    void listReq(std::string);
    void sendReq(std::string);
    void receiveReq(std::string);
    void quitReq();
private:
    int port;
    std::string name;
    int commandChannel;
};

#endif