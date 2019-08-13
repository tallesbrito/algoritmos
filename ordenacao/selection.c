#include <stdio.h>

void selection_sort(int A[], int n) { 
  int i, j, menor, aux;
  for (i = 0; i < n-1; i++) 
  {
     menor = i;
     for (j = i+1; j < n; j++) {
       if(A[j] < A[menor]) 
         menor = j;
     }
     
     aux = A[i];
     A[i] = A[menor];
     A[menor] = aux;
  }
}


int main(){

  int vet[] = {50,40,20,30,10};

  selection_sort(vet,5);

  int i;
  for(i=0;i<5;i++)
    printf("%d ", vet[i]);

  printf("\n");

  return 0;
}