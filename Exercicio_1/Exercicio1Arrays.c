#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 90

struct equipa{
	int id;
	char nome[20];
};

struct jogador{
	int id, numGolos, dataIniContrt, dataFimContrt;
	char nome[20], sobrenome[20];
	bool ativo;
	
	struct equipa equipaJogador;
} jogador[MAX];

//funcoes
int Menu(void);
void ordenar(void);
void listarJogador(void);
void listarJogadorEquipa(char equipaNome[]);
void cadastrarJogador(void);
void eliminarJogador(void);
void abrirArq(void);
void fecharArq(void);

int main(){
	abrirArq();
	int escolha;
	
	for(;;){
		escolha = Menu();
		switch(escolha){
			case 1:
				system("cls");
				cadastrarJogador();
				break;
			case 2:
				system("cls");
				listarJogador();
				printf("\n\n");
				break;
			case 3:
				system("cls");
				char nomeEquipa[20];
				printf("Nome da equipa: ");
				scanf("%s", &nomeEquipa);
				listarJogadorEquipa(nomeEquipa);
				printf("\n\n");
				break;
			case 4:
				system("cls");
				eliminarJogador();
				system("cls");
				listarJogador();
				printf("\n\n");
				break;	
			case 5:
				fecharArq();
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

void listarJogador(void){
	int i;
	for(i = 0; i < MAX; i++){
		
		printf("%d %8s %8s %8s %8d %8d %8d %8d\n",  	jogador[i].id,
								 						jogador[i].nome,
								 						jogador[i].sobrenome,
								 						jogador[i].equipaJogador.nome,
														jogador[i].numGolos,
														jogador[i].dataIniContrt,
														jogador[i].dataFimContrt,
														jogador[i].ativo);
	}
}

//Mostrar jogadores de uma equipa
void listarJogadorEquipa(char equipaNome[]){
	int i;
	for(i = 0; i < MAX; i++){
		
		if(strcmp(jogador[i].equipaJogador.nome,equipaNome) == 0){
			
			printf("%d %8s %8s %8s %8d %8d %8d %8d\n",  jogador[i].id,
								 						jogador[i].nome,
								 						jogador[i].sobrenome,
								 						jogador[i].equipaJogador.nome,
														jogador[i].numGolos,
														jogador[i].dataIniContrt,
														jogador[i].dataFimContrt,
														jogador[i].ativo);
		}

	}
}

//Cadastrar jogadores
void cadastrarJogador(void){
	int vazio;
	char resp;
	
	do{
		vazio = Vazio();
		if(vazio == -1){
			printf("Lista Cheia.\n");
			return;
		}
		
		printf("Insira o id do jogador: ");
		scanf("%d", &jogador[vazio].id);
		
		printf("Digite o Nome e sobrenome do jogador: ");
		scanf("%s %s", &jogador[vazio].nome, &jogador[vazio].sobrenome);
		
		printf("Digite a equipa do jogador: ");
		scanf("%s", &jogador[vazio].equipaJogador.nome);
		
		printf("Digite o inicio e fim do contrato do jogador: ");
		scanf("%d %d",&jogador[vazio].dataIniContrt, &jogador[vazio].dataFimContrt );
		
		printf("Quantos golos o jogador tem? ");
		scanf("%d", &jogador[vazio].numGolos);
		
		printf("O jagador ainda esta no ativo?(0-Nao/1-Sim) ");
		scanf("%d", &jogador[vazio].ativo);
		 
		printf("\n");
		printf("Adicionar outro jogador?(S/N): ");
		scanf("%s", &resp);
		
		system("cls");
		}while(resp != 'N');
}

//Eliminar terceiro jogador com mais jogos
void eliminarJogador(void){
	ordenar();
	jogador[2].nome[0] = '\0';
	
	
}

void ordenar(void){
	int i,j;
	struct jogador aux;
	for(i = 1; i < MAX; i++){
		aux = jogador[i];
		for(j = i; (j > 0) && (aux.numGolos < jogador[j-1].numGolos); j--){
			jogador[j] = jogador[j-1];
		}
		jogador[j] = aux;
	}
}

int Vazio(void){
	int i;
	
	for(i = 0; jogador[i].nome[0] && i < MAX; i++);
	
		if(i == MAX){
			return -1;
		}
	return i;
}

void abrirArq(void){
	FILE *abrir;
	abrir = fopen("Exercicio1.txt","rb");
	if(abrir == NULL){
		printf("Ocorreu algum erro\n");
	}
	fread(jogador,sizeof(struct jogador),MAX,abrir);
	fclose(abrir);
}

void fecharArq(void){
	FILE *fechar;
	fechar = fopen("Exercicio1.txt","ab");
	fwrite(jogador,sizeof(struct jogador),MAX,fechar);
	fclose(fechar);
}
