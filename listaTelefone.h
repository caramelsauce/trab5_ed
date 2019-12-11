#ifndef LISTA_TELEFONE_H
#define LISTA_TELEFONE_H

struct elementoTelefone{
	int telefone;
	struct elementoTelefone *prox, *ant;
};

struct listaTelefones{
	struct elementoTelefone *inicio, *fim;
};

void inicListaTelefone(struct listaTelefones *lista);

int listaVaziaTelefone(struct listaTelefones *lista);

void inserirTelefone(struct listaTelefones *lista, int telefone);

int excluirTelefone(struct listaTelefones *lista, int telefone);

void excluirListaTelefones(struct listaTelefones *lista);

void printTelefones(struct listaTelefones *lista);

#endif
