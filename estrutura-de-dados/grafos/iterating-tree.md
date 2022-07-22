# Aprendendo a percorrer em árvores binárias
Exemplos, definições, aplicações.

---
## Por que percorrer árvores binárias?
Para o programa de computador saber o que há nessa estrutura, podemos utilizar métodos para percorrer e lidar com os valores dos nós. Dessa forma, acessando os dados ou fazendo alguma operação. Para isso, é necessário criar um percurso sistemático que visite todos os nós. Entre os mais comuns temos:
    - Pré-Ordem
    - Ordem (simétrica)
    - Pós-Ordem


---
## Pré-Ordem 
De maneira prática, visita um nó `x` e após isso, visita seus descendentes. (esquerda, depois direita).

### Algoritmo de Pré-Ordem
Esse algoritmo basicamente percorrerá todos os nós da esquerda, depois da direita.

```
PreOrdem(struct Arvore p) {
    if (p!= null) {
        printf(p)
        PreOrdem(p.esquerda)
        PreOrdem(p.direita)
    }
}
```

---
## Ordem (Simétrica)
Este quando chega no nó, visitará primeiro os descendentes da esquerda, depois o nó raiz e depois o nó da direita.

### Algoritmo de Ordem
Esse algoritmo basicamente percorrerá todos os nós da esquerda, depois da direita.

```
Ordem(struct Arvore p) {
    if (p!= null) {
        Ordem(p.esquerda)
        printf(p)
        Ordem(p.direita)
    }
}
```

---
## Pós-Ordem (Simétrica)
Este só visitará um nó, depois de percorrer todos os seus descendentes (esquerda e direita)

### Algoritmo de Pós-Ordem
Esse algoritmo basicamente percorrerá todos os nós da esquerda, depois da direita.

```
PosOrdem(struct Arvore p) {
    if (p!= null) {
        PosOrdem(p.esquerda)
        PosOrdem(p.direita)
        printf(p)
    }
}
```
---
