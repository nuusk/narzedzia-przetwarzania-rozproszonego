#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define PORT 6005
#define MAX 100

int main(void)
{
  void *context = zmq_ctx_new();
  void *subscriber = zmq_socket(context, ZMQ_SUB);
  zmq_connect(subscriber, "tcp://unixlab:6005");
  zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "B", 1);

  while (1)
  {
    //  Read envelope with address
    char *address = s_recv(subscriber);
    //  Read message contents
    char *contents = s_recv(subscriber);
    printf("[%s] %s\n", address, contents);
    free(address);
    free(contents);
  }
  //  We never get here, but clean up anyhow
  zmq_close(subscriber);
  zmq_ctx_destroy(context);
  return 0;
}