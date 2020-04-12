/* xdr_jogada.c (Roland Teodorowitsch; 12 mar. 2014) */

#include <rpc/xdr.h>
#include "jogodavelha.h"

bool_t xdr_jogada(XDR *xdrsp, jogada_t *in)
{
	if	(!xdr_int(xdrsp,&(in->id)))
		return 0;
	if	(!xdr_int(xdrsp,&(in->jogada)))
		return 0;
	return 1;
}
