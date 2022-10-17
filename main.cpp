
#include <string>
#include <arpa/inet.h>
#include "FTPServer.h"
#include "OptionParserHandler.h"

int main(int argc, char *argv[]) {

    OptionParserHandler* oph = new OptionParserHandler(argc,argv);
    OptionParser op = oph->handle();

    uint16_t port = 1500;
    int max_conn = 3;
    std::string public_ip = "127.0.0.1";
    std::string root_dir = "/home/docode/project";
    srand(time(nullptr));

    if (oph->getHelpOption()->is_set()){
        std::cout << op << "\n";
        return 0;
    }

    if (oph->getImplicitIp()->is_set()){
        public_ip = oph->getImplicitIp()->value();
    }

    if (oph->getImplicitPort()->is_set()){
        port = stoi(oph->getImplicitPort()->value());
    }

    if (oph->getImplicitMax()->is_set()){
        max_conn = stoi(oph->getImplicitMax()->value());
    }

    if (oph->getImplicitPath()->is_set()){
        root_dir = oph->getImplicitPath()->value();
    }

    FTPServer server(root_dir, port, public_ip, max_conn);

    return 0;
}