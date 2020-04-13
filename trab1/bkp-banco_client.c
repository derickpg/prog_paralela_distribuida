
#include "banco.h"

int abreconta(CLIENT *clnt, int num) {
	param param;
	int *result;
	param.conta = num;

	result = abreconta_100(&param, clnt);
	if(result==NULL){
		fprintf(stderr, "Problema na chamada do RPC\n");
		exit(0);
	}
	return *result;
}

float main(int argc, char *argv[]) {
	CLIENT *clnt;

	clnt = clnt_create (argv[1], BANCO, VERSAO, "udp");
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror (argv[1]);
		exit (0);
	}

	printf("Servidor retornou: ");
	int result = abreconta(clnt, 1);
	if(result == 0) printf("LIMITE DE CONTAS EXCEDIDO\n");
	if(result == 1) printf("CLIENTE É CORRENTISTA\n");
	if(result == 2) printf("CONTA CRIADA\n");


		result = abreconta(clnt, 11);
		if(result == 0) printf("LIMITE DE CONTAS EXCEDIDO\n");
		if(result == 1) printf("CLIENTE É CORRENTISTA\n");
		if(result == 2) printf("CONTA CRIADA\n");


			result = abreconta(clnt, 11);
			if(result == 0) printf("LIMITE DE CONTAS EXCEDIDO\n");
			if(result == 1) printf("CLIENTE É CORRENTISTA\n");
			if(result == 2) printf("CONTA CRIADA\n");

	return(0);
}
