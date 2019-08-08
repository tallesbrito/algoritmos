#include <stdio.h>
#include <string.h>

#define MAXV 2000 //tamanho do grid
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

	return 0;
}