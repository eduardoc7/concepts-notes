# Usando a Clean Architecture no mundo real

Para facilitarmos o entendimento, criamos um exemplo bem simples de um sistema escolar, no qual vamos cadastrar novas turmas. A estrutura base do projeto foi divida nas camadas: Core, Entities, UseCases e Web, conforme nos mostra a imagem abaixo:
<p align="center">
    <img alt="Clean Architecture Concept" width="400px" src="https://raw.githubusercontent.com/eduardoc7/concepts-notes/main/web/clean-arch/assets/images/clean-arch-example.png" />   
</p>

---

## Camada Core

 - Maior nível de abstração da nossa arquitetura, ou seja, a camada que possuí a regra de negócio definida.
 - Essa camada possui apenas um repositório padrão (IRepository), um interactor que vai receber uma entrada e nos devolver uma resposta (IInteraction) e uma entidade que possui as propriedades que serão utilizadas por todas as classes (IEntity).
 - Outra coisa interessante nessa camada é que ela contém todos os pacotes que serão utilizados pelas outras camadas, já que, conforme dito anteriormente, as dependências são de “fora para dentro”.

--- 

## Camada Entities
 - Temos as Classes que de fato compõem o sistema – observe que ela conhece a camada Core, uma vez que ela é menos abstrata.

---

## Camada Use Cases
 - Possuímos todas as nossas regras de negócio.
 - Observe que temos apenas três arquivos para a entidade Turma, sendo um arquivo de Input que vai receber os dados (CadastrarTurmaInput), um Interactor (CadastrarTurmaInteractor) que contém todas as regras de negócio implementadas.
 - Arquivo de output (CadastrarTurmaOutput) que vai transformar os dados para que possa ser exibido. 

---

## Camada Web
-  Vai apenas consumir os dados transformados pela camada anterior e exibi-los para o usuário. Ela também é responsável, nesta implementação simplificada, por injetar os repositórios para consumo nos interactors, e os interactors para consumo pelos controllers.
- Conforme vimos no exemplo do sistema escolar, cada camada possui uma única responsabilidade sempre respeitando suas dependências, mantendo assim uma divisão total de responsabilidades, minimizando ao máximo qualquer alteração externa com interface com o usuário (de usuário?), banco de dados etc.
