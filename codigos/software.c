#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de constantes para os limites do sistema
#define MAX_PASSAGEIROS 100 // Máximo de passageiros permitidos
#define MAX_TRIPULANTES 50 // Máximo de tripulantes permitidos
#define MAX_VOOS 50        // Máximo de voos permitidos
#define MAX_ASSENTOS 200   // Máximo de assentos por voo
#define FIDELIDADE_PONTOS 10 // Pontos de fidelidade atribuídos por voo

// Estrutura para armazenar dados de passageiros
typedef struct {
int codigo;              // Código único do passageiro
char nome[50];           // Nome do passageiro
char endereco[100];      // Endereço do passageiro
char telefone[15];       // Telefone do passageiro
int fidelidade;          // Indicador de participação no programa de fidelidade (1: sim, 0: não)
int pontos;              // Pontos acumulados no programa de fidelidade
} Passageiro;

// Estrutura para armazenar dados de tripulantes
typedef struct {
int codigo;              // Código único do tripulante
char nome[50];           // Nome do tripulante
char telefone[15];       // Telefone do tripulante
char cargo[20];          // Cargo do tripulante (Piloto, Copiloto, Comissário)
} Tripulante;

// Estrutura para armazenar dados de voos
typedef struct {
int codigo;              // Código único do voo
char data[11];           // Data do voo no formato DD/MM/AAAA
char hora[6];            // Horário do voo no formato HH:MM
char origem[50];         // Cidade de origem
char destino[50];        // Cidade de destino
int codigoAviao;         // Código do avião
int codigoPiloto;        // Código do piloto responsável
int codigoCopiloto;      // Código do copiloto
int status;              // Status do voo (1: ativo, 0: inativo)
float tarifa;            // Tarifa do voo
} Voo;

// Estrutura para armazenar dados de assentos
typedef struct {
int numeroAssento;       // Número do assento
int codigoVoo;           // Código do voo ao qual o assento pertence
int status;              // Status do assento (1: ocupado, 0: livre)
} Assento;

// Estrutura para armazenar dados de reservas
typedef struct {
int codigoVoo;           // Código do voo
int numeroAssento;       // Número do assento reservado
int codigoPassageiro;    // Código do passageiro que fez a reserva
} Reserva;

// Arrays globais para armazenar os dados
Passageiro passageiros[MAX_PASSAGEIROS];
Tripulante tripulantes[MAX_TRIPULANTES];
Voo voos[MAX_VOOS];
Assento assentos[MAX_ASSENTOS];
Reserva reservas[MAX_ASSENTOS];

// Contadores globais para rastrear o número de registros
int numPassageiros = 0, numTripulantes = 0, numVoos = 0, numAssentos = 0, numReservas = 0;

// Prototipagem das funções
void menu();
void cadastrarPassageiro();
int validarNome(const char *nome);
int validarTelefone(const char *telefone);

// Função principal
int main() {
menu(); // Inicia o menu principal do sistema
return 0;
}

// Exibe o menu principal e gerencia a navegação entre as opções
void menu() {
int opcao;
do {
printf("\n===== Sistema de Gerenciamento de Voos =====\n");
printf("1. Cadastrar Passageiro\n");
printf("2. Listar Passageiros\n");
printf("3. Alterar Passageiro\n");
printf("4. Excluir Passageiro\n");
printf("5. Cadastrar Tripulante\n");
printf("6. Listar Tripulantes\n");
printf("7. Alterar Tripulante\n");
printf("8. Excluir Tripulante\n");
printf("9. Cadastrar Voo\n");
printf("10. Listar Voos\n");
printf("11. Alterar Voo\n");
printf("12. Excluir Voo\n");
printf("13. Cadastrar Assento\n");
printf("14. Listar Assentos\n");
printf("15. Alterar Assento\n");
printf("16. Excluir Assento\n");
printf("17. Cadastrar Reserva\n");
printf("18. Listar Reservas\n");
printf("19. Alterar Reserva\n");
printf("20. Excluir Reserva\n");
printf("21. Backup de Dados\n");
printf("22. Restaurar Dados\n");
printf("0. Sair\n");
printf("Selecione uma opcao: ");
scanf("%d", &opcao);

switch (opcao) {
case 1: cadastrarPassageiro(); break; // Opção para cadastrar um passageiro
case 2: listarPassageiros(); break; // opção para listar passageiro
case 3: alterarPassageiro(); break; //opção para alterar
case 4: excluirPassageiro(); break; //opção para excluir
case 5: cadastrarTripulante(); break;
case 6: listarTripulantes(); break;
case 7: alterarTripulante(); break;
case 8: excluirTripulante(); break;
case 0: printf("Saindo do sistema...\n"); break; // Sair do sistema
default: printf("Opcao invalida. Tente novamente.\n"); // Opção inválida
}
} while (opcao != 0);
}

