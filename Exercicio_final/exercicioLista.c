#include<stdio.h>
#include<stdlib.h>

typedef struct est{
	char nome[20];
	int codigo;
	int idade;
	
	struct est *proximo;
}Estudante;

//funcoes auxiliares

Estudante *inicializarLista();
Estudante *receber();
Estudante *ultimoLista(Estudante *lista);
int contador(Estudante *lista);
void mostrar(Estudante *lista);
void mostrarElemento(Estudante *Elemento);
void excluir(Estudante *lista);
Estudante *primeiroMenor(Estudante *lista);

//funcoes principais

Estudante *inserirFim(Estudante *lista);
Estudante *inserirInicio(Estudante *lista);
void inserirPosicao(Estudante *lista, int posicao);
void eliminarUltimo(Estudante* lista);
Estudante *eliminarPrimeiro(Estudante* lista);
void eliminarPosicao(Estudante *lista, int posicao);
void maisVelho(Estudante *lista);
void segundoMenor(Estudante *lista, Estudante *primeiro);


int main(){
	Estudante *lista = inicializarLista();
	
	lista = inserirInicio(lista);
	lista = inserirFim(lista);
	lista = inserirFim(lista);
	inserirPosicao(lista, 1);
	
	//eliminarUltimo(lista);
	//lista = eliminarPrimeiro(lista);
	//eliminarPosicao(lista,1);
	//maisVelho(lista);
	
	Estudante *primeiro = primeiroMenor(lista);
	segundoMenor(lista, primeiro);
	printf("\n\n");
	
	mostrar(lista);
	
	excluir(lista);
	
	return 0;
}

//funcao para inicializar lista
Estudante *inicializarLista(){
	return NULL;
}

//funcao para interacao
Estudante *receber(){
	Estudante *dado = (Estudante*)malloc(sizeof(Estudante));
	printf("Digite o nome: ");
	scanf("%s",&dado->nome);
	printf("Insira a idade: ");
	scanf("%d", &dado->idade);
	printf("Insira o codigo: ");
	scanf("%d", &dado->codigo);
	dado->proximo = NULL;
	system("cls");
	
	return dado;
}

//funcao para mostrar elemento da lista
void mostrarElemento(Estudante *Elemento){
	printf("%s\t|\t%d\t|\t%d\n",Elemento->nome, Elemento->idade, Elemento->codigo);
}

//funcao que retorna o ultimo elemento da lista
Estudante *ultimoLista(Estudante *lista){
	Estudante *aux = lista;
	while(aux->proximo){
		aux = aux->proximo;
	}
	return aux;
}

//funcacao para contar elementos da lista
int contador(Estudante *lista){
	Estudante *aux = lista;
	int cont = 0;
	while(aux){
		cont++;
		aux = aux->proximo;	
	}
	return cont;
}

//funcaco mostrar os dados da lista
void mostrar(Estudante *lista){
	Estudante *aux = lista;
	while(aux){
		printf("%s\t|\t%d\t|\t%d\n",aux->nome, aux->idade, aux->codigo);
		aux = aux->proximo;
	}
}

//funcao para elimnar lista
void excluir(Estudante *lista){
	Estudante *aux = lista;
	while(aux != NULL){
		free(aux);
		aux = aux->proximo;
	}
	free(aux);
	printf("\n\nEncerando...\n");
}
	
//funcao para inserir no fim da lista
Estudante *inserirFim(Estudante *lista){
	Estudante *dados = receber();
	Estudante *no = lista;
	if(contador(lista) == 0)lista = dados;
	else ultimoLista(no)->proximo = dados;
	
	printf("Novo estudante adicionado...\n\n");
	
	return lista;	
}

//inserir no inicio
Estudante *inserirInicio(Estudante *lista){
	Estudante *dados = receber();
	dados->proximo = lista;
	lista = dados;
	
	printf("Novo estudante adicionado...\n\n");
	
	return lista;
}

//funcao para inserir em qualquer posicao
void inserirPosicao(Estudante *lista, int posicao){
	Estudante *ant = lista, *pos = lista;
	Estudante *dados = receber();
	int i = 0;
	
	for(i;i < posicao; i++){
		ant = pos;
		pos = pos->proximo;
	}
	ant->proximo = dados;
	dados->proximo = pos;
	
	printf("Novo estudante adicionado...\n\n");
}

//funcao para eliminar o primero
Estudante *eliminarPrimeiro(Estudante* lista){
	if(contador(lista) != 0) 
		return lista = lista->proximo;
	else {
		printf("Lista Vazia...\n");
		return lista;
	}
}

//funcao para eliminar o ultimo da lista
void eliminarUltimo(Estudante* lista){
	if(contador(lista) == 0){
		printf("Lista Vazia...\n");
		exit(1);
	}else{
		Estudante *ant = lista, *pos = lista;
		while(pos->proximo != NULL){
			ant = pos;
			pos = pos->proximo;
		}
		ant->proximo = pos->proximo;
		printf("Dados eliminados...\n");
	}
	
}

//eliminar em qualquer posicao
void eliminarPosicao(Estudante *lista, int posicao){
	if(contador(lista) == 0){
		printf("Lista vazia...\n");
		exit(1);
	}else{
		Estudante *ant = lista, *post = lista;
		int i = 0;
		for(i;i < posicao ; i++){
			ant = post;
			post = post->proximo;
		}
		ant->proximo = post->proximo;
		printf("Dados eliminados...\n");
	}
}

//funcao para imprimir o estudante mais velho
void maisVelho(Estudante *lista){
	Estudante *aux = lista, *maior;
	while (aux != NULL){
		if(aux->idade > maior->idade){
			maior = aux;
		}
		aux = aux->proximo;
	}
	mostrarElemento(maior);
}

//funcao para mostrar o primeiro menor estudante
Estudante *primeiroMenor(Estudante *lista){
	Estudante *aux = lista, *primeiro = lista;
	while(aux != NULL){
		if(aux->idade < primeiro->idade){
			primeiro = aux;
		}
		aux = aux->proximo;
	}
	return primeiro;
}

//funcao para mostrar o segundo menor estudante
void segundoMenor(Estudante *lista, Estudante *primeiro){
	Estudante *aux = lista, *segundo = lista;
	while(aux != NULL){
		if(aux->idade > primeiro->idade && aux->idade < segundo->idade){
			segundo = aux;
		}
		aux = aux->proximo;
	}
	mostrarElemento(segundo);

}
