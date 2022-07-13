#include <stdio.h>
#include <stdlib.h>

void insertion (int *a, int n) {
	for (int i = 0; i < n; i++) {
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
