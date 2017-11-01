#ifndef MSERVER_H
#define MSERVER_H

#include<string>
#include<map>
#include<sys/types.h>   //for socket
#include<sys/socket.h>  //for socket
#include<netinet/in.h>

using namespace std;

class Mserver{
private:
    int sock,client_fd;
    string path;
    unsigned int port;
   
    sockaddr_in myAddr;
    sockaddr_in remoteAddr;
public:
    Mserver(string directory=".",unsigned int port=80);
    string getPath();
    string setPath(const char *);
    unsigned int getPort();
    unsigned int setPort(unsigned int );
    static map<string,string> parseReq(const char *,unsigned int);
    void run();
    void shutdown();
    static void res_404();
    static void res_500();
    static void* mthread(void*);
    
};





#endif