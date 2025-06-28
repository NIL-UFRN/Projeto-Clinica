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
    char op
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
    getchar();

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
    getchar();

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

void atualizar_agenda (void) {
    char id[11] = "";
    char data[11] = "";
    char paciente[50] = "";
    char CPF[15] = "";
    char idade[3] = "";
    char sexo[10] = "";
    char contato[15] = "";
    char medico[50] = "";
    char especializacao[20] = "";
    system ("color 09"); 
    system("cls || clear");
    printf("digite o ID da consulta: ");
    fgets(id, 11, stdin);
    getchar();
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  ATUALIZAR AGENDA                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("   ID:%s \n,",id);
    printf("   DATA:%s \n",data);
    printf("   PACIENTE:%s \n",paciente);
    printf("   CPF:%s    IDADE:%s  \n",CPF,idade);
    printf("   SEXO:%s    CONTATO:%s \n",sexo,contato);
    printf("                                                         \n");
    printf("                                                        \n");
    printf("   MEDICO:%s \n",medico);
    printf("   ESPECIALIZACAO:%s \n",especializacao);
    printf("                                                         \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();
}