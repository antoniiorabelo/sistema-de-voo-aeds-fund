#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


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
case 9: cadastrarVoo(); break;
case 10: listarVoos(); break;
case 11: alterarVoo(); break;
case 12: excluirVoo(); break;
case 0: printf("Saindo do sistema...\n"); break; // Sair do sistema
default: printf("Opcao invalida. Tente novamente.\n"); // Opção inválida
}
} while (opcao != 0);
}

// Funções de cadastro

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
getchar(); // Limpa o buffer de entrada
if (fgets(passageiros[i].nome, sizeof(passageiros[i].nome), stdin) != NULL) {
passageiros[i].nome[strcspn(passageiros[i].nome, "\n")] = 0; // Remove o caractere de nova linha
}

// Solicita o novo endereço do passageiro
printf("Novo endereço: ");
if (fgets(passageiros[i].endereco, sizeof(passageiros[i].endereco), stdin) != NULL) {
passageiros[i].endereco[strcspn(passageiros[i].endereco, "\n")] = 0;
}

// Solicita o novo telefone do passageiro
printf("Novo telefone: ");
if (fgets(passageiros[i].telefone, sizeof(passageiros[i].telefone), stdin) != NULL) {
passageiros[i].telefone[strcspn(passageiros[i].telefone, "\n")] = 0;
}

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


// Função para alterar os dados de um passageiro existente
void AlterarPassageiro() {
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

// Funções de cadastro, listagem, alteração e exclusão de voos

// Função para validar uma data no formato dd/mm/aaaa
int validarData(const char *data) {
if (strlen(data) != 10) return 0; // Verifica se o tamanho é correto

int dia, mes, ano;
if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) return 0; // Converte e valida o formato

if (ano < 1900 || ano > 2100 || mes < 1 || mes > 12 || dia < 1) return 0; // Valida intervalos

int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Verifica anos bissextos
if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
diasNoMes[1] = 29;
}

return dia <= diasNoMes[mes - 1];
}

// Função para validar se uma string contém apenas letras
int validarLetras(const char *str) {
for (int i = 0; str[i] != '\0'; i++) {
if (!isalpha(str[i]) && str[i] != ' ') {
    return 0;
}
}
return 1;
}

// Função para verificar se um código existe em um array
int verificarCodigo(int codigo, int tipo) {
switch (tipo) {
case 1: // Aviões
    for (int i = 0; i < MAX_VOOS; i++) {
        if (voos[i].codigoAviao == codigo) return 1;
    }
    break;
case 2: // Pilotos
    for (int i = 0; i < numTripulantes; i++) {
        if (strcmp(tripulantes[i].cargo, "Piloto") == 0 && tripulantes[i].codigo == codigo) return 1;
    }
    break;
case 3: // Copilotos
    for (int i = 0; i < numTripulantes; i++) {
        if (strcmp(tripulantes[i].cargo, "Copiloto") == 0 && tripulantes[i].codigo == codigo) return 1;
    }
    break;
}
return 0;
}

// Função para cadastrar um novo voo
void cadastrarVoo() {
if (numVoos >= MAX_VOOS) { // Verifica se o limite de voos foi atingido
printf("Limite de voos atingido!\n");
return;
}

Voo v;
v.codigo = numVoos + 1; // Gera um código único para o voo

// Solicita e valida a data
do {
printf("Data (dd/mm/aaaa): ");
getchar(); // Limpa o buffer do teclado
fgets(v.data, sizeof(v.data), stdin);
v.data[strcspn(v.data, "\n")] = 0; // Remove o caractere de nova linha

if (!validarData(v.data)) {
    printf("Erro: Data inválida. Tente novamente.\n");
} else {
    break;
}
} while (1);

// Solicita e valida a origem
do {
printf("Origem: ");
fgets(v.origem, sizeof(v.origem), stdin);
v.origem[strcspn(v.origem, "\n")] = 0; // Remove o caractere de nova linha

if (!validarLetras(v.origem)) {
    printf("Erro: Origem deve conter apenas letras.\n");
} else {
    break;
}
} while (1);

// Solicita e valida o destino
do {
printf("Destino: ");
fgets(v.destino, sizeof(v.destino), stdin);
v.destino[strcspn(v.destino, "\n")] = 0; // Remove o caractere de nova linha

if (!validarLetras(v.destino)) {
    printf("Erro: Destino deve conter apenas letras.\n");
} else {
    break;
}
} while (1);

// Solicita e valida o código do avião
do {
printf("Codigo do Aviao: ");
scanf("%d", &v.codigoAviao);

if (!verificarCodigo(v.codigoAviao, 1)) {
    printf("Erro: Codigo do avião não encontrado.\n");
} else {
    break;
}
} while (1);

// Solicita e valida o código do piloto
do {
printf("Codigo do Piloto: ");
scanf("%d", &v.codigoPiloto);

if (!verificarCodigo(v.codigoPiloto, 2)) {
    printf("Erro: Codigo do piloto não encontrado.\n");
} else {
    break;
}
} while (1);

// Solicita e valida o código do copiloto
do {
printf("Codigo do Copiloto: ");
scanf("%d", &v.codigoCopiloto);

if (!verificarCodigo(v.codigoCopiloto, 3)) {
    printf("Erro: Codigo do copiloto não encontrado.\n");
} else {
    break;
}
} while (1);

// Solicita a tarifa
printf("Tarifa: ");
scanf("%f", &v.tarifa);

// Define o status do voo
v.status = 1; // Ativo
printf("Voo ativado com sucesso!\n");

// Adiciona o voo ao array
voos[numVoos++] = v;
printf("Voo cadastrado com sucesso! Codigo: %d\n", v.codigo);
}