// Valida se uma string contém apenas letras e espaços
int validarNome(const char *nome) {
for (int i = 0; nome[i] != '\0'; i++) {
if (!isalpha(nome[i]) && nome[i] != ' ') {
return 0; // Retorna 0 se encontrar caractere inválido
}
}
return 1; // Retorna 1 se for válido
}

// Valida se uma string contém apenas números
int validarTelefone(const char *telefone) {
for (int i = 0; telefone[i] != '\0'; i++) {
if (!isdigit(telefone[i])) {
return 0; // Retorna 0 se encontrar caractere inválido
}
}
return 1; // Retorna 1 se for válido
}

// Função para cadastrar um novo passageiro
void cadastrarPassageiro() {
if (numPassageiros >= MAX_PASSAGEIROS) {
printf("Limite de passageiros atingido!\n");
return;
}

Passageiro p;
p.codigo = numPassageiros + 1; // Gera um código único para o passageiro

// Solicita e valida o nome do passageiro
do {
printf("Nome: ");
getchar(); // Limpa o buffer do stdin
fgets(p.nome, sizeof(p.nome), stdin);
p.nome[strcspn(p.nome, "\n")] = 0; // Remove o caractere de nova linha
if (!validarNome(p.nome)) {
printf("Erro: O nome deve conter apenas letras e espaços. Tente novamente.\n");
}
} while (!validarNome(p.nome));

// Solicita o endereço do passageiro
printf("Endereco: ");
fgets(p.endereco, sizeof(p.endereco), stdin);
p.endereco[strcspn(p.endereco, "\n")] = 0;

// Solicita e valida o telefone do passageiro
do {
printf("Telefone: ");
fgets(p.telefone, sizeof(p.telefone), stdin);
p.telefone[strcspn(p.telefone, "\n")] = 0; // Remove o caractere de nova linha
if (!validarTelefone(p.telefone)) {
printf("Erro: O telefone deve conter apenas números. Tente novamente.\n");
}
} while (!validarTelefone(p.telefone));

// Solicita a participação no programa de fidelidade
printf("Fidelidade (1 para Sim, 0 para Nao): ");
scanf("%d", &p.fidelidade);
p.pontos = 0; // Inicializa os pontos de fidelidade como zero

passageiros[numPassageiros++] = p; // Adiciona o passageiro ao array
printf("Passageiro cadastrado com sucesso! Codigo: %d\n", p.codigo);
}
// Função para listar todos os passageiros cadastrados
void listarPassageiros() {
// Verifica se existem passageiros cadastrados
if (numPassageiros == 0) {
printf("Nenhum passageiro cadastrado.\n");
return;
}


// Exibe o cabeçalho da lista de passageiros
printf("\n===== Lista de Passageiros =====\n");

// Percorre o array de passageiros e exibe os detalhes de cada um
for (int i = 0; i < numPassageiros; i++) {
Passageiro p = passageiros[i];
printf("Codigo: %d, Nome: %s, Fidelidade: %s, Pontos: %d\n",
p.codigo,                  // Exibe o código do passageiro
p.nome,                    // Exibe o nome do passageiro
p.fidelidade ? "Sim" : "Nao", // Indica se participa do programa de fidelidade
p.pontos);                 // Exibe os pontos acumulados
}
}

