#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include <string.h>
#include "utio.h" //biblioteca para funcoes
#include "estrutura.h" //biblioteca para estruturas
#include "relatorios.h"
#include "funcoes.h" //biblioteca para funcoes

int modulo_relatorio(void) {
    char op;
    do{
        op = menu_relatorio ();
        switch (op) {
        
        case '1':
            relatorio_medico();
            break;
        case '2':
            relatorio_paciente();
            break;
        case '3':   
            relatorio_consulta();
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
    } while (op != '0');
return 0;
}


char menu_relatorio(void) {
    char op;
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
    printf("@@           2 -> RELATORIO DE PACIENTES                   @@\n");
    printf("@@                                                         @@\n");
    printf("@@           3 -> RELATORIO DE CONSULTAS                   @@\n");
    printf("@@                                                         @@\n");
    printf("@@           0 -> VOLTAR                                   @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar(); // Limpa o buffer do teclado
    fflush(stdin); // Limpa o buffer de entrada
    return op;
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

void relatorio_paciente(void) {
    Paciente paciente;
    FILE *arq_paciente;

    system("color 09");
    system("cls || clear");
    arq_paciente = fopen("pacientes.dat", "rb");
    if (arq_paciente == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    while (fread(&paciente, sizeof(Paciente), 1, arq_paciente)) {
        if (paciente.estatos == 1) { // Verifica se o paciente esta ativo
            system("color 09");
            exibir_paciente(paciente);
        }
    }

    fclose(arq_paciente);
    printf("Pressione ENTER para continuar...\n");
    getchar();
}

void relatorio_consulta(void) {
    Consulta consulta;
    FILE *arq_consulta;

    system("color 09");
    system("cls || clear");
    arq_consulta = fopen("consultas.dat", "rb");
    if (arq_consulta == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        delay(1);
        exit(1);
    }

    while (fread(&consulta, sizeof(Consulta), 1, arq_consulta)) {
        if (consulta.estatos == 1) { // Verifica se a consulta esta ativa
            system("color 09");
            exibir_consulta(consulta);
            getchar(); // Espera o usuario pressionar ENTER para continuar
        }
    }

    fclose(arq_consulta);
    printf("Pressione ENTER para continuar...\n");
    getchar();
}

