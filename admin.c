/*
Processo Administração

 realiza abertura e fechamento de contas (para agências), e também autentica que contas já existem (tanto para agências e caixas automáticos). A abertura deve ser uma operação garantidamente não-idempotente (semântica de execução exactely once);


*/

#include <stdio.h>
#include <rpc/rpc.h>
#include "const.h"

int main(int argc, char *argv[])
{
	char *pd;
	int stat;
	double nota;

	if	(argc!=3)  {
		fprintf(stderr,"Uso:\n%s <nome_do_servidor> <nome>\n\n",argv[0]);
		return 1;
	}
	pd = argv[2];
	stat = callrpc(argv[1], NOTASPROG, NOTASVERS, OBTEM_NOTA,
		       (xdrproc_t)xdr_wrapstring, (char *)&pd, 
		       (xdrproc_t)xdr_double, (char *)&nota );
	if	(stat!= 0)  {
		clnt_perrno(stat);
		printf("\n");
		return 1;
	}
	printf("Nome: %s\n",argv[2]);
	if	(nota<0.0) 
		printf("Resultado: nome nao encontrado!\n");
	else
		printf("Nota: %.1lf\n",nota);
	return 0;
}

