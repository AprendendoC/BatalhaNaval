#include <stdio.h>

int main() {
    // Inicializa o tabuleiro com zeros (0 = água)
    int tabuleiro[10][10] = {0};
    int i, j;

    // Coordenadas iniciais e tamanho fixo dos navios
    int linhaHorizontal = 2, colunaHorizontal = 5; // Navio horizontal
    int linhaVertical = 7, colunaVertical = 1;     // Navio vertical
    int tamanhoNavio = 3;                          // Tamanho fixo do navio

    // Posiciona o navio horizontal no tabuleiro
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // Posiciona o navio vertical no tabuleiro
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro de Batalha Naval:\n");
    for (i = 0; i < 10; i++) { // 10x10 fixo no código
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}