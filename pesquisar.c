#include <stdio.h>
#include <stdlib.h>
#include "utio.h"
#include "pesquisar.h"
#include "estrutura.h"
#include "funcoes.h"
#include <string.h>

void modulo_pesquisar (void){
    char op;
    do{
        op=menu_pesquisar();
        switch (op)
        {case '1':
            pesquisar_medico();
            break;
        case '2':
            pesquisar_paciente();
            break;
        case '3':
            pesquisar_agenda();
            break;
        case '0':
            system("cls || clear");
            printf("Voltando ao menu principal...\n");
            delay(1);
            system("cls || clear");
            break;
        default:
            printf("Opcao invalida, digite uma opcao valida\n");
            delay(1);
            break;
        }
    } while (op != '0');
}

char menu_pesquisar (void) {
    char op;
    system ("color 0a");
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                    TELA DE PESQUISA                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@           1 -> PESQUISAR MEDICO                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           2 -> PESQUISAR PACIENTE                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@           3 -> PESQUISAR AGENDA                         @@\n");
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
void pesquisar_medico (void){
    Medico medico;
    char CPF[15] = "";
    int tam;
    FILE *arq_medico;
    int achou;
    system ("color 0e");
    system("cls || clear");
    printf("Digite o CPF do medico: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o caractere de nova linha
    }
    getchar();

    arq_medico = fopen("medicos.dat", "rb");
    if (arq_medico == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    achou = 0;
    while (fread(&medico, sizeof(Medico), 1, arq_medico)&&(!achou)) {
        printf("CPF: |%s|\n", medico.CPF);
        printf("CPF pesquisado: |%s|\n", CPF);
        if (strcmp(medico.CPF, CPF) == 0) {
            exibir_medico(medico);
            achou = 1;
        }
    
    }
    if (!achou) {
        printf("Medico nao encontrado.\n");
        delay(2);
    }
    fclose(arq_medico);
    getchar(); // Limpa o buffer do teclado
}

// void pesquisar_medico (void){
//     char nome[50] = "";
//     char CPF[15] = "";
//     char especializacao[20] = ""; 
//     char contato[15] = "";
    
//     system ("color 0e");
//     system("cls || clear");
//     printf("Digite o CPF do medico: ");
//     fgets(CPF, 15, stdin);
//     getchar();

//     printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//     printf("@@                                                         @@\n");
//     printf("@@                     FICHA  MEDICO                       @@\n");
//     printf("@@                                                         @@\n");
//     printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//     printf("                                                         \n");
//     printf("           NOME:%s\n",nome);
//     printf("                                                        \n");
//     printf("           CPF: ");
//     print_CPF(CPF);
//     printf("                                                       \n");
//     printf("           CONTATO:%s\n",contato);  
//     printf("                                                        \n");
//     printf("           ESPECIALIZACAO:%s\n",especializacao);
//     printf("                                                        \n");
//     printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//     printf("Precione a tecla ENTER para continuar...");
//     getchar();
// }

void pesquisar_paciente (void){
    Paciente paciente;
    char CPF[15] = "";
    int tam;
    FILE *arq_paciente;
    int achou;

    system ("color 0e");
    system("cls || clear");
    printf("Coloque o CPF do paciente: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o caractere de nova linha
    }
    getchar();

    arq_paciente = fopen("pacientes.dat", "rb");
    if (arq_paciente == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    achou = 0;
    while (fread(&paciente, sizeof(Paciente), 1, arq_paciente) && !achou) {
        if (strcmp(paciente.CPF, CPF) == 0) {
            exibir_paciente(paciente);
            achou = 1;
        }
    }
    if (!achou) {
        printf("Paciente nao encontrado.\n");
        delay(2);
    }
    fclose(arq_paciente);
}


void pesquisar_agenda (void){
    Consulta consulta;
    char data[11] = "";
    FILE *arq_agenda;
    system ("color 0e");
    system("cls || clear");

    printf("digite a data que deseja pesquisar: ");
    fgets(data, 11, stdin);
    getchar();

    arq_agenda = fopen("agenda.dat", "rb");
    if (arq_agenda == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    int achou = 0;
    while (fread(&consulta, sizeof(Consulta), 1, arq_agenda) && !achou) {
        if (strcmp(consulta.data, data) == 0) {
            exibir_consulta(consulta);
            achou = 1;
        }
    }
    if (!achou) {
        printf("Consulta nao encontrada.\n");
        delay(2);
    }
    fclose(arq_agenda);
}
