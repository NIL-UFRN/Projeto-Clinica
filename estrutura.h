typedef struct paciente Paciente;

struct paciente {
    char nome[50];
    char CPF[15];
    char email[50];
    char data_nascimento[12];
    char sexo;
    char contato[15];
};

typedef struct medico Medico;
struct medico {
    char nome[50];
    char CPF[15];
    char especialidade[50];
    char contato[15];
};

typedef struct consulta Consulta;
struct consulta {
    char data[10];
    char hora[6];
    char CPF_p[15];
    char CPF_m[15];
};