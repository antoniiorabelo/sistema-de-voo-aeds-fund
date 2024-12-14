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
- **void CadastrarPassageiros():** função alterarPassageiro
Descrição:
Permite editar as informações de um passageiro cadastrado, incluindo nome, endereço e telefone, identificando-o pelo código. Agora, a função valida nomes para aceitar apenas letras e espaços.

Etapas:

Solicita o código do passageiro e verifica sua existência.
Permite alterar o nome com validação (rejeita números e caracteres especiais).
Permite editar endereço e telefone.
Atualiza os dados no sistema e confirma a alteração.
Correção Realizada:
O problema que impedia a alteração do nome foi resolvido, e a validação de entrada foi implementada.

Mensagem de Erro:

"Nome inválido! Insira apenas letras e espaços."

Objetivo:
Garantir alterações consistentes e validadas nos dados dos passageiros.

- **void alterarPassageiro():** Função alterarPassageiro
Descrição:
Permite alterar os dados de um passageiro cadastrado, incluindo nome, endereço e telefone. Agora, a função realiza a validação do nome para aceitar apenas letras e espaços, rejeitando números ou caracteres especiais.

Principais Etapas:

Solicita o código do passageiro e verifica sua existência.
Permite a edição do nome com validação:
Aceita apenas letras e espaços.
Rejeita entradas inválidas e solicita novo nome.
Atualiza os demais dados (endereço e telefone) e salva no sistema.
Exibe confirmação de sucesso.
Correção Implementada:
Agora o nome do passageiro pode ser alterado corretamente, com validação para evitar inconsistências.

Mensagem de Erro para Nome Inválido:

"Nome inválido! Insira apenas letras e espaços."
# Menu 
![Captura de tela 2024-12-13 162521](https://github.com/user-attachments/assets/095133b7-199c-4a39-a433-22c05e9bd9b0)

# Metodos Ágeis 
Para a confecção de um ótimo trabalho pautado nas boas práticas da engenharia de software, utilizamos o Scrum e o Kanban

- **Scrum:** O framework Scrum, nos auxiliou a organizar o projeto em sprints de aproximadamente 5 dias, onde efetuamos as suas cerimônias criteriosamente. Planejávamos a sprint e definíamos qual seria o backlog da mesma. Realizávamos ¨daily's com durações aproximadas de 5 a 8 minutos. Ao final de cada sprint, revisávamos o que tinha sido concluído e entregue ao cliente e, por fim, revisávamos a maneira como trabalhamos para buscar melhorias no processo.
- **Kanban:** Utilizamos a funçao do Git Hub para criar um projeto para fazer o acompanhamento visual do projeto através do framework Kanban onde organizamos os requisitos, o backlog do produto, backlog da sprint e separavámos as tarefas da sprint no quadro To-do, Doing, Done.
# Evoluçao das Sprints
Abaixo é possível acompanhar a organização das sprints feita apartir do backlog feito no Github.
- **BackLog Geral**
![image](https://github.com/user-attachments/assets/d33431cf-ae50-494f-ba74-80153342109f)
- **Sprint 1**
![image](https://github.com/user-attachments/assets/20b219a6-bec1-4345-94c6-6360dba40e0d)
- **Sprint 2**
![image](https://github.com/user-attachments/assets/239c8e0d-8d6a-4f79-a34e-72927500868a)
- **Sprint 3**
![image](https://github.com/user-attachments/assets/7d97000d-0a89-48a6-942f-f52fcfd22377)
- **Sprint 4**
![image](https://github.com/user-attachments/assets/c4878b95-573f-4377-b906-11e4864be129)

# Relatorio de testes
Em anexo, temos tabelas que representam alguns dos relatórios de testes, neles é possível ver as entradas, classes válidas, classes inválidas e os resultados esperados.

![image](https://github.com/user-attachments/assets/e9738d07-5f38-4136-8e44-0dc9c5049262)

![image](https://github.com/user-attachments/assets/57182103-11d0-4c10-89a2-735276094eca)

![image](https://github.com/user-attachments/assets/6fdc2b4b-410b-44af-8229-2882adcae279)

# Vídeo Apresentando o Projeto.
<a href="C:\Users\Admin\OneDrive\Desktop\Aeds-Fundamentos\Site Aero.mp4"> Vídeo Aqui </a> <br>
