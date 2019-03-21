//  Hello World client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MAX 100

int main(void)
{
  printf("Connecting to hello world server...\n");
  void *context = zmq_ctx_new();
  void *requester = zmq_socket(context, ZMQ_REQ);
  zmq_connect(requester, "tcp://150.254.30.38:5555");

  int indeks = 127347;
  char buffer[MAX];
  printf("Sending indeks...\n");
  zmq_send(requester, &indeks, sizeof(int), 0);
  zmq_recv(requester, buffer, MAX, 0);
  printf("End... %s\n", buffer);
  zmq_close(requester);
  zmq_ctx_destroy(context);
  return 0;
}