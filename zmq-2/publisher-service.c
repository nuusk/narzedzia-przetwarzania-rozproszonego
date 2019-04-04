#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>
#include "zhelpers.h"

#define PORT 5002
#define MAX 100

int main(void) {
  void *context = zmq_ctx_new();
  void *publisher = zmq_socket(context, ZMQ_PUB);
  zmq_bind(publisher, "tcp://*:5002");

  while (1) {
    //  Write two messages, each with an envelope and content
    s_sendmore(publisher, ":");
    s_send(publisher, "[lab-os-15] poe");
    sleep(1);
  }

  //  We never get here, but clean up anyhow
  zmq_close(publisher);
  zmq_ctx_destroy(context);
  return 0;
}
