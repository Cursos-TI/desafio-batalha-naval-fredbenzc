#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_tabuleiro(int tab[10][10]) 
{
       
    printf("   "); 
    for (int i = 0; i < = 9; i++) 
	{
        printf(" %d", i);
    }
    printf("\n");

   
    for (int i = 0; i < 10; i++) 
	{
        printf("%d |", i); 
        for (int j = 0; j < 10; j++) 
		{
            printf(" %d", tab[i][j]);
        }
        printf("\n");
    }
 }


int main()
 {
  
    int tabuleiro[10][10] = {0},tabuleiro_PC[10][10] = {0},linha, coluna,maquina_C,maquina_L;

    srand(time(0));
    
	imprimir_tabuleiro(tabuleiro);
    
	
                
	for(int i=0; i<2;i++)
	{
		printf("\n\t %d\xa6 Porta-avioes: Ocupa 5 quadrados. \n\t Digite as COORDENADA\n\n",i+1);
		
		for(int j = 0; j < 5; j++)//Jogador adicionas os porta avioes
		{
	    	system("color 1E");
			printf("linha %d ",j );
			scanf("%d",&linha);
			printf("coluna %d ",j );
	    	scanf("%d",&coluna);
	    	system("cls");
			tabuleiro[linha][coluna] = 5;	
	    	imprimir_tabuleiro(tabuleiro); 
		
		}
}
	


    return 0;
}
