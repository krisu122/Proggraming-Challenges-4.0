#include <netinet/in.h>
#include <unistd.h> 
#include <cstring>
#include <iostream>
#include "TaskQueue.h"

class SingletonProcess
{
public:
    SingletonProcess(uint16_t port0);
    ~SingletonProcess();
    std::string GetLockFileName();
    void connectToSocket(std::string task);
    std::string listenForTask();
    bool operator()();
    TaskQueue *queue;
private:
    
    int socket_fd = -1;
    int rc;
    uint16_t port;
};