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
#include "User.h"
#include "vector"

using namespace std;

class Connection {
public:
    explicit Connection(cstring path);

    bool open(cstring admuser, cstring passw);

    std::vector<User*> load();

    std::string auth(cstring uname, cstring pass);


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
