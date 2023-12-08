#include <stdio.h>
#include <math.h>
/* Unesi n, a zatim n cijelih brojeva koji su poredani od manjeg prema veæem. Zatim unesi m pa m cijelih brojeva, za svakog od njih ispiši na kojem se mjestu 
nalazi u nizu (0-indeksirano), ako ga nema napiši "ne" */

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






