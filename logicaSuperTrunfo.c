#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[5];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void exibirCarta(Carta carta, int numero) {
    printf("Carta %d:\n", numero);
    printf("  Estado: %s\n", carta.estado);
    printf("  Código: %s\n", carta.codigo);
    printf("  Nome da Cidade: %s\n", carta.nomeCidade);
    printf("  População: %d\n", carta.populacao);
    printf("  Área: %.2f km²\n", carta.area);
    printf("  PIB: %.2f bilhões de reais\n", carta.pib);
    printf("  Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);

    float densidadePopulacional = carta.populacao / carta.area;
    float pibPerCapita = (carta.pib * 1e9) / carta.populacao;

    printf("  Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("  PIB per capita: %.2f reais\n\n", pibPerCapita);
}

int main() {
    Carta carta1 = {
        "SP", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50
    };

    Carta carta2 = {
        "RJ", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30
    };

    const int atributoComparar = 1;

    printf("=== Cartas cadastradas ===\n\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    float valor1, valor2;
    char nomeAtributo[30];

    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;

    float pibPerCapita1 = (carta1.pib * 1e9) / carta1.populacao;
    float pibPerCapita2 = (carta2.pib * 1e9) / carta2.populacao;

    switch (atributoComparar) {
        case 1:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            strcpy(nomeAtributo, "População");
            break;
        case 2:
            valor1 = carta1.area;
            valor2 = carta2.area;
            strcpy(nomeAtributo, "Área");
            break;
        case 3:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            strcpy(nomeAtributo, "PIB");
            break;
        case 4:
            valor1 = densidade1;
            valor2 = densidade2;
            strcpy(nomeAtributo, "Densidade Populacional");
            break;
        case 5:
            valor1 = pibPerCapita1;
            valor2 = pibPerCapita2;
            strcpy(nomeAtributo, "PIB per capita");
            break;
        default:
            printf("Atributo inválido para comparação.\n");
            return 1;
    }

    printf("Comparação de cartas (Atributo: %s):\n\n", nomeAtributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nomeCidade, carta2.estado, valor2);

    if (atributoComparar == 4) {
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor2 < valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor2 > valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}
