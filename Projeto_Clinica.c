#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include <string.h>
#include "cadastrar.h"
#include "atualizar.h"
#include "pesquisar.h"
#include "deletar.h"
#include "utio.h" //biblioteca para funcoes
#include "estrutura.h" //biblioteca para estruturas
#include "relatorios.h"


//prototipos das funcoes
char menu_prim (void);
void informacoes (void);


int main (void) {
    char op ;
    do{
   
        op = menu_prim();
        switch (op) {
    
        case '1':
           modulo_cadastro();
           break;
        case '2':
            modulo_atualizar();
            break;
        case '3':
            modulo_pesquisar();
            break;    
        case '4':
            modulo_deletar();
            break;
        case '5':
            modulo_relatorio();
            break;
        case '6':
            informacoes();
            break;

        case '0':
            system("cls || clear");
            printf("Saindo do programa...\n");
            delay(1);
            printf("Obrigado por usar o sistema de agendamento!\n");
            delay(1);
            system("cls || clear");

            break;
    
        default:
            printf("Opcao invalida, digite uma opcao valida.\n");
            delay(1);
            break;
        }
    } while (op != '0');
return 0;
}

char menu_prim (void) {
    char op;    
    system("color 0a");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                 SISTEMA DE AGENDAMENTO                  @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@           1 -> CADASTRAR                                @@\n");
    printf("@@                                                         @@\n");
    printf("@@           2 -> ATUALIZAR                                @@\n");
    printf("@@                                                         @@\n");
    printf("@@           3 -> PESQUISAR                                @@\n");
    printf("@@                                                         @@\n");
    printf("@@           4 -> DELETAR                                  @@\n");
    printf("@@                                                         @@\n");
    printf("@@           5 -> RELATORIOS                               @@\n");  
    printf("@@                                                         @@\n");
    printf("@@           6 -> INFORMACOES                              @@\n");
    printf("@@                                                         @@\n");
    printf("@@           0 -> SAIR                                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("escoha uma opcao: ");
    scanf("%c", &op);
    getchar();
    fflush(stdin);
    return op;
}
    

void informacoes (void) {
    system("cls || clear");
    printf("\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@             Universidade Federal do Rio Grande do Norte                 @@@\n");
    printf("@@@                 Centro de Ensino Superior do Serido                     @@@\n");
    printf("@@@               Departamento de Computacao e Tecnologia                   @@@\n");
    printf("@@@                  Disciplina DCT1106 -- Programacao                      @@@\n");
    printf("@@@                  Projeto Agendamento para clinica Medica                @@@\n");
    printf("@@@        Developed by https://github.com/NIL-UFRN -- since Mar, 2025      @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@              Sistema Agendamento para clinica Medica                    @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@  Programa sera utilizado na disciplina DCT1106 - Programacao, para      @@@\n");
    printf("@@@  fins de avaiacao, como modo do prefessor avaiar o desempenho ao longo  @@@\n");
    printf("@@@  da disciplina e colocar em pratita o assunto visto em aula.            @@@\n");
    printf("@@@                                                                         @@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();  

}