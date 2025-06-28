#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include <string.h>
#include "deletar.h"
#include "utio.h" //biblioteca para funcoes
#include "estrutura.h" //biblioteca para estruturas
#include "funcoes.h" //biblioteca para funcoes

void modulo_deletar (void){
    char op;
    do{
        op = menu_deletar();
        switch (op) {
            case '1':
                deletar_medico();
                break;

            case '2':
                deletar_paciente();
                break;

            case '3':
                deletar_consulta();
                break;

            case '0':
                printf("Voltando ao menu principal...\n");
                delay(1);
                system("cls || clear");
                break;

            default:
                printf("Opcao invalida, digite uma opcao valida\n");
                delay(1);
                break;
        }
    }
    while (op != '0');
}


char menu_deletar (void) {
    char op;
    system("color 0a");
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                    TELA DE EXCLUSAO                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@           1 -> DELETAR MEDICO                           @@\n");
    printf("@@                                                         @@\n");
    printf("@@           2 -> DELETAR PACIENTE                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           3 -> CANCELAR AGENDAMENTO                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@           0 -> VOLTAR                                   @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();  
    fflush(stdin);
    return op;
}

void deletar_medico (void){
    Medico medico;
    char CPF[15] = "";
    int tam,achou;
    FILE *arq_medico;

    system("color 0c");
    system("cls || clear");

    printf("Digite o CPF do medico que deseja deletar: ");
    fgets(CPF, 15, stdin);
    getchar();

    tam = strlen(CPF);

    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o caractere de nova linha
    }
    arq_medico = fopen("medicos.dat", "rb+");
    if (arq_medico == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    achou = 0;
    while (fread(&medico, sizeof(Medico), 1, arq_medico)) {
        if (strcmp(medico.CPF, CPF) == 0) {
            achou = 1;
            break; // Encontrou o medico, sai do loop
        }
    }
    if (!achou) {
        printf("Medico nao encontrado.\n");
        delay(2);
        fclose(arq_medico);
        return;
    }

    exibir_medico(medico); // Exibe os dados do médico para confirmação


    printf("Tem certeza que deseja deletar o medico? (S/N): ");
    char resp;
    scanf("%c", &resp);
    getchar();
    if (resp == 'S' || resp == 's') {
        medico.estatos = 0; // Define o status do médico como inativo
        fseek(arq_medico, -sizeof(Medico), SEEK_CUR); // Volta para a posicao correta
        fwrite(&medico, sizeof(Medico), 1, arq_medico);
        printf("Medico deletado com sucesso!\n");
        fclose(arq_medico);
        delay(1);
    } else {
        printf("Operacao cancelada.\n");
    }

}

void deletar_paciente (void){
    Paciente paciente;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_paciente;

    system("color 0c");
    system("cls || clear");
    printf("Digite o CPF do paciente que deseja deletar: ");
    fgets(CPF, 15, stdin);
    getchar();
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o caractere de nova linha
    }
    arq_paciente = fopen("pacientes.dat", "rb+");
    if (arq_paciente == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    achou = 0;
    while (fread(&paciente, sizeof(Paciente), 1, arq_paciente)) {
        if (strcmp(paciente.CPF, CPF) == 0) {
            achou = 1;
            break; // Encontrou o paciente, sai do loop
        }
    }
    if (!achou) {
        printf("Paciente nao encontrado.\n");
        delay(2);
        fclose(arq_paciente);
        return;
    }
    exibir_paciente(paciente);
    printf("Tem certeza que deseja deletar o paciente? (S/N): ");
    char resp;
    scanf("%c", &resp);
    getchar();
    if (resp == 'S' || resp == 's') {
        paciente.estatos = 0; // Define o status do paciente como inativo
        fseek(arq_paciente, -sizeof(Paciente), SEEK_CUR); // Volta para a posicao correta
        fwrite(&paciente, sizeof(Paciente), 1, arq_paciente);
        printf("Paciente deletado com sucesso!\n");
        fclose(arq_paciente);
        delay(1);
    } else {
        printf("Operacao cancelada.\n");
    }

}

void deletar_consulta (void){
    Consulta consulta;
    char id[11] = "";
    int tam, achou;

    system("color 0c");
    system("cls || clear");
    printf("Digite o ID da consulta que deseja deletar: ");
    fgets(id, 11, stdin);
    getchar();

    tam = strlen(id);
    if (id[tam - 1] == '\n') {
        id[tam - 1] = '\0'; // Remove o caractere de nova linha
    }
    FILE *arq_agenda = fopen("agenda.dat", "rb+");
    if (arq_agenda == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    achou = 0;
    while (fread(&consulta, sizeof(Consulta), 1, arq_agenda
)) {
        if (strcmp(consulta.id, id) == 0) {
            achou = 1;
            break; // Encontrou a consulta, sai do loop
        }
    }
    if (!achou) {
        printf("Consulta nao encontrada.\n");
        delay(2);
        fclose(arq_agenda);
        return;
    }
    exibir_consulta(consulta); // Exibe os dados da consulta para confirmação
    printf("Tem certeza que deseja deletar a consulta? (S/N): ");
    char resp;
    scanf("%c", &resp);
    getchar();
    if (resp == 'S' || resp == 's') {
        consulta.estatos = 0; // Define o status da consulta como inativa
        fseek(arq_agenda, -sizeof(Consulta), SEEK_CUR); // Volta para a posicao correta
        fwrite(&consulta, sizeof(Consulta), 1, arq_agenda);
        printf("Consulta deletada com sucesso!\n");
        fclose(arq_agenda);
        delay(1);
    } else {
        printf("Operacao cancelada.\n");
    }   




}
