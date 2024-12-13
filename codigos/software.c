#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Definição de constantes
#define MAX_PASSAGEIROS 100
#define MAX_TRIPULANTES 50
#define MAX_VOOS 50
#define MAX_ASSENTOS 200
#define FIDELIDADE_PONTOS 10

// Estruturas de dados
typedef struct {
int codigo;
char nome[50];
char endereco[100];
char telefone[15];
int fidelidade; // 1 para sim, 0 para não
int pontos;
} Passageiro;

typedef struct {
int codigo;
char nome[50];
char telefone[15];
char cargo[20]; // Piloto, Copiloto, Comissário
} Tripulante;

typedef struct {
int codigo;
char data[11];
char hora[6];
char origem[50];
char destino[50];
int codigoAviao;
int codigoPiloto;
int codigoCopiloto;
int status; // 1 para ativo, 0 para inativo
float tarifa;
} Voo;

typedef struct {
int numeroAssento;
int codigoVoo;
int status; // 1 para ocupado, 0 para livre
} Assento;

typedef struct {
int codigoVoo;
int numeroAssento;
int codigoPassageiro;
} Reserva;

// Arrays globais para armazenar os dados
Passageiro passageiros[MAX_PASSAGEIROS];
Tripulante tripulantes[MAX_TRIPULANTES];
Voo voos[MAX_VOOS];
Assento assentos[MAX_ASSENTOS];
Reserva reservas[MAX_ASSENTOS];

// Contadores globais
int numPassageiros = 0, numTripulantes = 0, numVoos = 0, numAssentos = 0, numReservas = 0;

// Prototipação
void menu();
void cadastrarPassageiro();
void listarPassageiros();
void alterarPassageiro();
void excluirPassageiro();
void cadastrarTripulante();
void listarTripulantes();
void alterarTripulante();
void excluirTripulante();
void cadastrarVoo();
void listarVoos();
void alterarVoo();
void excluirVoo();
void cadastrarAssento();
void listarAssentos();
void alterarAssento();
void excluirAssento();
void cadastrarReserva();
void listarReservas();
void alterarReserva();
void excluirReserva();
void backupDados();
void restaurarDados();

// Função principal
int main() {
menu();
return 0;
}

// Menu principal
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
case 1: cadastrarPassageiro(); break;
case 2: listarPassageiros(); break;
case 3: alterarPassageiro(); break;
case 4: excluirPassageiro(); break;
case 5: cadastrarTripulante(); break;
case 6: listarTripulantes(); break;
case 7: alterarTripulante(); break;
case 8: excluirTripulante(); break;
case 9: cadastrarVoo(); break;
case 10: listarVoos(); break;
case 11: alterarVoo(); break;
case 12: excluirVoo(); break;
case 13: cadastrarAssento(); break;
case 14: listarAssentos(); break;
case 15: alterarAssento(); break;
case 16: excluirAssento(); break;
case 17: cadastrarReserva(); break;
case 18: listarReservas(); break;
case 19: alterarReserva(); break;
case 20: excluirReserva(); break;
case 21: backupDados(); break;
case 22: restaurarDados(); break;
case 0: printf("Saindo do sistema...\n"); break;
default: printf("Opcao invalida. Tente novamente.\n");
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
do {
printf("Fidelidade (1 para Sim, 0 para Nao): ");
if (scanf("%d", &p.fidelidade) != 1 || (p.fidelidade != 0 && p.fidelidade != 1)) {
printf("Erro: Valor inválido. Digite 1 para Sim ou 0 para Nao.\n");
while (getchar() != '\n'); // Limpa o buffer de entrada
} else {
break; // Valor válido
}
} while (1);
p.pontos = 0; // Inicializa os pontos de fidelidade como zero

