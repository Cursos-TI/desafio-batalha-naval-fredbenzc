#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//========================tabuleiros=================================================================
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


void imprime_dois_tabuleiros(char tab[10][10], char tabuleiro_PC[10][10])
{
    system("color 17");
	printf("=====================================================================================================\n");
    printf("                   PLAYER 1                                             COMPUTADOR          \n");
    printf("=====================================================================================================\n\n");
     
    printf("     "); 
    for (char c = 'A'; c < 'A' + 10; c++) printf("  %c ", c); 
    
    printf("         "); 
    
    printf("     "); 
    for (char c = 'A'; c < 'A' + 10; c++) printf("  %c ", c); 
    printf("\n\n");
    
    for (int i = 0; i < 10; i++) 
    {
        // --- PARTE DO TABULEIRO 1 ---
        printf(" %d   ", i); 
        for (int j = 0; j < 10; j++) 
        {
            printf("  %c ", tab[i][j]);
        }  
        
        printf("         "); 
        
        // --- PARTE DO TABULEIRO 2 (MÁSCARA ATIVADA) ---
        printf(" %d   ", i); 
        for (int j = 0; j < 10; j++) 
        {
             
            if (tabuleiro_PC[i][j] == 'N') //Se for um navio escondido ('N'), mostra água ('~') para o jogador
		    {
                printf("  ~ ");
            } 
			else 
			{
                printf("  %c ", tabuleiro_PC[i][j]); // Mostra 'X' ou 'O' se já foi atingido
            }
        }  
        
        printf("\n"); 
    }       
    printf("\n");
}

//====================================================================================================


//===================================== NAVIOS ======================================================
void Porta_avioes(int linha, char coluna, char tab[10][10])
{
	char op; 
	int i;
	
	system("color 0B");
	printf("\a");
				
	for(i=0;i < 5;i++)
	{
		printf("\n\t Porta-avioes: Ocupa 5 quadrados. (Parte %d de 5)\n\t Digite as COORDENADAS\n\n", i+1); 			
		printf("Linha (0 a 9): ");
        scanf("%d", &linha);
        
        printf("Coluna (a - j): ");
        scanf(" %c", &coluna); 
            
        if ((coluna >= 'a') && (coluna <= 'j') ) {
            op = coluna - 'a'; 
        } else {
            printf("Coluna inválida! Tente novamente.\n");
            i--; 
            continue;
        }  

        if (linha < 0 || linha > 9) {
            printf("Linha inválida! Tente novamente.\n");
            i--;
            continue;
        }

        tab[linha][op] = 'P';
        system("cls");
		imprime_tabuleiro(tab);
    }
}

