#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "arvore.h"

void menu();
void incluir_contato(struct Node **r);
void buscar_contato(struct Node *r);
void excluir_contato(struct Node **r);

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	//declaraçao
	struct Node *r;
	int op, quit = 0;
	
	//inicializar a arvore
	inicArvore(&r);
	
	//loop do programa ate digitar 0 para sair
	while(!quit){
		//printar o menu e pegar a escolha
		menu();
		scanf("%d", &op);
		getchar();//tirar o '\n' do buff
		
		//tratar a escolha
		switch(op){
			case 1:
				incluir_contato(&r);
				break;
			case 2:
				buscar_contato(r);
				break;
			case 3:
				excluir_contato(&r);
				break;
			case 4:
				printEmOrdemCrescente(r);
				break;
			case 5:
				printEmOrdemDecrescente(r);
				break;
            case 6:
                printPreOrdem(r);
                break;
			case 0:
				quit = 1;
				break;
			default:
				printf("\nOpção Inválida\n");
				break;
		}
	}
	return 0;
}

void menu()
{
	printf("\n\n");
	printf("1 - Incluir Contato\n");
	printf("2 - Buscar Contato\n");
	printf("3 - Excluir Contato\n");
	printf("4 - Exibir Dados em Ordem Crescente\n");
	printf("5 - Exibir Dados em Ordem Decrescente\n");
        printf("6 - Exibir Dados em Pre-Ordem\n");
	printf("0 - Sair\n");
	printf("Opção: ");
}

void incluir_contato(struct Node **r)
{
	//variaveis
	struct Contato temp;//contato temporario para ser inserido na arvore
	struct Node *aux;
	int quit = 0;
	int telefone;
	
	//pegar o nome a ser inserido
	printf("Digite o nome do novo contato: ");
	gets(temp.nome);
	
	aux = localizarNode(*r, temp.nome);//procurar pelo nome
	
	//se aux for null entao o nome nao existe na arvore
	if(!aux){
		//inicializar a lista de telefone do contato
		inicListaTelefone(&temp.telefones);
		
		//inserir telefone até q seja digitado 0
		while(!quit){
			printf("Digite os telefones do contato ou 0 para parar de inserir: ");
			scanf("%d", &telefone);
			if(!telefone)
				quit = 1;
			else
				inserirTelefone(&temp.telefones, telefone);
		}
		//depois de recolhido os telefones insere o contato na arvore
		insereNode(r, temp);
	}
	
	//se aux nao for null entao ja existe um contato com o nome digitado
	else{
		//printa o contato e seus telefones
		printf("\nO contato já existe\n");
		printf("\t%s\n", aux->contato.nome);
		printTelefones(&aux->contato.telefones);
	}
}

void buscar_contato(struct Node *r)
{
	//variaveis
	char nome[50];
	struct Node *aux;
	
	//pegar o nome a ser procurado
	printf("Digite o nome a ser procurado: ");
	gets(nome);
	
	//procurar o nome na arvore
	aux = localizarNode(r, nome);
	
	//se aux for null entao nao encontrou o contato
	if(!aux)
		printf("\nNenhum contato foi encontrado com este nome\n");
	
	//se encontrar o contato printa os dados dele
	else{
		printf("Dados do contato:\n\t%s\n", aux->contato.nome);
		printTelefones(&aux->contato.telefones);
	}
}

void excluir_contato(struct Node **r)
{
	//variaveis
	struct Node *aux;
	char nome[50];
	
	//pegar o nome a ser excluido
	printf("Digite o nome a ser excluído: ");
	gets(nome);
	
	//procurar o nome na arvore
	aux = localizarNode((*r), nome);
	
	//se nao encontrar o contato mostra uma msg e n exclui nada
	if(!aux)
		printf("\nContato não encontrado\n");
	
	//se encontrar exclui e mostra uma msg de sucesso
	else{
		excluirNode(r, nome);
		printf("\nO contato '%s' foi excluído com sucesso\n", nome);
	}
}
