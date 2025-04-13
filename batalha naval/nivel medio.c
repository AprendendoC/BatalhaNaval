#include <stdio.h>

// Define constantes para melhorar a legibilidade e a manutenção
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define TOTAL_NAVIOS 4

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (representando água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionamento dos navios (coordenadas fixas para cada navio)
    int navios[TOTAL_NAVIOS][TAMANHO_NAVIO][2] = {
        // Cada navio é representado por três pares de (linha, coluna)
        {{1, 1}, {1, 2}, {1, 3}}, // Horizontal
        {{4, 2}, {5, 2}, {6, 2}}, // Vertical
        {{2, 2}, {3, 3}, {4, 4}}, // Diagonal crescente
        {{7, 9}, {8, 8}, {9, 7}}  // Diagonal decrescente
    };

    // Posiciona os navios no tabuleiro
    for (int n = 0; n < TOTAL_NAVIOS; n++) {
        for (int p = 0; p < TAMANHO_NAVIO; p++) {
            int linha = navios[n][p][0];
            int coluna = navios[n][p][1];
            tabuleiro[linha][coluna] = NAVIO;
        }
    }

    // Exibição do tabuleiro
    printf("Tabuleiro do Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}