void PC_porta_aviao(char tabuleiro_PC[10][10]) //pc
{
    int valido = 0;
    int maquina_L, maquina_C;
	system("color 04"); 
	    
    do {
        int direcao = rand() % 2; 
                		
		if (direcao == 0) // HORIZONTAL
    	{   
            maquina_L = rand() % 10;
            maquina_C = rand() % 6; 
            valido = 1;
            
    		for (int i = 0; i < 5; i++) {
                if (tabuleiro_PC[maquina_L][maquina_C + i] != '~') {
                    valido = 0; 
                    break;
                }
            }
            if (valido) {
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
            if (valido) {
                for (int i = 0; i < 5; i++) {
                    tabuleiro_PC[maquina_L + i][maquina_C] = 'N';
                }
            }
        }
    } while (!valido); 
    
}





//========ATAQUE DO PC================
void PC_ataca(char tabuleiro[10][10]) 
{
    int linha_ataque, coluna_ataque;
    int tiro_valido = 0;

    printf("\nTurno do Computador...\n");
    //system("pause"); // Dá uma pausa para o jogador ver que é a vez do PC

    do {
        linha_ataque = rand() % 10;
        coluna_ataque = rand() % 10;

        // Verifica se o PC já atirou nessa coordenada antes
        if (tabuleiro[linha_ataque][coluna_ataque] != 'X' && tabuleiro[linha_ataque][coluna_ataque] != 'O') 
        {
            tiro_valido = 1; // Encontrou uma posição inédita
            
            if (tabuleiro[linha_ataque][coluna_ataque] == 'N') 
            {
                tabuleiro[linha_ataque][coluna_ataque] = 'X'; // Acertou navio do jogador
                printf("O Computador acertou seu navio em [%d, %c]!\n\a", linha_ataque, 'a' + coluna_ataque);
            } 
            else 
            {
                tabuleiro[linha_ataque][coluna_ataque] = 'O'; // Acertou água
                printf("O Computador atirou em [%d, %c] e errou!\n", linha_ataque, 'a' + coluna_ataque);
            }
            //system("pause");
        }
    } while (!tiro_valido);
}





int main()
{
	 
    system("color 0B");
    
    char tabuleiro[10][10],tabuleiro_PC[10][10],coluna,op;
	int menu,linha,achou;
	
	srand(time(NULL)); 
    
    
    do
    {
       system("cls");
	   printf("\n\n");	
	   printf("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
	   printf("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");	
       printf("\t°°                       <<< BATALHA NAVAL >>>                         °°\n");
	   printf("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");	
       printf("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
	   printf("\t°°                                                                     °°\n");
       printf("\t°°            1 - 1 JOGADOR                                            °°\n");
	   printf("\t°°                                                                     °°\n");
	   printf("\t°°            2 - 2 JOGADOR                                            °°\n");
	   printf("\t°°                                                                     °°\n");
	   printf("\t°°            3 - PLACAR                                               °°\n");
	   printf("\t°°                                                                     °°\n");	
	   printf("\t°°                                                                     °°\n");	
	   printf("\t°°                                                                     °°\n");
	   printf("\t°°            4 - REGRA                                                °°\n");	
	   printf("\t°°                                                                     °°\n");
	   printf("\t°°            0- SAIR                                      <<FredBenz>>°°\n");	
       printf("\t°°                                                             V3.00.0 °°\n");	
	   printf("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
       printf("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
	   printf("\t- ");	 
	   scanf("%d",&menu);
	   
	   switch(menu)
	   {
	   	case 1:
	   		
			for (int i = 0; i < 10; i++) // Reinicia os tabuleiros com água
            {
               for (int j = 0; j < 10; j++) 
	           {   
			       tabuleiro[i][j] = '~';
    		        tabuleiro_PC[i][j] = '~'; 
                }   
            }           
                    
            PC_porta_aviao(tabuleiro_PC); 
            system("cls");	
			imprime_tabuleiro(tabuleiro);
			Porta_avioes(linha, coluna, tabuleiro);
			system("cls");
			imprime_dois_tabuleiros(tabuleiro, tabuleiro_PC);
			
			do
			{
       			PC_ataca(tabuleiro);
				   achou = 0; 
        
        		printf("digite linha (0 a 9): ");
        		scanf("%d", &linha);
        		printf("digite coluna (a a j): ");
        		scanf(" %c", &coluna);

        		if (linha < 0 && linha > 9) 
				{
           			printf("Linha inválida! Tente novamente.\n\n");
            		continue;
        		}

        		if (coluna >= 'a' && coluna <= 'j')
				{
            		op = coluna - 'a'; 
        		}		 
				else 
				{		
            		printf("Coluna inválida! Tente novamente.\n\n");
            	continue;
        		}		  
       
        		if (tabuleiro_PC[linha][op] == 'N')// Verifica o tiro
				{	
            		tabuleiro_PC[linha][op] = 'X'; 
            		system("cls");
            		imprime_dois_tabuleiros(tabuleiro, tabuleiro_PC);
            		printf("Acertou um navio!\n\a");
        		} 
        		else if (tabuleiro_PC[linha][op] == 'X' || tabuleiro_PC[linha][op] == 'O')
				{
           			printf("Você já atirou aqui antes! Tente outra coordenada.\n\n");
        		}	 
       			else 
				{
            		tabuleiro_PC[linha][op] = 'O'; 
            		system("cls");
            		imprime_dois_tabuleiros(tabuleiro, tabuleiro_PC);
            		printf("Errou! Tente novamente.\n\n");
        		}
          
        		for(int i = 0; i < 10; i++) // Verifica se ainda restam navios ocultos 'N'
				{
            		for(int j = 0; j < 10; j++) 
					{
                		if(tabuleiro_PC[i][j] == 'N') 
						{
                    		achou = 1; // Ainda tem navio ativo, o loop continua
                		}
            		}
        		}
          		if (achou == 0) 
				{
            		printf("Parabéns! Você destruiu todos os navios do computador!\n");
        		}
            } 
			while(achou == 1);
            system("pause");
        break;

              
		case 4:
		system("cls");	
		imprime_tabuleiro(tabuleiro);
		system("pause > nul");
		break;	   	
	   	
	   	
	   	
	   }//final do whitch
	   	   
	}//final do DO
	while(menu!=0);
    
return 0;
}   //final do MAIN()  
	   
