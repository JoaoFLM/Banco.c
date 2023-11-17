#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_NOME 50
#define MAX_CPF 11
#define MAX_REGISTROS 50
#define NUM_CPF 14

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#ifdef _WIN32 
	#define PAUSE "pause"
#else 
	#define PAUSE "echo "Pressione Enter para continuar..." read"
#endif

struct conta{
	int numero;
	short tipo;
	bool status;
	float saldo;
	float emprestimo;
};

typedef struct conta conta;

struct usuario {
	char nome[MAX_NOME + 1];
	int idade;
	char CPF[MAX_CPF + 1];
	conta conta;
};

typedef struct usuario usuario;

void escolhaErrada(char *warn)
{
	printf("%s\n", warn);
	fflush(stdin);
	system("PAUSE");
	fflush(stdin);
	system(CLEAR);
}
char tipoEscolha();
void printTipo(short T);
void printCPF(char *CPF);
void printStatus(bool S);
bool CPFexiste(char *cpf, int numeroRegistro, usuario *usuarios);
bool abrirConta(usuario *usuarios, int numeroRegistro);
void listarUm(usuario usuarios);
void listarTodos(usuario *usuarios, int numeroRegistro);
void fazerDeposito(usuario *usuarios, int numeroConta);
void fazerSaque(usuario *usuarios, int numeroConta);
bool saldoAgencia(usuario *usuarios, float valorEmprestimo, int numeroRegistro);
bool validarConta (usuario *usuarios, int numeroRegistro, int numeroConta);
void fazerEmprestimo (usuario *usuarios, int numeroConta, int numeroRegistro);
void fecharConta (usuario *usuarios, int numeroConta, int numeroRegistro);