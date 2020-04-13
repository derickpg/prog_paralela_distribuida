

#include "banco.h"

#define NUM_CONTAS 10
#define true 1
#define false 0

conta contas[NUM_CONTAS] = {
	{ 1, 150.51, true},
	{ 2, 813.49, true},
	{ 3,   0.00, false},
	{ -1,   0.00, true},
	{ -1,   0.00, true},
	{ -1,   0.00, true},
	{ -1,   0.00, true},
	{ -1,   0.00, true},
	{ -1,   0.00, true},
	{ -1,   0.00, true}
};

// 0 limite excedido / 1 ja tem conta / 2 abriu / 3 reabriu a conta
int *
abreconta_100_svc(param *argp, struct svc_req *rqstp)
{
	int  result = 0;
	int i;
	for	(i=0;i<NUM_CONTAS;++i) {
		if(contas[i].numero == argp->conta) {
			result = 1;
			if(contas[i].aberta == false) {
				contas[i].aberta = true;
				result = 3;
			}
			break;
		}
		if(contas[i].numero == -1) {
			contas[i].numero = argp->conta;
			result = 2;
			break;
		}
	}
	return &result;
}

// 0 nao tem a conta / 1 fechou / 2 conta ja estava fechada
int *
fechaconta_100_svc(param *argp, struct svc_req *rqstp)
{
	int  result = 0;
	int i;
	for	(i=0;i<NUM_CONTAS;++i) {
		if(contas[i].numero == argp->conta) {
			if(contas[i].aberta == true){
				contas[i].aberta = false;
				contas[i].saldo = 0.0;
				result = 1;
			} else {
				result = 2;
			}
			break;
		}
		if(contas[i].numero == -1) {
			break;
		}
	}
	return &result;
}

// 0 nao tem a conta / 1 autenticou
int *
autenticaconta_100_svc(param *argp, struct svc_req *rqstp)
{
	int result = 0;
	int i;
	for	(i=0;i<NUM_CONTAS;++i) {
		if(contas[i].numero == argp->conta) {
			result = 1;
			break;
		}
		if(contas[i].numero == -1) {
			break;
		}
	}
	return &result;
}

// 0 nao tem a conta / 1 valor inserido invalido / 2 depositou
int *
deposita_100_svc(param *argp, struct svc_req *rqstp)
{
	int result = 0;
	int i;
	if(argp->valor > 0) {
		for	(i=0;i<NUM_CONTAS;++i) {
			if(contas[i].numero == argp->conta) {
				contas[i].saldo += argp->valor;
				result = 2;
				break;
			}
			if(contas[i].numero == -1) {
				break;
			}
		}
	} else { result = 1; }
	return &result;
}

// 0 nao tem a conta / 1 valor inserido invalido / 2 retirou / 3 nao tem saldo
int *
retira_100_svc(param *argp, struct svc_req *rqstp)
{
	int result = 0;
	int i;
	if(argp->valor > 0) {
		for	(i=0;i<NUM_CONTAS;++i) {
			if(contas[i].numero == argp->conta) {
				if(contas[i].saldo >= argp->valor) {
					contas[i].saldo -= argp->valor;
					result = 2;
				} else {
					result = 3;
				}
				break;
			}
			if(contas[i].numero == -1) {
				break;
			}
		}
	} else { result = 1; }
	return &result;
}

// -1.0 nao tem a conta / senao retorna saldo
float *
saldo_100_svc(param *argp, struct svc_req *rqstp)
{
	float result = -1.0;
	int i;
	for	(i=0;i<NUM_CONTAS;++i) {
		if(contas[i].numero == argp->conta)
			result = contas[i].saldo;
			break;
		}
		if(contas[i].numero == -1) {
			break;
		}
	}
	return &result;
}
