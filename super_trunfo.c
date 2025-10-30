#include <stdio.h>

typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

void exibirCarta(Carta c) {
    printf("\n=== %s ===\n", c.nome);
    printf("Forca: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligencia: %d\n", c.inteligencia);
}

int getAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.forca;
        case 2: return c.velocidade;
        case 3: return c.inteligencia;
        default: return 0;
    }
}

int main() {
    Carta carta1 = {"Dragao Dourado", 90, 70, 60};
    Carta carta2 = {"Fenix de Fogo", 85, 75, 80};

    int modo, escolha1, escolha2;
    int total1, total2;

    printf("===== SUPER TRUNFO =====\n\n");
    printf("Escolha o desafio:\n");
    printf("1 - Comparar um atributo (if e if-else)\n");
    printf("2 - Comparacao com menus e decisao aninhada\n");
    printf("3 - Comparacao de dois atributos com operador ternario\n");
    printf("Opcao: ");
    scanf("%d", &modo);

    printf("\nCarta 1:");
    exibirCarta(carta1);
    printf("\nCarta 2:");
    exibirCarta(carta2);

    printf("\nAtributos disponiveis:\n");
    printf("1 - Forca\n");
    printf("2 - Velocidade\n");
    printf("3 - Inteligencia\n");

    if (modo == 1) {
        printf("\nEscolha o atributo para comparar: ");
        scanf("%d", &escolha1);

        int valor1 = getAtributo(carta1, escolha1);
        int valor2 = getAtributo(carta2, escolha1);

        if (valor1 > valor2)
            printf("\n%s venceu!\n", carta1.nome);
        else if (valor2 > valor1)
            printf("\n%s venceu!\n", carta2.nome);
        else
            printf("\nEmpate!\n");
    }
    else if (modo == 2) {
        printf("\nEscolha o atributo para comparar (1, 2 ou 3): ");
        scanf("%d", &escolha1);

        if (escolha1 == 1) {
            if (carta1.forca > carta2.forca)
                printf("\n%s venceu na forca!\n", carta1.nome);
            else if (carta2.forca > carta1.forca)
                printf("\n%s venceu na forca!\n", carta2.nome);
            else
                printf("\nEmpate na forca!\n");
        }
        else if (escolha1 == 2) {
            if (carta1.velocidade > carta2.velocidade)
                printf("\n%s venceu na velocidade!\n", carta1.nome);
            else if (carta2.velocidade > carta1.velocidade)
                printf("\n%s venceu na velocidade!\n", carta2.nome);
            else
                printf("\nEmpate na velocidade!\n");
        }
        else if (escolha1 == 3) {
            if (carta1.inteligencia > carta2.inteligencia)
                printf("\n%s venceu na inteligencia!\n", carta1.nome);
            else if (carta2.inteligencia > carta1.inteligencia)
                printf("\n%s venceu na inteligencia!\n", carta2.nome);
            else
                printf("\nEmpate na inteligencia!\n");
        }
        else {
            printf("\nOpcao invalida!\n");
        }
    }
    else if (modo == 3) {
        printf("\nEscolha o primeiro atributo: ");
        scanf("%d", &escolha1);
        printf("Escolha o segundo atributo: ");
        scanf("%d", &escolha2);

        total1 = getAtributo(carta1, escolha1) + getAtributo(carta1, escolha2);
        total2 = getAtributo(carta2, escolha1) + getAtributo(carta2, escolha2);

        printf("\nTotal de %s: %d\n", carta1.nome, total1);
        printf("Total de %s: %d\n", carta2.nome, total2);

        (total1 > total2) ? printf("\n%s venceu!\n", carta1.nome) :
        (total2 > total1) ? printf("\n%s venceu!\n", carta2.nome) :
                            printf("\nEmpate!\n");
    }
    else {
        printf("\nOpcao invalida!\n");
    }

    printf("\n===== Fim do Jogo =====\n");
    return 0;
}

