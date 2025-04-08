#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include "deletar.h"
#include "utio.h" //biblioteca para funcoes

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

    system("color 0c");
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                    DELETAR MEDICO                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@           NOME:                                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           CPF:                                          @@\n");
    printf("@@                                                         @@\n");
    printf("@@           ESPECIALIZACAO:                               @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();
}

void deletar_paciente (void){

    system("color 0c");
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                    DELETAR PACIENTE                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@           NOME:                                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           IDADE:                                        @@\n");
    printf("@@                                                         @@\n");
    printf("@@           CPF:                                          @@\n");
    printf("@@                                                         @@\n");
    printf("@@           SEXO:                                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();

}

void deletar_consulta (void){

    system("color 0c");
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                   DELETAR CONSULTA                      @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@   DATA:                                                 @@\n");
    printf("@@   PACIENTE:                                             @@\n");
    printf("@@   CPF:                                IDADE:            @@\n");
    printf("@@   SEXO:                     CONTATO:                    @@\n");
    printf("@@                                                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@   MEDICO:                                               @@\n");
    printf("@@   ESPECIALIZACAO:                                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();

}
