/*
Implementação da Busca em Profundidade (DFS) em um GRID de tamanho N X N.
Autor: Talles Brito Viana

Implementação de acordo com o algoritmo descrito em:
CORMEN, T. H. et.al. Algoritmos: Teoria e Prática, 3º edição. Ed. Elsevier, 2012.

Trata-se de um GRID de caracteres: caso deseje um grid de inteiros você deve alterar o tipo da matriz 'm'.

Os tipos de movimentos são ajustados através da constante QTD_MOVIMENTOS e da matriz 'movimentos'.

A complexidade da busca é O(Nˆ2 + QTD_MOVIMENTOS), como QTD_MOVIMENTOS é uma constante então podemos dizer que a complexidade da busca  é O(Nˆ2).
*/

#include <stdio.h>
#include <string.h>

#define MAXV 2000 //tamanho máximo do grid
#define QTD_MOVIMENTOS 4 //quantidade de movimentos

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NULO -1

char m[MAXV][MAXV]; //dados do grid
int N; //tamanho do grid
int c[MAXV][MAXV]; //cor
int d[MAXV][MAXV]; //tempo de descoberta
int t[MAXV][MAXV]; //tempo de término
int a[MAXV][MAXV][2]; //coordenadas x:[0] e y:[1] do antecessor
int tempo; //tempo corrente durante execução do algoritmo

int movimentos[QTD_MOVIMENTOS][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int adjacenteX(int mov,int i){
	return i + movimentos[mov][0];
}

int adjacenteY(int mov,int j){
	return j + movimentos[mov][1];
}

int valido(int x, int y){
	//posições com * e fora da matriz são IGNORADAS!
	if(x>=0 && x<N && y>=0 && y<N && m[x][y]!='*'){
		return 1;
	}else{
		return 0;
	}
}

void DFS_VISIT(int i, int j){
	c[i][j] = CINZA;
	tempo++;
	d[i][j] = tempo;

	int mov;
	for(mov = 0; mov < QTD_MOVIMENTOS; mov++){

		int x = adjacenteX(mov,i);
		int y = adjacenteY(mov,j);
		if(valido(x,y)){ //se o movimento é válido
			if(c[x][y]==BRANCO){
				a[x][y][0] = i; //coordenada x do antecessor
				a[x][y][1] = j; //coordenada y do antecessor
				DFS_VISIT(x,y);
			}
		}
	}

	c[i][j] = PRETO;
	tempo++;
	t[i][j] = tempo;
}

void DFS(){
	int i,j;
	for(i = 0; i < N; i++){
	  for(j = 0; j < N; j++){
			c[i][j] = BRANCO;
			d[i][j] = NULO;
			t[i][j] = NULO;
			a[i][j][0] = NULO;
			a[i][j][1] = NULO;
		}
	}

	tempo=0;

	for(i = 0; i < N; i++){
	  for(j = 0; j < N; j++){
			if(c[i][j] == BRANCO && m[i][j]!='*') //posições com * são IGNORADAS!
				DFS_VISIT(i,j);
		}
	}
}

void imprimir(int mat[][MAXV]){
	int i,j;
	for(i = 0; i < N; i++){
	  for(j = 0; j < N; j++){
		printf("%3d ", mat[i][j]);
	  }
	 printf("\n");
	}
	printf("\n");
}

void imprimirCoordenadas(int mat[][MAXV][2]){
	int i,j;
	for(i = 0; i < N; i++){
	  for(j = 0; j < N; j++){
		printf("(%2d,%2d) ", mat[i][j][0],mat[i][j][1]);
	  }
	 printf("\n");
	}
	printf("\n");
}


int main(){

	scanf("%d",&N);
	int i,j;
	for(i = 0; i < N; i++)
	  for(j = 0; j < N; j++)
	  		scanf(" %c",&m[i][j]);

	DFS();
	imprimir(c);
	imprimir(d);
	imprimir(t);
	imprimirCoordenadas(a);

	return 0;
}