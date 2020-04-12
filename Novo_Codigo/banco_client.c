#include "banco.h"

double consulta(CLIENT *clnt, int numero_conta){
	double *result;
	conta n_conta;

	n_conta.num_conta = numero_conta;

	result = consulta_100(&n_conta,clnt);
	
	if(result == NULL){
		printf("ERRO NA CHAMADA RPC");
		exit(0);
	}
	return *result;
}

double main (int argc, char *argv[]){
	CLIENT *clnt;
	int num_conta;

	printf("Bem vindo ao Banco, Digite sua Conta para ver seu saldo\n");
	scanf("%d",&num_conta);


	clnt = clnt_create (argv[1], BANCO, VERSAO, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (argv[1]);
		exit (1);
	}

	printf("Seu saldo é de: %f \n", consulta(clnt,num_conta));
	return(0);
}
