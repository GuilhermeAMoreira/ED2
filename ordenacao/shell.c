#include <stdio.h>
#include <stdlib.h>

void shell (int *a, int n) {
	int gap = 1;		//arbitrario
	while (gap < n) {	//
		gap *= 2;		//escolher um gap bom
	}					//O(logn)

	while (gap > 0) {
		for (int i = 0; i < n; i++) {
    		int x = a[i];
        	int j = i - gap;
        	while (j >= 0 && a[j] > x) {
        		a[j + gap] = a[j];
        	    j -= gap;
        	}
        	a[j + gap] = x;
		}
		gap /= 2;
	}
}
