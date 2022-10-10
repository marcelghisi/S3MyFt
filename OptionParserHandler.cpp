//
// Created by marcelghisi on 15/09/22.
//

#include "OptionParserHandler.h"

OptionParserHandler::OptionParserHandler(int pargc, char **pargv) {
    argc = pargc;
    argv = pargv;
}

OptionParser OptionParserHandler::handle(){
    OptionParser op("Allowed options");
    help_option = op.add<Switch>("h", "help", "produce help message");
    implicit_ip  = op.add<Value<std::string>>("i", "ip", "mode", "locahost");
    implicit_port  = op.add<Value<std::string>>("p", "port", "mode", "1500");
    implicit_path  = op.add<Value<std::string>>("f", "path", "mode", "/tmp");
    implicit_max  = op.add<Value<std::string>>("m", "max", "mode", "3");
    op.parse(argc, argv);
    return op;
}

std::shared_ptr<Switch> OptionParserHandler::getHelpOption(){
    return help_option;
}

std::shared_ptr<Value<std::string>> OptionParserHandler::getImplicitIp(){
    return implicit_ip;
}

std::shared_ptr<Value<std::string>> OptionParserHandler::getImplicitPort(){
    return implicit_port;
}

std::shared_ptr<Value<std::string>> OptionParserHandler::getImplicitPath(){
    return implicit_path;
}

std::shared_ptr<Value<std::string>> OptionParserHandler::getImplicitMax(){
    return implicit_max;
}