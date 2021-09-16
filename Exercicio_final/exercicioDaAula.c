#include <stdio.h>
#include <stdlib.h>
//declaracao da estrutura da lista
typedef struct cel celula;
struct cel
{
    int dado;
    celula *proximo;
};

//declaracao de prototipos
void imprimir(celula c);
void imprimir1(celula *c);
void imprimir_lista(celula *c);
int tamanho(celula *c);
celula *ultimo(celula *c);
celula *adicionar_no_final(celula *li, celula *e);
celula *adicionar_no_inicio(celula *lista, celula *elemento3);

//funcoes pedidas pelo docente
void *adicionar_Qposicao(celula *lista, celula *elemento, int posicao);
celula *eliminar_primeiro(celula *lista);
void *eliminar_ultimo(celula *lista);
void *eliminar_Qposicao(celula *lista, int posicao);


//inicio da funcao...
int main()
{

    celula *lista = NULL;
    celula *elemento1 = (celula *)malloc(sizeof(celula));
    celula *elemento2 = (celula *)malloc(sizeof(celula));
    celula *elemento3 = (celula *)malloc(sizeof(celula));
    celula *elemento4 = (celula *)malloc(sizeof(celula));

    //atribuicao de valores aos elementos da lista
    elemento3->dado = 3;
    elemento3->proximo = NULL;
    elemento2->dado = 2;
    elemento2->proximo = NULL;
    elemento4->dado = 17;
    elemento4->proximo = NULL;
    elemento1->dado = 20;
    elemento1->proximo = NULL;

  
    
	lista = adicionar_no_final(lista, elemento3);
	lista = adicionar_no_final(lista, elemento1);
	lista = adicionar_no_final(lista, elemento2);
	//lista = adicionar_no_final(lista, elemento4);
    adicionar_Qposicao(lista, elemento4, 2);
    
    //lista = eliminar_primeiro(lista);
    //eliminar_ultimo(lista);
    eliminar_Qposicao(lista, 2);
    imprimir_lista(lista);

    //liberando memoria usada
    free(elemento1);
    free(elemento2);
    free(elemento3);
    free(elemento4);
    return 0;
}
//
celula *adicionar_no_inicio(celula *lista, celula *elemento3)
{
    //celula *ptr = lista;
    elemento3->proximo = lista;
    return elemento3;
}
//adicionar elemento no final da lista
celula *adicionar_no_final(celula *lista, celula *elemento3)
{
    celula *ptr = lista;
    if (tamanho(ptr) == 0)
        ptr = elemento3;
    
    else
    
        ultimo(ptr)->proximo = elemento3;
    
    return ptr;
}

//adicionar elemento em qualquer posicao da lista
void *adicionar_Qposicao(celula *lista, celula *elemento, int posicao){
	celula *ant=lista, *post=lista;
	int i =0;
	for(i;i < posicao; i++){
		ant = post;
		post = post->proximo;
	}
	ant->proximo = elemento;
	elemento->proximo = post;
}

//funcao para eliminar o primeiro elemento da lista
celula *eliminar_primeiro(celula *lista){
	if(tamanho(lista) == 0){
		printf("Lista Vazia...\n");
		return lista; 
	}else{
		return lista = lista->proximo;
	}	
}

//funcao para eliminar o ultimo da elemento da lista
void *eliminar_ultimo(celula *lista){
	if(tamanho(lista) == 0){
		printf("Lista Vazia...\n");
		exit(1);
	}else{
		celula *ant = lista, *post = lista;
		while(post->proximo != NULL){
			ant = post;
			post = post->proximo;
		}
		ant->proximo = post->proximo;
	}
}

//funcao para eliminar elemento de qualquer posicao
void *eliminar_Qposicao(celula *lista, int posicao){
	if(tamanho(lista) == 0){
		printf("Lista Vazia...\n");
		exit(1);
	}else{
	celula *ant = lista, *post = lista;
	int i = 0;
	for(i;i < posicao; i++){
		ant = post;
		post = post->proximo;
	}
	ant->proximo = post->proximo;
	}
}

//funcao para contar ele,mentos de uma llista
int tamanho(celula *c)
{
    celula *ptr;
    ptr = c;
    int i = 0;
    while (ptr)
    {
        i++;
        ptr = ptr->proximo;
    }
    return i;
}

//ultimo elemento
celula *ultimo(celula *c)
{
    celula *ptr = c;
    while (ptr->proximo)
        ptr = ptr->proximo;
    return ptr;
}
//funcao para imprimir elementos de uma lista]
void imprimir_lista(celula *c)
{
    celula *ptr;
    ptr = c;
    printf("\n[");
    while (ptr)
    {
        imprimir1(ptr);
        ptr = ptr->proximo;
    }
    printf("]\n");
}
void imprimir1(celula *c)
{
    //printf("\n[ %p ][%i]\n", c->proximo, c->dado);
    printf(" %i ,", c->dado);
}
void imprimir(celula c)
{
    printf("\n[ %p ][%i]\n", c.proximo, c.dado);
}

