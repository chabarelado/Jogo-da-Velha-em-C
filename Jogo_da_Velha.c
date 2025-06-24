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
    return;
}

void Imprime_Tabuleiro(char tabuleiro[Linha][Coluna]){
    printf("    1   2   3\n");
    printf("----------------\n");
    printf("1 | %c | %c | %c\n", tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
    printf("   ---+---+---\n");
    printf("2 | %c | %c | %c\n", tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
    printf("    --+---+---\n");
    printf("3 | %c | %c | %c\n", tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);
    
    return;
}

void Jogo(char tabuleiro[Linha][Coluna]){
    char jogadores;
    int vencedor = 0;
    int linha, coluna;

    Incializa_Tabuleiro(tabuleiro);

    for (int i = 0; i <= 9 && vencedor == 0; i++)
    {
        if (i % 2 == 0)
        {
            jogadores = 'X';
        } 
        else {
            jogadores = 'O';
        }
        
        Imprime_Tabuleiro(tabuleiro);
        
        do
        {
            printf("\n> Jogador %c digite uma linha para posicionar o %c (de 1 a 3):",jogadores,jogadores);
            scanf("%d", &linha);
            printf("\n> Jogador %c digite uma coluna para posicionar o %c (de 1 a 3):",jogadores,jogadores);
            scanf("%d", &coluna);

            if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 )
            {
                printf("\n> Digite um valor válido!!!\n");
            }
            
            if (tabuleiro[linha-1][coluna-1] != '-')
            {
                printf("\n> Posição já utilizada, digite novamente.\n");
            }


        } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha-1][coluna-1] != '-');
        
        
        tabuleiro[linha-1][ coluna-1] = jogadores;

        if (tabuleiro[linha-1][0] == tabuleiro[linha-1][1] && tabuleiro[linha-1][1] == tabuleiro[linha-1][2])
        {
            vencedor = 1;
        }
        else {
            if (tabuleiro[0][coluna-1] == tabuleiro[1][coluna-1] && tabuleiro[1][coluna-1] == tabuleiro[2][coluna-1])
            {
                vencedor = 1;
            }
            else {
                if (linha == coluna && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
                    vencedor = 1;
                }
                else{ 
                    if (linha + coluna == 4 && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
                        vencedor = 1;
                    }
                }
            }
            
        }
    }
    
    if (vencedor == 0)
    {
        printf("\n> Deu velha!!!\n");
    } 
    else {
        printf("\n> Jogador %c Venceu!!!\n", jogadores);
    }
    
    return;
}


int main (){
    char tabuleiro[Linha][Coluna];
    int opcao;

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
            Jogo(tabuleiro);   
            break;
        case 2:
            printf("\nDuas pessoas jogam alternadamente, preenchendo cada um dos espaços vazios.\nTradicionalmente se faz com X e O como elementos para a marcação.\nCada participante deve usar um símbolo (X ou O). Vence o jogador que conseguir \nformar primeiro uma linha com três símbolos iguais, seja ela na horizontal,\nvertical ou diagonal.\n");
            break;
        case 3:
            printf("\n> Encerrando o jogo...\n");
            break;
        default:
            printf("\n!!!Opção Inválida, digite novamente!!!\n");
            break;
        }
    } while (opcao != 3);
    
    return 0;
}