/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "counter.h"

static int counter = 0;

int *
next_1_svc(void *argp, struct svc_req *rqstp)
{
	static int  result;
	result = counter;
	counter++;	

	return &result;
}
