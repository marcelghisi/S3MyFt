cmake_minimum_required(VERSION 3.23)
project(my_ftp)


link_libraries(stdc++fs)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_STANDARD 14)

add_executable(my_ftp main.cpp Client.cpp Client.h Connection.cpp Connection.h Database.cpp Database.h DataConnection.cpp DataConnection.h defines.h FileExplorer.cpp FileExplorer.h FTPServer.cpp FTPServer.h OptionParserHandler.cpp OptionParserHandler.h popl.hpp Request.h str_switch.h TcpSocket.cpp TcpSocket.h Thread.h User.cpp User.h)
