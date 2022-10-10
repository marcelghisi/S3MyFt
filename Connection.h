//
// Created by marcelghisi on 15/09/22.
//

#ifndef MY_FTP_CONNECTION_H
#define MY_FTP_CONNECTION_H

#include <string>
#include "defines.h"
#include <list>
#include <fstream>
#include <iostream>

using namespace std;

class Connection {
public:
    explicit Connection(cstring path);

    bool open(cstring admuser, cstring passw);

    std::string auth(cstring uname, cstring pass);

    std::list<std::string> find(uint32_t id);

    bool connected();

    void close();
private:
    std::string error;
    std::string db_name;
    bool is_connected;
    //ofstream data;
    std::ifstream data;
};


#endif //MY_FTP_CONNECTION_H
