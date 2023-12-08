#include <stdio.h>

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
		t = search(x);
		if (t == -1) printf("ne\n");
		else printf("%d\n", t);
	}
	return 0;
}

int search (int x){
	int lowerBound, upperBound, i, middle;
	lowerBound = 0;
	upperBound = n - 1;
	while(lowerBound < upperBound){
		middle = (lowerBound + upperBound)/2;
		if (P[middle] >= x) upperBound = middle;
		else lowerBound = middle + 1;
	}
	if (P[lowerBound] == x) return lowerBound;
	return -1;
}






