//
// Created by marcelghisi on 15/09/22.
//

#include "Connection.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "User.h"

using namespace std;

Connection::Connection(cstring path){
    db_name = "/home/marcelghisi/ftp_root/ftp_database.dat";
    std::ifstream exists(db_name);
    if(!exists){
        std::cout << "Creating a new database file" << std::endl;
        std::ofstream file(db_name);
        file.close();
    }

}

bool Connection::open(cstring admuser, cstring passw){
    try {
        data.open(db_name);
    } catch (std::exception& e)
    {
            cerr << e.what() << endl;
            is_connected = false;
            return false;
    }
    is_connected = true;
    return true;
}

bool Connection::connected(){
    return is_connected;
}

void Connection::close(){
    is_connected = false;
}

std::vector<User *> Connection::load() {
    std::vector<User*> users;
    std::string line;
    while ( std::getline(data, line) )
    {
        if (line.empty())
            continue;

        stringstream str(line);
        std::string word;
        std::vector<std::string> words;

        while(getline(str, word, ';')) {
            words.push_back(word);
        }
        User *user = new User();
        user->setId(words.at(0));
        user->setName(words.at(1));
        user->setPassword(words.at(2));
        user->setPath(words.at(3));
        users.push_back(user);
    }
    return users;
};