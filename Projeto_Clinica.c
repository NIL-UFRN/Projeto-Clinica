#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal

void menu_prim (void);
void menu_cadastro (void);
void cadastrar_medico (void);
void cadastrar_paciente (void);
void menu_atualizacao (void);
void menu_pesquisa (void);
void menu_deletar (void);
void informacoes (void);


int main (void){
    menu_prim();
    menu_cadastro();
    cadastrar_medico();
    cadastrar_paciente();
    menu_atualizacao ();
    menu_pesquisa();
    menu_deletar();
    informacoes();
    return 0;
}


void menu_prim (void) {    
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
    printf("Precione a tecla ENTER para continuar...");
    getchar();
}

void menu_cadastro (void) {    
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
    printf("@@           3 -> CADASTRAR CONSULTA                       @@\n");
    printf("@@                                                         @@\n");
    printf("@@           0 -> VOLTAR                                   @@\n");
    printf("@@                                                         @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("Precione a tecla ENTER para continuar...");
    getchar();
} 

void cadastrar_medico (void) {
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
    printf("@@           3 -> ATUALIZAR CONSULTA                       @@\n");
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
    printf("@@           3 -> PESQUISAR CONSULTA                       @@\n");
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
    printf("@@           3 -> DELETAR CONSULTA                         @@\n");
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