#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf(". "); // Água
            else if (tabuleiro[i][j] == 3)
                printf("N "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf("H "); // Área de habilidade
        }
        printf("\n");
    }
}

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Posiciona navios fixos no tabuleiro
void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    tabuleiro[2][2] = 3; // Exemplo de navio
    tabuleiro[5][5] = 3; // Outro navio
    tabuleiro[7][3] = 3; // Outro navio
}

// Aplica uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemX, int origemY, int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int deslocamento = TAM_HABILIDADE / 2; // Para centralizar a matriz da habilidade

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int x = origemX + i - deslocamento;
                int y = origemY + j - deslocamento;

                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO) {
                    if (tabuleiro[x][y] == 0) { // Não sobrescreve navios
                        tabuleiro[x][y] = 5;
                    }
                }
            }
        }
    }
}

// Cria uma matriz de habilidade em formato de Cruz
void preencherCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria uma matriz de habilidade em formato de Cone
void preencherCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i && i >= TAM_HABILIDADE / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria uma matriz de habilidade em formato de Octaedro
void preencherOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona alguns navios
    posicionarNavios(tabuleiro);

    // Exibe o tabuleiro inicial
    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Habilidade 1: Cruz
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    preencherCruz(habilidade);
    aplicarHabilidade(tabuleiro, 5, 5, habilidade);
    printf("\nTabuleiro com habilidade Cruz aplicada:\n");
    exibirTabuleiro(tabuleiro);

    // Habilidade 2: Cone
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    preencherCone(habilidade);
    aplicarHabilidade(tabuleiro, 7, 5, habilidade);
    printf("\nTabuleiro com habilidade Cone aplicada:\n");
    exibirTabuleiro(tabuleiro);

    // Habilidade 3: Octaedro
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    preencherOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, 5, 5, habilidade);
    printf("\nTabuleiro com habilidade Octaedro aplicada:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}