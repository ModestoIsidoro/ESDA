#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct equipa{
	int id;
	char nome[20];
};

typedef struct jogador{
	int id, numGolos, dataIniContrt, dataFimContrt;
	char nome[20], sobrenome[20];
	bool ativo;
	
	struct equipa equipaJogador;
}Jogador;

typedef struct elemento{
	Jogador Dados;
	struct elemento *prox;
}*Lista , Elem;

//funcoes
int Menu();
Lista* Criar_lista();
Jogador receber(Lista* li);
void cadastrarJogador(Lista* li, Jogador jogdr);
void listarJogadorEquipa(Lista* li, char equipaNome[]);
void listarJogador(Lista* li);
void eliminarJogador(Lista* li);
void apagar(Lista *li);

int main(){
	Lista *li;
	Jogador jogdr;
	li = Criar_lista();
	
	int escolha;
	
	for(;;){
		escolha = Menu();
		switch(escolha){
			case 1:
				system("cls");
				jogdr = receber(li);
				cadastrarJogador(li, jogdr);
				break;
			case 2:
				system("cls");
				listarJogador(li);
				printf("\n");
				break;
			case 3:
				system("cls");
				char nomeEquipa[20];
				printf("Nome da equipa: ");
				scanf("%s", &nomeEquipa);
				listarJogadorEquipa(li, nomeEquipa);
				printf("\n");
				break;
			case 4:
				system("cls");
				eliminarJogador(li);
				system("cls");
				listarJogador(li);
				printf("\n");
				break;	
			case 5:
				system("cls");
				apagar(li);
				exit(0);
			default:
				printf("Opcao invalida\n\n");
		}
	}
	
	return 0;
}

int Menu(void){
	int esc;
	printf("ESCOLHA UMA OPCAO:\n");
	printf("1. Cadastrar Jogador \n");
	printf("2. Listar Jogadores \n");
	printf("3. Listar Jogadores duma equipa: \n");
	printf("4. Eliminar Jogador \n");
	printf("5. Sair\n");
	scanf("%d", &esc);
	
	return esc;
}

Lista* Criar_lista(){
	Lista* li = (Lista*)malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	}
	return li;
}

Jogador receber(Lista* li){
	Jogador jogdr;
	printf("Insira o id do jogador: ");
	scanf("%d", &jogdr.id);
		
	printf("Digite o Nome e sobrenome do jogador: ");
	scanf("%s %s", &jogdr.nome, &jogdr.sobrenome);
		
	printf("Digite a equipa do jogador: ");
	scanf("%s", &jogdr.equipaJogador.nome);
		
	printf("Digite o inicio e fim do contrato do jogador: ");
	scanf("%d %d",&jogdr.dataIniContrt, &jogdr.dataFimContrt );
		
	printf("Quantos golos o jogador tem? ");
	scanf("%d", &jogdr.numGolos);
		
	printf("O jagador ainda esta no ativo?(0-Nao/1-Sim) ");
	scanf("%d", &jogdr.ativo);

	system("cls");
	return jogdr;
}

//Cadastrar jogador
void cadastrarJogador(Lista* li, Jogador jogdr){
	if(li == NULL) return;
	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return;
	
	no->Dados = jogdr;
	no->prox = NULL;
	
	if((*li) == NULL){
		*li = no;
	}else{
		Elem *aux = *li;
		while(aux->prox != NULL){
			aux = aux->prox; 
		}
		aux->prox = no;
	}
	printf("Adicionado novo Jogador!!\n\n");
}

void listarJogador(Lista* li){
	if(li == NULL) return;
	if((*li) == NULL){
		printf("lista vazia...\n\n");
		return;
	}
	
	Elem *no = *li;
	do{
		printf("%d %8s %8s %8s %8d %8d %8d %8d\n",  	no->Dados.id,
								 						no->Dados.nome,
								 						no->Dados.sobrenome,
								 						no->Dados.equipaJogador.nome,
														no->Dados.numGolos,
														no->Dados.dataIniContrt,
														no->Dados.dataFimContrt,
														no->Dados.ativo);
		
		no = no->prox;
	}while(no->prox == NULL);
}

//Mostrar jogadores de uma equipa
void listarJogadorEquipa(Lista* li, char equipaNome[]){
	if(li == NULL) return;
	if((*li) == NULL){
		printf("lista vazia...\n\n");
		return;
	}
	
	Elem *no = *li;
	do{
		if(strcmp(no->Dados.equipaJogador.nome,equipaNome) == 0){
			
			printf("%d %8s %8s %8s %8d %8d %8d %8d\n",  no->Dados.id,
								 						no->Dados.nome,
								 						no->Dados.sobrenome,
								 						no->Dados.equipaJogador.nome,
														no->Dados.numGolos,
														no->Dados.dataIniContrt,
														no->Dados.dataFimContrt,
														no->Dados.ativo);
		}
		
		no = no->prox;
	}while(no->prox == NULL);
}

//Eliminar terceiro jogador com mais jogos
void eliminarJogador(Lista* li){
	if(li == NULL) return;
	if((*li) == NULL){
		printf("lista vazia...\n\n");
		return;
	}
	Elem *ant, *no = *li;
	while(no->prox != NULL){
		ant = no;
		no = no->prox;
	}
	if(no == *li) *li = no->prox;
	else ant->prox = no->prox;
	
	free(no);
}

void apagar(Lista *li){
	if(li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}
