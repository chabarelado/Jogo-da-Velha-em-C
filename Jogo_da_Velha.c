#include <stdio.h>

#define Linha 3
#define Coluna 3

void Incializa_Tabuleiro(char tabuleiro[Linha][Coluna]){
    for (int i = 0; i < Linha; i++)
    {
        for (int j = 0; j < Coluna; j++)
        {
            tabuleiro[i][j] = '-';
        }
        
    }
}

void Imprime_Tabuleiro(char tabuleiro[Linha][Coluna]){
    printf(" %c | %c | %c\n", tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);
}



int main (){
    char tabuleiro[Linha][Coluna];
    int opcao;
    //Incializa_Tabuleiro(tabuleiro);
    //Imprime_Tabuleiro(tabuleiro);

    printf("\tJogo da velha\n");
    do  
    {   
        printf("\n-> Escolha as opções abaixo: \n");
        printf("1.Jogar\n");
        printf("2.Regras\n");
        printf("3.Sair\n");
        printf("-> Sua escolha: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            
            break;
        case 2:

            break;
        default:
            printf("\n!!!Opção Inválida, digite novamente!!!\n");
            break;
        }
    } while (opcao != 3);
    

    return 0;
}