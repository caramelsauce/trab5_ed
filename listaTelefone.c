#include <stdio.h>
#include <stdlib.h>
#include "listaTelefone.h"

void inicListaTelefone(struct listaTelefones *lista)
{
	lista->inicio = NULL;
	lista->fim = NULL;
}

int listaVaziaTelefone(struct listaTelefones *lista)
{
	return (!lista->inicio && !lista->fim);
}

void inserirTelefone(struct listaTelefones *lista, int telefone)
{
	struct elementoTelefone *novo;
	novo = malloc(sizeof(struct elementoTelefone));
	novo->telefone = telefone;
	if(listaVaziaTelefone(lista)){
		novo->ant = novo->prox = NULL;
		lista->inicio = lista->fim = novo;
	}
	else{
		novo->ant = lista->fim;
		lista->fim->prox = novo;
		novo->prox = NULL;
		lista->fim = novo;
	}
}

int excluirTelefone(struct listaTelefones *lista, int telefone)
{
	struct elementoTelefone *aux = lista->inicio;
	int status = 0;
	while(aux != NULL){
		if(aux->telefone == telefone){
			status = 1;
			if(!aux->ant)
				lista->inicio = aux->prox;
			else if(aux == lista->fim){
				lista->fim = lista->fim->ant;
				lista->fim->prox = NULL;
			}
			else{
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
			}
			free(aux);
			aux = NULL;
		}
		else
			aux = aux->prox;
	}
	return status;
}

void excluirListaTelefones(struct listaTelefones *lista)
{
	struct elementoTelefone *aux = lista->inicio, *prox;
	while(aux != NULL){
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
	lista->inicio = NULL;
}

void printTelefones(struct listaTelefones *lista)
{
	struct elementoTelefone *aux = lista->inicio;
	printf("\tTelefones:\n");
	while(aux != NULL){
		printf("\t\t%d\n", aux->telefone);
		aux = aux->prox;
	}
	printf("\n\n");
}
