# 🕹️ Jogo da Velha em C

Este é um simples jogo da velha (tic-tac-toe) implementado na linguagem C, para dois jogadores, jogado via terminal. O código permite que os jogadores joguem alternadamente, insiram suas jogadas e verifiquem a vitória ou empate.

---

## 📋 Funcionalidades

- Menu interativo com três opções: Jogar, Ver Regras e Sair
- Jogo entre dois jogadores (X e O)
- Validação de jogadas (posição inválida ou já ocupada)
- Verificação automática de vitória ou empate
- Tabuleiro impresso de forma clara e interativa

---

## ▶️ Como Executar

1. **Compile o código:**

```bash
gcc jogo_da_velha.c -o jogo

    Execute o programa:

./jogo

    É necessário ter o compilador gcc instalado. No Linux, você pode instalar com:

    sudo apt install build-essential

📌 Regras do Jogo

    Dois jogadores jogam alternadamente (X e O).

    Os jogadores escolhem uma linha e uma coluna (de 1 a 3) para marcar sua jogada.

    Vence quem alinhar três símbolos iguais na horizontal, vertical ou diagonal.

    Se todas as posições forem preenchidas sem vencedor, o jogo termina em empate (velha).

📁 Estrutura do Código

    main() — Menu e controle geral do programa.

    Jogo() — Loop principal do jogo, alternância de jogadores e verificação de vitória.

    Incializa_Tabuleiro() — Inicializa o tabuleiro com '-'.

    Imprime_Tabuleiro() — Mostra o estado atual do tabuleiro.


