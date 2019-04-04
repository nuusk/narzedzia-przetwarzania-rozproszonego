#include "zhelpers.h"

#define PORT 5002
#define MAX 512

int main(void) {
  void *context = zmq_init(1);
  char *filter;
  char *content;

  //  Connect our subscriber socket
  void *subscriber = zmq_socket(context, ZMQ_SUB);

  zmq_connect(subscriber, "tcp://lab-os-2:5002");
  zmq_connect(subscriber, "tcp://lab-os-3:5002");
  zmq_connect(subscriber, "tcp://lab-os-4:5002");
  zmq_connect(subscriber, "tcp://lab-os-8:5002");
  zmq_connect(subscriber, "tcp://lab-os-9:5002");
  zmq_connect(subscriber, "tcp://lab-os-10:5002");
  zmq_connect(subscriber, "tcp://lab-os-11:5002");
  zmq_connect(subscriber, "tcp://lab-os-12:5002");
  zmq_connect(subscriber, "tcp://lab-os-13:5002");
  zmq_connect(subscriber, "tcp://lab-os-14:5002");
  zmq_connect(subscriber, "tcp://lab-os-15:5002");

  zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, ":", 1);

  //  Get updates, exit when told to do so
  while (1) {
    filter = s_recv(subscriber);
    content = s_recv(subscriber);
    printf("[%s] %s\n", filter, content);
  }

  free(filter);
  free(content);
  zmq_close(subscriber);
  zmq_term(context);
  return 0;
}