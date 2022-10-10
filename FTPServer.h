//
// Created by marcelghisi on 15/09/22.
//

#ifndef MY_FTP_FTPSERVER_H
#define MY_FTP_FTPSERVER_H


#include "defines.h"
#include "Thread.h"
#include <vector>

class TcpSocket;
class DataThread;
struct Client;

class FTPServer {
public:
    explicit FTPServer(cstring root_dir, uint16_t port = 21, cstring ip = "", int max_connections = 1000);

private:
    void get_my_ip();

    void connection_handler(TcpSocket *sock);


    TcpSocket *listening;
    const std::string root_dir;
    const int max_connections;
    int connections;
    const uint16_t port;
    std::vector<Client*> clients;
    std::string ip;
};


#endif //MY_FTP_FTPSERVER_H
