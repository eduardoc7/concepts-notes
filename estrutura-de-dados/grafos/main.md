# Aprendendo a teoria dos Grafos
História, teoria, exemplos, definições, aplicações

---
## Como surgiu e por que surgiu?
Grafos surgiu no início do século XVII, com o objetivo de resolver um questionamento que os cidadãos da cidade de Königsberg não eram capazes de entender. Essa cidade é constituída por quatro áreas de terra separadas pelo Rio Pregel, sobre o qual há sete pontes. O problema que os cidadãos se encabularam era caminhar ao redor da cidade, cruzando cada uma das sete pontes apenas uma vez e se possível, retornar ao seu ponto de partida.

Em meio a tanta curiosidade humana sedenta por conhecimento, o prefeito da cidade soube que um renomado matemático estava próximo da cidade e decidiu enviar uma carta ao Leonhard Euler (1707-1783). 
Diante dessa questão banal sem explicação, Euler ficou interessado em tentar explicar essa impossibilidade de maneira lógica.

Euler, sistematizou um novo campo da matemática, era o surgimento da Teoria dos Grafos. O matemático não precisou de uma quinzena de dias para resolver o enigma. Para isso, ele criou um modelo matemático que simulasse a cidade russa, que é hoje o que chamamos de grafo.

<p align="center">
    <img alt="Clean Architecture Concept" width="400px" src="https://www.universoracionalista.org/wp-content/uploads/2016/03/untitled-infographic_block_2.jpg" />   
</p>

---
## O que é um grafo?
Por definição um grafo é um conjunto de vértices (ou nós) e arestas (ou arcos), em que cada aresta conecta dois vértices.

    - Vértices: Podem ser representados por pontos.
    - Arestas: Podem ser representadas por linhas que ligam os pontos.
    - Grafo: É um par de conjuntos, onde: G = (V, A). V é o conjunto de vértices e A é o conjunto de arestas.
    - Vértices Adjacentes: Quando uma aresta X está ligando o vértice Y no Z. Y e Z são adjacentes. E também a aresta é Incidente aos vértices Y e Z.
    - Grau do vértice: Número de arestas que incidem sobre o vértice v, simbolizado por d(v).

---
## Onde grafos são usados?
 - Transporte aéreo (Vértices: cidades, Arestas: vôo comercial entre duas cidades)
 - Robustez da malha elétrica (Vértices: torres de transmissão, Arestas: linhas entre torres)
 - Internet (Vértices: Hosts, Arestas: Conexões)
 - Logística (Vértices: Destinos, Arestas: Rotas)

---

## Referências
[Curso do Prof. Douglas Maioli](https://www.youtube.com/watch?v=T6yKp82k9vM&list=PLrOyM49ctTx-xtyVeuO7ylclgXHd4ws9a)

[Repositório da IFES](https://repositorio.ifes.edu.br/bitstream/handle/123456789/73/PRODUTO_Constru%C3%A7%C3%A3o_utiliza%C3%A7%C3%A3o_maquete_eletr%C3%B4nica_ensino_grafos.pdf?sequence=5&isAllowed=y)