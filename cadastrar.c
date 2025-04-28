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
            printf("Opcao invalida, digite uma opcao valida.\n");
            delay(1);
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
    printf("Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();
    fflush(stdin); // Limpa o buffer do teclado
    return op;
} 

void cadastrar_medico (void) {
    char nome[50], CPF[15], especializacao[20], resp;
    do{
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
            ler_CPF(CPF); // Chama a função para ler o CPF
            getchar(); // Limpa o buffer do teclado
            printf("Digite a especializacao do medico: ");
            fgets(especializacao, 20, stdin);

            getchar(); // Limpa o buffer do teclado

            printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("@@                                                         @@\n");
            printf("@@                  CADASTRAR MEDICO                       @@\n");
            printf("@@                                                         @@\n");
            printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("                                                         \n");
            printf("           NOME:%s\n",nome);
            printf("                                                        \n");
            printf("           CPF: ");
            print_CPF(CPF);
            printf("                                                        \n");
            printf("           ESPECIALIZACAO:%s\n",especializacao);
            printf("                                                        \n");
            printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("Os dados estao corretos? (S/N): ");
            scanf("%c", &resp);
            getchar();
    }while (resp != 'S' && resp != 's'); // Verifica se o usuário digitou 'S' ou 's'
    printf("Cadastro realizado com sucesso!\n");      
    delay(1);            
                    
 }   



void cadastrar_paciente (void) {
    system("cls || clear");
    char nome[50], CPF[15], sexo[3], data_nascimento[12], contato[15];
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
    printf("@@           CONTATO:                                      @@\n");
    printf("@@                                                         @@\n");
    printf("@@           SEXO:                                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Digite o nome do paciente: ");
    fgets(nome, 50, stdin);
    printf("Digite a data de nascimento: ");
    Ler_data(data_nascimento); // Chama a funcao para ler a data
    printf("Digite o CPF do paciente: ");
    ler_CPF(CPF); // Chama a função para ler o CPF
    getchar(); // Limpa o buffer do teclado
    printf("Digite o sexo do paciente M ou F: ");
    fgets(sexo, 3, stdin);
    printf("Digite o contato do paciente: ");
    fgets(contato, 15, stdin);
    getchar(); // Limpa o buffer do teclado

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  CADASTRAR PACIENTE                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("           NOME:%s\n",nome);
    printf("                                                        \n");
    printf("           IDADE:%s\n",data_nascimento);
    printf("                                                        \n");
    printf("           CPF:");
    print_CPF(CPF);
    printf("                                                        \n");
    printf("                                                        \n");
    printf("           CONTATO:%s\n",contato);
    printf("                                                        \n");
    printf("           SEXO:%s\n",sexo);
    printf("                                                        \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();

}

void agendar_consulta (void) {
    system("cls || clear");
    char data[10], paciente[50], CPF[15], sexo[3], contato[15], medico[50], especializacao[20];
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
    printf("Digite a data da consulta: ");
    scanf("%s", data);
    printf("Digite o nome do paciente: ");
    scanf("%s", paciente);
    printf("Digite o CPF do paciente: ");
    scanf("%s", CPF);
    printf("Digite o sexo do paciente M ou F: ");
    scanf("%s", sexo);
    printf("Digite o contato do paciente: ");
    scanf("%s", contato);
    printf("Digite o nome do medico: ");
    scanf("%s", medico);
    printf("Digite a especializacao do medico: ");
    scanf("%s", especializacao);
    getchar(); // Limpa o buffer do teclado

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  AGENDAR CONSULTA                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("   DATA:%s       \n",data);
    printf("   PACIENTE:%s    \n",paciente);
    printf("   CPF:%s  IDADE:%s     \n"CPF, data);
    printf("   SEXO:%s      CONTATO:%s     \n",sexo, contato);
    printf("                                                         \n");
    printf("                                                         \n");
    printf("   MEDICO:%s     \n",medico);
    printf("  ESPECIALIZACAO:%s  \n",especializacao);
    printf("                                                         \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    printf("Precione a tecla ENTER para continuar...");
    getchar();

}
