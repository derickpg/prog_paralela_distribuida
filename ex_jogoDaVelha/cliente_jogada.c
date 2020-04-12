#include <stdio.h>
#include <unistd.h>
#include <rpc/rpc.h>
#include "jogodavelha.h"

int main(int argc, char *argv[])
{
	jogada_t j_in;
	jogada_t j_out;
	int stat;

	j_in.id = 12;
	j_in.jogada = 34;
	stat = callrpc(	"localhost", JDV_PROG, JDV_VERS, ENVIA_JOGADA,
			(xdrproc_t)xdr_jogada, (char *)&j_in,
			(xdrproc_t)xdr_jogada, (char *)&j_out);
	if	(stat!= 0)  {
		clnt_perrno(stat);
		printf("\n");
		exit(1);
	}
	printf("> Cliente recebeu: id=%d jogada=%d\n",j_out.id,j_out.jogada);
	return 0;
}
