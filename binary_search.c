#include <stdio.h>
#include <math.h>
/* Enter n (1 <= n <= 10000), then an array of n integers sorted from smallest to largest. Then enter m (1 <= m <= 100000), followed by m integers. 
For each of the entered m numbers, print the position in the array (0-indexed) or "ne" (no) if it is not present. Use binary search for array search. */
/*Instead of searching an array element by element binary search looks for the value in the middle of an array and decides if the left or right half of the array is 
appropriate. In each iteration it redues size of the array by half. This approach results in O(n logn) time complexity. It is important to note that binary search
works only on pre-sorted arrays.*/

int n;
int P[10000];

int pretraga(int );

int main(){
	int i, m, t, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &P[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++){
		scanf("%d", &x);
		t = pretraga(x);
		if (t == -1) printf("ne\n");
		else printf("%d\n", t);
	}
	return 0;
}

int pretraga (int x){
	int donjaGranica, gornjaGranica, i, sredina;
	donjaGranica = 0;
	gornjaGranica = n - 1;
	while(donjaGranica < gornjaGranica){
		sredina = (donjaGranica + gornjaGranica)/2;
		if (P[sredina] >= x) gornjaGranica = sredina;
		else donjaGranica = sredina + 1;
	}
	if (P[donjaGranica] == x) return donjaGranica;
	return -1;
}






