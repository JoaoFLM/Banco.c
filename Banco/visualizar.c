#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "banco.h"




void printTipo(short T)
{
	if(T == 1) printf("Poupanca");
	else if(T == 2) printf("Corrente");
	else printf("#Erro#");
	
	printf("\n");
}

void printCPF(char *CPF)
{
	char cpfTemp[14];
	int contador = 0;
	
	for (int i = 0; i < NUM_CPF ; i++)
	{
		if(i == 3 || i == 7) cpfTemp[i] = '.';
		else if(i == 11) cpfTemp[i] = '-';
		else 
		{
			cpfTemp[i] = CPF[contador];
			contador++;
		}
	}
	printf("%s", cpfTemp);
	printf("\n");
		
}

void printStatus(bool S)
{
	if(S == true) printf("Aberta");
	else if(S == false) printf("Fechada");
	else printf("#Erro#");
	
	printf("\n");
}

void listarUm(usuario usuarios)
{
	printf("\n******************************\n");
	printf("Nome...: %s\n", usuarios.nome);
	printf("Idade..: %i\n", usuarios.idade);
	printf("CPF....: "); 
	printCPF(usuarios.CPF);
	printf("Numero da conta: %i\n", usuarios.conta.numero);
	printf("Tipo da conta: "); printTipo(usuarios.conta.tipo);
	printf("Status.: "); printStatus(usuarios.conta.status);
	printf("Saldo..: R$%f\n", usuarios.conta.saldo);
	printf("Emprestimo..: R$%f", usuarios.conta.emprestimo);
	printf("\n******************************\n");
}

void listarTodos(usuario *usuarios, int numeroRegistro)
{
	if(numeroRegistro == 0) printf("Nao possuem usuarios cadastrados\n");
	else
	{
		system(CLEAR);
		for(int i = 0; i < numeroRegistro; i++)
		{
			printf("\n******************************\n");
			printf("Nome...: %s\n", usuarios[i].nome);
			printf("Idade..: %i\n", usuarios[i].idade);
			printf("CPF....: "); 
			printCPF(usuarios[i].CPF);
			printf("Numero da conta: %i\n", usuarios[i].conta.numero);
			printf("Tipo da conta: "); printTipo(usuarios[i].conta.tipo);
			printf("Status.: "); printStatus(usuarios[i].conta.status);
			printf("Saldo..: R$%f\n", usuarios[i].conta.saldo);
			printf("Emprestimo..: R$%f", usuarios[i].conta.emprestimo);
			printf("\n******************************\n");
		}
	}
}
