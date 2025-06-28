#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include <string.h>
#include "utio.h" //biblioteca para funcoes
#include "estrutura.h" //biblioteca para estruturas
#include "relatorios.h"
#include "funcoes.h" //biblioteca para funcoes


void menu_relatorio(void) {
    char op;
    do{
        system("color 09");
        system("cls || clear");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@                    TELA DE RELATORIOS                   @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@           1 -> RELATORIO DE MEDICOS                     @@\n");
        printf("@@                                                         @@\n");
        printf("@@           0 -> VOLTAR                                   @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("Escolha a opcao desejada: ");
        scanf("%c", &op);
        getchar(); // Limpa o buffer do teclado
        fflush(stdin); // Limpa o buffer de entrada
    } while (op != '0' && op != '1');

    switch (op) {
        case '1':
            relatorio_medico();
            break;
        case '0':
            system("cls || clear");
            printf("Voltando ao menu principal...\n");
            delay(1);
            system("cls || clear");
            break;
        default:
            printf("Opcao invalida, digite uma opcao valida.\n");
            delay(1);
            break;
    }
}


void relatorio_medico(void) {
    Medico medico;
    FILE *arq_medico;

    system("color 09");
    system("cls || clear");
    arq_medico = fopen("medicos.dat", "rb");
    if (arq_medico == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    while (fread(&medico, sizeof(Medico), 1, arq_medico)) {
        if (medico.estatos == 1) { // Verifica se o medico esta ativo
            system("color 09");
            exibir_medico(medico);

        }
    }

    fclose(arq_medico);
    printf("Pressione ENTER para continuar...\n");
    getchar();
}

