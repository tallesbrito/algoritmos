#include <stdio.h>

int partition(int A[],int p,int r){
	int u,q,aux;
	q=p;
	for(u=p; u<=r-1; u++){
		if(A[u]<=A[r]){
			aux = A[u];
			A[u] = A[q];
			A[q] = aux;
			q++;
		}
	}
	aux = A[q];
	A[q] = A[r];
	A[r] = aux;
	return q;
}

void quicksort(int A[],int p,int r){
	if(p>=r){
		return;
	}else{
		int q;
		q = partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}


int main(){

	int vet[]={12,7,14,9,10,11};

	quicksort(vet,0,5);

	int i;
	for(i=0;i<6;i++){
		printf("%d ", vet[i]);
	}
}