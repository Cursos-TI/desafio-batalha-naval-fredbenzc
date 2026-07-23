#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void imprime_tabuleiro(char tab[10][10])
{
	printf("======================================================================================\n");
    printf(" \t                          CAMPO DE BATALHA NAVAL            \n");
    printf("======================================================================================\n\n");
	 
	for (char c = 'A'; c < 'A' + 10; c++)
	{
		printf("\t  %c ", c);
	}
	printf("\n");
    
	for (int i = 0; i < 10; i++) 
	{
        printf(" %d ", i);
	    printf("  "); 
                  
	    for (int j = 0; j < 10; j++) 
	    {
	        printf("\t  %c ",tab[i][j] );
        }  
    printf("\n");
   }       
}

// Sugestão: Use esta função para ver onde o PC jogou durante seus testes!
void imprime_tabuleiro_PC(char tab_PC[10][10])
{
	printf("======================================================================================\n");
    printf(" \t                       GABARITO SECRETO DA MAQUINA          \n");
    printf("======================================================================================\n\n");
	 
	for (char c = 'A'; c < 'A' + 10; c++)
	{
		printf("\t  %c ", c);
	}
	printf("\n");
    
	for (int i = 0; i < 10; i++) 
	{
        printf(" %d ", i);
	    printf("  "); 
                  
	    for (int j = 0; j < 10; j++) 
	    {
	        printf("\t  %c ",tab_PC[i][j] );
        }  
    printf("\n");
   }       
}

void Porta_avioes(int linha, char coluna, char tab[10][10])
{
	char op; 
	int i;
	
	printf("\a");
				
	for(i=0;i < 5;i++)
	{
		printf("\n\t Porta-avioes: Ocupa 5 quadrados. (Parte %d de 5)\n\t Digite as COORDENADAS\n\n", i+1); 			
		printf("Linha (0 a 9): ");
        scanf("%d", &linha);
        
        printf("Coluna (a - j): ");
        scanf(" %c", &coluna); 
            
        if ((coluna >= 'a') && (coluna <= 'j') ) 
    	{
            op = coluna - 'a'; 
        } 
		else 
	    {
            printf("Coluna inválida! Tente novamente.\n");
            i--; 
            continue;
        }  

        if (linha < 0 || linha > 9) 
		{
            printf("Linha inválida! Tente novamente.\n");
            i--;
            continue;
        }

        tab[linha][op] = 'P';
        system("cls");
		imprime_tabuleiro(tab);
    }
}

void submarino(int linha, char coluna, char tab[10][10])
{
	char op; 
	int i;
	
	printf("\a");
	system("color 0b");
				
	for(i=0;i < 2;i++)
	{
		printf("\n\t Submarino: Ocupa 2 quadrados. (Parte %d de 2)\n\t Digite as COORDENADAS\n\n", i+1); 			
		printf("Linha (0 a 9): ");
        scanf("%d", &linha);
        
        printf("Coluna (a - j): ");
        scanf(" %c", &coluna); 
            
        if ((coluna >= 'a') && (coluna <= 'j') ) 
    	{
            op = coluna - 'a'; 
        } 
		else 
	    {
            printf("Coluna inválida! Tente novamente.\n");
            i--; 
            continue;
        }  

        if (linha < 0 || linha > 9) 
		{
            printf("Linha inválida! Tente novamente.\n");
            i--;
            continue;
        }

        tab[linha][op] = 'S';
        system("cls");
		imprime_tabuleiro(tab);
    }
}
		
void PC_porta_aviao(char tabuleiro_PC[10][10])
{
    int valido = 0;
    int maquina_L, maquina_C;
        
    do {
        int direcao = rand() % 2; 
        
        if (direcao == 0) // HORIZONTAL
    	{   
            maquina_L = rand() % 10;
            maquina_C = rand() % 6; 
                   
            valido = 1;
            
    		for (int i = 0; i < 5; i++)
    		{
                if (tabuleiro_PC[maquina_L][maquina_C + i] != '~') 
    			{
                    valido = 0; 
                    break;
                }
            }
            
            if (valido) 
    		{
                for (int i = 0; i < 5; i++) {
                    tabuleiro_PC[maquina_L][maquina_C + i] = 'N';
                }
            }
        } 
        else  // VERTICAL
    	{
            maquina_L = rand() % 6; 
            maquina_C = rand() % 10;
            
            valido = 1;  
            
    		for (int i = 0; i < 5; i++) {
                if (tabuleiro_PC[maquina_L + i][maquina_C] != '~') {
                    valido = 0;
                    break;
                }
            }
            
            if (valido)  
    		{
                for (int i = 0; i < 5; i++) 
    			{
                    tabuleiro_PC[maquina_L + i][maquina_C] = 'N';
                }
            }
        }

    } while (!valido); 
    
    
    imprime_tabuleiro_PC(tabuleiro_PC); 
}

int main()
{
	char tabuleiro[10][10], tabuleiro_PC[10][10], coluna;
	int linha;
	
	srand(time(NULL)); // ADICIONADO: Configura a semente para sorteios aleatórios reais
	system("color 17");
	
	
	for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
	    {
    		tabuleiro[i][j] = '~';
    		tabuleiro_PC[i][j] = '~'; 
        }   
    }           


	
	imprime_tabuleiro(tabuleiro);
	Porta_avioes(linha, coluna, tabuleiro);
	submarino(linha, coluna, tabuleiro);
	system("cls");
	

	// Executa e mostra o posicionamento automático do PC
	PC_porta_aviao(tabuleiro_PC);
	
	return 0;	
}
