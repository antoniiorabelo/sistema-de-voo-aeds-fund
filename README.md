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
#Funções Ultilizadas



# Menu 
![Captura de tela 2024-12-13 141504](https://github.com/user-attachments/assets/0c17bdb7-f752-4d83-94e3-c4f5bc73ce54)


