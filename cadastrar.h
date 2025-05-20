typedef struct medico Medico;
typedef struct paciente Paciente;
typedef struct consulta Consulta;

void modulo_cadastro (void);
char menu_cadastro (void);
void cadastrar_medico (void);
void cadastrar_paciente (void);
void agendar_consulta (void);
void delay (int);
void grava_medico(Medico);
void grava_paciente (Paciente);
void grava_consulta (Consulta);