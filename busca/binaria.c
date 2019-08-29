#include <stdio.h>

int busca_binaria(int A[],int n, int x){
	int p,r,q;
	p=0;
	r=n-1;
	while(p<=r){
		q=(p+r)/2;
		if(A[q]==x){
			return q;
		}else if(x<A[q]){
			r=q-1;
		}else{
			p=q+1;
		}
	}
	return -1;
}

int main(){
	
	int vet[10]={1,3,7,10,21,33,44,70,100,1000};

	printf("%d\n", busca_binaria(vet,10,70));
	printf("%d\n", busca_binaria(vet,10,7));
	printf("%d\n", busca_binaria(vet,10,1));
	printf("%d\n", busca_binaria(vet,10,1000));
	printf("%d\n", busca_binaria(vet,10,9999));

	return 0;
}