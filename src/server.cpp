#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
class server {
private:
  int server_fd;
  int port;
  int sockfd;
  int acceptConnection;

public:
  void createSocket() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
      std::cout << "Failed to create the socket .errno" << errno << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  void bindScoket() {
    sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(9999);
    sockaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, reinterpret_cast<struct sockaddr *>(&sockaddr),
             sizeof(sockaddr)) < 0) {
      std::cout << "Failed to bind the port. errno" << errno << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  void startListing() {
    listen(sockfd, 5);
    std::cout << "Server is listening to the port 9999" << std::endl;
  }
  void closeSocket() { close(sockfd); }
  void accept() {
    acceptConnection = accept(sockfd, struct sockaddr *restrict sockaddr)
  }
  void recv() {}
  void send() {}
};
class httpResponse {

} int main() {
  server ss;
  ss.createSocket();
  ss.bindScoket();
  ss.startListing();
  ss.closeSocket();
  return 0;
}
