#include <stdio.h>
#include <string.h>

//Uma empresa de turismo deseja um programa que calcule o valor das viagens dos clientes. Serão informados os seguintes dados: código do cliente, nome, roteiro desejado(1-Brasil, 2-EUA, 3-África), tipo de quarto (1-Standard, 2-Luxo), Se deseja alugar carro(1-sim/0-nao) e a quantidade de dias. A quantidade de clientes é desconhecida. O programa irá calcular o total da viagem usando os valores da tabela abaixo, que variam de acordo com o roteiro escolhido. A diária do quarto de luxo é R$30 mais cara que o valor da diária em um quarto standard. Exemplo: Se a pessoa escolher roteiro 2, em quarto de luxo, a diária irá custar: 320 + 30 = R$ 350.

typedef struct {
	int codigo, roteiro, tipoDeQuarto, alugarCarro, quantosDias;
	char nome[20];
	float total;
} Cliente;

int main(void) {
	int novoCliente = 1;
	int cliCadast = 0;
	Cliente cliente[20];

	while (novoCliente == 1) {
		

		printf("\n                                                      Cadastro de Cliente\n\n");

		printf("Codigo: ");
		scanf("%d", &cliente[cliCadast].codigo);

		setbuf(stdin, 0);
		printf("Nome: ");
		fgets(cliente[cliCadast].nome, 20, stdin);
		cliente[cliCadast].nome[strcspn(cliente[cliCadast].nome, "\n")] = '\0';

		do {
			printf("Roteiro (1 - Brasil, 2 - EUA, 3 - África): ");
			scanf("%d", &cliente[cliCadast].roteiro);
			if (cliente[cliCadast].roteiro < 1 ||
				cliente[cliCadast].roteiro > 3) {
				printf("\nInforme um valor valido!\n");
			}
		} while (cliente[cliCadast].roteiro < 1 ||
				 cliente[cliCadast].roteiro > 3);

		do {
			printf("Tipo de Quarto (1 - Standard, 2 - Luxo): ");
			scanf("%d", &cliente[cliCadast].tipoDeQuarto);
			if (cliente[cliCadast].tipoDeQuarto < 1 ||
				cliente[cliCadast].tipoDeQuarto > 2) {
				printf("\nInforme um valor valido!\n");
			}
		} while (cliente[cliCadast].tipoDeQuarto < 1 ||
				 cliente[cliCadast].tipoDeQuarto > 2);

		do {
			printf("Alugar Carro (1 - sim / 0 - não )? ");
			scanf("%d", &cliente[cliCadast].alugarCarro);
			if (cliente[cliCadast].alugarCarro < 0 ||
				cliente[cliCadast].alugarCarro > 1) {
				printf("\nInforme um valor valido!\n");
			}
		} while (cliente[cliCadast].alugarCarro < 0 ||
				 cliente[cliCadast].alugarCarro > 1);

		do {
			printf("Quantidade de Dias: ");
			scanf("%d", &cliente[cliCadast].quantosDias);
			if (cliente[cliCadast].quantosDias < 1) {
				printf("\nA estadia deve ser acima de um dia!\n");
			}
		} while (cliente[cliCadast].quantosDias < 1);

		if (cliente[cliCadast].roteiro == 1) {
			if (cliente[cliCadast].tipoDeQuarto == 1) {
				cliente[cliCadast].total = 170 * cliente[cliCadast].quantosDias;
			} else {
				cliente[cliCadast].total =
					(170 + 30) * cliente[cliCadast].quantosDias;
			}
			if (cliente[cliCadast].alugarCarro == 1) {
				cliente[cliCadast].total += 50 * cliente[cliCadast].quantosDias;
			}
		} else if (cliente[cliCadast].roteiro == 2) {
			if (cliente[cliCadast].tipoDeQuarto == 1) {
				cliente[cliCadast].total = 350 * cliente[cliCadast].quantosDias;
			} else {
				cliente[cliCadast].total =
					(350 + 30) * cliente[cliCadast].quantosDias;
			}
			if (cliente[cliCadast].alugarCarro == 1) {
				cliente[cliCadast].total += 60 * cliente[cliCadast].quantosDias;
			}
		} else {
			if (cliente[cliCadast].tipoDeQuarto == 1) {
				cliente[cliCadast].total = 370 * cliente[cliCadast].quantosDias;
			} else {
				cliente[cliCadast].total =
					(370 + 30) * cliente[cliCadast].quantosDias;
			}
			if (cliente[cliCadast].alugarCarro == 1) {
				cliente[cliCadast].total += 75 * cliente[cliCadast].quantosDias;
			}
		}

		cliCadast++;

		printf("\nDeseja cadastrar outro cliente (1 - sim, 0 - nao)?: ");
		scanf("%d", &novoCliente);
	}

	printf("\n                                                        Relatorio Geral\n");
	printf("┌──────────┬───────────────────────────┬──────────┬─────────┬──────"
		   "──┬─────────┬───────────────┐\n");
	printf("│ Código   | Nome                      | Roteiro  | Quarto  | "
		   "Carro  | Dias    | Total         │");
	printf("\n├──────────┼───────────────────────────┼──────────┼─────────┼────"
		   "────┼─────────┼───────────────┤");
	for (int i = 0; i < cliCadast; i++) {
		printf(
			"\n│ %-8d │ %-25s │ %-8d │ %-7d │ %-6d │ %-7d │ %-10.2f    │",
			cliente[i].codigo,
			cliente[i].nome,
			cliente[i].roteiro,
			cliente[i].tipoDeQuarto,
			cliente[i].alugarCarro,
			cliente[i].quantosDias,
			cliente[i].total);
	}
  }