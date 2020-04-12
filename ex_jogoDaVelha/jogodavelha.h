/* jogodavelha.h (Roland Teodorowitsch; 12 mar. 2014) */

#define JDV_PROG	0x20000009LU
#define JDV_VERS	1

#define TAM_GRADE	60
#define TAM_NOME	256

#define REGISTRA_JOGADOR	1
#define	TEM_PARTIDA		2
#define	EH_MINHA_VEZ		3
#define	OBTEM_GRADE		4
#define ENVIA_JOGADA		5
#define OBTEM_OPONENTE		6

typedef struct {
	int id;
	int jogada;
} jogada_t;

bool_t xdr_jogada(XDR *xdrsp, jogada_t *in);
