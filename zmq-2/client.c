#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>

#define MAX 512

int main(void) {
  printf("Connecting to many servers...\n");
  void *context = zmq_ctx_new();
  void *requester = zmq_socket(context, ZMQ_REQ);

  zmq_connect(requester, "tcp://lab-os-2:5001");
  zmq_connect(requester, "tcp://lab-os-3:5001");
  zmq_connect(requester, "tcp://lab-os-4:5001");
  zmq_connect(requester, "tcp://lab-os-8:5001");
  zmq_connect(requester, "tcp://lab-os-9:5001");
  zmq_connect(requester, "tcp://lab-os-10:5001");
  zmq_connect(requester, "tcp://lab-os-11:5001");
  zmq_connect(requester, "tcp://lab-os-12:5001");
  zmq_connect(requester, "tcp://lab-os-13:5001");
  zmq_connect(requester, "tcp://lab-os-14:5001");
  zmq_connect(requester, "tcp://lab-os-15:5001");

  while (1) {
    char buffer[MAX] = "";
    zmq_send(requester, "Hello from poe.", MAX, 0);
    zmq_recv(requester, buffer, MAX, 0);
    printf("%s\n", buffer);
  }

  zmq_close(requester);
  zmq_ctx_destroy(context);
  return 0;
}