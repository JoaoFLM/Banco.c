#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "banco.h"

bool CPFexiste(char *cpf, int numeroRegistro, usuario *usuarios)
{
	for(int i = 0; i < MAX_REGISTROS; i++)
	{	
		if(i != numeroRegistro)
		{
			if((strcmp(cpf, usuarios[i].CPF) == 0)) 
			{
				escolhaErrada("Cliente ja cadastrado");
				return true;
			}
		}
	}
	return false;
}

bool saldoAgencia(usuario *usuarios, float valorEmprestimo, int numeroRegistro)
{
	float somaTotal = 0;
	for(int i = 0; i < numeroRegistro; i++)
	{
		somaTotal += usuarios[i].conta.saldo;
	}
	
	if(somaTotal/(float)5 > valorEmprestimo) return false;
	else return true;
	
	
}

bool validarConta (usuario *usuarios, int numeroRegistro, int numeroConta)
{
	if(usuarios[numeroConta].conta.status)
	{
		if(numeroConta >= numeroRegistro)
		{
			escolhaErrada("Usuario nao encontrado");
			return false;
		}
		else 
		{
			return true;
		}
	}
	
	else escolhaErrada("Conta desativada");
}