// Função para listar todos os voos cadastrados
void listarVoos() {
if (numVoos == 0) { // Verifica se há voos cadastrados
printf("Nenhum voo cadastrado.\n");
return;
}

// Exibe a lista de voos
printf("\n===== Lista de Voos =====\n");
for (int i = 0; i < numVoos; i++) {
Voo v = voos[i];
printf("Codigo: %d, Data: %s, Hora: %s, Origem: %s, Destino: %s, Status: %s, Tarifa: %.2f\n",
v.codigo, v.data, v.hora, v.origem, v.destino,
v.status ? "Ativo" : "Inativo", v.tarifa);
}
}

// Função para alterar os dados de um voo existente
void alterarVoo() {
int codigo; // Variável para armazenar o código do voo a ser alterado

// Solicita o código do voo ao usuário
printf("Informe o código do voo para alterar: ");
scanf("%d", &codigo);

// Percorre o array de voos em busca do código informado
for (int i = 0; i < numVoos; i++) {
if (voos[i].codigo == codigo) { // Verifica se o código coincide

// Solicita os novos dados do voo
printf("Nova data (dd/mm/aaaa): ");
getchar(); // Limpa o buffer do teclado
fgets(voos[i].data, 11, stdin);
voos[i].data[strcspn(voos[i].data, "\n")] = 0;

printf("Nova hora (hh:mm): ");
fgets(voos[i].hora, 6, stdin);
voos[i].hora[strcspn(voos[i].hora, "\n")] = 0;

printf("Nova origem: ");
fgets(voos[i].origem, 50, stdin);
voos[i].origem[strcspn(voos[i].origem, "\n")] = 0;

printf("Novo destino: ");
fgets(voos[i].destino, 50, stdin);
voos[i].destino[strcspn(voos[i].destino, "\n")] = 0;

printf("Novo código do avião: ");
scanf("%d", &voos[i].codigoAviao);

printf("Novo código do piloto: ");
scanf("%d", &voos[i].codigoPiloto);

printf("Novo código do copiloto: ");
scanf("%d", &voos[i].codigoCopiloto);

printf("Nova tarifa: ");
scanf("%f", &voos[i].tarifa);

// Informa que o voo foi alterado com sucesso
printf("Voo alterado com sucesso!\n");
return;
}
}

// Caso o código não seja encontrado
printf("Voo nao encontrado.\n");
}

// Função para excluir um voo do sistema
void excluirVoo() {
int codigo; // Variável para armazenar o código do voo a ser excluído

// Solicita o código do voo ao usuário
printf("Informe o código do voo para excluir: ");
scanf("%d", &codigo);

// Percorre o array de voos em busca do código informado
for (int i = 0; i < numVoos; i++) {
if (voos[i].codigo == codigo) { // Verifica se o código coincide

// Desloca todos os voos subsequentes uma posição para trás
for (int j = i; j < numVoos - 1; j++) {
voos[j] = voos[j + 1];
}

// Decrementa o contador global de voos
numVoos--;

// Informa que o voo foi excluído com sucesso
printf("Voo excluido com sucesso!\n");
return;
}
}

// Caso o código não seja encontrado
printf("Voo nao encontrado.\n");
}

// Funções de cadastro, listagem, alteração e exclusão de assentos

// Função para cadastrar um novo assento
void cadastrarAssento() {
if (numAssentos >= MAX_ASSENTOS) { // Verifica se o limite de assentos foi atingido
printf("Limite de assentos atingido!\n");
return;
}

Assento a;
printf("Numero do Assento: ");
scanf("%d", &a.numeroAssento);

// Verifica se o número do assento já está em uso
for (int i = 0; i < numAssentos; i++) {
if (assentos[i].numeroAssento == a.numeroAssento) {
printf("Erro: O numero do assento ja esta em uso.\n");
return;
}
}

printf("Codigo do Voo: ");
scanf("%d", &a.codigoVoo);

// Verifica se o voo existe
int vooEncontrado = 0;
for (int i = 0; i < numVoos; i++) {
if (voos[i].codigo == a.codigoVoo) {
vooEncontrado = 1;
break;
}
}

if (!vooEncontrado) {
printf("Erro: Codigo do voo nao encontrado.\n");
return;
}

a.status = 0; // Define o assento como livre por padrão

// Adiciona o assento ao array
assentos[numAssentos++] = a;
printf("Assento cadastrado com sucesso! Numero: %d\n", a.numeroAssento);
}
