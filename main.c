#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore.h"

int main()
{
    struct Node *r;
    struct Contato temp;
    inicListaTelefone(&temp.telefones);
    inicArvore(&r);
    strcpy(temp.nome, "10");
    insereNode(&r, temp);
    strcpy(temp.nome, "20");
    insereNode(&r, temp);
    strcpy(temp.nome, "30");
    insereNode(&r, temp);
    strcpy(temp.nome, "40");
    insereNode(&r, temp);
    strcpy(temp.nome, "50");
    insereNode(&r, temp);
    strcpy(temp.nome, "25");
    insereNode(&r, temp);
    printPreOrdem(r);
    return 0;
}