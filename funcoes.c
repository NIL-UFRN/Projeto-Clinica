#include <stdio.h>
#include <stdlib.h> //biblioteca para colorir o terminal
#include <string.h>
#include "utio.h"
#include "estrutura.h"

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
    printf("Precione a tecla ENTER para continuar...");
    getchar();
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
    printf("@@                     FICHA CONSULTA                       @@\n");
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

