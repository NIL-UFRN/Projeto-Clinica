#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include "cadastrar.h"

//prototipos das funcoes
char menu_prim (void);
void menu_atualizacao (void);
void menu_pesquisa (void);
void menu_deletar (void);
void informacoes (void);


int main (void) {
    char op ;
    op = menu_prim();
    switch (op)
    {
    case '1':
        modulo_cadastro();

        break;
    case '2':
        menu_atualizacao();
        break;
    
    case '3':
        menu_pesquisa();
        break;    

    case '4':
        menu_deletar();
        break;

    case '5':
        informacoes();
        break;

    case '0':
        system("cls || clear");
        printf("Saindo do programa...\n");
        break;

    default:
        printf("Opcao invalida\n");
        
        break;
    }
    
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
    printf("@@           5 -> INFORMACOES                              @@\n");
    printf("@@                                                         @@\n");
    printf("@@           0 -> SAIR                                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("escoha uma opcao: ");
    scanf("%c", &op);
    getchar();
    return op;
}
    

void menu_atualizacao (void) {
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
    printf("Precione a tecla ENTER para continuar...");
    getchar();    
}

void menu_pesquisa (void) {
    system("cls || clear");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@                    TELA DE PESQUISA                     @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@                                                         @@\n");
    printf("@@           1 -> PESQUISAR MEDICO                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           2 -> PESQUISAR PACIENTE                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@           3 -> PESQUISAR AGENDA                         @@\n");
    printf("@@                                                         @@\n");
    printf("@@           0 -> VOLTAR                                   @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();    

}

void menu_deletar (void) {
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
    printf("Precione a tecla ENTER para continuar...");
    getchar();  
    
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