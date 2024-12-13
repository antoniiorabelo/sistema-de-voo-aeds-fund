# LIDER-AERO (AEDS1/FUNDAMENTOS)
# Projeto
LIDER AERO: Um Sistema para Modernizar a Gestão de Voos

A LIDER AERO é uma empresa focada em oferecer aos seus clientes uma experiência única no transporte aéreo. Localizada estrategicamente no coração do país, a LIDER AERO opera voos nacionais e internacionais, buscando atender seus passageiros com segurança, eficiência e conforto. Para manter essa excelência, a empresa conta com uma equipe dedicada, composta por pilotos, copilotos, comissários de bordo e operadores de solo.

No entanto, até hoje, a LIDER AERO gerenciava suas operações de voos, reservas, tripulações e assentos utilizando planilhas de Excel e documentos físicos. Esse método tem gerado problemas significativos, como sobreposição de reservas, dificuldades no controle de horários dos voos e erros no gerenciamento das equipes. Essas falhas não só prejudicam a eficiência da empresa, como também comprometem a satisfação dos passageiros.

Diante dessa situação, foi decidido implementar um sistema em linguagem C para modernizar e centralizar as operações da LIDER AERO. Esse sistema terá como objetivo resolver os problemas enfrentados, oferecendo funcionalidades como cadastro e controle de voos, gerenciamento de tripulantes e reservas de assentos, garantindo que a empresa opere com maior organização e precisão.
# Bibliotecas Usadas
- **time.h**: Usada para demarcar as datas de entrada e saída dos integrantes e reservas no voo.
- **stdio.h**: Biblioteca padrão que fornece funções como printf e scanf, fundamentais para interação entre entrada e saída de dados.
- **stdlib.h**: Oferece funções para manipulação de memória, conversão de tipos, geração de números aleatórios e controle do ambiente de execução do software.
- **string.h**: Utilizado para manipulação de strings, exemplo cópia, concatenação, etc.
- **ctype.h**: Usada para manipulação e classificação de caracteres.
- **unity.h**: Ultilizada para manipular os casos de teste, auxilia na confirmação de testes.
# Estrutura de Dados
- **typedef struct Passageiros**: Armazena as informações dos passageiros incluindo: código, nome, endereço e telefone, fidelidade (1 = sim / 0 = nao) e pontos.
- **typedef struct Tripulantes**: Armazena as informações dos tripulantes incluindo: código, nome, telefone e cargo.
 - **typedef struct Voo**: Armazena as informações dos voos incluindo: origem, data, hora, destino, codigo do aviao, codigo do piloto, codigo do copilo e status (1 = ativo / 0 = inativo).
- **typedef struct Assento**: Armazena as informações do assento incluindo: numero do assento, codigo do voo e status (1 = ocupado / 0 = livre).
- **typedef struct Reserva**: Armazena as informaçoes da reserva incluindo: codigo do voo, numero do assento e codigo do passageiro.
# Funções Ultilizadas
 - **Cadastrar Passageiro:**

Função que adiciona um novo passageiro ao sistema, atribuindo-lhe um código único.
Verifica se há espaço suficiente no array de passageiros.
Solicita e armazena informações como nome, endereço, telefone, e dados de fidelidade.
- **Listar Passageiros:**

Exibe a lista de passageiros cadastrados no sistema.
- **Alterar Passageiro:**

Permite alterar as informações de um passageiro existente, como nome, endereço ou telefone.
- **Excluir Passageiro:**

Exclui um passageiro do sistema, removendo-o do array de passageiros.
- **Cadastrar Tripulante:**

Função que adiciona um novo tripulante ao sistema, atribuindo-lhe um código único.
Solicita dados como nome, telefone e cargo (piloto, copiloto, comissário, etc.).
- **Listar Tripulantes:**

Exibe a lista de tripulantes cadastrados no sistema.
- **Alterar Tripulante:**

Permite alterar as informações de um tripulante existente.
 - **Excluir Tripulante:**

Exclui um tripulante do sistema.
- **Cadastrar Voo:**

Adiciona um novo voo ao sistema, com informações como data, hora, origem, destino, tripulação (piloto e copiloto), e tarifa.
- **Listar Voos:**

Exibe a lista de voos disponíveis no sistema.
- **Alterar Voo:**

Permite alterar as informações de um voo, como data, hora, origem, destino, etc.
- **Excluir Voo:**

Exclui um voo do sistema.
- **Cadastrar Assento:**

Cadastra os assentos de um voo, indicando se estão livres ou ocupados.
- **Listar Assentos:**

Exibe a lista de assentos disponíveis ou ocupados para um voo.
- **Alterar Assento:**

Permite alterar o status de um assento (livre ou ocupado).
- **Excluir Assento:**

Exclui um assento do sistema.
- **Cadastrar Reserva:**

Registra uma nova reserva para um passageiro, incluindo a atribuição de um assento em um voo.
- **Listar Reservas:**

Exibe as reservas feitas pelos passageiros, mostrando o número do voo e o assento reservado.
- **Alterar Reserva:**

Permite alterar uma reserva, como trocar o assento ou o voo.
- **Excluir Reserva:**

Exclui uma reserva do sistema.
- **Exibir Informações:**

Exibe informações gerais sobre o sistema, como número de passageiros, tripulantes, voos, etc.
- **Backup de Dados:**

Cria uma cópia de segurança dos dados em arquivos.
- **Restaurar Dados:**

Restaura os dados do sistema a partir de backups armazenados.
# Casos de Teste
- ** void testarCadastroPassageiros():** A função testarCadastroPasssageiros testa o cadastro de passageiros em um sistema, redirecionando a entrada padrão para ler dados de um arquivo e executando a função "cadastrarPassageiros" para adicionar passageiros a um array. Após verificar o número de passageiros cadastrados, ela imprime e valida os dados de cada cliente usando asserções.
- **void testarVoo():** A função "testarVoo" lê dados do voo de um arquivo "vooTeste.txt" e os cadastra em um array até atingir o limite "MAX_VOO". Para cada voo, são validados origem, data, hora, destino, codigo do aviao, codigo do piloto, codigo do copilo e status (1 = ativo / 0 = inativo) atribuindo um código sequencial. Caso a leitura dos dados falhe ou os dados sejam inválidos, uma mensagem de erro é exibida. Se não houver dados suficientes, voos já cadastrados são duplicados automaticamente para preencher o array. Ao final, a lista de funcionários cadastrados é impressa e verificada.




# Menu 
![Captura de tela 2024-12-13 141504](https://github.com/user-attachments/assets/0c17bdb7-f752-4d83-94e3-c4f5bc73ce54)


