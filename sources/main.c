/*
 * library project
 *  Created on: Jun 16, 2017
 *      Author: ftavares
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


void cadastrarTombos(){
	printf("cadastrarTombos");
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
	printf("\033[2J");// limpar a tela para linux
	printf("\n\nObrigado por utilizar nosso sistema!!\n\n");
	exit(0);
}


void menu(){
	int key;
	char condition;

	printf("Bem vindo ao acervo da biblioteca!\n");
	printf("Informe-me uma opção: ");
	scanf("%d",&key);


	switch (key) {
		case 1:
			cadastrarTombos();
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
				printf("\033[2J");// limpar a tela para linux
				menu();
			}else{
				encerrarPrograma();
			}
	}
}

int main(int argc, char** argv){

	menu();
	return (EXIT_SUCCESS);
}


