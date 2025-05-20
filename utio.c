#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include <string.h>
#include <time.h> // biblioteca para manipular tempo
#include "utio.h"

void delay(int secondos) {
    // Converte segundos para milissegundos
    int tempo = secondos * 1000;
    // Aguarda o tempo especificado
   clock_t inicio = clock();
    while (clock() < inicio + tempo) {
        // Loop vazio para criar o atraso
    }
    // Limpa a tela após o atraso
    system("cls || clear");
}

void ler_CPF (char CPF[15]) {
    int cpf_valido = 0; // Variável para verificar se o CPF é válido
    do
    {   printf("Digite o CPF (apenas numeros): ");
        scanf("%s", CPF);
        // Verifica se o CPF é válido
        cpf_valido = validar_CPF(CPF);

        if (cpf_valido) {
            printf("CPF valido!\n");
            break; // Sai do loop se o CPF for válido
        } else {
            printf("CPF invalido! Tente novamente.\n");
        }

    } while (!cpf_valido); // Continua pedindo CPF até que seja válido
}


int validar_CPF (char CPF[15]) {
    int soma = 0, i, digito1, digito2;
    int cpf[11];
    for (i = 0; i < 11; i++) {
        cpf[i] = CPF[i] - '0'; // Converte o caractere para inteiro
    }
    for (i = 0; i < 9; i++) {
        soma += cpf[i] * (10 - i);
    }
    digito1 = (soma * 10) % 11;
    if (digito1 == 10) {
        digito1 = 0;
    }
    soma = 0;
    for (i = 0; i < 10; i++) {
        soma += cpf[i] * (11 - i);
    }
    digito2 = (soma * 10) % 11;
    if (digito2 == 10) {
        digito2 = 0;
    }
    return (digito1 == cpf[9] && digito2 == cpf[10]);
}

void print_CPF (char CPF[15]) {
    printf("%c%c%c.",CPF[0], CPF[1], CPF[2]);
    printf("%c%c%c.", CPF[3], CPF[4], CPF[5]);
    printf("%c%c%c-", CPF[6], CPF[7], CPF[8]);
    printf("%c%c\n", CPF[9], CPF[10]);
}

//char ler_email (char email) {
  //  printf("Digite o email: ");
    //scanf("%s", email);
    //validar_email(email); // Chama a função para ler email
//}

// VALIDADECAO EMAIL FEITO COM AJUDA DO CHATGPT
//void validar_email(char* email) {
  // int i = 0, arroba = -1, ponto2 = 0;
   //do {
     //  if email[i] == '@') {
         //  arroba = i;
       //} else if (email[i] == '.') {
           //ponto2 = i;
      // }
  // }while (email[i] != '\0' && i < 50); // Verifica se o email é válido
   //{
    //* code */
   //}
   
//}


void ler_data(char data[12]) {
    int dia, mes, ano;
    int dataValida;
     //printf("Programa Data de Nascimento\n\n");
    do {
        scanf("%d/%d/%d", &dia, &mes, &ano);
        getchar(); // Limpa o buffer do teclado
        //printf("Data digitada: %02d/%02d/%04d\n", dia, mes, ano);
        dataValida = testaData(dia, mes, ano);
        if (!dataValida) {
        printf("%02d/%02d/%d invalida\n",dia,mes,ano);
        printf("Tente novamente\n\n");
        }   
        else {
            printf("A data %02d/%02d/%d valida\n",dia,mes,ano);
        }
     } while (!dataValida);
    sprintf(data, "%02d/%02d/%04d", dia, mes, ano); // Formata a data como string
 
}

int bissexto(int aa) {
    if ((aa % 4 == 0) && (aa % 100 != 0)) {
     return 1;
     } else if (aa % 400 == 0) {
     return 1;
     } else {
     return 0;
     }
}

int testaData(int dd, int mm, int aa) {
    int maiorDia;
    if (aa < 0 || mm < 1 || mm > 12)
     return 0;
    if (mm == 2) {
     if (bissexto(aa))
     maiorDia = 29;
     else
     maiorDia = 28;
     } else if (mm == 4 || mm == 6 ||
     mm == 9 || mm == 11) {
     maiorDia = 30;
     } else
     maiorDia = 31;
    if (dd < 1 || dd > maiorDia)
     return 0;
    return 1;
}


void ler_nome (char nome[50]) {
    printf("Digite o nome: ");
    fgets(nome, 50, stdin);
    size_t len = strlen(nome);
    if (len > 0 && nome[len - 1] == '\n') {
        nome[len - 1] = '\0'; // Remove a nova linha
    }
}