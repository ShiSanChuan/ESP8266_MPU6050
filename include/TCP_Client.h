#ifndef _TCP_CLIENT_H
#define _TCP_CLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/shm.h>
#include <unistd.h> 

using std::string;

class TCP_Client
{
private:
	static int NumClient;
	string _addr;
	int _port;
	int sock_cli;
public:
	TCP_Client(string addr="127.0.0.1",int port=1000){
		_addr=addr;
		_port=port;
		NumClient++;
	}
	~TCP_Client(){
		close(sock_cli);
	}
	string GetAddr(void)const{return _addr;}
	int GetPort(void)const{return _port;}
	bool CreatConnect(void);
	bool Recv(string & data)const;
	friend string & operator<<(string &buf,const TCP_Client & Client);
};
#endif