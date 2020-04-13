struct conta{
    int numero;
    float saldo;
    int aberta;
};

struct param{
    int conta;
    float valor;
};

program BANCO{
    version VERSAO{

        int ABRECONTA(param)=1;
        int FECHACONTA(param)=2;
        int AUTENTICACONTA(param)=3;
        int DEPOSITA(param)=4;
        int RETIRA(param)=5;
        float SALDO(param)=6;

    }=100;
}=1000;
