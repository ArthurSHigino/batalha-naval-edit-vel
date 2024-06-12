#include<stdio.h>
#include<stdlib.h>

int main (){
	FILE *fp;
	char tile = 196, letra = 65, linha_barco;
	int k = 0, linhas, colunas, n, i, j, q, vitoria = 0,turno = 1, posicionamento_barcos1 = 0,posicionamento_barcos2 = 0,barcos = 0, barcos_a_serem_posicionados, coluna_barco, conversor, barcos_afundados1 = 0, barcos_afundados2 = 0;
	
	fp = fopen("placar.txt", "a+");
	//entradas
	printf("CRIACAO DO MAPA");
	
	printf("\n\ndigite a quantidade de linhas (letras)\t");
	scanf("%d", &linhas);
	printf("\ndigite a quantidade de colunas (numeros)\t");
	scanf("%d", &colunas);
	printf("\nquantos barcos serao posicionados por cada jogador?\t");
	scanf("%d", &barcos_a_serem_posicionados);
	
	char barcos1[colunas][linhas], barcos2[colunas][linhas], bombardeio1[colunas][linhas], bombardeio2[colunas][linhas];
	
	system("cls"); //comando limpar tela
	
	//inicializando com espaço as variaveis de preenchimento
	for (i = 0; i < colunas; i++){
		for (j = 0; j < linhas; j++){
			barcos1[i][j] = 32;
			barcos2[i][j] = 32;
			bombardeio1[i][j] = 32;
			bombardeio2[i][j] = 32;
		}
	}
	
	//inicio do sistema do batalha naval
	while (vitoria == 0){
		if((turno % 2)!=0){ //turnos variam com a variavel turno se for impar e o turno do jogador 1
			printf("\n\nVEZ DO JOGADOR 1\n\n");
			if(posicionamento_barcos1 == 0){ //se os barcos nao tiverem sido posicionados ainda (ou seja a varivel "posicionamento_de_barcos" tenha o valor 0)
				for(n = 0; n < barcos_a_serem_posicionados; n++){
					
					//começo de printar o mapa ******************
				
					//tabela para localização (funciona de 1 a 99)
					for(i = 0; i < colunas; i++){
						if(i <= 9){
							printf("   %d", i+1);	
						}else{
							printf("  %d", i+1);
						}
					}
					printf("\n");
					for (i = 0;i < linhas; i++){
						
						k = 0;
							while (k != colunas){
								if(i > 0){
									break;
								}
								if(k == 0){
									printf(" %c%c%c%c%c", 218, tile, tile, tile, 194);
								}else if(k==colunas-1){
									printf("%c%c%c%c", tile, tile, tile, 191);
								}else{
									printf("%c%c%c%c", tile, tile, tile, 194);
								}
								k++;
							}
						
						printf("\n");
						
						k = 0;
						while (k != colunas){
							if(k==0){
								printf("%c%c%c%c%c%c", letra++, 179, 32, barcos1[k][i], 32, 179);  //variavel **
								}else{
								printf("%c%c%c%c", 32, barcos1[k][i], 32, 179);	//variavel**
							}
							k++;
						}
						
						printf("\n");	
						k = 0;	
						while (k != colunas){
							if((k == 0)&&(i == linhas-1)){
								printf(" %c%c%c%c%c", 192 ,tile, tile, tile, 193);
							}else if((k==0)&&(i != linhas-1)){
								printf(" %c%c%c%c%c", 195 ,tile, tile, tile, 197);
							}else if((k == colunas-1)&&(i == linhas-1)){
								printf("%c%c%c%c", tile, tile, tile, 217);
							}else if((k == colunas-1)&&(i != linhas-1)){
								printf("%c%c%c%c", tile, tile, tile, 180);				
							}else if(i==linhas-1){
								printf("%c%c%c%c", tile, tile, tile, 193);
							}else{
								printf("%c%c%c%c", tile, tile, tile, 197);				
							}
							k++;
						}		
					}
					
					//fim de printar o mapa ***************************
					letra = 65;
					fflush(stdin);
					printf("\ndigite qual sera a linha (letra maiuscula) a posicionar o barco %d\t", n+1);
					scanf("%c", &linha_barco);
					printf("\ndigite qual sera a coluna(numero) a posicionar o barco %d\t", n+1);
					scanf("%d", &coluna_barco);
					conversor = 0;
					for(q = 65; q <= 90; q++){ //converte linha_barco em numero a ser utilizadopelo mapa
						conversor++;
						if(linha_barco == q){
							linha_barco = conversor;
						}
					}
					barcos1[coluna_barco - 1][linha_barco - 1] = 42; //!!!!!!
					
					system("cls");		//limpa a tela		
				}
				posicionamento_barcos1 = 1; //comando diz que ja posicionou os barcos
				turno++; //passa o turno
			}else{ //se os barcos ja tiverem sido posicionados
			
					//começo de printar o mapa ******************
					//tabela para localização (funciona de 1 a 99)
					for(i = 0; i < colunas; i++){
						if(i <= 9){
							printf("   %d", i+1);	
						}else{
							printf("  %d", i+1);
						}
					}
					printf("\n");
					letra = 65;
					for (i = 0;i < linhas; i++){
						
						k = 0;
							while (k != colunas){
								if(i > 0){
									break;
								}
								if(k == 0){
									printf(" %c%c%c%c%c", 218, tile, tile, tile, 194);
								}else if(k==colunas-1){
									printf("%c%c%c%c", tile, tile, tile, 191);
								}else{
									printf("%c%c%c%c", tile, tile, tile, 194);
								}
								k++;
							}
						
						printf("\n");
						
						k = 0;
						while (k != colunas){
							if(k==0){
								printf("%c%c%c%c%c%c", letra++, 179, 32, bombardeio1[k][i], 32, 179);  //variavel **
								}else{
								printf("%c%c%c%c", 32, bombardeio1[k][i], 32, 179);	//variavel**
							}
							k++;
						}
						
						printf("\n");	
						k = 0;	
						while (k != colunas){
							if((k == 0)&&(i == linhas-1)){
								printf(" %c%c%c%c%c", 192 ,tile, tile, tile, 193);
							}else if((k==0)&&(i != linhas-1)){
								printf(" %c%c%c%c%c", 195 ,tile, tile, tile, 197);
							}else if((k == colunas-1)&&(i == linhas-1)){
								printf("%c%c%c%c", tile, tile, tile, 217);
							}else if((k == colunas-1)&&(i != linhas-1)){
								printf("%c%c%c%c", tile, tile, tile, 180);				
							}else if(i==linhas-1){
								printf("%c%c%c%c", tile, tile, tile, 193);
							}else{
								printf("%c%c%c%c", tile, tile, tile, 197);				
							}
							k++;
						}		
					}
					
					//fim de printar o mapa *************************** (BOMBARDEIO1)
			fflush(stdin);		
			printf("\ndigite a linha (letra maiuscula) onde quer bombardear\t");
			scanf("%c", &linha_barco);
			printf("\ndigite a coluna (numero) onde quer bombardear\t");
			scanf("%d", &coluna_barco);
			conversor = 0;
			for(q = 65; q <= 90; q++){
				conversor++;
				if(linha_barco == q){
				linha_barco = conversor;
				}
			}
			
			bombardeio1[coluna_barco - 1][linha_barco - 1] = 42;
			if(bombardeio1[coluna_barco - 1][linha_barco - 1] == barcos2[coluna_barco - 1][linha_barco -1]){
				bombardeio1[coluna_barco - 1][linha_barco - 1] = 88; //!!!!!!
				barcos_afundados1++;
				if(barcos_afundados1 == barcos_a_serem_posicionados){
					vitoria = 1;
				}
				
			}
			if(vitoria == 1){
				break;
			}
			
			system("cls");		//limpa a tela			
			
			turno++; //avanço do turno
			}
			
		}else{ //turno do jogador 2 ocorre com turno par
			printf("\n\nVEZ DO JOGADOR 2\n\n");
			if(posicionamento_barcos2 == 0){ //se os barcos nao tiverem sido posicionados ainda (ou seja a varivel "posicionamento_de_barcos" tenha o valor 0)
				for(n = 0; n < barcos_a_serem_posicionados; n++){
					
					//começo de printar o mapa ******************
				
					//tabela para localização (funciona de 1 a 99)
					for(i = 0; i < colunas; i++){
						if(i <= 9){
							printf("   %d", i+1);	
						}else{
							printf("  %d", i+1);
						}
					}
					printf("\n");
					for (i = 0;i < linhas; i++){
						
						k = 0;
							while (k != colunas){
								if(i > 0){
									break;
								}
								if(k == 0){
									printf(" %c%c%c%c%c", 218, tile, tile, tile, 194);
								}else if(k == colunas-1){
									printf("%c%c%c%c", tile, tile, tile, 191);
								}else{
									printf("%c%c%c%c", tile, tile, tile, 194);
								}
								k++;
							}
						
						printf("\n");
						
						k = 0;
						while (k != colunas){
							if(k==0){
								printf("%c%c%c%c%c%c", letra++, 179, 32, barcos2[k][i], 32, 179);  //variavel **
								}else{
								printf("%c%c%c%c", 32, barcos2[k][i], 32, 179);	//variavel**
							}
							k++;
						}
						
						printf("\n");	
						k = 0;	
						while (k != colunas){
							if((k == 0)&&(i == linhas-1)){
								printf(" %c%c%c%c%c", 192 ,tile, tile, tile, 193);
							}else if((k==0)&&(i != linhas-1)){
								printf(" %c%c%c%c%c", 195 ,tile, tile, tile, 197);
							}else if((k == colunas-1)&&(i == linhas-1)){
								printf("%c%c%c%c", tile, tile, tile, 217);
							}else if((k == colunas-1)&&(i != linhas-1)){
								printf("%c%c%c%c", tile, tile, tile, 180);				
							}else if(i==linhas-1){
								printf("%c%c%c%c", tile, tile, tile, 193);
							}else{
								printf("%c%c%c%c", tile, tile, tile, 197);				
							}
							k++;
						}		
					}
					
					//fim de printar o mapa ***************************
					letra = 65;
					fflush(stdin);
					printf("\ndigite qual sera a linha (letra maiuscula) a posicionar o barco %d\t", n+1);
					scanf("%c", &linha_barco);
					printf("\ndigite qual sera a coluna(numero) a posicionar o barco %d\t", n+1);
					scanf("%d", &coluna_barco);
					conversor = 0;  //começa converter letra em numero a ser usado no mapa
					for(q = 65; q <= 90; q++){
						conversor++;
						if(linha_barco == q){
							linha_barco = conversor;
						}
					}
					barcos2[coluna_barco - 1][linha_barco - 1] = 42; //!!!!!!
					
					system("cls");		//limpa a tela		
				}
				posicionamento_barcos2 = 1; //comando diz que ja posicionou os barcos
				turno++; //passa o turno
			}else{ //se os barcos ja tiverem sido posicionados (BOMBARDEIO2)
			
					//começo de printar o mapa ******************
				letra = 65;
					//tabela para localização (funciona de 1 a 99)
					for(i = 0; i < colunas; i++){
						if(i <= 9){
							printf("   %d", i+1);	
						}else{
							printf("  %d", i+1);
						}
					}
					printf("\n");
					for (i = 0;i < linhas; i++){
						
						k = 0;
							while (k != colunas){
								if(i > 0){
									break;
								}
								if(k == 0){
									printf(" %c%c%c%c%c", 218, tile, tile, tile, 194);
								}else if(k==colunas-1){
									printf("%c%c%c%c", tile, tile, tile, 191);
								}else{
									printf("%c%c%c%c", tile, tile, tile, 194);
								}
								k++;
							}
						
						printf("\n");
						k = 0;
						while (k != colunas){
							if(k==0){
								printf("%c%c%c%c%c%c", letra++, 179, 32, bombardeio2[k][i], 32, 179);  //variavel **
								}else{
								printf("%c%c%c%c", 32, bombardeio2[k][i], 32, 179);	//variavel**
							}
							k++;
						}
						
						printf("\n");	
						k = 0;	
						while (k != colunas){
							if((k == 0)&&(i == linhas-1)){
								printf(" %c%c%c%c%c", 192 ,tile, tile, tile, 193);
							}else if((k==0)&&(i != linhas-1)){
								printf(" %c%c%c%c%c", 195 ,tile, tile, tile, 197);
							}else if((k == colunas-1)&&(i == linhas-1)){
								printf("%c%c%c%c", tile, tile, tile, 217);
							}else if((k == colunas-1)&&(i != linhas-1)){
								printf("%c%c%c%c", tile, tile, tile, 180);				
							}else if(i==linhas-1){
								printf("%c%c%c%c", tile, tile, tile, 193);
							}else{
								printf("%c%c%c%c", tile, tile, tile, 197);				
							}
							k++;
						}		
					}
					
					//fim de printar o mapa ***************************
					
			fflush(stdin);		
			printf("\ndigite a linha (letra maiuscula) onde quer bombardear\t");
			scanf("%c", &linha_barco);
			printf("\ndigite a coluna (numero) onde quer bombardear\t");
			scanf("%d", &coluna_barco);
			conversor = 0;
			for(q = 65; q <= 90; q++){ //conversor
				conversor++;
				if(linha_barco == q){
				linha_barco = conversor;
				}
			}
			
			bombardeio2[coluna_barco - 1][linha_barco - 1] = 42;
			if(bombardeio2[coluna_barco - 1][linha_barco - 1] == barcos1[coluna_barco - 1][linha_barco -1]){
				bombardeio2[coluna_barco - 1][linha_barco - 1] = 88; //!!!!!!
				barcos_afundados2++;
				if(barcos_afundados2 == barcos_a_serem_posicionados){
					vitoria = 2;
				}
				
			}
			if(vitoria == 2){
				break;
			}
			
			system("cls");		//limpa a tela			
			
			turno++; //avanço do turno
			} //fim dos barcos ja tiverem sido posicionados
		} //fim do turno 2
		
		
	} //fim dos turnos (vitoria declarada)
	
	printf("\n\nparabens o jogador %d ganhou!", vitoria);
	fprintf(fp,"jogador %d ganhou\n", vitoria);
	fclose(fp);
	
	return 0;
} //fim do int main
