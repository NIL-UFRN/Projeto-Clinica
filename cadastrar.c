# include <stdio.h>
# include <stdlib.h> 
# include <string.h> //biblioteca para funcoes de string
# include "cadastrar.h"
# include "utio.h" //biblioteca para funcoes
# include "estrutura.h"

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
    //char nome[50], CPF[15], especializacao[20], contato[15], 
    Medico medico;
    char resp, tam;
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
            printf("@@           CONTATO:                                      @@\n");
            printf("@@                                                         @@\n");
            printf("@@           ESPECIALIZACAO:                               @@\n");
            printf("@@                                                         @@\n");
            printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("Digite o nome do medico: ");
            ler_nome(medico.nome);
            tam = strlen(medico.nome);
            if (medico.nome[tam - 1] == '\n') {
                medico.nome[tam - 1] = '\0'; // Remove o caractere de nova linha
            }
            printf("Digite o CPF do medico: ");
            ler_CPF(medico.CPF); // Chama a função para ler o CPF
            getchar(); // Limpa o buffer do teclado
            printf("Digite o telefone do medico: ");
            fgets(medico.contato, 15, stdin);
            tam = strlen(medico.contato);
            if (medico.contato[tam - 1] == '\n') {
                medico.contato[tam - 1] = '\0'; // Remove o caractere de nova linha
            }
            printf("Digite a especializacao do medico: ");
            fgets(medico.especialidade, 20, stdin);

            getchar(); // Limpa o buffer do teclado

            printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("@@                                                         @@\n");
            printf("@@                  CADASTRAR MEDICO                       @@\n");
            printf("@@                                                         @@\n");
            printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("                                                         \n");
            printf("           NOME:%s\n",medico.nome);
            printf("                                                        \n");
            printf("           CPF: ");
            print_CPF(medico.CPF);
            printf("                                                       \n");
            printf("           CONTATO:%s\n",medico.contato);  
            printf("                                                        \n");
            printf("           ESPECIALIZACAO:%s\n",medico.especialidade);
            printf("                                                        \n");
            printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("Os dados estao corretos? (S/N): ");
            scanf("%c", &resp);
            getchar();
    }while (resp != 'S' && resp != 's'); // Verifica se o usuário digitou 'S' ou 's'

    grava_medico(medico); // Chama a função para gravar os dados do médico

    printf("Cadastro realizado com sucesso!\n");      
    delay(1);            
                    
 }   

