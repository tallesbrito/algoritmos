#include <stdio.h>

void COUNTING_SORT(int A[], int n, int k) { 
  int C[k+1];
  int B[n];
  int i,j;
  for(i=0;i<=k;i++) C[i] = 0;
  for(j=0;j<n;j++) C[A[j]] = C[A[j]] + 1;
  for(i=1;i<=k;i++) C[i] = C[i] + C[i-1];
  for(j=n-1;j>=0;j--){
  	B[C[A[j]]-1] = A[j];
  	C[A[j]] = C[A[j]] - 1;
  }
  for(j=0;j<n;j++) A[j] = B[j];
}


int main(){

  int N=8;
  int K=5;
  int vet[] = {2,5,3,0,2,3,0,3};

  COUNTING_SORT(vet,N,K);
  
  int i;
  for(i=0;i<N;i++)
    printf("%d ", vet[i]);

  printf("\n");

  return 0;
}