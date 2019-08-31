/*
Implementação da Busca em Profundidade (DFS) com Listas de Adjacência.
Autor: Talles Brito Viana

Implementação de acordo com o algoritmo descrito em:
CORMEN, T. H. et.al. Algoritmos: Teoria e Prática, 3º edição. Ed. Elsevier, 2012.

A variável 'N' define a quantidade de vértices do grafo.

O vetor 'l' é um vetor de listas.

Caso você deseje utilizar um grafo ponderado, é necessário alterar o tipo do vetor de listas 'l' para vector<pair<int,int> >. Neste caso, cada elemento da lista tem um par, o primeiro valor de um par (o identificador do vértice adjacente) é acessado através de .first, já o segundo (o peso da aresta que permite chegar no adjacente) através de .second. Para criar um novo par utilize a função make_pair(int,int). Não esqueça de adicionar #include <utility> no cabeçalho do programa. Além disso, você deve alterar a função DFS-VISIT para que a mesma trate os pares ao percorrer as listas.

Supondo que M é a quantidade de arestas do grafo então a complexidade da busca é dada por O(N + M).
*/


#include <stdio.h>
#include <vector>
using namespace std;

#define MAXV 2000 //quantidade máxima de vértices

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NULO -1

vector<int> l[MAXV + 1]; //lista de adjacências
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

	int i,v;
	for(int v: l[u]){ //percorre cada elemento da lista l[u]
		if(c[v]==BRANCO){
			a[v] = u;
			DFS_VISIT(v);
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
	int u;
	for(u = 0; u <= MAXV; u++){
		l[u] = vector<int>(); //cria uma lista vazia para cada vértice u
	}
}

int main(){

	inicializar();

	N=4;
	
	//l[u].pushback(v) torna v adjacente a u
	l[1].push_back(2);
	l[2].push_back(3);
	l[3].push_back(3);
	l[3].push_back(1);
	l[4].push_back(2);

	DFS();
	imprimir(c);
	imprimir(d);
	imprimir(t);
	imprimir(a);

	return 0;
}