BRANCO = 0
CINZA = 1
PRETO = 2
NULO = -1

def DFS_VISIT(u,c,d,t,a,tempo):
  c[u] = CINZA
  tempo+=1
  d[u] = tempo

  for v in l[u]: #percorre cada elemento da lista l[u]
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
    c.append(BRANCO) 
    d.append(NULO) 
    t.append(NULO) 
    a.append(NULO)

  tempo=0

  for u in range(1,N+1):
    if(c[u] == BRANCO):
      u,c,d,t,a,tempo=DFS_VISIT(u,c,d,t,a,tempo)

  return [c,d,t,a,tempo]


def imprimir(lista):
  for i in range(1,N+1):
    if(i==N):
      print(lista[i])
      break
    print(str(lista[i])+", ", end=" ")

def inicializar(N):
  l=[]
  for i in range(N+1):
    l.append([])
  return l

#main
N=4
l=inicializar(N)

#l[u].append(v) torna v adjacente a u
l[1].append(2)
l[2].append(3)
l[3].append(3)
l[3].append(1)
l[4].append(2)

c,d,t,a,tempo=DFS()
imprimir(c)
imprimir(d)
imprimir(t)
imprimir(a)