#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cassert>
#include <cerrno>
#include <unistd.h>
#include <sys/ioctl.h>

/*
struct sockaddr_in {
	__uint8_t       sin_len;
	sa_family_t     sin_family;
	in_port_t       sin_port;
	struct  in_addr sin_addr;
	char            sin_zero[8];
};
*/

/*
类别       request           说明               数据类型
套接字    SIOCATMARK     是否位于带外标记         int
         SIOCSPGRP      设置套接字的进程id或进程组id  int
         SIOCGPGRP      获取套接字的进程id或进程组id  int
 
文件      FIONBIO        设置清除非阻塞的IO标志     int
         FIOASYNC       设置清除信号驱动异步IO标志  int
         FIONREAD       设置接收缓冲区的字节数      int
         FIOSEROWN      设置文件的进程ID或进程组ID  int
         FIOGETOWN      获取文件的进程ID或进程组ID  int
 
接口     SIOCGIFCONF     获取所有接口的列表      struct ifconf
        SIOCSIFADDR     设置接口地址            struct ifreq
        SIOCGTFADDR      获取接口地址          struct ifreq
        SIOCSIFFLAGS     设置接口标志           struct ifreq
        SIOCGIFFLAGS     获取接口标志           struct ifreq
        SIOCSTFDSTADDR   设置点到点标志          struct ifreq
        SIOCGTFDSTADDR   获取点到点标志         struct ifreq
        SIOCGIFBRDADDR    获取广播地址          struct ifreq
        SIOCSIFBRDADDR    设置广播地址          struct  ifreq
        SIOCGIFNETMASK    获取子网掩码          struct ifreq
        SIOCSIFNETMASK    设置子网掩码          struct   ifreq
        SIOCGIFMETRIC     获取接口的测度         struct ifreq
        SIOCSIFMETRIC      设置接口的测度       struct  ifreq
        SIOCGIFMTU          获取接口的MTU          struct ifreq
        .........
ARP     SIOCSARP          创建修改ARP项表       struct  arpreq
        SIOCGARP          获取ARP项表         struct  qrpreq
        SIOCDARP          删除ARP项表          struct qrpreq
路由      SIOCADDRT         增加路径            struct  rtentry
        SIOCDELRT         删除路径            struct rtentry
流
*/

//把文件描述符设置成非阻塞模式 #include <sys/ioctl.h>
//https://blog.csdn.net/qq_32783703/article/details/86503713
int setNonblocking(int fd)
{
    int flags;

    /* If they have O_NONBLOCK, use the Posix way to do it */
#if defined(O_NONBLOCK)
    /* Fixme: O_NONBLOCK is defined but broken on SunOS 4.1.x and AIX 3.2.5. */
    if (-1 == (flags = fcntl(fd, F_GETFL, 0)))
        flags = 0;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    /* Otherwise, use the old way of doing it */
    flags = 1;
    return ioctl(fd, FIONBIO, &flags);
#endif
}

// 此文件会创建一个socket监听，端口是8809
// https://blog.csdn.net/qq_34400232/article/details/115960120
int main(int argc, char** argv) {
  const char* ip = "127.0.0.1";
  int port = 8809;

  int ret = 0;
  struct sockaddr_in addr{};

  //初始化结构体
  bzero(&addr, sizeof(addr));

  //AF_INET代表ipv4
  addr.sin_family = AF_INET;

  //把ip地址转换为ipv4格式，并写入sin_addr结构体中
  inet_pton(AF_INET, ip, &addr.sin_addr);

  //htons把整形变量从主机序转成网络序
  addr.sin_port = htons(port);

  // 创建socket SOCK_STREAM是是数据流，一般表示TCP；SOCK_DGRAM表示UDP   
  int listenfd = socket(PF_INET, SOCK_STREAM, 0);
  assert(listenfd != -1);

  setNonblocking(listenfd);

  // 绑定端口
  ret = bind(listenfd, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr));
  assert(ret != -1);

  // 监听，把socket设置为监听模式。
  ret = listen(listenfd, 5);
  assert(ret != -1);

  struct sockaddr_in client{};
  socklen_t client_addr_len = sizeof(client);
  // 等待连接, 此处将会阻塞，直到有一个客户端连接到来
  while(1){
    int connfd = accept(listenfd, reinterpret_cast<struct sockaddr*>(&client), &client_addr_len);
    if(connfd < 0) {
        // printf("connection error, errno is:%d\n", errno);
        // exit(1);
        // printf("等待");
        continue;
    }
    printf("连接成功, 客户端地址:[%s:%d]\n", inet_ntoa(client.sin_addr), client.sin_port);

    char buffer[1024] = {0};
    // 接收数据，此处将会阻塞，直到有数据到来
    ret = recv(connfd, buffer, sizeof(buffer) - 1, 0);
    printf("接受到%d字节数据, 内容为:%s\n", ret, buffer);

    // 服务器做出回应
    bzero(&buffer, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "This is from server!!!!!.");
    ret = send(connfd, buffer, strlen(buffer), 0);
    printf("发送%d字节数据, 内容为:%s\n", ret, buffer);


    // close(connfd);
    // close(listenfd);
  }
  return 0;
}
