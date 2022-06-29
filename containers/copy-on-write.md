# Copy on Write

De modo geral, cada instrução que o docker executa é gerada uma camada isolada.
Portanto, não é possível que o docker modifique o run (a camada anterior) com uma outra instrução qualquer. Todas as instruções executadas são criadas camadas dentro do docker automaticamente de apenas leitura.

    - Sendo possível escrever apenas na última camada, utilizada pelo próprio docker em tempo de execução.
    - O container sempre utiliza o mesmo espaço no disco para a roda a mesma imagem no docker.