// Função para alterar os dados de um passageiro existente
void alterarPassageiro() {
int codigo; // Variável para armazenar o código do passageiro a ser alterado

// Solicita o código do passageiro ao usuário
printf("Informe o código do passageiro para alterar: ");
scanf("%d", &codigo);

// Percorre o array de passageiros em busca do código informado
for (int i = 0; i < numPassageiros; i++) {
if (passageiros[i].codigo == codigo) { // Verifica se o código coincide

// Solicita o novo nome do passageiro
printf("Novo nome: ");
getchar(); // Limpa o buffer do teclado
fgets(passageiros[i].nome, 50, stdin);
passageiros[i].nome[strcspn(passageiros[i].nome, "\n")] = 0; // Remove o caractere de nova linha

// Solicita o novo endereço do passageiro
printf("Novo endereço: ");
fgets(passageiros[i].endereco, 100, stdin);
passageiros[i].endereco[strcspn(passageiros[i].endereco, "\n")] = 0;

// Solicita o novo telefone do passageiro
printf("Novo telefone: ");
fgets(passageiros[i].telefone, 15, stdin);
passageiros[i].telefone[strcspn(passageiros[i].telefone, "\n")] = 0;

// Solicita a nova participação no programa de fidelidade
printf("Fidelidade (1 para Sim, 0 para Não): ");
scanf("%d", &passageiros[i].fidelidade);

// Informa ao usuário que os dados foram alterados com sucesso
printf("Passageiro alterado com sucesso!\n");
return; // Sai da função após encontrar e alterar o passageiro
}
}

// Informa ao usuário caso o código do passageiro não seja encontrado
printf("Passageiro não encontrado.\n");
}

// Função para excluir um passageiro do sistema
void excluirPassageiro() {
int codigo; // Variável para armazenar o código do passageiro a ser excluído

// Solicita ao usuário o código do passageiro
printf("Informe o código do passageiro para excluir: ");
scanf("%d", &codigo);

// Percorre o array de passageiros em busca do código informado
for (int i = 0; i < numPassageiros; i++) {
if (passageiros[i].codigo == codigo) { // Verifica se o código coincide

// Desloca todos os passageiros subsequentes uma posição para trás
for (int j = i; j < numPassageiros - 1; j++) {
passageiros[j] = passageiros[j + 1];
}

// Decrementa o contador global de passageiros
numPassageiros--;

// Exibe mensagem de sucesso ao usuário
printf("Passageiro excluído com sucesso!\n");
return; // Sai da função após a exclusão
}
}

// Caso o código não seja encontrado, informa ao usuário
printf("Passageiro não encontrado.\n");
}
// Funções de cadastro, listagem, alteração e exclusão de tripulantes

// Função para cadastrar um novo tripulante
void cadastrarTripulante() {
if (numTripulantes >= MAX_TRIPULANTES) { // Verifica se o limite de tripulantes foi atingido
printf("Limite de tripulantes atingido!\n");
return;
}

Tripulante t;
t.codigo = numTripulantes + 1; // Define um código único para o tripulante

// Solicita e valida o nome do tripulante
do {
printf("Nome (somente letras): ");
getchar(); // Limpa o buffer do teclado
fgets(t.nome, sizeof(t.nome), stdin);
t.nome[strcspn(t.nome, "\n")] = 0; // Remove o caractere de nova linha

int valido = 1;
for (int i = 0; t.nome[i] != '\0'; i++) {
if (!isalpha(t.nome[i]) && t.nome[i] != ' ') {
valido = 0;
break;
}
}

if (!valido) {
printf("Erro: O nome deve conter apenas letras.\n");
} else {
break;
}
} while (1);

// Solicita e valida o telefone do tripulante
do {
printf("Telefone (somente números): ");
fgets(t.telefone, sizeof(t.telefone), stdin);
t.telefone[strcspn(t.telefone, "\n")] = 0; // Remove o caractere de nova linha

int valido = 1;
for (int i = 0; t.telefone[i] != '\0'; i++) {
if (!isdigit(t.telefone[i])) {
valido = 0;
break;
}
}

if (!valido) {
printf("Erro: O telefone deve conter apenas números.\n");
} else {
break;
}
} while (1);

// Solicita e valida o cargo do tripulante
int cargoOpcao;
do {
printf("Cargo (1 para Piloto, 2 para Copiloto, 3 para Comissário): ");
scanf("%d", &cargoOpcao);

switch (cargoOpcao) {
case 1:
strcpy(t.cargo, "Piloto");
break;
case 2:
strcpy(t.cargo, "Copiloto");
break;
case 3:
strcpy(t.cargo, "Comissario");
break;
default:
printf("Opção inválida. Escolha 1 para Piloto, 2 para Copiloto ou 3 para Comissário.\n");
}
} while (cargoOpcao < 1 || cargoOpcao > 3); // Garante que apenas valores válidos sejam aceitos

tripulantes[numTripulantes++] = t; // Adiciona o tripulante ao array
printf("Tripulante cadastrado com sucesso! Codigo: %d\n", t.codigo);
}


