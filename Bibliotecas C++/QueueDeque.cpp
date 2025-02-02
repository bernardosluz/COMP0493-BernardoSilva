#include <iostream>
#include <queue> // Inclui a biblioteca para trabalhar com fila
#include <deque> // Inclui a biblioteca para trabalhar com Double Ended Queue → Fila de Duplo Fim

/*
*   QUEUE   
*   O std::queue é uma fila FIFO (First In, First Out), onde apenas o primeiro elemento da fila
*   pode ser acessado diretamente (usando front), e o acesso ao último é feito por back.
*   Você só pode adicionar ou remover elementos no final ou no início da fila, respectivamente.
*   queue<Type> variable;
*   Funções principais da std::queue:
*   push(valor): Insere um elemento na fila.
*   pop(): Remove o elemento na frente da fila.
*   front(): Retorna o elemento da frente da fila.
*   back(): Retorna o último elemento da fila.
*   empty(): Verifica se a fila está vazia.
*   size(): Retorna o número de elementos na fila.
*/

/*
*   DEQUE
*   O std::deque (Double Ended Queue) é uma estrutura de dados da biblioteca padrão do C++ 
*   que permite inserções e remoções eficientes em ambos os extremos.
*   Abaixo estão algumas das funções principais e o que elas fazem de forma resumida:
*   deque<Type> variable;
*   Funções principais do std::deque:
*   push_back(value): Adiciona um elemento no final do deque.
*   push_front(value): Adiciona um elemento no início do deque.
*   pop_back(): Remove o elemento do final do deque.
*   pop_front(): Remove o elemento do início do deque.
*   front(): Retorna uma referência ao primeiro elemento do deque (o elemento da frente).
*   back(): Retorna uma referência ao último elemento do deque (o elemento do final).
*   at(index): Retorna uma referência ao elemento no índice especificado (acesso direto por índice).
*   size(): Retorna o número de elementos no deque.
*   empty(): Retorna true se o deque estiver vazio, caso contrário, retorna false.
*   clear(): Remove todos os elementos do deque.
*   insert(position, value): Insere um elemento na posição especificada.
*   erase(position): Remove o elemento na posição especificada.
*/