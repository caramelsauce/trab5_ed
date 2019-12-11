#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void inicArvore(struct Node **r)
{
	(*r) = NULL;
}

void insere(struct Node **r, struct Node *novo)
{
	if((*r) != NULL){
		if(strcmp((*r)->contato.nome, novo->contato.nome) > 0){
			if((*r)->esq == NULL)
				(*r)->esq = novo;
			else
				insere(&(*r)->esq, novo);
		}
		else{
			if((*r)->dir == NULL)
				(*r)->dir = novo;
			else
				insere(&(*r)->dir, novo);
		}
	}
	else
		(*r) = novo;
    (*r)->h = 1 + max(altura((*r)->esq), altura((*r)->dir));
    if(FB(*r) > 1){
        if(FB((*r)->dir) > 0)
            *r = RE(*r);
        else
            *r = RDE(*r);
    }
    else if(FB(*r) < -1){
        if(FB((*r)->esq) < 0)
            *r = RD(*r);
        else
            *r = RED(*r);
    }
}

void insereNode(struct Node **r, struct Contato temp)
{
	struct Node *novo = malloc(sizeof(struct Node));
	novo->contato = temp;
	novo->esq = NULL;
	novo->dir = NULL;
    novo->h = 1;
	insere(r, novo);
}

void excluirNode(struct Node **r, char *nome)
{
	struct Node *aux;
	if((*r) != NULL){
		if(strcmp(nome, (*r)->contato.nome) == 0){
			aux = (*r);
			if((*r)->esq == NULL)
				(*r) = (*r)->dir;
			else
				if((*r)->dir == NULL)
					(*r) = (*r)->esq;
				else{
					aux = encontrarMaiorEAjeitar(&((*r)->esq));
					(*r)->contato = aux->contato;
				}
			excluirListaTelefones(&aux->contato.telefones);
			free(aux);
		}
		else{
			if(strcmp(nome, (*r)->contato.nome) < 0)
				excluirNode(&((*r)->esq), nome);
			else
				excluirNode(&((*r)->dir), nome);
		}
	}
}

struct Node * encontrarMaiorEAjeitar(struct Node **r)
{
	struct Node *aux = (*r);
	if((*r)->dir == NULL){
		(*r) = (*r)->esq;
		return(aux);
	}
	else
		return encontrarMaiorEAjeitar(&((*r)->dir));
}

struct Node *localizarNode(struct Node *r, char *nome)
{
	if(!r)
		return NULL;
	else if(strcmp(r->contato.nome, nome) == 0)
		return r;
	else if(strcmp(r->contato.nome, nome) > 0)
		return (localizarNode(r->esq, nome));
	else
		return (localizarNode(r->dir, nome));
}

void printEmOrdemCrescente(struct Node *r)
{
	if(r != NULL){
		printEmOrdemCrescente(r->esq);
		printf("%s\n", r->contato.nome);
		printTelefones(&r->contato.telefones);
		printEmOrdemCrescente(r->dir);
	}
}

void printEmOrdemDecrescente(struct Node *r)
{
	if(r != NULL){
		printEmOrdemDecrescente(r->dir);
		printf("%s\n", r->contato.nome);
		printTelefones(&r->contato.telefones);
		printEmOrdemDecrescente(r->esq);
	}
}

void printPreOrdem(struct Node *r)
{
    if(r != NULL){
		printf("%s\n", r->contato.nome);
		printTelefones(&r->contato.telefones);
        printPreOrdem(r->esq);
        printPreOrdem(r->dir);
	}
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int altura(struct Node *r)
{
    if(!r)
        return 0;
    return r->h;
}

int FB(struct Node *y)
{
    if(!y)
        return 0;
    return (altura(y->dir) - altura(y->esq));
}

struct Node *RE(struct Node *y)
{
    struct Node *x = y->dir;
    struct Node *aux = x->esq;
    x->esq = y;
    y->dir = aux;
    y->h = 1 + max(altura(y->esq), altura(y->dir));
    x->h = 1 + max(altura(x->esq), altura(x->dir));
    return x;
}

struct Node *RD(struct Node *y)
{
    struct Node *x = y->esq;
    struct Node *aux = x->dir;
    x->dir = y;
    y->esq = aux;
    y->h = 1 + max(altura(y->esq), altura(y->dir));
    x->h = 1 + max(altura(x->esq), altura(x->dir));
    return x;
}

struct Node *RED(struct Node *y)
{
    y->esq = RE(y->esq);
    return RD(y);
}

struct Node *RDE(struct Node *y)
{
    y->dir = RD(y->dir);
    return RE(y);
}