# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "utio.h"
# include "atualizar.h"
# include "estrutura.h"
#include "funcoes.h"

void modulo_atualizar (void){
    char op;
    do{
        op=menu_atualizar();
        switch (op)
        {case '1':
            atualizar_medico();
            break;
        case '2':
            atualizar_paciente();
            break;
        case '3':
            atualizar_agenda();
            break;
        case '0':
            system("cls || clear");
            printf("Voltando ao menu principal...\n");
            delay(1);
            system("cls || clear");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (op != '0');


    
}

char menu_atualizar(void) {
    char op;
    system("color 09");
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                    TELA DE ATUALIZACAO                  @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@           1 -> ATUALIZAR MEDICO                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           2 -> ATUALIZAR PACIENTE                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@           3 -> ATUALIZAR AGENDA                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           0 -> VOLTAR                                   @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();
    return op;  
}

void atualizar_medico (void) {
    att_campo();
}




void atualizar_paciente (void){
    char op;
    do{
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@            ATUALIZAR CAMPO PACIENTE                     @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@           1 -> NOME                                     @@\n");
        printf("@@                                                         @@\n");
        printf("@@           2 -> TELEFONE                                 @@\n");
        printf("@@                                                         @@\n");
        printf("@@           3 -> EMAIL                                    @@\n");
        printf("@@                                                         @@\n");
        printf("@@           4 -> DATA DE NASCIMENTO                       @@\n");
        printf("@@                                                         @@\n");
        printf("@@           5 -> SEXO                                     @@\n");
        printf("@@                                                         @@\n");
        printf("@@           6 -> TUDO                                     @@\n");
        printf("@@                                                         @@\n");
        printf("@@           0 -> VOLTAR                                   @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("Digite a opcao desejada: ");
        scanf("%c", &op);
        getchar(); // Limpa o buffer do teclado
        switch (op) {
            case '1':
                att_nome_paciente();
                break;
            case '2':
                att_contato_paciente();
                break;
            case '3':
                att_email_paciente();
                break;
            case '4':
                att_data_nascimento_paciente();
                break;
            case '5':
                att_sexo_paciente();
                break;
            case '6':
                att_tudo_paciente();
                break;
            case '0':
                return;
            default:
                printf("Opcao invalida\n");
                delay(1);
                printf("Digite a opcao desejada: ");
                scanf("%c", &op);
                break;
        }

    }while (op != '0');
}
void att_nome_paciente (void) {
    Paciente paciente;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_paciente;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do paciente: ");
    fgets(CPF, 15, stdin);

    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
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

    printf("Digite o novo nome do paciente: ");
    fgets(paciente.nome, sizeof(paciente.nome), stdin);
    tam = strlen(paciente.nome);
    if (paciente.nome[tam - 1] == '\n') {
        paciente.nome[tam - 1] = '\0'; // Remove o '\n' do final da string
    }

    fseek(arq_paciente, -sizeof(Paciente), SEEK_CUR); // Volta para a posicao correta
    fwrite(&paciente, sizeof(Paciente), 1, arq_paciente);

    fclose(arq_paciente);

    printf("Nome atualizado com sucesso!\n");
    delay(2);
}

void att_contato_paciente (void) {
    Paciente paciente;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_paciente;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do paciente: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
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

    printf("Digite o novo contato do paciente: ");
    fgets(paciente.contato, sizeof(paciente.contato), stdin);
    tam = strlen(paciente.contato);
    if (paciente.contato[tam - 1] == '\n') {
        paciente.contato[tam - 1] = '\0'; // Remove o '\n' do final da string
    }

    fseek(arq_paciente, -sizeof(Paciente), SEEK_CUR); // Volta para a posicao correta
    fwrite(&paciente, sizeof(Paciente), 1, arq_paciente);

    fclose(arq_paciente);

    printf("Contato atualizado com sucesso!\n");
    delay(2);
}

void att_email_paciente (void) {
    Paciente paciente;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_paciente;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do paciente: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
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

    printf("Digite o novo email do paciente: ");
    fgets(paciente.email, sizeof(paciente.email), stdin);
    tam = strlen(paciente.email);
    if (paciente.email[tam - 1] == '\n') {
        paciente.email[tam - 1] = '\0'; // Remove o '\n' do final da string
    }

    fseek(arq_paciente, -sizeof(Paciente), SEEK_CUR); // Volta para a posicao correta
    fwrite(&paciente, sizeof(Paciente), 1, arq_paciente);

    fclose(arq_paciente);

    printf("Email atualizado com sucesso!\n");
    delay(2);
}

void att_data_nascimento_paciente (void) {
    Paciente paciente;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_paciente;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do paciente: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
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

    printf("Digite a nova data de nascimento do paciente (DD/MM/AAAA): ");
    ler_data(paciente.data_nascimento); // Chama a funcao para ler a data

    fseek(arq_paciente, -sizeof(Paciente), SEEK_CUR); // Volta para a posicao correta
    fwrite(&paciente, sizeof(Paciente), 1, arq_paciente);

    fclose(arq_paciente);

    printf("Data de nascimento atualizada com sucesso!\n");
    delay(2);
}

void att_sexo_paciente (void) {
    Paciente paciente;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_paciente;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do paciente: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
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

    printf("Digite o novo sexo do paciente: ");
    fgets(paciente.sexo, sizeof(paciente.sexo), stdin);
    tam = strlen(paciente.sexo);
    if (paciente.sexo[tam - 1] == '\n') {
        paciente.sexo[tam - 1] = '\0'; // Remove o '\n' do final da string
    }

    fseek(arq_paciente, -sizeof(Paciente), SEEK_CUR); // Volta para a posicao correta
    fwrite(&paciente, sizeof(Paciente), 1, arq_paciente);

    fclose(arq_paciente);

    printf("Sexo atualizado com sucesso!\n");
    delay(2);
}

void att_tudo_paciente (void) {
    Paciente paciente;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_paciente;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do paciente: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
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
    printf("Digite o novo nome do paciente: ");
    fgets(paciente.nome, sizeof(paciente.nome), stdin);
    tam = strlen(paciente.nome);
    if (paciente.nome[tam - 1] == '\n') {
        paciente.nome[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    printf("Digite o novo contato do paciente: ");
    fgets(paciente.contato, sizeof(paciente.contato), stdin);
    tam = strlen(paciente.contato);
    if (paciente.contato[tam - 1] == '\n') {
        paciente.contato[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    printf("Digite o novo email do paciente: ");
    fgets(paciente.email, sizeof(paciente.email), stdin);
    tam = strlen(paciente.email);
    if (paciente.email[tam - 1] == '\n') {
        paciente.email[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    printf("Digite a nova data de nascimento do paciente (DD/MM/AAAA): ");
    ler_data(paciente.data_nascimento); // Chama a funcao para ler a data

    printf("Digite o novo sexo do paciente: ");
    fgets(paciente.sexo, sizeof(paciente.sexo), stdin);
    tam = strlen(paciente.sexo);
    if (paciente.sexo[tam - 1] == '\n') {
        paciente.sexo[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    fseek(arq_paciente, -sizeof(Paciente), SEEK_CUR); // Volta para a posicao correta
    fwrite(&paciente, sizeof(Paciente), 1, arq_paciente);
    fclose(arq_paciente);
    printf("Todos os campos do paciente foram atualizados com sucesso!\n");
    delay(2);   
}

void atualizar_agenda (void) {
    char op;
    do{
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@            ATUALIZAR CAMPOS AGENDA                      @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@           1 -> ATUALIZAR DATA                           @@\n");
        printf("@@                                                         @@\n");
        printf("@@           2 -> ATUALIZAR HORARIO                        @@\n");
        printf("@@                                                         @@\n");
        printf("@@           3 -> ATUALIZAR MEDICO                         @@\n");
        printf("@@                                                         @@\n");
        printf("@@           4 -> ATUALIZAR PACIENTE                       @@\n");
        printf("@@                                                         @@\n");
        printf("@@           0 -> VOLTAR                                   @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("Digite a opcao desejada: ");
        scanf("%c", &op);
        getchar(); // Limpa o buffer do teclado
        switch (op) {
            case '1':
                att_data_agenda();
                break;
            case '2':
                att_horario();
                break;
            case '3':
                att_medico_agenda();
                break;
            case '4':
                att_paciente_agenda();
                break;
            case '0':
                return;
            default:
                printf("Opcao invalida\n");
                delay(1);
                break;
        }
    } while (op != '0');

}

void att_data_agenda (void) {
    Consulta consulta;
    char id[11] = "";
    int tam, achou;
    FILE *arq_agenda;
    system ("color 09");
    system("cls || clear");
    printf("Digite o ID da consulta: ");
    fgets(id, 11, stdin);
    tam = strlen(id);
    if (id[tam - 1] == '\n') {
        id[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    arq_agenda = fopen("consultas.dat", "rb+");
    if (arq_agenda == NULL) {
        printf("Erro ao abrir o arquivo de agenda.\n");
        delay(2);
        return;
    }
    achou = 0;
    while (fread(&consulta, sizeof(Consulta), 1, arq_agenda) && !achou) {
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
    printf("Digite a nova data da consulta (DD/MM/AAAA): ");
    ler_data(consulta.data); // Chama a funcao para ler a data
    fseek(arq_agenda, -sizeof(Consulta), SEEK_CUR); // Volta para a posicao correta
    fwrite(&consulta, sizeof(Consulta), 1, arq_agenda);
    fclose(arq_agenda);
    printf("Data da consulta atualizada com sucesso!\n");
    delay(2);
}
void att_horario (void) {
    Consulta consulta;
    char id[11] = "";
    int tam, achou;
    FILE *arq_agenda;
    system ("color 09");
    system("cls || clear");
    printf("Digite o ID da consulta: ");
    fgets(id, 11, stdin);
    tam = strlen(id);
    if (id[tam - 1] == '\n') {
        id[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    arq_agenda = fopen("consultas.dat", "rb+");
    if (arq_agenda == NULL) {
        printf("Erro ao abrir o arquivo de agenda.\n");
        delay(2);
        return;
    }
    achou = 0;
    while (fread(&consulta, sizeof(Consulta), 1, arq_agenda) && !achou) {
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
    printf("Digite o novo horario da consulta (HH:MM): ");
    fgets(consulta.hora, sizeof(consulta.hora), stdin);
    tam = strlen(consulta.hora);
    if (consulta.hora[tam - 1] == '\n') {
        consulta.hora[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    fseek(arq_agenda, -sizeof(Consulta), SEEK_CUR); // Volta para a posicao correta
    fwrite(&consulta, sizeof(Consulta), 1, arq_agenda);
    fclose(arq_agenda);
    printf("Horario da consulta atualizado com sucesso!\n");
    delay(2);
}

void att_medico_agenda (void) {
    Consulta consulta;
    char id[11] = "";
    int tam, achou;
    FILE *arq_agenda;
    system ("color 09");
    system("cls || clear");
    printf("Digite o ID da consulta: ");
    fgets(id, 11, stdin);
    tam = strlen(id);
    if (id[tam - 1] == '\n') {
        id[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    arq_agenda = fopen("consultas.dat", "rb+");
    if (arq_agenda == NULL) {
        printf("Erro ao abrir o arquivo de agenda.\n");
        delay(2);
        return;
    }
    achou = 0;
    while (fread(&consulta, sizeof(Consulta), 1, arq_agenda) && !achou) {
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
    printf("Digite o novo CPF do medico: ");
    fgets(consulta.CPF_m, sizeof(consulta.CPF_m), stdin);
    tam = strlen(consulta.CPF_m);
    if (consulta.CPF_m[tam - 1] == '\n') {
        consulta.CPF_m[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    fseek(arq_agenda, -sizeof(Consulta), SEEK_CUR); // Volta para a posicao correta
    fwrite(&consulta, sizeof(Consulta), 1, arq_agenda);
    fclose(arq_agenda);
    printf("CPF do medico atualizado com sucesso!\n");
    delay(2);
}

void att_paciente_agenda (void) {
    Consulta consulta;
    char id[11] = "";
    int tam, achou;
    FILE *arq_agenda;
    system ("color 09");
    system("cls || clear");
    printf("Digite o ID da consulta: ");
    fgets(id, 11, stdin);
    tam = strlen(id);
    if (id[tam - 1] == '\n') {
        id[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    arq_agenda = fopen("consultas.dat", "rb+");
    if (arq_agenda == NULL) {
        printf("Erro ao abrir o arquivo de agenda.\n");
        delay(2);
        return;
    }
    achou = 0;
    while (fread(&consulta, sizeof(Consulta), 1, arq_agenda) && !achou) {
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
    printf("Digite o novo CPF do paciente: ");
    fgets(consulta.CPF_p, sizeof(consulta.CPF_p), stdin);
    tam = strlen(consulta.CPF_p);
    if (consulta.CPF_p[tam - 1] == '\n') {
        consulta.CPF_p[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    fseek(arq_agenda, -sizeof(Consulta), SEEK_CUR); // Volta para a posicao correta
    fwrite(&consulta, sizeof(Consulta), 1, arq_agenda);
    fclose(arq_agenda);
    printf("CPF do paciente atualizado com sucesso!\n");
    delay(2);
}