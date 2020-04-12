#include "banco.h"

#define LIMITE_CONTAS 100

int qnt_contas = 2;

// Struct da Conta
typedef struct {
	int	numero_conta;
	double	saldo;
} CONTA;

//Lista de todas as contas
CONTA lista_conta[LIMITE_CONTAS]={
	{1,100.0},
	{2,10.0}
};



double * consulta_100_svc(conta *argp, struct svc_req *rqstp)
{
	static double  result;
	int i;

		for(i=0;i<qnt_contas;++i) //Processo de Procura da Conta, se a mesma existe ou não...
			if(lista_conta[i].numero_conta == argp->num_conta){
				printf("\n CONTA = %d \n solicitou o saldo! \n", argp->num_conta);
				printf("Saldo = %f", lista_conta[i].saldo);
				result = (lista_conta[i].saldo);
			}else result = -9999.9;
	
	return &result;
}
