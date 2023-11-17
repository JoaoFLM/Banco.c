#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "banco.h"



int main ()
{
	
	usuario usuarios[MAX_REGISTROS];
	
	int numeroRegistro = 0;
	
	printf("\nBoas vindas ao programa em terminal da *Imagine um nome legal de agencia bancaria aqui*\n");
	
	while(true)
	{
		int escolha = 0, listaEscolha = 0,listaEscolha1 = 0, escolha1;
		printf("\nEscolha a opcao que dejesa fazer\n");
		printf("[1] Abrir conta\n[2] Fazer deposito\n[3] Fazer saque\n[4] Fazer emprestimo\n[5] Fechar conta\n[6] Listar clientes\n[0] Sair\n");
		fflush(stdin);
		scanf("%i", &escolha);
		fflush(stdin);
		
		switch (escolha) 
		{
			escolha1 = 0;
			case 1:
				if (numeroRegistro >= MAX_REGISTROS) printf("Limite de registros excedido\n");
				else
				{
					bool flag = abrirConta(usuarios, numeroRegistro);
					if(flag == true)
					{
						usuarios[numeroRegistro].conta.tipo = tipoEscolha();
						usuarios[numeroRegistro].conta.status = true;
						usuarios[numeroRegistro].conta.saldo = 0;
						usuarios[numeroRegistro].conta.numero = numeroRegistro;
						usuarios[numeroRegistro].conta.emprestimo = 0;
						numeroRegistro++;
						escolhaErrada("usuario cadastrado\n");
							
					}
				}
				break;
			case 2:
				printf("Digite o numero da conta\n");
				scanf("%i", &escolha1);
				if (validarConta(usuarios, numeroRegistro, escolha1)) fazerDeposito(usuarios, escolha1);
				break;
			case 3:
				printf("Digite o numero da conta\n");
				scanf("%i", &escolha1);
				if (validarConta(usuarios, numeroRegistro, escolha1)) fazerSaque(usuarios, escolha1);
				break;
			case 4: 
				printf("Digite o numero da conta\n");
				scanf("%i", &escolha1);
				if(validarConta(usuarios, numeroRegistro, escolha1)) fazerEmprestimo(usuarios, escolha1, numeroRegistro);
				break;
			case 5:
				printf("Digite o numero da conta\n");
				scanf("%i", &escolha1);
				if(validarConta(usuarios, numeroRegistro, escolha1)) fecharConta(usuarios, escolha1, numeroRegistro);
				break;
			case 6:
				printf("Escolha a operacao que deseja fazer\n[1] Listar todos os clientes cadastrados\n[2] Escolher uma conta para vizualizar\n[0] voltar\n");
				scanf("%i", &listaEscolha);
				switch(listaEscolha)
				{
					case 1:
						listarTodos(usuarios, numeroRegistro);
						break;
					case 2:
						printf("Digite o numero da conta que deseja vizualizar\n");
						scanf("%i", &listaEscolha1);
						if(validarConta(usuarios, numeroRegistro, listaEscolha1)) listarUm(usuarios[listaEscolha1]);
						break;
					case 0:
					break;
				}
				break;
			case 0:
				printf("Obrigado por usar o programa em terminal da *Imagine aqui um nome legal de agencia bancario*\n");
				return 0;
				break;
			default:
				escolhaErrada("Opcao invalida...");
				break;
		}
		
		fflush(stdin);
		
	}
}