// Função para listar todos os tripulantes cadastrados
void listarTripulantes() {
if (numTripulantes == 0) { // Verifica se há tripulantes cadastrados
printf("Nenhum tripulante cadastrado.\n");
return;
}

// Exibe a lista de tripulantes
printf("\n===== Lista de Tripulantes =====\n");
for (int i = 0; i < numTripulantes; i++) {
Tripulante t = tripulantes[i];
printf("Codigo: %d, Nome: %s, Cargo: %s\n", t.codigo, t.nome, t.cargo);
}
}

// Função para alterar os dados de um tripulante existente
void alterarTripulante() {
int codigo; // Variável para armazenar o código do tripulante a ser alterado

// Solicita o código do tripulante ao usuário
printf("Informe o código do tripulante para alterar: ");
scanf("%d", &codigo);

// Percorre o array de tripulantes em busca do código informado
for (int i = 0; i < numTripulantes; i++) {
if (tripulantes[i].codigo == codigo) { // Verifica se o código coincide

// Solicita o novo nome do tripulante
printf("Novo nome: ");
getchar(); // Limpa o buffer do teclado
fgets(tripulantes[i].nome, sizeof(tripulantes[i].nome), stdin);
tripulantes[i].nome[strcspn(tripulantes[i].nome, "\n")] = 0; // Remove o caractere de nova linha

// Solicita o novo telefone do tripulante
printf("Novo telefone: ");
fgets(tripulantes[i].telefone, sizeof(tripulantes[i].telefone), stdin);
tripulantes[i].telefone[strcspn(tripulantes[i].telefone, "\n")] = 0;

// Solicita o novo cargo do tripulante
printf("Novo cargo: ");
fgets(tripulantes[i].cargo, sizeof(tripulantes[i].cargo), stdin);
tripulantes[i].cargo[strcspn(tripulantes[i].cargo, "\n")] = 0;

// Informa que os dados foram alterados com sucesso
printf("Tripulante alterado com sucesso!\n");
return;
}
}

// Caso o código não seja encontrado
printf("Tripulante não encontrado.\n");
}

// Função para excluir um tripulante do sistema
void excluirTripulante() {
int codigo; // Variável para armazenar o código do tripulante a ser excluído

// Solicita o código do tripulante ao usuário
printf("Informe o código do tripulante para excluir: ");
scanf("%d", &codigo);

// Percorre o array de tripulantes em busca do código informado
for (int i = 0; i < numTripulantes; i++) {
if (tripulantes[i].codigo == codigo) { // Verifica se o código coincide

// Desloca todos os tripulantes subsequentes uma posição para trás
for (int j = i; j < numTripulantes - 1; j++) {
tripulantes[j] = tripulantes[j + 1];
}

// Decrementa o contador global de tripulantes
numTripulantes--;

// Informa que o tripulante foi excluído com sucesso
printf("Tripulante excluído com sucesso!\n");
return;
}
}

// Caso o código não seja encontrado
printf("Tripulante não encontrado.\n");
}
