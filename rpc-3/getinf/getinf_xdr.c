/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "getinf.h"

bool_t
xdr_Msg (XDR *xdrs, Msg *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, 50))
		 return FALSE;
	return TRUE;
}
