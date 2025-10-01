#include <stdio.h>
#include <string.h>

int main() {
    /* --- Dados da Carta 1 --- */
    char estado1;
    char codigo1[4];
    char nome1[60];
    unsigned long populacao1;
    double area1, pib1;
    int pontos1;

    /* --- Dados da Carta 2 --- */
    char estado2;
    char codigo2[4];
    char nome2[60];
    unsigned long populacao2;
    double area2, pib2;
    int pontos2;

    /* --- Valores calculados --- */
    double dens1 = 0.0, dens2 = 0.0;

    /* -------- Cadastro Carta 1 -------- */
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%3s", codigo1);
    getchar(); // limpar '\n' do buffer

    printf("Nome da Cidade: ");
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = '\0'; // remove '\n'

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (em km2): ");
    scanf("%lf", &area1);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    /* -------- Cadastro Carta 2 -------- */
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: B01): ");
    scanf("%3s", codigo2);
    getchar();

    printf("Nome da Cidade: ");
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (em km2): ");
    scanf("%lf", &area2);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    /* -------- Cálculo das densidades -------- */
    if (area1 != 0.0) dens1 = (double)populacao1 / area1;
    else dens1 = 0.0;
    if (area2 != 0.0) dens2 = (double)populacao2 / area2;
    else dens2 = 0.0;

    /* -------- Menu: escolher 2 atributos diferentes -------- */
    int escolha1 = 0, escolha2 = 0;
    int valido = 0;

    printf("\nEscolha dois atributos numericos diferentes para comparar.\n");
    printf(" 1 - Populacao\n");
    printf(" 2 - Area\n");
    printf(" 3 - PIB\n");
    printf(" 4 - Numero de Pontos Turisticos\n");
    printf(" 5 - Densidade Populacional (menor eh melhor)\n");

    /* primeira escolha */
    do {
        printf("Escolha o primeiro atributo (1-5): ");
        scanf("%d", &escolha1);
        valido = (escolha1 >= 1 && escolha1 <= 5);
        if (!valido) printf("Opcao invalida. Tente novamente.\n");
    } while (!valido);

    /* segunda escolha (diferente da primeira) */
    do {
        printf("Escolha o segundo atributo (1-5, diferente do primeiro): ");
        scanf("%d", &escolha2);
        valido = (escolha2 >= 1 && escolha2 <= 5 && escolha2 != escolha1);
        if (!valido) printf("Opcao invalida ou igual a primeira. Tente novamente.\n");
    } while (!valido);

    /* -------- Obter os valores dos atributos escolhidos -------- */
    double val1_a = 0.0, val2_a = 0.0; /* atributo 1 -> carta1, carta2 */
    double val1_b = 0.0, val2_b = 0.0; /* atributo 2 -> carta1, carta2 */

    /* atributo 1 */
    switch (escolha1) {
        case 1: val1_a = (double)populacao1; val2_a = (double)populacao2; break;
        case 2: val1_a = area1; val2_a = area2; break;
        case 3: val1_a = pib1; val2_a = pib2; break;
        case 4: val1_a = (double)pontos1; val2_a = (double)pontos2; break;
        case 5: val1_a = dens1; val2_a = dens2; break;
    }
    /* atributo 2 */
    switch (escolha2) {
        case 1: val1_b = (double)populacao1; val2_b = (double)populacao2; break;
        case 2: val1_b = area1; val2_b = area2; break;
        case 3: val1_b = pib1; val2_b = pib2; break;
        case 4: val1_b = (double)pontos1; val2_b = (double)pontos2; break;
        case 5: val1_b = dens1; val2_b = dens2; break;
    }

    /* nomes dos atributos para exibir */
    char nomeAttr1[50], nomeAttr2[50];
    switch (escolha1) {
        case 1: strcpy(nomeAttr1, "Populacao"); break;
        case 2: strcpy(nomeAttr1, "Area"); break;
        case 3: strcpy(nomeAttr1, "PIB"); break;
        case 4: strcpy(nomeAttr1, "Pontos Turisticos"); break;
        case 5: strcpy(nomeAttr1, "Densidade Populacional"); break;
    }
    switch (escolha2) {
        case 1: strcpy(nomeAttr2, "Populacao"); break;
        case 2: strcpy(nomeAttr2, "Area"); break;
        case 3: strcpy(nomeAttr2, "PIB"); break;
        case 4: strcpy(nomeAttr2, "Pontos Turisticos"); break;
        case 5: strcpy(nomeAttr2, "Densidade Populacional"); break;
    }

    /* -------- Comparacoes individuais -------- */
    int resA = 0, resB = 0; /* 1 -> carta1 venceu, 2 -> carta2 venceu, 0 -> empate */

    /* atributo 1 */
    if (escolha1 == 5) { /* densidade: menor vence */
        if (val1_a < val2_a) resA = 1;
        else if (val2_a < val1_a) resA = 2;
        else resA = 0;
    } else { /* maior vence */
        if (val1_a > val2_a) resA = 1;
        else if (val2_a > val1_a) resA = 2;
        else resA = 0;
    }

    /* atributo 2 */
    if (escolha2 == 5) {
        if (val1_b < val2_b) resB = 1;
        else if (val2_b < val1_b) resB = 2;
        else resB = 0;
    } else {
        if (val1_b > val2_b) resB = 1;
        else if (val2_b > val1_b) resB = 2;
        else resB = 0;
    }

    /* -------- Soma dos atributos (normalizando densidade) -------- */
    /* Para que a soma tenha a mesma direção ("maior = melhor"), usamos 1/densidade quando o atributo é densidade.
       Protegemos divisão por zero verificando dens != 0. */
    double soma1 = 0.0, soma2 = 0.0;

    if (escolha1 == 5) {
        soma1 += (dens1 != 0.0) ? 1.0 / dens1 : 0.0;
        soma2 += (dens2 != 0.0) ? 1.0 / dens2 : 0.0;
    } else {
        soma1 += val1_a;
        soma2 += val2_a;
    }

    if (escolha2 == 5) {
        soma1 += (dens1 != 0.0) ? 1.0 / dens1 : 0.0;
        soma2 += (dens2 != 0.0) ? 1.0 / dens2 : 0.0;
    } else {
        soma1 += val1_b;
        soma2 += val2_b;
    }

    /* -------- Exibição dos resultados (claro e organizado) -------- */
    printf("\n=== Comparacao de Cartas ===\n");
    printf("Carta 1: %s (%s)\n", nome1, codigo1);
    printf("Carta 2: %s (%s)\n\n", nome2, codigo2);

    /* Atributo 1 */
    printf("Atributo 1: %s\n", nomeAttr1);
    if (escolha1 == 1) {
        printf("  Carta 1: Populacao = %lu\n", populacao1);
        printf("  Carta 2: Populacao = %lu\n", populacao2);
    } else if (escolha1 == 2) {
        printf("  Carta 1: Area = %.2f km2\n", area1);
        printf("  Carta 2: Area = %.2f km2\n", area2);
    } else if (escolha1 == 3) {
        printf("  Carta 1: PIB = %.2f bilhoes\n", pib1);
        printf("  Carta 2: PIB = %.2f bilhoes\n", pib2);
    } else if (escolha1 == 4) {
        printf("  Carta 1: Pontos Turisticos = %d\n", pontos1);
        printf("  Carta 2: Pontos Turisticos = %d\n", pontos2);
    } else {
        printf("  Carta 1: Densidade = %.2f hab/km2\n", dens1);
        printf("  Carta 2: Densidade = %.2f hab/km2\n", dens2);
    }

    if (resA == 1) printf("Resultado Atributo 1: Carta 1 venceu\n");
    else if (resA == 2) printf("Resultado Atributo 1: Carta 2 venceu\n");
    else printf("Resultado Atributo 1: Empate!\n");

    printf("\n");

    /* Atributo 2 */
    printf("Atributo 2: %s\n", nomeAttr2);
    if (escolha2 == 1) {
        printf("  Carta 1: Populacao = %lu\n", populacao1);
        printf("  Carta 2: Populacao = %lu\n", populacao2);
    } else if (escolha2 == 2) {
        printf("  Carta 1: Area = %.2f km2\n", area1);
        printf("  Carta 2: Area = %.2f km2\n", area2);
    } else if (escolha2 == 3) {
        printf("  Carta 1: PIB = %.2f bilhoes\n", pib1);
        printf("  Carta 2: PIB = %.2f bilhoes\n", pib2);
    } else if (escolha2 == 4) {
        printf("  Carta 1: Pontos Turisticos = %d\n", pontos1);
        printf("  Carta 2: Pontos Turisticos = %d\n", pontos2);
    } else {
        printf("  Carta 1: Densidade = %.2f hab/km2\n", dens1);
        printf("  Carta 2: Densidade = %.2f hab/km2\n", dens2);
    }

    if (resB == 1) printf("Resultado Atributo 2: Carta 1 venceu\n");
    else if (resB == 2) printf("Resultado Atributo 2: Carta 2 venceu\n");
    else printf("Resultado Atributo 2: Empate!\n");

    printf("\nSoma (normalizada) dos dois atributos escolhidos:\n");
    printf("  Carta 1: %.6f\n", soma1);
    printf("  Carta 2: %.6f\n", soma2);

    if (soma1 > soma2) printf("\nResultado Final: Carta 1 venceu a rodada!\n");
    else if (soma2 > soma1) printf("\nResultado Final: Carta 2 venceu a rodada!\n");
    else printf("\nResultado Final: Empate!\n");

    return 0;
}