#include <stdio.h>
#define TAM 10 // Tamanho do tabuleiro (10x10)

// Função para inicializar a matriz com 0
void inicializarMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = 0; // Inicializa todas as células com 0
        }
    }
}

// Função para exibir a matriz no console
void exibirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]); // Exibe cada elemento
        }
        printf("\n"); // Quebra de linha para o próximo nível
    }
}

// Função para criar o padrão em cone
void habilidadeCone(int matriz[TAM][TAM], int x, int y) {
    // Define o formato do cone
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (x + i >= 0 && x + i < TAM && y + j >= 0 && y + j < TAM) {
                // Condição para a forma de um cone
                if (abs(i) + abs(j) <= 2) {
                    matriz[x + i][y + j] = 1;
                }
            }
        }
    }
}

// Função para criar o padrão em cruz
void habilidadeCruz(int matriz[TAM][TAM], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        if (x + i >= 0 && x + i < TAM) {
            matriz[x + i][y] = 1; // Linha vertical da cruz
        }
        if (y + i >= 0 && y + i < TAM) {
            matriz[x][y + i] = 1; // Linha horizontal da cruz
        }
    }
}

// Função para criar o padrão em octaedro
void habilidadeOctaedro(int matriz[TAM][TAM], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (x + i >= 0 && x + i < TAM && y + j >= 0 && y + j < TAM) {
                // Condição para a forma de um octaedro
                if (abs(i) + abs(j) <= 2) {
                    matriz[x + i][y + j] = 1;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializar e exibir habilidade cone
    inicializarMatriz(tabuleiro);
    habilidadeCone(tabuleiro, 4, 4); // Coordenadas centrais
    printf("Habilidade: Cone\n");
    exibirMatriz(tabuleiro);

    printf("\n");

    // Inicializar e exibir habilidade cruz
    inicializarMatriz(tabuleiro);
    habilidadeCruz(tabuleiro, 4, 4); // Coordenadas centrais
    printf("Habilidade: Cruz\n");
    exibirMatriz(tabuleiro);

    printf("\n");

    // Inicializar e exibir habilidade octaedro
    inicializarMatriz(tabuleiro);
    habilidadeOctaedro(tabuleiro, 4, 4); // Coordenadas centrais
    printf("Habilidade: Octaedro\n");
    exibirMatriz(tabuleiro);

    return 0;
}
