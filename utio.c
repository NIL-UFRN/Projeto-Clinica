#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include <time.h> // biblioteca para manipular tempo

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