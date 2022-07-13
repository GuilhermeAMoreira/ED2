#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int kindex[20];
	int posicao;
} hash

unsigned h_div(unsigned x, unsigned i, unsigned B) {
	return ((x % B) + 1) % B;
}

unsigned h_mul(unsigned x, unsigned i, unsigned tam) {
	const double A = 0.6180;
	return ((int) ((fmod(x * A, 1) * B) + i)) % B;
}

hash *criaTabela (int B) {
	hash *tabela = malloc(sizeof(hash) * B);
	if (tabela == NULL)
		exit(-1);
	for (int i = 0; i < B; i++) {	//
		tabela[i].kindex = 0;		//preenche todos os elementos com zeros
	}								//
	return tabela;
}

int inserirDiv (hash *tabela, int new, int B) {
	int colisoes = 0;
	unsigned pos;
	for (int i = 0; i < B; i++) {
		pos = h_div(new, i, B);
	
		if (tabela[pos].dados == 0) {
			tabela[pos].dados = new;
			return colisoes;
		} 
		if (tabela[pos].dados == new) {
			return colisoes;	
		}
		colisoes = 1;
	}
	return colisoes;
}

int buscaDiv (hash *tabela, int x, int B) {
	unsigned pos;
	for (int i = 0; i < b; i++) {
		pos = h_div(x, i, B);
		
		if (tabela[pos].dados == x)
			return 1; //encontrado
		if (tabela[pos].dados == 0)
			return 0; //nao esta na lista, mas pode ser colocado
	}
	return -1; //lista cheia
}

int inserirMult (hash *tabela, int new, int B) {
	int colisoes = 0;
	unsigned pos;
	for (int i = 0; i < B; i++) {
		pos = h_mul(new, i, B);

		if (tabela[pos].dados == 0) {
			tabela[pos].dados = new;
			return colisoes;
		}
		if (tabela[pos].dados == new) {
			return colisoes;
		}
		colisoes = 1;
	}
	return colisoes;
}

int buscaMult (hash *tabela, int x, int B) {
	unsigned pos;
	for (int i = 0; i <B; i++) {
		pos = h_mul (x, i, B);

		if (tabela[pos].dados == x)
			return 1;	//achou
		if (tabela[pos].dados == 0)
			return 0; //nao esta na lista, mas pode ser colocado
	}
	return -1; //lista cheia
}
