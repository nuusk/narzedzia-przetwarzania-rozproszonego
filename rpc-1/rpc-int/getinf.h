/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _GETINF_H_RPCGEN
#define _GETINF_H_RPCGEN

#include <rpc/rpc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GETINF 0x21000000
#define Ver1 1

#if defined(__STDC__) || defined(__cplusplus)
#define getmsg 1
extern int *getmsg_1(int *, CLIENT *);
extern int *getmsg_1_svc(int *, struct svc_req *);
extern int getinf_1_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define getmsg 1
extern int* getmsg_1();
extern int* getmsg_1_svc();
extern int getinf_1_freeresult();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_GETINF_H_RPCGEN */