#include "TCP_Client.h"

using std::string;
int TCP_Client::NumClient=0;

bool TCP_Client::CreatConnect(void){
	sock_cli=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(_port);
	servaddr.sin_addr.s_addr=inet_addr(_addr.data());

	if(connect(sock_cli,(struct sockaddr *)&servaddr,sizeof(servaddr))<0){
		perror("connect");
		return false;
	}
	return true;
}
bool TCP_Client::Recv(string & data)const {
	char buf[200]={0};
	recv(sock_cli,buf,200,0);
	data=buf;
	return true;
}
string & operator<<(string &buf,const TCP_Client & Client){
	Client.Recv(buf);//will wait in here 
	return buf;
}

// int main(int argc, char const *argv[])
// {
// 	TCP_Client Client("127.0.0.1",1000);
// 	Client.CreatConnect();
// 	string m;
// 	m<<Client;
// 	std::cout<<m;
// 	getchar();
// 	return 0;
// }