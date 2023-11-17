#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "banco.h"


char tipoEscolha ()
{
	int escolha;
	bool flag = true;
	bool tipo;
	{
		while(true)
		{
			system(CLEAR);
			int escolha;
			printf("Escolha qual o tipo de conta que deseja criar\n[1] Poupanca\n[2] Corrente\n");
			scanf("%i", &escolha);
			switch (escolha)
			{
				case 1:
					return 1;
					break;
				case 2:
					return 2;
					break;
				default:
					escolhaErrada("Escolha uma opcao valida");	
			}
		}
	}
}

bool abrirConta(usuario *usuarios, int numeroRegistro)
{
	
	printf("Insira as informacoes de cadastro");
	
	printf("\nNome......(Max:%i caracteres): ", MAX_NOME);
	scanf(" %50[^\n]s", usuarios[numeroRegistro].nome);
	
	while(true)
	{
		printf("\nIdade.....: ");
		fflush(stdin);
		scanf("%i", &usuarios[numeroRegistro].idade);
		fflush(stdin);
		if(usuarios[numeroRegistro].idade < 18) 
		{
			escolhaErrada("Usuario precisa ser maior de idade");
			return false;
		}
		else break;
	}
	
	while(true)
	{
		int i;
		bool validar = true;
		printf("\nCPF.......(Apenas os numeros):");
		fflush(stdin);
		scanf("%11[^\n]s", &usuarios[numeroRegistro].CPF);
		fflush(stdin);
		for(i = 0; i < MAX_CPF; i++)
		{
			if(!(usuarios[numeroRegistro].CPF[i] >= 48 && usuarios[numeroRegistro].CPF[i] <= 57)) 
			{
				validar = false;
			}
		}
		
		if (validar == false) escolhaErrada("CPF invalido....");
		if (CPFexiste(usuarios[numeroRegistro].CPF, numeroRegistro, usuarios))
		{
			validar = false;
		}
		
		
		else break;

		if (validar == false)
		{
			return false;
		}
	}
	
	return true;
	
}

void fazerDeposito(usuario *usuarios, int numeroConta)
{
	float saldoTemp = 0;
	while (true)
	{
		
		printf("Digite o valor do deposito (R$0.00): R$");
		scanf("%f", &saldoTemp);
		if(saldoTemp < 0) escolhaErrada("Valor invalido");
		else break;
	}
	
	usuarios[numeroConta].conta.saldo += saldoTemp;
	
	escolhaErrada("Deposito efetuado com sucesso");
}

void fazerSaque(usuario *usuarios, int numeroConta)
{
	float saldoTemp;
	while(true)
	{
		printf("Saldo disponivel...: R$:%.2f\n", usuarios[numeroConta].conta.saldo);
		printf("Digite o valor do saque (0.00): R$");
		scanf("%f", &saldoTemp);
		if(saldoTemp < 0 || saldoTemp > usuarios[numeroConta].conta.saldo) escolhaErrada("Valor invalido");
		else break;
	}
	
	usuarios[numeroConta].conta.saldo -= saldoTemp;
	
	escolhaErrada("Saque efetuado com sucesso");
	
}

void fazerEmprestimo (usuario *usuarios, int numeroConta, int numeroRegistro)
{
	
	while(true)
	{
		float valorEmprestimo = 0;
		printf("Escolha o valor do emprestimo(R$0.00): R$");
		scanf("%f", &valorEmprestimo);
		
		if((usuarios[numeroConta].conta.saldo*(float)2 < valorEmprestimo))
		{
			escolhaErrada("valor maior que o limite\n");
		}
		else if((saldoAgencia(usuarios, valorEmprestimo, numeroRegistro)))
		{
			escolhaErrada("valor maior que o credito disponivel nesta agencia\n");
			return;
		}
		else 
		{
			usuarios->conta.emprestimo += valorEmprestimo;
			escolhaErrada("Emprestimo efetuado\n");
			break;
		}
	}
}

void fecharConta (usuario *usuarios, int numeroConta, int numeroRegistro)
{
	int confirmar;
	printf("Tem certeza que deseja fechar a conta ?\nDigite 1 para confirmar e qualquer outro digito para nao\n");
	scanf("%i", &confirmar);
	if(confirmar == 1)
	{
		if (usuarios[numeroConta].conta.saldo == 0 && usuarios[numeroConta].conta.emprestimo ==0)
		{
			usuarios[numeroConta].conta.status = false;
		}
		else escolhaErrada("e necessario esvaziar a conta antes de fecha-la");
	}
}
