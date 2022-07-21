# Aprendendo a teoria das Árvores
História, teoria, exemplos, definições, aplicações

---

## O que é uma árvore em estrutura de dados?
Podemos definir uma árvore sendo um tipo específico de grafo. No qual, é conexo e sem ciclos (acíclico), com um vértice (nó) especial, chamado de raiz.
    - **Acíclico:** Ocorre quando não há ciclos entre os vértices. Em todos os caminhos, nenhum voltará para o mesmo ponto raiz ou anterior.
    - **Conexo:** Quando conseguimos conectar, fazer caminhos entre vértices.

---
## Árvore Livre
Acontece quando temos uma estrutura conexa e acíclica sem uma raiz especificada. Isso torna a possibilidade de montarmos a estrutura usando qualquer um dos nós como raiz.

---
## Floresta
É definido como um grafo em que seus componentes conexas são árvores. Ou seja, uma estrutura com várias árvores conectadas.

__

## Onde Árvores são usadas?
    - Estruturas de diretórios. Exemplo: Pasta raiz -> Sistema -> Exec
    - Orgonograma de empresas.
    - Para representar possbilidades de jogadas em jogos.
    - Interfaces gráficas.
    - Bancos de dados.

---

## O que é importante saber nessa estrutura?
Dado um nó `x` de uma árvore com raiz `r`. Temos:

    - Ancestral: Qualquer nó `y` no caminho de `r` a `x`.
    - Descendente: `x` é um descendente de `y` se `y` é um ancestral de `x`. 
    Todo nó conectado a `y` que se encontra abaixo.
    - Filho: `x` é um filho de `y` se ele é um descendente direto. Descendente direto é quando é o nó conectado mais próximo, com um grau 1.
    - Pai: É o nó mais próximo acima. Sendo a raiz o único nó sem pai.
    - Folha: É um nó sem filhos.

---

## O que é uma Árvore Binária?
Uma árvore em que cada nó internop tem no máximo dois filhos é denominado de `Árvore Binária`.

### Árvore Binária Cheia
É denominada quando a todas as folhas da árvore estão na mesma profundidade e todos os nós internos tem grau 2.
Seguindo a fórmula:
    - O número de vértices em uma árvore binária cheia é `2` elevado a `h+1`, onde h é a altura da árvore.
    - Uma árvore com `n` vértices tem `n-1` arestas.
    - Em uma árvore com `n` vértices, o número total de extremidades de arestas é `2n-2`.
---