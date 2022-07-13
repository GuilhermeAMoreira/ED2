#include <stdio.h>

int simples (int *a, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x)
			return i;
	}
	return -1;
}

// vetor nao ordenadp
int comSentinela (int *a, int n, int x) {
	a[n] = x;

	int i = 0;
	while (1) {
		if (a[i] == x)
			break;
		i++;
	}
	if (i < n)
		return i;
	return -1;
}

//vetor nao ordenado
int ordSemSentinela (int *a, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] >= x) {
			if (a[i] == x)
				return i;
			else
				return -1;
		}
	}
	return -1
}

//vetor ordenado
int ordComSentinela (int *a, int n, int x) {
	if (a[n - 1] < x)
		return -1;
	
	int i = 0;
	while (1) {
		if (a[i] >= x) {
			if (a[i] == x)
				return i;
			return -1;
		}
		i++;
	}
	return -1;		//tecnicamente nao precisa, nunca chega aqui
}
