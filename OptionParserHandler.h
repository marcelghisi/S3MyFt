//
// Created by marcelghisi on 15/09/22.
//

#ifndef MY_FTP_OPTIONPARSERHANDLER_H
#define MY_FTP_OPTIONPARSERHANDLER_H

#include "popl.hpp"

using namespace popl;

class OptionParserHandler {
private:
    int argc;
    char **argv;
    std::shared_ptr<Switch> help_option;
    std::shared_ptr<Value<std::string>> implicit_ip;
    std::shared_ptr<Value<std::string>> implicit_port;
    std::shared_ptr<Value<std::string>> implicit_path;
    std::shared_ptr<Value<std::string>> implicit_max;

public:
    OptionParserHandler(int pargc, char **pargv);
    std::shared_ptr<Switch> getHelpOption();
    std::shared_ptr<Value<std::string>> getImplicitIp();
    std::shared_ptr<Value<std::string>> getImplicitPort();
    std::shared_ptr<Value<std::string>> getImplicitPath();
    std::shared_ptr<Value<std::string>> getImplicitMax();
    OptionParser handle();
};


#endif //MY_FTP_OPTIONPARSERHANDLER_H
