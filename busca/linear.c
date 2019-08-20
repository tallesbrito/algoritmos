#include <stdio.h>

int BUSCA_LINEAR(int A[],int n,int x){
	int i;
	for(i=0;i<n;i++){
		if(A[i]==x){
			return i;
		}
	}

	return -1;
}

int main(){
	
	int vet[5] = {23,45,12,34,11};

	int posicao = BUSCA_LINEAR(vet,5,34);

	printf("%d\n", posicao);

	return 0;
}