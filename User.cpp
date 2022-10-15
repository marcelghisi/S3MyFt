//
// Created by marcelghisi on 13/10/22.
//

#include "User.h"

const std::string &User::getId() const {
    return id;
}

void User::setId(const std::string &id) {
    User::id = id;
}

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    User::password = password;
}

const std::string &User::getPath() const {
    return path;
}

void User::setPath(const std::string &path) {
    User::path = path;
}
