# Clean Architecture

## O que é?
Clean Architecture é uma arquitetura de software proposta por Robert Cecil Martin (ou Uncle Bob, como é mais conhecido) que tem por objetivo padronizar e organizar o código desenvolvido, favorecer a sua reusabilidade, assim como independência de tecnologia.

Por mais que a Clean Architecture foi criada em meados de 2012, está repleta de princípios atemporais que podem ser aplicados independente da tecnologia utilizada e linguagem de programação.

---

## Qual o seu principal objetivo?
De forma rudimentar, podemos definir isso em dois tópicos: 
    
    - Tornar o código de um projeto o mais manutenível possível
    - Permitir que todas as pequenas partes do código sejam testáveis
---

## O que isso nos proporciona?
Isso permite várias vantagens que aumentam o valor de um Software:

    - Robustez
    - Escalabilidade
    - Flexível
    - Tolerante a mudanças
    - Facilita a evolução e manutenção do sistema
    - Devido ser uma arquitetura centrada no domínio, o Clean Architecture trabalha bem com DDD, onde o seu acoplamento direcionado preza que o núcleo não dependa de nada, de forma a conseguirmos inclusive testá-lo isoladamente.
---

## Características que tornam isso possível
    - Arquitetura FOCADA nas regras de negócio: suas regras não devem conhecer o "mundo lá fora" (Frameworks, Ferramentas, Tecnologias, etc).
    - Inversão de dependências: Por exemplo, seu banco de dados deve depender das suas regras, e não suas regras do seu banco. Sua UI? Mesma coisa!
    - A melhor decisão é a que você pode tomar depois? Isso não é preguiça, é arquitetura incremental.
    - Regras de negócio devem ser 100% TESTÁVEIS e INDEPENDENTES!
---

## Muito mais do que camadas
Dentre as principais regras do Clean Architecture, devemos ter maior atenção ao fato que `podemos mover as dependências apenas dos níveis externos para os internos`, conforme as setas apresentadas na clássica imagem abaixo.

Com isso, os códigos nas camadas internas não precisam ter conhecimento necessariamente das funções nas camadas externas. Os níveis mais internos não podem mencionar as variáveis, funções e classes que existem nas camadas externas.

<p align="center">
    <img alt="Clean Architecture Concept" width="400px" src="https://github.com/eduardoc7/concepts-notes/blob/0d825b7c18d0554cf5ebd864bf5aa52b8d106a9b/clean-arch/assets/images/CleanArchitecture.png" />   
</p>

---

## Por que separar em camadas?
Partindo do princípio de que esta regra de dependência está sendo bem aplicada, esta separação de camadas visa nos `poupar de problemas futuros com a manutenção do software`. Deixando, inclusive, o `sistema completamente testável`, pois as regras de negócios podem ser validadas sem a necessidade da interface do usuário, banco de dados, servidor ou qualquer outro elemento externo. 

Outro ponto de extrema relevância, por ser uma arquitetura de software amplamente independente, é que a princípio conseguimos fazer a substituição da interface do usuário sem que isso reflita no resto do sistema. 

Assim como podemos trocar o banco de dados, por exemplo, de Oracle ou SQL Server, por Mongo, DynamoDB ou qualquer outro, pois suas regras de negócios não estão vinculadas ao banco de dados, nos facilitando a troca destes componentes caso tenham se tornado obsoletos ou por qualquer outra necessidade de negócio/técnica sem encontrar maiores dificuldades.

---

## Infraestrutura 
Para facilitar o nosso entendimento, vamos reduzir o escopo do desenho apresentado pelo Uncle Bob em seu blog. Assim, isolamos o nosso entendimento sobre cada parte da arquitetura, dividindo em duas camadas de alto nível, separando a `camada de domínio` contendo toda a lógica de negócio, da nossa `camada de infraestrutura`, contendo as tecnologias utilizadas no projeto.

### Camada de domínio
O núcleo deve ser responsável pela razão do software existir, ou seja, o domínio entrega a identidade do seu aplicativo. Através da lógica central do negócio contida nele, devido a sua importância, alterações nesta camada, faz com que provavelmente modifique a essência do software.

### Camada de Infraestrutura
Como podemos perceber, a ideia principal neste tipo de arquitetura é proteger o domínio, tornando inclusive mais simples a troca de algum componente de infraestrutura caso se torne necessário. Afinal, a responsabilidade de como seu software se comunica com o mundo externo, fica para a camada de infraestrutura, que com base na especificidade do software, abre a comunicação a humanos, através de uma interface visual, por exemplo, ou comunicação a um banco de dados, filas e até mesmo integração com outras APIs.

---

## Aprofundando nas camadas
Agora que conhecemos a divisão de papéis entre as camadas de domínio e Infraestrutura, estamos aptos a aumentar o escopo. 

### Interface Adapters
Apesar de estar fora da camada de domínio, são os serviços intermediários na comunicação com o mundo exterior. Devido a esta sua responsabilidade, podemos considerá-la como uma subcamada dentro da infraestrutura.

#### `Responsabilidades`
    
    - Conversão de dados
    - Tratamento de erros
    - Validação de regras sintáticas (por exemplo, formato de data invalido ou envio de texto em campo do tipo numérico)

Ponto de atenção. Por estar muito próximo da camada de domínio, devemos ter cuidado para nunca implementarmos uma lógica de negócios em adaptadores, pois eles são apenas “tradutores de linguagem”.

### Entities
Agora iremos aumentar o zoom na camada de domínio. Vamos começar pelo núcleo, ali temos as Entidades ou Entities, sendo que não podemos considerar como uma camada de software, pois a separação contida no diagrama de Uncle Bob, apenas nos demonstra que as entidades não dependem de absolutamente nada. As Entities representam os nossos objetos de negócios.

Podemos definir então, esta uma camada que encapsula as entidades e regras de negócio. O principal entendimento aqui é que essa camada deve conter tudo que seja pertinente ao sistema como um todo de uma maneira mais genérica, ou seja, deve conter as regras que tenham menos possibilidades de mudança quando algo externo mudar, como algo na interface do usuário.

### Use Cases
Na camada vizinha, temos Casos de Uso ou Use Cases, trazendo em seus códigos as funcionalidades mapeadas nas histórias de usuário, onde implementamos as regras de negócio, com suas específicas particularidades. Conforme a necessidade, um caso de uso lida com uma ou mais entidades, interagindo com um ou mais adaptadores ao realizar o seu trabalho.

Essa camada é a que contém as regras de negócios mais específicas do sistema. É aqui que todos os casos de uso do sistema são implementados. É esperado que apenas mudanças de requisitos afetem essa camada, sendo que assim como na Entities, alterações nas camadas externas não devem afetar essa camada. (sugestão: essa camada. No entanto, assim como na Entities, alterações…)

---



## Referências
[Uncle Bob Blog](https://blog.cleancoder.com/uncle-bob/2012/08/13/the-clean-architecture.html)

Clean Architecture: A Craftsman's Guide to Software Structure - Book by Robert Cecil Martin