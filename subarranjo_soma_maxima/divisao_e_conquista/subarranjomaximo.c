/*
Implementação do Subarranjo de Soma Máxima (Maximum Subarray Problem) utilizando o paradigma de divisão e conquista.
Autor: Talles Brito Viana

Implementação de acordo com o algoritmo descrito em:
CORMEN, T. H. et.al. Algoritmos: Teoria e Prática, 3º edição. Ed. Elsevier, 2012.

Por se tratar de um algoritmo de divisão e conquista a complexidade é O(N*lg N), tal que N é o tamanho do arranjo de entrada.
*/

#include <stdio.h>
#include <limits.h>

typedef struct subarranjo{
  int esq;
  int dir;
  int soma;
}SubArranjo;

SubArranjo CRUZAMENTO_MAXIMO(int A[], int baixo, int meio, int alto){
  int soma_esq,soma_dir,soma;
  int i,j,max_esq,max_dir;
  
  soma_esq = INT_MIN;
  soma=0;
  for(i=meio;i>=baixo;i--){
    soma = soma + A[i];
    if(soma > soma_esq){
      soma_esq = soma;
      max_esq = i;
    }
  }

  soma_dir = INT_MIN;
  soma = 0;
  for(j=meio+1; j<=alto; j++){
    soma = soma + A[j];
    if(soma > soma_dir){
      soma_dir = soma;
      max_dir = j;
    }
  }

  SubArranjo sub = {max_esq, max_dir, soma_esq + soma_dir};
  return sub;
}

SubArranjo SUBARRANJO_MAXIMO(int A[], int baixo, int alto){
  if(alto==baixo){
    SubArranjo sub = {baixo, alto, A[baixo]};
    return sub;
  }else{
    int meio;
    meio = (alto + baixo)/2;

    SubArranjo subEsq, subDir, subCrz;
    subEsq = SUBARRANJO_MAXIMO(A,baixo,meio);
    subDir = SUBARRANJO_MAXIMO(A,meio+1,alto);
    subCrz = CRUZAMENTO_MAXIMO(A,baixo,meio,alto);

    if(subEsq.soma >= subDir.soma && subEsq.soma >= subCrz.soma){
      return subEsq;
    }else if(subDir.soma >= subEsq.soma && subDir.soma >= subCrz.soma){
      return subDir; 
    }else{
      return subCrz;
    }
  }
}
 
int main(){

  int N,i;
  scanf("%d",&N);
  int V[N];

  for(i=0;i<N;i++){
    scanf("%d",&V[i]);
  }

  SubArranjo sub;
  sub = SUBARRANJO_MAXIMO(V,0,N-1);

  for(i=sub.esq; i<=sub.dir; i++){
  	printf("%d ", V[i]);
  }
  printf("\nSoma total: %d\n",sub.soma);

}