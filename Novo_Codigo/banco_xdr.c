/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "banco.h"

bool_t
xdr_conta (XDR *xdrs, conta *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->num_conta))
		 return FALSE;
	return TRUE;
}
