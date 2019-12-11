#ifndef ARVORE_H
#define ARVORE_H

#include "listaTelefone.h"

struct Contato{
	char nome[50];
	struct listaTelefones telefones;
};

struct Node{
	struct Contato contato;
	struct Node *esq, *dir;
    int h;
};

void inicArvore(struct Node **r);

void insereNode(struct Node **r, struct Contato temp);

void insere(struct Node **r, struct Node *novo);

void excluirNode(struct Node **r, char *nome);

int altura(struct Node *r);

int max(int a, int b);

int FB(struct Node *y);

struct Node *RE(struct Node *y);

struct Node *RD(struct Node *y);

struct Node *RED(struct Node *y);

struct Node *RDE(struct Node *y);

struct Node *encontrarMaiorEAjeitar(struct Node **r);

struct Node *localizarNode(struct Node *r, char *nome); 

void printEmOrdemCrescente(struct Node *r);

void printEmOrdemDecrescente(struct Node *r);

void printPreOrdem(struct Node *r);

#endif
