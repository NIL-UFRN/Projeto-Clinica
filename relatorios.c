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

void relatorio_medico (void){
char op;
    do{

        system("color 09");
        system("cls || clear");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@                    RELATORIO DE MEDICOS                 @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@           1 -> TODOS OS MEDICOS                         @@\n");
        printf("@@                                                         @@\n");
        printf("@@           2 -> ORDEM ALFABETICA                         @@\n");
        printf("@@                                                         @@\n");
        printf("@@           3 -> POR ESPECIALIDADE                        @@\n");
        printf("@@                                                         @@\n");
        printf("@@           0 -> VOLTAR                                   @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("Digite a opcao desejada: ");
        scanf("%c", &op);
        getchar(); // Limpa o buffer do teclado
        fflush(stdin); // Limpa o buffer de entrada

        switch (op) {
            case '1':
                relatorio_todos_medico();
                break;
            case '2':
                relatorio_medico_ordem_alfabetica();
                break;
            case '3':
                relatorio_medico_especialidade();
                break;
            case '0':
                return;
            default:
                printf("Opcao invalida\n");
                delay(1);
                break;
        }

    } while (op != '0');
    system("cls || clear");
}

void relatorio_todos_medico(void) {
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

void relatorio_medico_ordem_alfabetica(void) {
    Medico medico;
    FILE *arq_medico;

    system("color 09");
    system("cls || clear");
    arq_medico = fopen("medicos.dat", "rb");
    if (arq_medico == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    // Cria um vetor para armazenar os médicos
    Medico medicos[100];
    int count = 0;
    // Lê os médicos do arquivo e armazena no vetor
    while (fread(&medico, sizeof(Medico), 1, arq_medico)) {
        if (medico.estatos == 1) { // Verifica se o medico esta ativo
            medicos[count++] = medico; // Armazena o médico no vetor
        }
    }

    // Ordena os médicos por nome
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(medicos[i].nome, medicos[j].nome) > 0) {
                Medico temp = medicos[i];
                medicos[i] = medicos[j];
                medicos[j] = temp;
            }
        }
    }

    // Exibe os médicos ordenados
    for (int i = 0; i < count; i++) {
        system("color 09");
        exibir_medico(medicos[i]);
    }

    fclose(arq_medico);
    printf("Pressione ENTER para continuar...\n");
    getchar();
}

void relatorio_medico_especialidade(void) {
    Medico medico;
    FILE *arq_medico;
    char especialidade[50];

    printf("Digite a especialidade desejada: ");
    fgets(especialidade, sizeof(especialidade), stdin);
    especialidade[strcspn(especialidade, "\n")] = 0; // Remove a nova linha

    system("color 09");
    system("cls || clear");
    arq_medico = fopen("medicos.dat", "rb");
    if (arq_medico == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    
    while (fread(&medico, sizeof(Medico), 1, arq_medico)) {
        if (medico.estatos == 1 && strcmp(medico.especialidade, especialidade) == 0) { // Verifica se o medico esta ativo e se a especialidade corresponde
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
        }
    }

    fclose(arq_consulta);
    printf("Pressione ENTER para continuar...\n");
    getchar();
}

