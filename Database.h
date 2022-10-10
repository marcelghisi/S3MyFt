//
// Created by marcelghisi on 15/09/22.
//

#ifndef MY_FTP_DATABASE_H
#define MY_FTP_DATABASE_H

#include <string>
#include "Connection.h"
#include "defines.h"

class Database {
public:
    explicit Database(cstring database);

    bool connect(cstring user, cstring passw, cstring host);

    struct DBUser{
        int id;
        std::string homedir;
        std::string uname;
    };

    int auth(cstring uname, cstring pass);

    std::string last_error() const;

    DBUser getUserInfo(uint32_t id);

    void disconnect();
private:
    std::string error;
    std::string db_name;
    Connection conn;

};

#endif //MY_FTP_DATABASE_H