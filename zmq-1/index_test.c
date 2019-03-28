// Simple program to send my index to unixlab and get a prize

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>

#define MAX 100

int main(void) {
  printf(
      "This client is about to send my index to unixlab server (~ D. "
      "Wawrzyniak)...\n");
  void *context = zmq_ctx_new();
  void *requester = zmq_socket(context, ZMQ_REQ);
  zmq_connect(requester, "tcp://150.254.30.38:5555");

  int indeks = 127347;
  char buffer[MAX];
  printf("Sending index...\n");
  zmq_send(requester, &indeks, sizeof(int), 0);
  zmq_recv(requester, buffer, MAX, 0);
  printf("In response I got:\n%s\n", buffer);
  zmq_close(requester);
  zmq_ctx_destroy(context);
  return 0;
}