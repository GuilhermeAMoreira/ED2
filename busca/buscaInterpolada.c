#include <stdio.h>

//termos precisam ser aleatorios
int interpolacao (int *a, int n, int x) {	//O(log log n)
	int c = 0;
	int f = n - 1;
	while (c <= f) {
		if (a[f] == a[c]) {
			if (a[c] == x)
				return c;
			else
				return -1;
		}
		int m =  c + (x - a[c]) * (f - c) / (a[f] - a[c]);
		// A = x - a[c]
		// B = a[f] - a[c]
		// C = m - c
		// D = f - c
		// A / B = C / D
		// A / B = ( m - c) / D
		// A * D / B = m - c
		// m = c + A * D / B
		if (a[m] == x)
			return m;
		else if (a[m] < x)
			c = m + 1;
		else
			f = m - 1;
	}
	return -1;
}
