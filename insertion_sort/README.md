# Apresentação

Este código foi desenvolvido duranta a aula de EDB1 em 23 de março, 2017.
Partiu-se de um problema menor, que consistia em inserir um elemento em um vetor já ordenado. A estratégia é a mesma adotada quando tentamos ordenar cartas de um baralho em uma de nossas mão: tiramos a carta de um bolo e a inserimos em sua posição ordenada na mão.

Na segunda parte da aula, foi indicado que o problema de ordenação poderia ser resolvido a partir da solução desenvolvida (problema menor). Para tanto, teríamos que usar a mesma estratégia de outros problemas: movimentar dados dentro do próprio vetor.

Portanto, a abordagem sugerida foi:

1. Divida o vetor a ser ordenado em duas regiões: elementos **já ordenados** (que é iniciada com apenas um elemento, o primeiro elemento do vetor) e região dos elementos **ainda não processados**.

2. Para cada um dos elementos da região _ainda não processada_, procure inserir este elemento no subvetor ordenado, invocando a função `insercao_ordeanada` ou (novo nome) `sorted_array_insert`.

# TODO

O próximo passo é:

- [ ] Modificar o programa de maneira que a função `insertion_sort()` não precise chamar a função auxiliar `sorted_array_insert`. Isso significa que o código da função auxiliar será adaptado dentro da função `insertion_sort()`.

