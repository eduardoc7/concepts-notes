# Descomplicando o Docker

## Conhecendo um pouco da história
O Docker foi desenvolvido em 2013 por uma empresa chamada dotCloud, Inc (que futuramente se chamará Docker, INC) com a necessidade de melhoramento da grande demanda de máquinas virtuais. A criação das máquinas virtuais dependiam de grandes espaços de discos e outros recursos e ainda havia a questão das aplicações, que poderiam serem corrompidas em algumas situações pelas próprias máquinas virtuais. Com isso, houve a necessidade desenvolver um sistema e assim surgiu o LXC.
O LXC foi criado em 2008 e é uma tecnologia que trabalha com a criação de instâncias isoladas de um sistema operacional dentro da máquina hospedeira. Ou seja, a base do docker começou a ser desenvolvida. Com sua facilidade de uso, o mercado obteve uma rápida adoção dessa tecnologia. Contanto que houve um “boom” nas empresas após mostrar que o desenvolvedor conseguiria colocar suas aplicações diretamente do notebook para a produção.O LXC foi criado em 2008 e é uma tecnologia que trabalha com a criação de instâncias isoladas de um sistema operacional dentro da máquina hospedeira. Ou seja, a base do docker começou a ser desenvolvida. Com sua facilidade de uso, o mercado obteve uma rápida adoção dessa tecnologia. Contanto que houve um “boom” nas empresas após mostrar que o desenvolvedor conseguiria colocar suas aplicações diretamente do notebook para a produção.

---
## Por que foi adotado rapidamente?
As primeiras versões do Docker nada mais eram do que um wrapper do LXC integrado ao Union Filesystem, mas o seu crescimento foi fantástico e muito rápido, tanto que em seis meses seu GitHub já possuía mais de seis mil stars e mais de 170 pessoas contribuindo para o projeto ao redor do mundo.

Com isso, a dotCloud passou a se chamar Docker e a versão 1.0 foi lançada apenas 15 meses após sua versão 0.1. A versão 1.0 do Docker trouxe muito mais estabilidade e foi considerada "production ready", além de trazer o Docker Hub, um repositório público para containers.

Por ser um projeto open source, qualquer pessoa pode visualizar o código e contribuir com melhorias para o Docker. Isso traz maior transparência e faz com que correções de bugs e melhorias aconteçam bem mais rápido do que seria em um software proprietário com uma equipe bem menor e poucos cenários de testes.

Quando o Docker 1.0 foi lançado e anunciado que estava pronto para produção, empresas como Spotify já o utilizavam em grande escala; logo AWS e Google começaram a oferecer suporte a Docker em suas nuvens. Outra gigante a se movimentar foi a Red Hat, que se tornou uma das principais parceiras do Docker, inclusive o incorporando-o ao OpenShift.

---
## **1.1** O que são Containers?
    - Containers é uma solução de isolamento.

### **1.2** Isolamento Lógico
    - Isolamento de processos: usuários, networking.
    - Outro container não consegue ver nada além do seu isolamento.
    - Responsáveis: Namespaces.

### **1.2** Isolamento Físico
    - Isolamento de recursos: CPU, memória e I/O.
    - Responsáveis: CGroups.

 # adicionar mais informações aqui quando tiver um tempo
---
## Referências
 - [LINUXtips](https://www.youtube.com/c/LinuxTips)
 - [Livro descomplicando o docker](https://livro.descomplicandodocker.com.br/chapters/chapter_02.html)
 - [4Linux.com.br](https://4linux.com.br/o-que-e-docker/#:~:text=O%20Docker%20foi%20desenvolvido%20em,grande%20demanda%20de%20m%C3%A1quinas%20virtuais.)

---
