#include <stdio.h>
#include <string.h>

#define MAXV 2000 //quantidade máxima de vértices
#define ADJACENTE 1
#define NAO_ADJACENTE 0

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NULO -1

char m[MAXV + 1][MAXV +1]; //matriz de adjacências
int N; //quantidade de vértices
int c[MAXV+1]; //cor
int d[MAXV+1]; //tempo de descoberta
int t[MAXV+1]; //tempo de término
int a[MAXV+1]; //antecessor na árvore de busca
int tempo; //tempo corrente durante execução do algoritmo

void DFS_VISIT(int u){
	c[u] = CINZA;
	tempo++;
	d[u] = tempo;

	int v;
	for(v = 1; v <= N; v++){
		if(m[u][v] == ADJACENTE){ //se v é adjacente a u
			if(c[v]==BRANCO){
				a[v] = u;
				DFS_VISIT(v);
			}
		}
	}

	c[u] = PRETO;
	tempo++;
	t[u] = tempo;
}

void DFS(){
	int u;
	for(u = 1; u <= N; u++){
		c[u] = BRANCO;
		d[u] = NULO;
		t[u] = NULO;
		a[u] = NULO;
	}

	tempo=0;

	for(u = 1; u <= N; u++){
		if(c[u] == BRANCO)
			DFS_VISIT(u);
	}
}

void imprimir(int vet[]){
	int i;
	for(i = 1; i <= N; i++){
		printf("%d, ", vet[i]);
	}
	printf("\n");
}

void inicializar(){
	memset(m,NAO_ADJACENTE,sizeof(m));
}


int main(){

	inicializar();

	N=4;
	
	m[1][2] = ADJACENTE;
	m[2][3] = ADJACENTE;
	m[3][3] = ADJACENTE;
	m[3][1] = ADJACENTE;
	m[4][2] = ADJACENTE;

	DFS();
	imprimir(c);
	imprimir(d);
	imprimir(t);
	imprimir(a);

	return 0;
}