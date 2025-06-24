#include <stdio.h>  // Biblioteca padrão para entrada e saída de dados

// Definição das dimensões do tabuleiro (3x3)
#define Linha 3
#define Coluna 3

// Função para inicializar o tabuleiro com o caractere '-'
void Incializa_Tabuleiro(char tabuleiro[Linha][Coluna]){
    for (int i = 0; i < Linha; i++){
        for (int j = 0; j < Coluna; j++){
            tabuleiro[i][j] = '-'; // Preenche cada posição com '-'
        }
    }
    return;
}

// Função para imprimir o tabuleiro na tela de forma formatada
void Imprime_Tabuleiro(char tabuleiro[Linha][Coluna]){
    printf("    1   2   3\n");              // Títulos das colunas
    printf("----------------\n");
    printf("1 | %c | %c | %c\n", tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
    printf("   ---+---+---\n");
    printf("2 | %c | %c | %c\n", tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
    printf("    --+---+---\n");
    printf("3 | %c | %c | %c\n", tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);
    return;
}

// Função principal do jogo
void Jogo(char tabuleiro[Linha][Coluna]){
    char jogadores;     // Armazena o jogador da vez ('X' ou 'O')
    int vencedor = 0;   // Flag para verificar se houve um vencedor
    int linha, coluna;  // Coordenadas da jogada

    Incializa_Tabuleiro(tabuleiro);  // Inicializa o tabuleiro vazio

    // Loop principal: máximo de 9 rodadas (caso todas as casas sejam usadas)
    for (int i = 0; i <= 9 && vencedor == 0; i++){
        
        // Alterna entre jogador X e O
        if (i % 2 == 0){
            jogadores = 'X';
        } else {
            jogadores = 'O';
        }

        Imprime_Tabuleiro(tabuleiro);  // Mostra o tabuleiro atualizado

        // Laço para garantir que a entrada seja válida
        do {
            // Solicita linha e coluna ao jogador
            printf("\n> Jogador %c digite uma linha para posicionar o %c (de 1 a 3):",jogadores,jogadores);
            scanf("%d", &linha);
            printf("\n> Jogador %c digite uma coluna para posicionar o %c (de 1 a 3):",jogadores,jogadores);
            scanf("%d", &coluna);

            // Validação de entrada fora dos limites
            if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3){
                printf("\n> Digite um valor válido!!!\n");
            }

            // Verifica se a posição já está ocupada
            if (tabuleiro[linha-1][coluna-1] != '-'){
                printf("\n> Posição já utilizada, digite novamente.\n");
            }

        } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha-1][coluna-1] != '-');

        // Marca a jogada no tabuleiro
        tabuleiro[linha-1][coluna-1] = jogadores;

        // Verificação de vitória por linha
        if (tabuleiro[linha-1][0] == tabuleiro[linha-1][1] && tabuleiro[linha-1][1] == tabuleiro[linha-1][2]){
            vencedor = 1;
        }
        // Verificação de vitória por coluna
        else if (tabuleiro[0][coluna-1] == tabuleiro[1][coluna-1] && tabuleiro[1][coluna-1] == tabuleiro[2][coluna-1]){
            vencedor = 1;
        }
        // Verificação de vitória na diagonal principal
        else if (linha == coluna && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
            vencedor = 1;
        }
        // Verificação de vitória na diagonal secundária
        else if (linha + coluna == 4 && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
            vencedor = 1;
        }
    }

    // Após o laço, verifica se houve vencedor ou deu empate
    if (vencedor == 0){
        printf("\n> Deu velha!!!\n"); // Empate
    } else {
        printf("\n> Jogador %c Venceu!!!\n", jogadores); // Vitória
    }

    return;
}

// Função principal que exibe o menu e chama as outras funções
int main (){
    char tabuleiro[Linha][Coluna]; // Matriz do tabuleiro
    int opcao; // Escolha do menu

    printf("\tJogo da velha\n");

    // Menu principal com laço para continuar até escolher sair
    do {
        printf("\n-> Escolha as opções abaixo: \n");
        printf("1.Jogar\n");
        printf("2.Regras\n");
        printf("3.Sair\n");
        printf("-> Sua escolha: ");
        scanf("%d", &opcao);

        // Estrutura de decisão para tratar a escolha do jogador
        switch (opcao){
        case 1:
            Jogo(tabuleiro); // Inicia o jogo
            break;
        case 2:
            // Mostra as regras básicas do jogo da velha
            printf("\nDuas pessoas jogam alternadamente, preenchendo cada um dos espaços vazios.\n");
            printf("Tradicionalmente se faz com X e O como elementos para a marcação.\n");
            printf("Cada participante deve usar um símbolo (X ou O).\n");
            printf("Vence o jogador que conseguir formar primeiro uma linha com três símbolos iguais,\n");
            printf("seja ela na horizontal, vertical ou diagonal.\n");
            break;
        case 3:
            printf("\n> Encerrando o jogo...\n"); // Encerra o jogo
            break;
        default:
            printf("\n!!!Opção Inválida, digite novamente!!!\n"); // Trata entrada inválida
            break;
        }
    } while (opcao != 3); // Continua enquanto a opção for diferente de 3 (sair)

    return 0;
}
