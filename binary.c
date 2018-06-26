//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//Estrutura
struct str_no {
	char dado;
	int valNo;
	int esquerda;
	int direita;
	int pai;
};


//Vari�veis globais
char vetorValores[9] = {'+','*','5','-','+','6','3','4','1'};
struct str_no arvore[16];

//Prototipa��o
void menu_mostrar(void);
void arvore_popula(void);
void resultado(void);

//Fun��o principal
int main(void)
{	
setlocale(LC_ALL, "Portuguese");
	int opt = -1, temp;
	char pai, no, lado;
	do {
		menu_mostrar();
		scanf("%d", &opt);
		switch (opt) {
			case 1:
				
				arvore_popula();
				break;
			case 2:
				resultado();
				printf("Resultado final: %d\n", arvore[0].valNo);
					system("pause");
				break;
		}
	} while (opt!=0);

	
	return 0;
}

//Inserir n�s na �rvore
void arvore_popula()
{
	int pai;
	int filho;
	
	
			arvore[0].dado = '+';
			arvore[0].pai = -1;
			arvore[0].valNo = -1;
			arvore[0].esquerda = -1;
			arvore[0].direita = -1;
		
			filho = 1;
			arvore[0].esquerda = filho;
			arvore[filho].dado = '*';
			arvore[filho].pai = pai;
			arvore[filho].valNo = -1;
			arvore[filho].esquerda = -1;
			arvore[filho].direita = -1;
			
			filho = 2;
			arvore[0].direita = filho;
			arvore[filho].dado = '5';
			arvore[filho].pai = pai;
			arvore[filho].valNo = 5;
			arvore[filho].esquerda = -1;
			arvore[filho].direita = -1;
			
			filho = 3;
			arvore[1].esquerda = filho;
			arvore[filho].dado = '-';
			arvore[filho].pai = pai;
			arvore[filho].esquerda = -1;
			arvore[filho].direita = -1;
			
			filho = 4;
			arvore[1].direita = filho;
			arvore[filho].dado = '+';
			arvore[filho].pai = pai;
			arvore[filho].valNo = -1;
			arvore[filho].esquerda = -1;
			arvore[filho].direita = -1;
			
			filho = 7;
			arvore[3].esquerda = filho;
			arvore[filho].dado = '6';
			arvore[filho].pai = pai;
			arvore[filho].valNo = 6;
			arvore[filho].esquerda = -1;
			arvore[filho].direita = -1;
			
			filho = 8;
			arvore[3].direita = filho;
			arvore[filho].dado = '3';
			arvore[filho].pai = pai;
			arvore[filho].valNo = 3;
			arvore[filho].esquerda = -1;
			arvore[filho].direita = -1;
			
			filho = 9;
			arvore[4].esquerda = filho;
			arvore[filho].dado = '4';
			arvore[filho].pai = pai;
			arvore[filho].valNo = 4;
			arvore[filho].esquerda = -1;
			arvore[filho].direita = -1;
			
			filho = 10;
			arvore[4].direita = filho;
			arvore[filho].dado = '1';
			arvore[filho].pai = pai;
			arvore[filho].valNo = 1;
			arvore[filho].esquerda = -1;
			arvore[filho].direita = -1;
			
		
	}


// Calcular equa��es da �rvore
void resultado()
{
	int i;
	for (i = 15; i >= 0; i--) {
	
		if (arvore[i].dado=='+')
		{
		arvore[i].valNo = arvore[2*i+1].valNo + arvore[2*i+2].valNo;
	printf("%d + %d = %d\n", arvore[2*i+1].valNo,arvore[2*i+2].valNo, arvore[i].valNo);
	
		
		
		}
		
		if (arvore[i].dado=='-')
		{
			arvore[i].valNo = arvore[2*i+1].valNo - arvore[2*i+2].valNo;
	
		printf("%d - %d = %d\n", arvore[2*i+1].valNo,arvore[2*i+2].valNo, arvore[i].valNo);	
		
		}
		
		if (arvore[i].dado=='*')
		{
			arvore[i].valNo = arvore[2*i+1].valNo * arvore[2*i+2].valNo;
	
	printf("%d * %d = %d\n", arvore[2*i+1].valNo,arvore[2*i+2].valNo, arvore[i].valNo);
		
		}
		
		if (arvore[i].dado=='/')
		{
			arvore[i].valNo = arvore[2*i+1].valNo / arvore[2*i+2].valNo;
	
	printf("%d / %d = %d\n", arvore[2*i+1].valNo,arvore[2*i+2].valNo, arvore[i].valNo);
		
		}
	}
	
	
}
//Desenha o menu na tela
void menu_mostrar(void)
{
	system("cls");
	int i;
	for (i = 0; i < 15; i++) {
	
		printf("| %c ", arvore[i].dado);
	
	}
	printf("|  -- Dados\n");
	for (i = 0; i < 15; i++) {
		printf("----", i);
		
	}
	printf("\n");
	for (i = 0; i < 15; i++) {
		
		if (i<10)
		printf("| %d ", i);
		else
		printf("| %d", i);
	}
	printf("|  -- �ndice", i);
	
	printf("\n\n1 - Popular �rvore");
	printf("\n2 - Calcular e exibir resultado");
	printf("\n0 - Sair...\n\nOpcao: ");
}
