
#include "banco.h"

int abreconta(CLIENT *clnt) {
	param param;
	int *result;
	int num;
	char pop;

	printf("> Solicitacao de Abertura de Conta  \n");
	printf("> Insira o numero da conta: ");
	scanf("%d",&num);
	param.conta = num;

	result = abreconta_100(&param, clnt);

	if(result==NULL){
		fprintf(stderr, "Problema na chamada do RPC\n");
		exit(0);
	}

	if(*result == 0) printf("\nLimite de contas excedido, serviço fora de operação.\n");
	else if(*result == 1) printf("\nEssa conta já está ativa em nosso cadastro.\n");
	else if(*result == 2) printf("\nConta aberta com sucesso, o saldo é R$ 0.00.\n");
	else if(*result == 3) printf("\nEssa conta estava fechada e foi reaberta.\n");
	else printf("\n???.\n");

	printf("\n\n --> digite 0 para voltar ao menu principal: \n");
	scanf("%s",&pop);
	printf("\n\n\n\n\n\n");
	return *result;
}

int fechaconta(CLIENT *clnt) {
	param param;
	int *result;
	int num;
	char pop;

	printf("> Solicitacao de Fechamento de Conta  \n");
	printf("> Insira o numero da conta: ");
	scanf("%d",&num);
	param.conta = num;

	result = fechaconta_100(&param, clnt);
	if(result==NULL){
		fprintf(stderr, "Problema na chamada do RPC\n");
		exit(0);
	}

	if(*result == 0) printf("\nNúmero de conta inválido.\n");
	else if(*result == 1) printf("\nConta fechada com sucesso, poderá ser reaberta no futuro.\n");
	else if(*result == 2) printf("\nPara fechar uma conta é necessário zerar o saldo.\n");
	else if(*result == 3) printf("\nEssa conta já está fechada.\n");
	else printf("\n???.\n");

	printf("\n\n --> digite 0 para voltar ao menu principal: \n");
	scanf("%s",&pop);
	printf("\n\n\n\n\n\n");
	return *result;
}

int autentica(CLIENT *clnt) {
	param param;
	int *result;
	int num;
	char pop;

	printf("> Solicitacao de Autenticação de Conta  \n");
	printf("> Insira o numero da conta: ");
	scanf("%d",&num);
	param.conta = num;

	result = autenticaconta_100(&param, clnt);

	if(result==NULL){
		fprintf(stderr, "Problema na chamada do RPC\n");
		exit(0);
	}

	if(*result == 0) printf("\nNúmero de conta inválido.\n");
	else if(*result == 1) printf("\nConta autenticada.\n");
	else printf("\n???.\n");

	printf("\n\n --> digite 0 para voltar ao menu principal: \n");
	scanf("%s",&pop);
	printf("\n\n\n\n\n\n");
	return *result;
}

int deposita(CLIENT *clnt) {
	param param;
	int *result;
	int num;
	float valor;
	char pop;

	printf("> Solicitacao de Depósito \n");
	printf("> Insira o numero da conta: ");
	scanf("%d",&num);
	printf("> Insira o valor a ser depositado: ");
	scanf("%f",&valor);
	param.conta = num;
	param.valor = valor;

	result = deposita_100(&param, clnt);
	if(result==NULL){
		fprintf(stderr, "Problema na chamada do RPC\n");
		exit(0);
	}

	if(*result == 0) printf("\nNúmero de conta inválido.\n");
	else if(*result == 1) printf("\nValor inserido é inválido, deve ser maior que zero.\n");
	else if(*result == 2) printf("\nMontante depositado com sucesso.\n");
	else printf("\n???.\n");

	printf("\n\n --> digite 0 para voltar ao menu principal: \n");
	scanf("%s",&pop);
	printf("\n\n\n\n\n\n");
	return *result;
}

int retira(CLIENT *clnt) {
	param param;
	int *result;
	int num;
	float valor;
	char pop;

	printf("> Solicitacao de Saque \n");
	printf("> Insira o numero da conta: ");
	scanf("%d",&num);
	printf("> Insira o valor a ser sacado: ");
	scanf("%f",&valor);
	param.conta = num;
	param.valor = valor;

	result = retira_100(&param, clnt);
	if(result==NULL){
		fprintf(stderr, "Problema na chamada do RPC\n");
		exit(0);
	}

	if(*result == 0) printf("\nNúmero de conta inválido.\n");
	else if(*result == 1) printf("\nValor inserido é inválido, deve ser maior que zero.\n");
	else if(*result == 2) printf("\nMontante sacado com sucesso.\n");
	else if(*result == 3) printf("\nSaldo insuficiente.\n");
	else printf("\n???.\n");

	printf("\n\n --> digite 0 para voltar ao menu principal: \n");
	scanf("%s",&pop);
	printf("\n\n\n\n\n\n");
	return *result;
}

int saldo(CLIENT *clnt) {
	param param;
	float *result;
	int num;
	char pop;

	printf("> Solicitacao de Saldo \n");
	printf("> Insira o numero da conta: ");
	scanf("%d",&num);
	param.conta = num;

	result = saldo_100(&param, clnt);
	if(result==NULL){
		fprintf(stderr, "Problema na chamada do RPC\n");
		exit(0);
	}

	if(*result == -1) printf("\nNúmero de conta inválido.\n");
	else printf("\nSaldo da conta é R$ %.2f\n",*result);

	printf("\n\n --> digite 0 para voltar ao menu principal: \n");
	scanf("%s",&pop);
	printf("\n\n\n\n\n\n");
	return -1;
}

float main(int argc, char *argv[]) {
	CLIENT *clnt;
	int operacao = 0;

	clnt = clnt_create (argv[1], BANCO, VERSAO, "udp");
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror (argv[1]);
		exit (0);
	}

	while(operacao < 1 || operacao > 6) {
		printf("-------------------------------------\n");
		printf("-- Banco RPC-TF1, Derick, Vinicius --\n");
		printf("-------------------------------------\n");
		printf("-- [1] Abrir conta\n");
		printf("-- [2] Fechar conta\n");
		printf("-- [3] Autenticar conta\n");
		printf("-- [4] Depositar dinheiro\n");
		printf("-- [5] Sacar dinheiro\n");
		printf("-- [6] Verificar saldo\n");
		printf("-- Informe a operação: ");
		scanf("%d", &operacao);

		if (operacao == 1) abreconta(clnt);
		else if (operacao == 2) fechaconta(clnt);
		else if (operacao == 3) autentica(clnt);
		else if (operacao == 4) deposita(clnt);
		else if (operacao == 5) retira(clnt);
		else if (operacao == 6) saldo(clnt);
		operacao = 0;

	}

	return(0);
}
