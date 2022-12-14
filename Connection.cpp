//
// Created by marcelghisi on 15/09/22.
//

#include "Connection.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "User.h"
#include <experimental/filesystem>

using namespace std;

Connection::Connection(std::string path){
    root_path = path;
    db_name = path.append("/ftp_database.dat").c_str();
    std::ifstream exists(db_name);
    if(!exists){
        std::cout << "Creating a new database file" << std::endl;
        std::ofstream file(db_name);
        file << "1;anonymous;123456;/anonymous;" << std::endl;
        file << "2;emilia;123456;/emilia;" << std::endl;
        file << "3;leticia;123456;/leticia;" << std::endl;
        file << "4;marcel;123456;/marcel;" << std::endl;
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

        std::stringstream bufH;
        bufH << root_path << user->getPath();
        if (!std::experimental::filesystem::exists(bufH.str()))
        {
            std::experimental::filesystem::create_directories(bufH.str());
        }

        users.push_back(user);
    }
    return users;
};