passageiros[numPassageiros++] = p; // Adiciona o passageiro ao array
backupDados(); // Atualiza backup após cadastro
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
backupDados(); // Atualiza backup após alteração

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
backupDados(); // Atualiza backup após exclusão

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
backupDados(); // Atualiza backup após cadastro
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
backupDados(); // Atualiza backup após alteração

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
backupDados(); // Atualiza backup após exclusão

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
// Verifica se o tamanho da string é exatamente 10 caracteres (dd/mm/aaaa)
if (strlen(data) != 10) return 0;

int dia, mes, ano;

// Verifica se o formato da data é válido e extrai dia, mês e ano
if (sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano) != 3) return 0;

// Verifica se o ano está dentro de um intervalo razoável
if (ano < 1900 || ano > 2100) return 0;

// Verifica se o mês está entre 1 e 12
if (mes < 1 || mes > 12) return 0;

// Array com os dias máximos de cada mês
int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Ajusta para anos bissextos
if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
diasNoMes[1] = 29; // Fevereiro tem 29 dias em anos bissextos
}

// Verifica se o dia está dentro do limite do mês
if (dia < 1 || dia > diasNoMes[mes - 1]) return 0;

// Data válida
return 1;
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
backupDados(); // Atualiza backup após cadastro
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
backupDados(); // Atualiza backup após exclusão

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
backupDados(); // Atualiza backup após alteração

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
backupDados(); // Atualiza backup após cadastro

printf("Assento cadastrado com sucesso! Numero: %d\n", a.numeroAssento);
}


// Função para listar todos os assentos cadastrados
void listarAssentos() {
// Verifica se há assentos cadastrados
if (numAssentos == 0) {
printf("Nenhum assento cadastrado.\n");
return;
}

// Exibe a lista de assentos
printf("\n===== Lista de Assentos =====\n");
for (int i = 0; i < numAssentos; i++) {
Assento a = assentos[i];
printf("Número: %d, Código do Voo: %d, Status: %s\n",
a.numeroAssento, a.codigoVoo, a.status ? "Ocupado" : "Livre");
}
}

