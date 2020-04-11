#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/rpc.h>
#include "const.h"

int limite_contas = 100; // Limitei para que possa usar a estrutura de vector com struct
int qnt_contas = 2;


// Struct da Conta
typedef struct {
	int	num_conta;
	double	saldo;
} CONTAS;

// Lista inicial de contas
CONTAS lista_contas[limite_contas] = {
	{00000001, 100.0},
	{00000002, 20.0}
};

// ------ METODOS ------ 

// Abertura de Conta
int *abre_conta(){
	if(limite_contas > qnt_contas){
		qnt_contas = qnt_contas + 1;
		int novo_num_conta = qnt_contas;
		int i;
		// Coloca a nova conta em um espaço em branco da lista de contas
		for(i=0;i<qnt_contas;++i)
			if(lista_contas[i] == NULL)
				lista_contas [qnt_contas] = CONTAS{novo_num_conta, 0.0};
		return novo_num_conta;
	}else return -1; //Excedeu o limite de contas criadas
}

// Fechamento de Conta
/*
	Indices de Return
		1 -> Fechou a conta
       	       -1 -> Conta não encontrada
               -2 -> Existe saldo na conta
*/
int *fecha_conta(){
	for(i=0;i<qnt_contas;++i) //Processo de Procura da Conta, se a mesma existe ou não...
		if(lista_contas[i].num_conta == *num_conta)
			if(lista_contas[i].saldo == 0.0) //se não existir saldo
				lista_contas == NULL:
			else return -2; //Conta com saldo, precisa retirar!
			return 1; // Conta deletada
		else return -1; // Conta nao encontrada
}



// Consulta Saldo
double *obtem_saldo_conta_1_svc(int **num_conta)
{

	static double erro = -1.0;
	int i;

	for(i=0;i<qnt_contas;++i) //Processo de Procura da Conta, se a mesma existe ou não...
		if	(lista_contas[i].num_conta == *num_conta)
			return &(lista_contas[i].saldo);
	return &erro;
}


// Verifica se a conta existe
bool *obtem_conta_1_svc(int **num_conta)
{
	int i;

	for(i=0;i<qnt_contas;++i) //Processo de Procura da Conta, se a mesma existe ou não...
		if	(lista_contas[i].num_conta == *num_conta)
			return true;
	return false;
}

// Deposito
bool *deposito_conta_1_svc(int **num_conta, double **valor)
{
	int i;

	for(i=0;i<qnt_contas;++i) //Processo de Procura da Conta, se a mesma existe ou não...
		if	(lista_contas[i].num_conta == *num_conta)
			*(lista_contas[i].saldo) = (&(lista_contas[i].saldo) + *valor) ; //Adiciona o valor do deposito na conta
			return true;
	return false;
}

// Saque
bool *deposito_conta_1_svc(int **num_conta, double **valor)
{
	int i;

	for(i=0;i<qnt_contas;++i) //Processo de Procura da Conta, se a mesma existe ou não...
		if	(lista_contas[i].num_conta == *num_conta)
			*(lista_contas[i].saldo) = (&(lista_contas[i].saldo) - *valor) ; //Adiciona o valor do saque na conta
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

