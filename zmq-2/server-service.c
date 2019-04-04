#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>

#define MAX 512

int main(void) {
  void *context = zmq_ctx_new();
  void *responder = zmq_socket(context, ZMQ_REP);
  int rc = zmq_bind(responder, "tcp://*:5001");
  assert(rc == 0);
  int i;

  while (1) {
    char buffer[MAX];
    char message[MAX];

    strcpy(message, "[lab-os-15]: ");
    zmq_recv(responder, buffer, 50, 0);
    for (i = 0; (i < MAX && buffer[i] != '\0'); i++)
      buffer[i] = buffer[i] + 3;  // szyfr cezara
    strcat(message, buffer);
    zmq_send(responder, message, 50, 0);
  }
  return 0;
}
