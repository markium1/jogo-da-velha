/*
	Name: JOGO DA VELHA	
	Copyright: 
	Author: Marcos Soares
	Date: 07/05/18 21:14
	Description: O famoso jogo da velha feito por Marcos Soares para trabalhar seus conhecimentos na Linguagem C.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define JOGADOR1 1
#define JOGADOR2 2
#define GANHAR 666

char linha_coluna[100][100] = {""};
int linha1,coluna1;
int linha2,coluna2;
int vez = 1;
int i = 0;
int ganhou = 0;


int jogo()
{
	printf("  1   2   3\n");
	printf("1 %c | %c |%c\n",linha_coluna[1][1],linha_coluna[1][2],linha_coluna[1][3]);
	printf("2 %c | %c |%c\n",linha_coluna[2][1],linha_coluna[2][2],linha_coluna[2][3]);
	printf("3 %c | %c |%c\n",linha_coluna[3][1],linha_coluna[3][2],linha_coluna[3][3]);
	
	//DIAGONAIS
	if(linha_coluna[1][1] == linha_coluna[2][2] && linha_coluna[2][2] == linha_coluna[3][3] && linha_coluna[1][1] != NULL)
	{
		printf("VOCÊ GANHOU!!!!!!!\n");
		ganhou = GANHAR;
	}
	else if(linha_coluna[1][3] == linha_coluna[2][2] && linha_coluna[2][2] == linha_coluna[3][1] && linha_coluna[1][3] != NULL)
	{
		printf("VOCÊ GANHOU!!!!!!!\n");
		ganhou = GANHAR;
	}
	//VERTICAIS
	else if(linha_coluna[1][1] == linha_coluna[2][1] && linha_coluna[2][1] == linha_coluna[3][1] && linha_coluna[1][1] != NULL)
	{
		
		printf("VOCÊ GANHOU!!!!!!!\n");
		ganhou = GANHAR;
	}
	else if(linha_coluna[1][2] == linha_coluna[2][2] && linha_coluna[2][2] == linha_coluna[3][2] && linha_coluna[1][2] != NULL)
	{
		printf("VOCÊ GANHOU!!!!!!!\n");
		ganhou = GANHAR;		
	}
	else if(linha_coluna[1][3] == linha_coluna[2][3] && linha_coluna[2][3] == linha_coluna[3][3] && linha_coluna[1][3] != NULL)
	{
		printf("VOCÊ GANHOU!!!!!!!\n");
		ganhou = GANHAR;		
	}
	//HORIZONTAIS
	else if(linha_coluna[1][1] == linha_coluna[1][2] && linha_coluna[1][2] == linha_coluna[1][3] && linha_coluna[1][1] != NULL)
	{
		printf("VOCÊ GANHOU!!!!!!!\n");
		ganhou = GANHAR;		
	}
	else if(linha_coluna[2][1] == linha_coluna[2][2] && linha_coluna[2][2] == linha_coluna[2][3] && linha_coluna[2][1] != NULL)
	{
		printf("VOCÊ GANHOU!!!!!!!\n");
		ganhou = GANHAR;		
	}
	else if(linha_coluna[3][1] == linha_coluna[3][2] && linha_coluna[3][2] == linha_coluna[3][3] && linha_coluna[3][1] != NULL)
	{
		printf("VOCÊ GANHOU!!!!!!!\n");
		ganhou = GANHAR;		
	}
	
}

int jogador1()
{
		printf("JOGADOR 1\n");
		printf("LINHA = ");
		scanf("%d",&linha1);
		printf("COLUNA = ");
		scanf("%d",&coluna1);
		if(linha1 == 1 || linha1 == 2 || linha1 == 3 && coluna1 == 1 || coluna1 == 2 || coluna1 == 3)
		{
			if(linha_coluna[linha1][coluna1] != 'O')
			{
				linha_coluna[linha1][coluna1] = 'X';
			}		
			else
			{
				printf("JOGADA PERDIDA _|_\n");
			}
		}
		else
		{
			printf("JOGADA INVALIDA\n");
		}
		
		vez = JOGADOR2;
		i++;
		system("cls");
		jogo();
}

int jogador2()
{
		printf("JOGADOR 2\n");
		printf("LINHA = ");
		scanf("%d",&linha2);
		printf("COLUNA = ");
		scanf("%d",&coluna2);
		if(linha2 == 1 || linha2 == 2 || linha2 == 3 && coluna2 == 1 || coluna2 == 2 || coluna2 == 3 )
		{
			if(linha_coluna[linha2][coluna2] != 'X')
			{
				linha_coluna[linha2][coluna2] = 'O';
			}
			else
			{
				printf("JOGADA PERDIDA _|_\n");
			}
		}
		else
		{
			printf("JOGADA INVALIDA\n");
		}

		vez = JOGADOR1;
		i++;
		system("cls");
		jogo();
		
}

int main(){
	
	jogo();
	while(i < 9)
	{
	
		if(vez == JOGADOR1)
		{
			jogador1();
		}
		else
		{
			jogador2();
		}
		if(ganhou)
		{
			break;
		}
	}
	system("pause");
}

