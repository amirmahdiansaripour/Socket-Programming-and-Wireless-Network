#include "../header/configReader.hpp"

using namespace std;

ConfigReader::ConfigReader(const string path_){
    path = path_;
    readConfigFile();
}

ConfigReader::ConfigReader(){
}

void ConfigReader::printData(){
    for(User* user : users){
        user->printUserData();
    }
    for(string fileName : adminFiles){
        cout << fileName << "\n";
    }
}

int ConfigReader::getCommandChannel(){
    return commandChannel;
}

int ConfigReader::getDataChannel(){
    return dataChannel;
}

void ConfigReader::readConfigFile(){
    ifstream inputFile(path);
    json j;
    inputFile >> j;
    for(auto record: j["users"]){
        string username = record["user"].get<string>();
        string password = record["password"].get<string>();
        bool isAdmin = false;
        string admin = record["admin"].get<string>(); 
        if(admin == "true")
            isAdmin = true;
        int size = stoi(record["size"].get<string>());
        size = (size * 1024); // convert into Bytes
        User* newUser = new User(username, password, size, isAdmin);
        users.push_back(newUser);
    }

    for(auto fileRecord: j["files"])
        adminFiles.push_back(fileRecord.get<string>());

    commandChannel = stoi(j["commandChannel"].get<string>());
    dataChannel = stoi(j["dataChannel"].get<string>());
    // printData();

}

vector<User*> ConfigReader::getUsers(){
    return users;
}

vector<string> ConfigReader::getAdminFiles(){
    return adminFiles;
}