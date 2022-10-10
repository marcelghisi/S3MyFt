//
// Created by marcelghisi on 15/09/22.
//

#include "Connection.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Connection::Connection(cstring path){
    db_name = "/tmp/ftp_database.dat";
    std::ifstream exists(db_name);
    if(!exists){
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

std::string Connection::auth(cstring uname, cstring pass){
    std::vector<std::string> lines;
    std::string line;
    while ( std::getline(data, line) )
    {
        if (line.empty())
            continue;
        lines.push_back(line);
    }
    return "1";
}

std::list<std::string> Connection::find(uint32_t id){
    std::list<std::string> user;
    user.emplace_front("1");
    user.emplace_back("");
    user.emplace_back("anonymous");
    user.emplace_back("123456789");
    return user;
}

bool Connection::connected(){
    return is_connected;
}

void Connection::close(){
    is_connected = false;
};