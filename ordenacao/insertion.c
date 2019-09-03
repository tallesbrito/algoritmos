#include <stdio.h>

void INSERTION_SORT(int A[], int n) { 
  int i, j, chave;
  for (i = 1; i < n; i++){   
     chave = A[i];
     j = i-1;

     while (j>=0 && A[j]>chave){
        A[j+1] = A[j];
        j--;       
     }
     
     A[j+1] = chave;
  }
}


int main(){

  int vet[] = {50,40,20,30,10};

  INSERTION_SORT(vet,5);

  int i;
  for(i=0;i<5;i++)
    printf("%d ", vet[i]);

  printf("\n");

  return 0;
}