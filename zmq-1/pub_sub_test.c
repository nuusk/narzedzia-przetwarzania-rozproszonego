#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>
#include "zhelpers.h"

#define PORT 6005
#define MAX 100

int main(void) {
  void *context = zmq_ctx_new();
  void *subscriber = zmq_socket(context, ZMQ_SUB);
  zmq_connect(subscriber, "tcp://unixlab:6005");
  zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "W", 1);

  while (1) {
    //  Read message from the publisher
    char *message = s_recv(subscriber);
    printf("Message: %s\n", message);
    free(message);
  }

  //  We never get here, but clean up anyhow
  zmq_close(subscriber);
  zmq_ctx_destroy(context);
  return 0;
}