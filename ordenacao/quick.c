#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void destruit(int *a) {
	free(a);
}

void _quick(int *a, int c, int f, int profundidade) {
	if (c >= f)
		return;

	int m = (c + f) / 2;
	//int m = c + ((rand() % (f - c + 1));
	int pivot = a[m];

	int i = c;
	int j = f;
	while (1) {
		while (a[i] < pivot) {
			i++;
		}
		//a[i] <= pivot
		while (a[j] > pivot) {
			j--;
		}
		//a[j] <= pivot
		if (j <= i) {
			break;
		}
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		i++;
		j--;
	}
	_quick(a, c, j, profundidade + 1);
	_quick(a, j + 1, f, profundidade + 1);
}

void quick(int *a, int c) {
	_quick(a, 0, n - 1, 0);
}
