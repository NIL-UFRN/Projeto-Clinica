typedef struct paciente Paciente;

struct paciente {
    char nome[50];
    char CPF[15];
    char email[50];
    char data_nascimento[12];
    char sexo[3];
    char contato[15];
    int estatos;
};

typedef struct medico Medico;
struct medico {
    char nome[50];
    char CPF[15];
    char especialidade[50];
    char contato[15];
    int estatos;
};

typedef struct consulta Consulta;
struct consulta {
    char data[12];
    char hora[6];
    char id[11];
    char CPF_p[15];
    char CPF_m[15];
    int estatos;
};