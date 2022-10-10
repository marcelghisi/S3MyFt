LDFLAGS 	:= -L/usr/local/lib
LDLIBS 		:= -lpthread -lrt -pthread

#If you’re building a threaded program, use -lmysqlclient_r instead of -lmysqlclient here.
EXECUTABLE := src/main.cpp src/OptionParserHandler.cpp src/Connection.cpp src/Database.cpp src/TcpSocket.cpp src/DataConnection.cpp \
src/FileExplorer.cpp src/FTPServer.cpp src/Client.cpp
all: $(EXECUTABLE)
	g++ -o Server $(EXECUTABLE) $(LDFLAGS) $(LDLIBS)
	echo "\n\n"
clean:
	rm -f Server