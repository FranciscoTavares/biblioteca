/*
 * library project
 *  Created on: Jun 16, 2017
 *      Author: ftavares
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//tecnologias da informação e comunicação e suas relações com a agricultura
//tecnologiasdainformaçãoecomunicaçãoesuasrelaçõescomaagricultura

	typedef struct registroTombo{
		int numTombo;
		char nomeObra[150];
		char nomeAutor[50];
		char nomeEditora[30];
		int codArea;
	}Tombo;

	struct registroObra{
			int numTombo;
			int numExemplar;
			int dataCompra;
	};

	//struct registroTombo Tombo;
	struct registroObra Obra;

int criarDataBase(FILE *dataBase){
     if((dataBase = fopen("libraryDataBase.txt","a+")) == NULL){
    	 exit(0);
     }else{
    	 return 1;//error
     }
     fclose(dataBase);
     return 0;//success
}

void cadastrarTombos(FILE *libraryDataBase){

	system("clear");// limpar a tela para linux

	printf(" ********* CADASTRO DE TOMBOS ********* \n\n");

	Tombo newTombo;

    //Tombo = (struct registroTombo*) malloc(sizeof(struct registroTombo));
    if((libraryDataBase = fopen("libraryDataBase.txt","a+")) != NULL){

		//numero do tombo gerar automaticamente seguindo a estrutura xxxx-moth-year
    	printf("Número do Tombo: ");
    	scanf("%d", &newTombo.numTombo);

    	printf("Nome do livro: ");
    	scanf("\n%[^\n]s",newTombo.nomeObra);

	 	printf("Nome do Autor: ");
	 	scanf("\n%[^\n]s", newTombo.nomeAutor);

	 	printf("Nome do Editora: ");
	 	scanf("\n%[^\n]s", newTombo.nomeEditora);

	 	printf("Código da Área: ");
	 	scanf("%d",&newTombo.codArea);

	 	fwrite(&newTombo,sizeof(Tombo),1,libraryDataBase);
	 	rewind (libraryDataBase);
    }
    printf("TESTE DO VETOR: \n");
    while(fread(&newTombo,sizeof(Tombo),1,libraryDataBase)==1){
       printf("%d \n", newTombo.numTombo);
       printf("%s \n", newTombo.nomeObra);
       printf("%s \n", newTombo.nomeAutor);
       printf("%s \n", newTombo.nomeEditora);
       printf("%d \n", newTombo.codArea);
     }

	fclose(libraryDataBase);

	 printf(" ********* TOMBOS CADASTRADO ********* \n\n");

}


void cadastrarObras(){
	printf("cadastrarObras");
}
void mostrarObrasPorAreas(){
	printf("mostrarObrasPorAreas");
}
void mostrarObrasPorAutor(){
	printf("mostrarObrasPorAutor");
}
void mostrarObrasPorEditora(){
	printf("mostrarObrasPorEditora");
}
void encerrarPrograma(){
	system("clear");// limpar a tela para linux
	//printf("\033[2J");// limpar a tela para linux
	printf("\n\nObrigado por utilizar nosso sistema!!\n\n");
	exit(0);
}


void menu(FILE *libraryDataBase){
	int key;
	char condition;

	printf("Bem vindo ao acervo da biblioteca!\n");
	printf("Informe-me uma opção: ");
	scanf("%d",&key);
	fflush(stdin);

	switch (key) {
		case 1:
			cadastrarTombos(libraryDataBase);
			break;
		case 2:
			cadastrarObras();
			break;
		case 3:
			mostrarObrasPorAreas();
			break;
		case 4:
			mostrarObrasPorAutor();
			break;
		case 5:
			mostrarObrasPorEditora();
			break;
		case 6:
			encerrarPrograma();
			break;
		default:
			printf("Ops, você não informou-me uma opção válida!!\n\n");
			printf("Deseja repetir? [y|n] ");
			scanf(" %c", &condition);
			condition = tolower(condition);
			if(condition == 'y'){
				system("clear");// limpar a tela para linux
				//printf("\033[2J");// limpar a tela para linux
				menu(libraryDataBase);
			}else{
				encerrarPrograma();
			}
	}
}

int main(int argc, char** argv){

	FILE *dataBase;
	if(criarDataBase(dataBase))
		menu(dataBase);
	else
		printf("Ops, não foi possível encontrar ou criar um arquivo de banco de dados");
	return (EXIT_SUCCESS);
}