void grava_medico(Medico medico) {
    FILE *arq_medico;
    arq_medico = fopen("medicos.txt", "wt");
    if (arq_medico == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fprintf(arq_medico, "%s;%s;%s;%s\n", medico.nome, medico.CPF, medico.contato, medico.especialidade);
    fclose(arq_medico);
}

void cadastrar_paciente (void) {
    system("cls || clear");
    //char nome[50], CPF[15], sexo[3], data_nascimento[12], contato[15], email[50], resp;
    Paciente paciente;
    char resp, tam;
    do{
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
        printf("@@           TELEFONE:                                     @@\n");
        printf("@@                                                         @@\n");
        printf("@@           EMAIL:                                        @@\n");
        printf("@@                                                         @@\n");
        printf("@@           SEXO:                                         @@\n");
        printf("@@                                                         @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("Digite o nome do paciente: ");
        ler_nome(paciente.nome);
        tam = strlen(paciente.nome);
        if (paciente.nome[tam - 1] == '\n') {
            paciente.nome[tam - 1] = '\0'; // Remove o caractere de nova linha
        }
        printf("Digite a data de nascimento: ");
        ler_data(paciente.data_nascimento); // Chama a funcao para ler a data
        printf("Digite o CPF do paciente: ");
        ler_CPF(paciente.CPF); // Chama a função para ler o CPF
        getchar(); // Limpa o buffer do teclado
        printf("Digite o sexo do paciente M ou F: ");
        fgets(paciente.sexo, 3, stdin);
        tam = strlen(paciente.sexo);
        if (paciente.sexo[tam - 1] == '\n') {
            paciente.sexo[tam - 1] = '\0'; // Remove o caractere de nova linha
        }
        printf("Digite o telefone do paciente: ");
        fgets(paciente.contato, 15, stdin);
        tam = strlen(paciente.contato);
        if (paciente.contato[tam - 1] == '\n') {
            paciente.contato[tam - 1] = '\0'; // Remove o caractere de nova linha
        }
        printf("Digite o email do paciente: ");
        fgets(paciente.email, 50, stdin); // Chama a função para ler o email
        tam = strlen(paciente.email);
        if (paciente.email[tam - 1] == '\n') {
            paciente.email[tam - 1] = '\0'; // Remove o caractere de nova linha
        }
        getchar(); // Limpa o buffer do teclado

        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@                  CADASTRAR PACIENTE                     @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("                                                         \n");
        printf("           NOME:%s\n",paciente.nome);
        printf("                                                        \n");
        printf("           IDADE:%s\n",paciente.data_nascimento);
        printf("                                                        \n");
        printf("           CPF:");
        print_CPF(paciente.CPF);
        printf("                                                        \n");
        printf("                                                        \n");
        printf("           CONTATO:%s\n",paciente.contato);
        printf("                                                        \n");
        printf("           EMAIL:%s\n",paciente.email);
        printf("                                                        \n");
        printf("           SEXO:%s\n",paciente.sexo);
        printf("                                                        \n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("Os dados estao corretos? (S/N): ");
        scanf("%c", &resp); 
        getchar();
    }while (resp != 'S' && resp != 's'); // Verifica se o usuário digitou 'S' ou 's'

    grava_paciente(paciente); // Chama a função para gravar os dados do paciente

    printf("Cadastro realizado com sucesso!\n");
    delay(1);    

}

void grava_paciente(Paciente paciente) {
    FILE *arq_paciente;
    arq_paciente = fopen("pacientes.txt", "wt");
    if (arq_paciente == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fprintf(arq_paciente, "%s;%s;%s;%s;%s;%s\n", paciente.nome, paciente.CPF, paciente.data_nascimento, paciente.sexo, paciente.contato, paciente.email);
    fclose(arq_paciente);
}

void agendar_consulta (void) {
    system("cls || clear");
    Consulta consulta;
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  AGENDAR CONSULTA                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@   DATA:             HORA:                               @@\n");
    printf("@@   PACIENTE:                                             @@\n");
    printf("@@   CPF:                                IDADE:            @@\n");
    printf("@@   SEXO:                     CONTATO:                    @@\n");
    printf("@@                                                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@   MEDICO:                                               @@\n");
    printf("@@   CPF:                                                  @@\n");
    printf("@@   ESPECIALIZACAO:                                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Digite a data da consulta: ");
    ler_data(consulta.data);
    printf("Digite a hora da consulta: ");
    fgets(consulta.hora, 6, stdin);
    printf("Digite o CPF do paciente: ");
    ler_CPF(consulta.CPF_p);
    printf("Digite o CPF do medico: ");
    ler_CPF(consulta.CPF_m);
    getchar(); // Limpa o buffer do teclado

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                  AGENDAR CONSULTA                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("   DATA:%s      HORA:%s \n",consulta.data,consulta.hora);
    printf("   PACIENTE:   \n");
    printf("   CPF:%s  IDADE:   \n",consulta.CPF_p);
    printf("   SEXO:      TELEFONE:    \n");
    printf("   EMAIL: \n");
    printf("                                                         \n");
    printf("                                                         \n");
    printf("  MEDICO:    \n");
    printf("  CPF:%s  \n",consulta.CPF_m);
    printf("  ESPECIALIZACAO:  \n");
    printf("                                                         \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

    printf("Precione a tecla ENTER para continuar...");
    getchar();

}
