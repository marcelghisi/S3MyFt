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
    users = conn.load();
    return true;
}


std::string Database::auth(cstring uname, cstring pass) {

    if (uname == "anonymous")
        return "1";

    User* theUser = findByUserName(uname);

    if (theUser == NULL){
        error = "User not found";
        return "0";
    }

    if (theUser->getPassword() == pass){
        return theUser->getId();
    } else {
        error = "Invalid password";
        return "0";
    }
}
std::string Database::last_error() const {
    return error;
}

User* Database::getUserInfo(std::string id) {
    User* userInfo = find(id);
    if (userInfo == NULL){
        error = "User not found";
        return NULL;
    }
    return userInfo;
}

User* Database::find(std::string id){
    User* userL;
    for (User *user : users) {
        if (user->getId() == id){
            userL = user;
            break;
        }
    }
    return userL;
}

User* Database::findByUserName(std::string userName){
    User* userL = NULL;
    for (User *user : users) {
        if (user->getName() == userName){
            userL = user;
            break;
        }
    }
    return userL;
}
void Database::disconnect()
{
    conn.close();
}
