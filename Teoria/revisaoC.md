## Ponteiros
- C permite o armazenamento e manipulação de valores de endereço de memória.
- Para cada tipo de dados existente, há um tipo de ponteiro que pode armazenar endereços de memória de variáveis daquele tipo.

```C
/* variável inteiro */

int a;

/* variável ponteiro p/ inteiro */

int *p;
```

## Operadores

### Operador Unário &
- ``Endereço de``
- Aplicado a uma variável x, resulta no ``endereço da posição de memória`` reservada para a variável x.

#### Operador Unário *
- ``Conteúdo do endereço apontado por``
- Aplicado a variavéis do tipo ponteiro, acessa o ``conteúdo do endereço de memória`` armazenado pela variável ponteiro.

````C
int a, *p, c;

/* a recebe o valor 5 */

a = 5;

/* p recebe o endereço de a (p aponta para a) */

p = &a;

/* posição de memória apontada por p recebe 6 */

*p = 6;

/* c recebe o valor armazenado na posição de memória apontada por p */

c = *p;
````

#### Exemplo com erro
- ``Erro na atribuição *p = 3``
- Utiliza a memória apontada por p para armazenar o valor 3, sem que p tivesse sido inicializada.
- Armazena 3 num espaço de memória ``desconhecido``.
````C
int main() {
    int a, b, *p;
    
    a = 2;
    *p = 3; 
    
    b = a + (*p);
    
    printf(" %d", b);
    return 0;
}
````

#### Exemplo Corrigido
- ``atribuição *p = 3``
- p aponta para c.
- Atribuição armazena 3 no espaço de memória da variável c.

````C
int main() {
    int a, b, c, *p;
    
    a = 2;
    p = &c;
    *p = 3; 
    
    b = a + (*p);
    
    printf(" %d", b);
    return 0;
}
````
## Passagem de ponteiros para funções
- C usa passagem de parâmetros ``por valor``.
- Alterações nos valores dos parâmetros não afetam as variavéis que foram usadas na chamada da função.
- Caso seja necessário que as alterações sejam refletidas nas variavéis usadas na chamada, pode-se ``passar endereços das variavéis como parâmetro`` ao invés de variavéis comuns.
- Nesse caso os parâmetros da função precisam de ponteiros.

## Vetores são ponteiros
- Um vetor é alocado em posições contíguas de memória.

Exemplo:
  - Vetor v de 10 elementos inteiros.
  - Espaço de memória de v = 10 * valores inteiros de 4 bytes = 40 bytes.
- **Alocação estática! (espaço de memória é reservado no momento da declaração do vetor)**
- ``Nome do vetor é um ponteiro`` que aponta para o endereço inicial do vetor.
    ```C
    int v[10];
    ```
## Vetores e Ponteiros
``C permite aritmética de ponteiros``

Exemplo:
  - v + 0: primeiro elemento de v
  - v + 1: segundo elemento de v
  - ...
  - v + 9: último elemento de v
  - Elementos do vetor podem ser acessados usando colchetes:
    - v[0] é o primeiro elemento do vetor
  
## Passagem de parâmetro vetor para função
- Como um vetor na verdade é um ponteiro, passar um vetor como parâmetro para uma função ``exige`` que o ``parâmetro da função seja um ponteiro``

## Função pode alterar valores do vetor
- Como o que é passado é o endereço do vetor, e não uma cópia dos valores:
  - a ``função pode alterar os valores do vetor``, e
  - as ``alterações serão refletidas no programa principal``
  
Exemplo:
```C
/* Incrementa elementos de um vetor */
# include <stdio.h>

void incr_vetor (int n, int *v){
    int i;
    for (i = 0; i < n; i++)
        v[i]++;
}

int main (void) {
    int a[] = {1, 3, 5};
    incr_vetor(3, a);
    printf("%d %d %d \n", a[0], a [1], a[2]) // vai imprimir 2 4 6
    return 0;
}
```