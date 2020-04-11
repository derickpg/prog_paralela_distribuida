all:		servidor admin agencia caixa

caixa:		caixa.c const.h
			@gcc -o caixa caixa.c

agencia:	agencia.c const.h
			@gcc -o agencia agencia.c

admin:	   	admin.c const.h
			@gcc -o admin admin.c

servidor:	servidor.c const.h
			@gcc -o servidor servidor.c

clean:
		@rm -f caixa agencia admin servidor *~

info:
		@echo "T1 Derick Garcez e Vinicius Azevedo"
