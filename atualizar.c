# include <stdio.h>
# include <stdlib.h>
# include "utio.h"
# include "atualizar.h"


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
    system("color 0a");
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
    char nome[50] = "";
    char CPF[15] = "";
    char especializacao[20] = "";
    char contato[15] = "";
    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do medico: ");
    fgets(CPF, 15, stdin);
    getchar();

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  ATUALIZAR MEDICO                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("           NOME:%s\n",nome);
    printf("                                                        \n");
    printf("           CPF: ");
    print_CPF(CPF);
    printf("                                                       \n");
    printf("           CONTATO:%s\n",contato);  
    printf("                                                        \n");
    printf("           ESPECIALIZACAO:%s\n",especializacao);
    printf("                                                        \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();
}


void atualizar_paciente (void){
    char nome[50] = "";
    char CPF[15] = "";
    char sexo[10] = "";
    char idade[3] = "";
    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do paciente: ");
    fgets(CPF, 15, stdin);
    getchar();

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  ATUALIZAR PACIENTE                     @@\n");
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