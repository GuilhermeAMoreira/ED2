#include <stdio.h>
#include <stdlib.h>

void heapficador(int *a, int pai, int ult) {
	while (pai <= ult) {
		int fi = 2*pai + 1;
		if (fi <= ult) {
			if (fi + 1 <= ult && a[fi + 1] > a[fi]) {
				fi++;
			}
			if (a[pai] < a[fi]) {
				int tmp = a[pai];
				a[pai] = a[fi];
				a[fi] = tmp;
				pai = fi;
			} else {
				return;
			}
		} else {
			return;	
		}
	}
}

void heap (int *a, int n) {
	for (i = n / 2; i >= 0; i--) {
		heapficador(a, i, n - 1);	//transforma numa heap
	}

	for (int i = n - 1; i > 0; i--) {
		int tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		heapficador(a, 0, i - 1);
	}
}
