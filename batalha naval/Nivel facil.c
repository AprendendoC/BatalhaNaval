#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Inicializa o tabuleiro com zeros (0 = água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    int i, j;

    // Coordenadas iniciais e orientação dos navios
    int linhaHorizontal = 4, colunaHorizontal = 1; // Navio horizontal
    int linhaVertical = 1, colunaVertical = 2;     // Navio vertical

    // Posiciona o navio horizontal no tabuleiro
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // Posiciona o navio vertical no tabuleiro
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro de Batalha Naval:\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}