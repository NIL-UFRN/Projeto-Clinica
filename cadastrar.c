# include <stdio.h>
# include <stdlib.h> 
# include "cadastrar.h"
# include "utio.h" //biblioteca para funcoes

void modulo_cadastro (void) {
    char op;
    do{
        op = menu_cadastro();
        switch (op)
        {
        case '1':
            cadastrar_medico();
            break;
        case '2':
            cadastrar_paciente();
            break;
        case '3':
            agendar_consulta();
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
char menu_cadastro (void) { 
    char op;   
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                    TELA DE CADASTRO                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@           1 -> CADASTRAR MEDICO                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           2 -> CADASTRAR PACIENTE                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@           3 -> AGENDAR CONSULTA                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           0 -> VOLTAR                                   @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    scanf("%c", &op);
    printf("Escolha a opcao desejada: ");
    getchar();
    return op;
} 

void cadastrar_medico (void) {
    char nome[50], CPF[15], especializacao[20];
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  CADASTRAR MEDICO                       @@\n");
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
    printf("Digite o nome do medico: ");
    fgets(nome, 50, stdin);
    printf("Digite o CPF do medico: ");
    fgets(CPF, 15, stdin);
    printf("Digite a especializacao do medico: ");
    fgets(especializacao, 20, stdin);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  CADASTRAR MEDICO                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("           NOME:%s\n",nome);
    printf("                                                        \n");
    printf("           CPF:%s\n",CPF);
    printf("                                                        \n");
    printf("           ESPECIALIZACAO:%s\n",especializacao);
    printf("                                                        \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");

    getchar();
}

void cadastrar_paciente (void) {
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  CADASTRAR PACIENTE                     @@\n");
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

void agendar_consulta (void) {
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  AGENDAR CONSULTA                       @@\n");
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
