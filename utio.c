#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
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

void validar_email (char email[50]) {
    int i, arroba = 0, ponto = 0;
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            arroba = 1;
        } else if (email[i] == '.') {
            ponto = 1;
        }
    }
    if (arroba && ponto) {
        printf("Email valido!\n");
    } else {
        printf("Email invalido! Tente novamente.\n");
    }
}