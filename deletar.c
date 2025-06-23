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

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                    DELETAR MEDICO                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("                                                         \n");
    printf("           NOME:%s\n",medico.nome);
    printf("                                                        \n");
    printf("           CPF: ");
    print_CPF(medico.CPF);
    printf("                                                       \n");
    printf("           CONTATO:%s \n",medico.contato);  
    printf("                                                        \n");
    printf("           ESPECIALIZACAO:%s\n",medico.especialidade);
    printf("                                                        \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    getchar();

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
    char nome[50] = "";
    char CPF[15] = "";
    char idade[3] = "";
    char sexo[10] = "";
    system("color 0c");
    system("cls || clear");
    printf("Digite o CPF do paciente que deseja deletar: ");
    fgets(CPF, 15, stdin);
    getchar();

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                    DELETAR PACIENTE                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("           NOME:%s    \n",nome);
    printf("                                                         \n");
    printf("           IDADE:%s   \n",idade);
    printf("                                                         \n");
    printf("           CPF:%s    \n",CPF);
    printf("                                                         \n");
    printf("           SEXO:%s    \n",sexo);
    printf("                                                         \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();

}

void deletar_consulta (void){
    char id[11] = "";
    char data[11] = "";
    char paciente[50] = "";
    char CPF[15] = "";
    char idade[3] = "";
    char sexo[10] = "";
    char contato[15] = "";
    char medico[50] = "";
    char especializacao[20] = "";
    system("color 0c");
    system("cls || clear");
    printf("Qual o CPF do paciente que deseja cancelar a Consulta? ");
    fgets(CPF, 15, stdin);
    getchar();

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                   CANCELAR CONSULTA                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("   ID:%s \n",id);
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