// Função para alterar os dados de um assento existente
void alterarAssento() {
int numeroAssento, codigoVoo;

// Solicita o número do assento e o código do voo ao qual pertence
printf("Informe o número do assento: ");
if (scanf("%d", &numeroAssento) != 1 || numeroAssento <= 0) {
printf("Erro: Número do assento inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

printf("Informe o código do voo: ");
if (scanf("%d", &codigoVoo) != 1 || codigoVoo <= 0) {
printf("Erro: Código do voo inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

// Procura o assento no array global
for (int i = 0; i < numAssentos; i++) {
if (assentos[i].numeroAssento == numeroAssento && assentos[i].codigoVoo == codigoVoo) {
// Solicita novos valores para o assento
printf("Novo número do assento: ");
if (scanf("%d", &assentos[i].numeroAssento) != 1 || assentos[i].numeroAssento <= 0) {
printf("Erro: Número do assento inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

printf("Novo código do voo: ");
if (scanf("%d", &assentos[i].codigoVoo) != 1 || assentos[i].codigoVoo <= 0) {
printf("Erro: Código do voo inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

printf("Novo status (1 para ocupado, 0 para livre): ");
if (scanf("%d", &assentos[i].status) != 1 || (assentos[i].status != 0 && assentos[i].status != 1)) {
printf("Erro: Status inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

backupDados(); // Atualiza backup após alteração
printf("Assento alterado com sucesso!\n");
return;
}
}

// Caso o assento não seja encontrado
printf("Assento não encontrado.\n");
}

// Função para excluir um assento do sistema
void excluirAssento() {
int numeroAssento, codigoVoo;

// Solicita o número do assento e o código do voo ao qual pertence
printf("Informe o número do assento: ");
if (scanf("%d", &numeroAssento) != 1 || numeroAssento <= 0) {
printf("Erro: Número do assento inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

printf("Informe o código do voo: ");
if (scanf("%d", &codigoVoo) != 1 || codigoVoo <= 0) {
printf("Erro: Código do voo inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

// Procura o assento no array global
for (int i = 0; i < numAssentos; i++) {
if (assentos[i].numeroAssento == numeroAssento && assentos[i].codigoVoo == codigoVoo) {
// Remove o assento deslocando os elementos subsequentes
for (int j = i; j < numAssentos - 1; j++) {
assentos[j] = assentos[j + 1];
}

// Decrementa o contador de assentos
numAssentos--;
backupDados(); // Atualiza backup após exclusão

printf("Assento excluído com sucesso!\n");
return;
}
}

// Caso o assento não seja encontrado
printf("Assento não encontrado.\n");
}

// Funções de cadastro, listagem, alteração e exclusão de reservas

// Função para cadastrar uma nova reserva
void cadastrarReserva() {
// Verifica se o limite de reservas foi atingido
if (numReservas >= MAX_ASSENTOS) {
printf("Limite de reservas atingido!\n");
return;
}

Reserva r;

// Solicita e valida o código do voo
printf("Código do Voo: ");
if (scanf("%d", &r.codigoVoo) != 1 || r.codigoVoo <= 0) {
printf("Erro: Código do voo inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

// Verifica se o voo existe
int vooEncontrado = 0;
for (int i = 0; i < numVoos; i++) {
if (voos[i].codigo == r.codigoVoo) {
vooEncontrado = 1;
break;
}
}
if (!vooEncontrado) {
printf("Erro: Código do voo não encontrado.\n");
return;
}

// Solicita e valida o número do assento
printf("Número do Assento: ");
if (scanf("%d", &r.numeroAssento) != 1 || r.numeroAssento <= 0) {
printf("Erro: Número do assento inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

// Verifica se o assento existe e está disponível
int assentoEncontrado = 0;
for (int i = 0; i < numAssentos; i++) {
if (assentos[i].codigoVoo == r.codigoVoo && assentos[i].numeroAssento == r.numeroAssento) {
assentoEncontrado = 1;
if (assentos[i].status == 1) {
printf("Erro: O assento já está ocupado.\n");
return;
}
break;
}
}
if (!assentoEncontrado) {
printf("Erro: Assento não encontrado no voo especificado.\n");
return;
}

// Solicita e valida o código do passageiro
printf("Código do Passageiro: ");
if (scanf("%d", &r.codigoPassageiro) != 1 || r.codigoPassageiro <= 0) {
printf("Erro: Código do passageiro inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

// Verifica se o passageiro existe
int passageiroEncontrado = 0;
for (int i = 0; i < numPassageiros; i++) {
if (passageiros[i].codigo == r.codigoPassageiro) {
passageiroEncontrado = 1;
break;
}
}
if (!passageiroEncontrado) {
printf("Erro: Código do passageiro não encontrado.\n");
return;
}

// Atualiza o status do assento para ocupado
for (int i = 0; i < numAssentos; i++) {
if (assentos[i].codigoVoo == r.codigoVoo && assentos[i].numeroAssento == r.numeroAssento) {
assentos[i].status = 1;
break;
}
}

// Atualiza os pontos de fidelidade do passageiro
for (int i = 0; i < numPassageiros; i++) {
if (passageiros[i].codigo == r.codigoPassageiro) {
passageiros[i].pontos += FIDELIDADE_PONTOS;
break;
}
}

// Adiciona a reserva ao array global
reservas[numReservas++] = r;
backupDados(); // Atualiza backup após cadastro
printf("Reserva realizada com sucesso!\n");
}


// Função para listar todas as reservas cadastradas
void listarReservas() {
// Verifica se há reservas cadastradas
if (numReservas == 0) {
printf("Nenhuma reserva cadastrada.\n");
return;
}

// Exibe a lista de reservas
printf("\n===== Lista de Reservas =====\n");
for (int i = 0; i < numReservas; i++) {
Reserva r = reservas[i];
printf("Código do Voo: %d, Número do Assento: %d, Código do Passageiro: %d\n",
r.codigoVoo, r.numeroAssento, r.codigoPassageiro);
}
}

// Função para alterar uma reserva existente
void alterarReserva() {
int codigoVoo, numeroAssento;

// Solicita o código do voo e o número do assento da reserva
printf("Informe o código do voo da reserva: ");
if (scanf("%d", &codigoVoo) != 1 || codigoVoo <= 0) {
printf("Erro: Código do voo inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

printf("Informe o número do assento da reserva: ");
if (scanf("%d", &numeroAssento) != 1 || numeroAssento <= 0) {
printf("Erro: Número do assento inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

// Procura a reserva no array global
for (int i = 0; i < numReservas; i++) {
if (reservas[i].codigoVoo == codigoVoo && reservas[i].numeroAssento == numeroAssento) {
// Solicita novos valores para a reserva
printf("Novo código do voo: ");
if (scanf("%d", &reservas[i].codigoVoo) != 1 || reservas[i].codigoVoo <= 0) {
printf("Erro: Código do voo inválido.\n");
while (getchar() != "\n");
return;
}

printf("Novo número do assento: ");
if (scanf("%d", &reservas[i].numeroAssento) != 1 || reservas[i].numeroAssento <= 0) {
printf("Erro: Número do assento inválido.\n");
while (getchar() != "\n");
return;
}

printf("Novo código do passageiro: ");
if (scanf("%d", &reservas[i].codigoPassageiro) != 1 || reservas[i].codigoPassageiro <= 0) {
printf("Erro: Código do passageiro inválido.\n");
while (getchar() != "\n");
return;
}

backupDados(); // Atualiza backup após alteração
printf("Reserva alterada com sucesso!\n");
return;
}
}

// Caso a reserva não seja encontrada
printf("Reserva não encontrada.\n");
}

// Função para excluir uma reserva existente
void excluirReserva() {
int codigoVoo, numeroAssento;

// Solicita o código do voo e o número do assento da reserva
printf("Informe o código do voo da reserva: ");
if (scanf("%d", &codigoVoo) != 1 || codigoVoo <= 0) {
printf("Erro: Código do voo inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

printf("Informe o número do assento da reserva: ");
if (scanf("%d", &numeroAssento) != 1 || numeroAssento <= 0) {
printf("Erro: Número do assento inválido.\n");
while (getchar() != "\n"); // Limpa o buffer de entrada
return;
}

// Procura a reserva no array global
for (int i = 0; i < numReservas; i++) {
if (reservas[i].codigoVoo == codigoVoo && reservas[i].numeroAssento == numeroAssento) {
// Remove a reserva deslocando os elementos subsequentes
for (int j = i; j < numReservas - 1; j++) {
reservas[j] = reservas[j + 1];
}

// Decrementa o contador de reservas
numReservas--;
backupDados(); // Atualiza backup após exclusão

printf("Reserva excluída com sucesso!\n");
return;
}
}

// Caso a reserva não seja encontrada
printf("Reserva não encontrada.\n");
}

// Função para realizar o backup dos dados
void backupDados() {
// Abre o arquivo para escrita binária
FILE *file = fopen("backup.bin", "wb");
if (!file) {
// Verifica se houve erro ao abrir o arquivo
printf("Erro ao criar arquivo de backup.\n");
return;
}

// Escreve o número de passageiros no arquivo
if (fwrite(&numPassageiros, sizeof(int), 1, file) != 1) {
printf("Erro ao salvar o número de passageiros no backup.\n");
fclose(file);
return;
}

// Escreve os dados dos passageiros no arquivo
if (fwrite(passageiros, sizeof(Passageiro), numPassageiros, file) != numPassageiros) {
printf("Erro ao salvar os passageiros no backup.\n");
fclose(file);
return;
}

// Escreve o número de tripulantes no arquivo
if (fwrite(&numTripulantes, sizeof(int), 1, file) != 1) {
printf("Erro ao salvar o número de tripulantes no backup.\n");
fclose(file);
return;
}

// Escreve os dados dos tripulantes no arquivo
if (fwrite(tripulantes, sizeof(Tripulante), numTripulantes, file) != numTripulantes) {
printf("Erro ao salvar os tripulantes no backup.\n");
fclose(file);
return;
}

// Escreve o número de voos no arquivo
if (fwrite(&numVoos, sizeof(int), 1, file) != 1) {
printf("Erro ao salvar o número de voos no backup.\n");
fclose(file);
return;
}

// Escreve os dados dos voos no arquivo
if (fwrite(voos, sizeof(Voo), numVoos, file) != numVoos) {
printf("Erro ao salvar os voos no backup.\n");
fclose(file);
return;
}

// Escreve o número de assentos no arquivo
if (fwrite(&numAssentos, sizeof(int), 1, file) != 1) {
printf("Erro ao salvar o número de assentos no backup.\n");
fclose(file);
return;
}

// Escreve os dados dos assentos no arquivo
if (fwrite(assentos, sizeof(Assento), numAssentos, file) != numAssentos) {
printf("Erro ao salvar os assentos no backup.\n");
fclose(file);
return;
}

// Escreve o número de reservas no arquivo
if (fwrite(&numReservas, sizeof(int), 1, file) != 1) {
printf("Erro ao salvar o número de reservas no backup.\n");
fclose(file);
return;
}

// Escreve os dados das reservas no arquivo
if (fwrite(reservas, sizeof(Reserva), numReservas, file) != numReservas) {
printf("Erro ao salvar as reservas no backup.\n");
fclose(file);
return;
}

// Fecha o arquivo após a escrita
fclose(file);
printf("Backup realizado com sucesso!\n");
}

// Função para restaurar os dados a partir de um backup
void restaurarDados() {
// Abre o arquivo para leitura binária
FILE *file = fopen("backup.bin", "rb");
if (!file) {
// Verifica se houve erro ao abrir o arquivo
printf("Erro ao abrir arquivo de backup.\n");
return;
}

// Lê o número de passageiros do arquivo
if (fread(&numPassageiros, sizeof(int), 1, file) != 1) {
printf("Erro ao restaurar o número de passageiros.\n");
fclose(file);
return;
}

// Lê os dados dos passageiros do arquivo
if (fread(passageiros, sizeof(Passageiro), numPassageiros, file) != numPassageiros) {
printf("Erro ao restaurar os passageiros.\n");
fclose(file);
return;
}

// Lê o número de tripulantes do arquivo
if (fread(&numTripulantes, sizeof(int), 1, file) != 1) {
printf("Erro ao restaurar o número de tripulantes.\n");
fclose(file);
return;
}

// Lê os dados dos tripulantes do arquivo
if (fread(tripulantes, sizeof(Tripulante), numTripulantes, file) != numTripulantes) {
printf("Erro ao restaurar os tripulantes.\n");
fclose(file);
return;
}

// Lê o número de voos do arquivo
if (fread(&numVoos, sizeof(int), 1, file) != 1) {
printf("Erro ao restaurar o número de voos.\n");
fclose(file);
return;
}

// Lê os dados dos voos do arquivo
if (fread(voos, sizeof(Voo), numVoos, file) != numVoos) {
printf("Erro ao restaurar os voos.\n");
fclose(file);
return;
}

// Lê o número de assentos do arquivo
if (fread(&numAssentos, sizeof(int), 1, file) != 1) {
printf("Erro ao restaurar o número de assentos.\n");
fclose(file);
return;
}

// Lê os dados dos assentos do arquivo
if (fread(assentos, sizeof(Assento), numAssentos, file) != numAssentos) {
printf("Erro ao restaurar os assentos.\n");
fclose(file);
return;
}

// Lê o número de reservas do arquivo
if (fread(&numReservas, sizeof(int), 1, file) != 1) {
printf("Erro ao restaurar o número de reservas.\n");
fclose(file);
return;
}

// Lê os dados das reservas do arquivo
if (fread(reservas, sizeof(Reserva), numReservas, file) != numReservas) {
printf("Erro ao restaurar as reservas.\n");
fclose(file);
return;
}

// Fecha o arquivo após a leitura
fclose(file);
printf("Dados restaurados com sucesso!\n");
}
