#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include <string.h>
#include "estrutura.h"
#include "funcoes.h"
#include "utio.h"


void exibir_medico (Medico medico){

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                     FICHA  MEDICO                       @@\n");
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
}

void exibir_paciente (Paciente paciente){

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                     FICHA PACIENTE                      @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("           NOME:%s\n",paciente.nome);
    printf("                                                        \n");
    printf("           IDADE:%s\n",paciente.data_nascimento);
    printf("                                                        \n");
    printf("           CPF: ");
    print_CPF(paciente.CPF);
    printf("                                                        \n");
    printf("           CONTATO:%s\n",paciente.contato);
    printf("                                                        \n");
    printf("           EMAIL:%s\n",paciente.email);
    printf("                                                        \n");
    printf("           SEXO:%s\n",paciente.sexo);
    printf("                                                        \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void exibir_consulta (Consulta consulta){

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                     FICHA CONSULTA                      @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                                                         \n");
    printf("           ID:%s\n",consulta.id);
    printf("           DATA:%s      HORA:%s\n",consulta.data, consulta.hora);
    printf("           PACIENTE:   \n");
    printf("           CPF:%s  IDADE:   \n",consulta.CPF_p);
    printf("           SEXO:      TELEFONE:    \n");
    printf("           EMAIL: \n");
    printf("           MEDICO: %s\n", consulta.CPF_m);
    printf("                                                        \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void grava_medico(Medico medico) {
    FILE *arq_medico;
    arq_medico = fopen("medicos.dat", "ab");
    if (arq_medico == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fwrite(&medico, sizeof(Medico), 1, arq_medico);
    fclose(arq_medico);
}

void grava_paciente(Paciente paciente) {
    FILE *arq_paciente;
    arq_paciente = fopen("pacientes.dat", "ab");
    if (arq_paciente == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fwrite(&paciente, sizeof(Paciente), 1, arq_paciente);
    fclose(arq_paciente);
}

void grava_consulta(Consulta consulta) {
    FILE *arq_consulta;
    arq_consulta = fopen("consultas.dat", "ab");
    if (arq_consulta == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fwrite(&consulta, sizeof(Consulta), 1, arq_consulta);
    fclose(arq_consulta);
}

void att_campo (void){
    char op;
    do{
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@            ATUALIZAR CAMPO MEDICO                       @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("@@                                                         @@\n");
        printf("@@           1 -> NOME                                     @@\n");
        printf("@@                                                         @@\n");
        printf("@@           2 -> CONTATO                                  @@\n");
        printf("@@                                                         @@\n");
        printf("@@           3 -> ESPECIALIZACAO                           @@\n");
        printf("@@                                                         @@\n");
        printf("@@           4 -> TUDO                                     @@\n");
        printf("@@                                                         @@\n");
        printf("@@           0 -> VOLTAR                                   @@\n");
        printf("@@                                                         @@\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("Digite a opcao desejada: ");
        scanf("%c", &op);
        getchar(); // Limpa o buffer do teclado
        fflush(stdin); // Limpa o buffer de entrada
        
    
        switch (op) {
        case '1':
            att_nome();
            break;
        case '2':
            att_contato();
            break;
        case '3':
            att_especializacao();
            break;
        case '4':
            att_tudo();
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

    } while (op != '0');
}


void att_nome (void) {
    Medico medico;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_medico;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do medico: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
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

    printf("Digite o novo nome do medico: ");
    fgets(medico.nome, sizeof(medico.nome), stdin);
    tam = strlen(medico.nome);
    if (medico.nome[tam - 1] == '\n') {
        medico.nome[tam - 1] = '\0'; // Remove o '\n' do final da string
    }

    fseek(arq_medico, -sizeof(Medico), SEEK_CUR); // Volta para a posicao correta
    fwrite(&medico, sizeof(Medico), 1, arq_medico);
    
    fclose(arq_medico);
    
    printf("Nome atualizado com sucesso!\n");
    delay(2);
}

void att_contato (void) {
    Medico medico;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_medico;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do medico: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    getchar();
    
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

    printf("Digite o novo contato do medico: ");
    fgets(medico.contato, sizeof(medico.contato), stdin);
    tam = strlen(medico.contato);
    if (medico.contato[tam - 1] == '\n') {
        medico.contato[tam - 1] = '\0'; // Remove o '\n' do final da string
    }

    fseek(arq_medico, -sizeof(Medico), SEEK_CUR); // Volta para a posicao correta
    fwrite(&medico, sizeof(Medico), 1, arq_medico);
    
    fclose(arq_medico);
    
    printf("Contato atualizado com sucesso!\n");
    delay(1);
}

void att_especializacao (void) {
    Medico medico;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_medico;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do medico: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    getchar();
    
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

    printf("Digite a nova especializacao do medico: ");
    fgets(medico.especialidade, sizeof(medico.especialidade), stdin);
    tam = strlen(medico.especialidade);
    if (medico.especialidade[tam - 1] == '\n') {
        medico.especialidade[tam - 1] = '\0'; // Remove o '\n' do final da string
    }

    fseek(arq_medico, -sizeof(Medico), SEEK_CUR); // Volta para a posicao correta
    fwrite(&medico, sizeof(Medico), 1, arq_medico);
    
    fclose(arq_medico);
    
    printf("Especializacao atualizada com sucesso!\n");
    delay(1);
}

void att_tudo (void) {
    Medico medico;
    char CPF[15] = "";
    int tam, achou;
    FILE *arq_medico;

    system ("color 09");
    system("cls || clear");
    printf("Digite o CPF do medico: ");
    fgets(CPF, 15, stdin);
    tam = strlen(CPF);
    if (CPF[tam - 1] == '\n') {
        CPF[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    getchar();
    
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

    printf("Digite o novo nome do medico: ");
    fgets(medico.nome, sizeof(medico.nome), stdin);
    tam = strlen(medico.nome);
    if (medico.nome[tam - 1] == '\n') {
        medico.nome[tam - 1] = '\0'; // Remove o '\n' do final da string
    }

    printf("Digite o novo contato do medico: ");
    fgets(medico.contato, sizeof(medico.contato), stdin);
    tam = strlen(medico.contato);
    if (medico.contato[tam - 1] == '\n') {
        medico.contato[tam - 1] = '\0'; // Remove o '\n' do final da string
    }

    printf("Digite a nova especializacao do medico: ");
    fgets(medico.especialidade, sizeof(medico.especialidade), stdin);
    tam = strlen(medico.especialidade);
    if (medico.especialidade[tam - 1] == '\n') {
        medico.especialidade[tam - 1] = '\0'; // Remove o '\n' do final da string
    }
    fseek(arq_medico, -sizeof(Medico), SEEK_CUR); // Volta para a posicao correta
    fwrite(&medico, sizeof(Medico), 1, arq_medico);

    fclose(arq_medico);
    printf("Todos os campos atualizados com sucesso!\n");
    delay(1);
}
