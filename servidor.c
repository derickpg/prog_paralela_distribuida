#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/rpc.h>
#include "const.h"

int limite_contas = 100; // Limitei para que possa usar a estrutura de vector com struct
int qnt_contas = 2;


typedef struct {
	char	num_conta[8];
	double	saldo;
} CONTAS;

CONTAS lista_contas[limite_contas] = {
	{"13201877", 100.0},
	{"13201878", 20.0}
};

// Consulta Saldo
double *obtem_saldo_conta_1_svc(char **num_conta)
{

	static double erro = -1.0;
	int i;

	for	(i=0;i<qnt_contas;++i)
		if	(strcmp(lista_contas[i].num_conta,*num_conta)==0)
			return &(lista_contas[i].saldo);
	return &erro;
}


// Verifica se a conta existe
bool *obtem_conta_1_svc(char **num_conta)
{
	int i;

	for	(i=0;i<qnt_contas;++i)
		if	(strcmp(lista_contas[i].num_conta,*num_conta)==0)
			return true;
	return false;
}

// Deposito
bool *deposito_conta_1_svc(char **num_conta, double **valor)
{
	int i;

	for	(i=0;i<qnt_contas;++i)
		if	(strcmp(lista_contas[i].num_conta,*num_conta)==0)
			*(lista_contas[i].saldo) = (&(lista_contas[i].saldo) + *valor) ; //Adiciona o valor do deposito na conta
			return true;
	return false;
}

// Saque
bool *deposito_conta_1_svc(char **num_conta, double **valor)
{
	int i;

	for	(i=0;i<qnt_contas;++i)
		if	(strcmp(lista_contas[i].num_conta,*num_conta)==0)
			*(lista_contas[i].saldo) = (&(lista_contas[i].saldo) - *valor) ; //Adiciona o valor do deposito na conta
			return true;
	return false;
}





int main()
{
	//copia do exemplo, nao sei como configurar !
	if	(registerrpc(NOTASPROG,NOTASVERS,OBTEM_NOTA,obtem_nota_1_svc,
			     (xdrproc_t)xdr_wrapstring,(xdrproc_t)xdr_double ) == -1)  {
		fprintf(stderr,"Erro em registerrpc()!\n");
		exit(1);
	}
	svc_run();
	fprintf(stderr,"Erro em svc_run()!\n");
	return 1;
}

