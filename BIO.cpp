#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cassert>
#include <cerrno>
#include <unistd.h>
/*
1.初始化sockaddr_in结构体
    1.host，ip配置
    2.AF_INET设置
2.socket套接字
3.bind绑定
4.accept阻塞，等待事件回调，客户端信息存在sockaddr_in内
5.recv读取套接字内容
6.send响应结果， 
*/

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
    if(connfd <= 0) {
        printf("connection error, errno is:%d\n", errno);
        exit(1);
    }

    printf("连接成功, 客户端地址:[%s:%d]\n", inet_ntoa(client.sin_addr), client.sin_port);

    char buffer[1024] = {0};
    // 接收数据，此处将会阻塞，直到有数据到来
    ret = recv(connfd, buffer, sizeof(buffer) - 1, 0);
    printf("接受到%d字节数据, 内容为:%s\n", ret, buffer);

    // 服务器做出回应
    bzero(&buffer, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "This is from server.");
    ret = send(connfd, buffer, strlen(buffer), 0);
    printf("发送%d字节数据, 内容为:%s\n", ret, buffer);


    // close(connfd);
    // close(listenfd);
  }
  return 0;
}
