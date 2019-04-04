#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>
#include "zhelpers.h"

#define PORT 5002
#define MAX 100

char* itoa(int i, char b[]) {
  char const digit[] = "0123456789";
  char* p = b;
  if (i < 0) {
    *p++ = '-';
    i *= -1;
  }
  int shifter = i;
  do {  // Move to where representation ends
    ++p;
    shifter = shifter / 10;
  } while (shifter);
  *p = '\0';
  do {  // Move back, inserting digits as u go
    *--p = digit[i % 10];
    i = i / 10;
  } while (i);
  return b;
}

int main(void) {
  void* context = zmq_ctx_new();
  void* responder = zmq_socket(context, ZMQ_PUSH);
  int rc = zmq_bind(responder, "tcp://*:5003");
  assert(rc == 0);
  int counter = 0;
  char message[MAX];
  char buf[MAX];

  while (1) {
    //  Write two messages, each with an envelope and content
    strcpy(message, "[lab-os-15] poe");
    itoa(counter, buf);
    strcat(message, buf);
    printf("Sending %s\n", message);

    zmq_send(responder, message, MAX, 0);

    counter++;
    sleep(1);
  }

  //  We never get here, but clean up anyhow
  zmq_close(responder);
  zmq_ctx_destroy(context);
  return 0;
}
