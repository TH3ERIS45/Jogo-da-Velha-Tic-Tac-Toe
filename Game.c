#include <stdio.h>
#include <locale.h>

#define jogador1 'X'
#define jogador2 'O'

char matriz[3][3];

void exibirTabuleiro() {
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            printf("%c   ", matriz[l][c]);
        }
        printf("\n");
    }
}

int verificarVitoria() {
    // Verifica vitória nas linhas e colunas
    for (int i = 0; i < 3; i++) {
        if ((matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2] && matriz[i][0] != '.') ||
            (matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i] && matriz[0][i] != '.')) {
            return 1;  // Vitória
        }
    }

    // Verifica vitória nas diagonais
    if ((matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != '.') ||
        (matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0] && matriz[0][2] != '.')) {
        return 1;  // Vitória
    }

    return 0;  // Sem vitória
}

int realizarJogada(char jogador) {
    int linha, coluna;

    do {
        printf("Jogador %c, informe a linha (0 a 2): ", jogador);
        scanf("%d", &linha);
        printf("Jogador %c, informe a coluna (0 a 2): ", jogador);
        scanf("%d", &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Entrada invÃ¡lida. Tente novamente.\n");
            continue;
        }

        if (matriz[linha][coluna] != '.') {
            printf("Essa posiÃ§Ã£o jÃ¡ foi jogada. Tente novamente.\n");
            continue;
        }

        break;  // Sai do loop se a jogada for valida
    } while (1);

    matriz[linha][coluna] = jogador;
    exibirTabuleiro();

    return verificarVitoria();
}

int main() {
    setlocale(LC_ALL, "pt_BR");

    // Inicializar o tabuleiro
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            matriz[l][c] = '.';
        }
    }

    int resultado;

    for (int contador = 0; contador < 9; contador++) {
        resultado = realizarJogada((contador % 2 == 0) ? jogador1 : jogador2);
        
        if (resultado) {
            printf("Jogador %c venceu!\n", (resultado == 1) ? jogador1 : jogador2);
            break;
        }

        if (contador == 8) {
            printf("Empate!\n");
        }
    }

    return 0;
}
