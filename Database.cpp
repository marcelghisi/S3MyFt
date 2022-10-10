//
// Created by marcelghisi on 15/09/22.
//

#include "Database.h"
#include <utility>
#include <cstring>

Database::Database(cstring database):
        db_name(std::move(database)),
        conn(database){

};

bool Database::connect(cstring user, cstring passw, cstring host) {
    conn.open(user.c_str(), passw.c_str());

    if (!conn.connected())
    {
        error = "Not connected";
        return false;
    }
    return true;
}


int Database::auth(cstring uname, cstring pass) {
    if (uname == "anonymous")
        return 1;

    std::string id = conn.auth(uname,pass);

    if (id.empty()){
        error = "User not found";
        return -1;
    }
    return std::stoi(id);
}
std::string Database::last_error() const {
    return error;
}

std::string get(std::list<std::string> _list, int _i){
    std::list<std::string>::iterator it = _list.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}

Database::DBUser Database::getUserInfo(uint32_t id) {
    DBUser userInfo;
    std::list<std::string> user = conn.find(id);
    if (user.empty()){
        error = "User not found";
        return {};
    }
    userInfo.id = id;
    userInfo.homedir = get(user,1).c_str();
    userInfo.uname = get(user,2).c_str();
    return userInfo;
}

void Database::disconnect()
{
    conn.close();
}
