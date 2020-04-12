#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <rpc/rpc.h>
#include <pthread.h>
#include "jogodavelha.h"

jogada_t *envia_jogada(jogada_t *j_in)
{
	static jogada_t res;

	printf("> Servidor recebeu: id=%d jogada=%d\n",j_in->id,j_in->jogada);
	res.id = 56;
	res.jogada = 78;
	return &res;
}

int main()
{
	if	(registerrpc(JDV_PROG,JDV_VERS,ENVIA_JOGADA,envia_jogada,
			     (xdrproc_t)xdr_jogada,(xdrproc_t)xdr_jogada ) == -1)  {
		fprintf(stderr,"Erro em registerrpc()!\n");
		exit(1);
	}
	svc_run();
	fprintf(stderr,"Erro em svc_run()!\n");
	return 1;
}
