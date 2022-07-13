#include <stdio.h>

//Busca Binaria (Vetor Ordenado)
int buscaBinaria (int *a, int n, int x) {
	int c= 0;
	int f = n -1;

	while (c <= f) {
		int m = (c + f) / 2;
		if (a[m] == x)
			return m;
		else if (a[m] < x)
			c = m + 1;
		else
			f = m - 1;
	}
	return -1
}

int buscaBin(int *a, int n, int x) {
	return buscaRec (a, 0, n - 1, x);
}

int buscaRec (int *a, int c, int f, int x) {
	if (c > f)
		return -1;
	
	int m = (c + f) / 2;
	if (a[m] == x)
		return m;
	else if (a[m] < x)
		return buscaRec (a, m + 1, f, x);
	else
		return buscaRec (a, c, m - 1, x);
}
