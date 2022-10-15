//
// Created by marcelghisi on 13/10/22.
//

#ifndef MY_FTP_USER_H
#define MY_FTP_USER_H
#include "iostream"

class User {

private:
    std::string id;
    std::string name;
    std::string password;
    std::string path;

public:
    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    const std::string &getPath() const;

    void setPath(const std::string &path);
};


#endif //MY_FTP_USER_H
