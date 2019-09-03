ADJACENTE = 1
NAO_ADJACENTE = 0

BRANCO = 0
CINZA = 1
PRETO = 2
NULO = -1

N = 0 #Quantidade de vértices

def DFS_VISIT(u,c,d,t,a,tempo):
  c[u] = CINZA
  tempo+=1
  d[u] = tempo

  for v in range(1,N+1):
    if(m[u][v] == ADJACENTE): #se v é adjacente a u
      if(c[v]==BRANCO):
        a[v] = u
        v,c,d,t,a,tempo=DFS_VISIT(v,c,d,t,a,tempo)

  c[u] = PRETO
  tempo+=1
  t[u] = tempo
  return [u,c,d,t,a,tempo]

def DFS():
  c,d,t,a = [],[],[],[]
  for u in range(0,N+1):
    c.append(BRANCO) #cor
    d.append(NULO) #tempo de descoberta
    t.append(NULO) #tempo de término
    a.append(NULO) #antecessor na árvore de busca

  tempo=0 #tempo corrente durante execução do algoritmo

  for u in range(1,N+1):
    if(c[u] == BRANCO):
      u,c,d,t,a,tempo=DFS_VISIT(u,c,d,t,a,tempo)

  return [c,d,t,a,tempo]

def imprimir(vet):
  for i in range(1,N+1):
    if(i==N):
      print(vet[i])
      break
    print(str(vet[i])+", ", end=" ")

#colunas vinculadas
def inicializar(N):
  m=[]
  for i in range(N+1):
    aux=[]
    for j in range(N+1):
      aux.append(0)
    m.append(aux)

  return m #matriz de adjacências

#main
N = 4
m=inicializar(N)

m[1][2] = ADJACENTE
m[2][3] = ADJACENTE
m[3][3] = ADJACENTE
m[3][1] = ADJACENTE
m[4][2] = ADJACENTE


c,d,t,a,tempo=DFS()
imprimir(c)
imprimir(d)
imprimir(t)
imprimir(a)