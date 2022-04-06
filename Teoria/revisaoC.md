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

### Operador Unário *
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
## Alocação dinâmica de memória
- Alocação dinâmica é usada quando não se sabe de antemão quanto espaço de memória será necessário.
  - Exemplo, quando não é possível determinar o tamanho de um vetor de antemão.
- **Alocção dinâmica**
  - Espaço de memória é requisitado em tempo de execução.
  - Espaço permanece alocado até que seja explicitamente liberado.
- Depois de liberado, espaço pode ser disponibilizado para outros usos e não pode mais ser acessado.
- Espaço alocado e não liberado explicitamente é liberado ao final do programa.

## Alocação Estática x Alocação Dinâmica
![](../img/Diferença%20entre%20alocação%20estática%20e%20dinâmica.png)

## Biblioteca stdlib.h
- A biblioteca ``stdlib.h`` contém funções e constantes para a alocação dinâmica de memória.

### Funções importantes da stdlib.h
- ``sizeof(tipo)``
  - Retorna o número de bytes ocupado por um **tipo**.
- ``malloc(tamanho)``
  - Recebe como parâmetro o **tamanho** do espaço de memória (em bytes) que se deseja alocar.
  - Retorna um ponteiro genérico para o endereço inicial da área de memória alocada, se houver espaço livre.
    - Ponteiro genérico é representado por void*
    - Ponteiro é convertido automaticamente para o tipo apropriado.
    - Ponteiro pode ser convertido explicitamente.
  - Retorna um endereço nulo (NULL) se não houver espaço livre.

Exemplo:

Alocação dinâmica de um vetor de inteiros com 10 elementos.
  - malloc retorna o endereço do espaço de memória alocado.
  - ponteiro de inteiro (v) recebe o endereço inicial do espaço de memória alocado.
````c
int *v;
v = (int*) malloc(10 * sizeof(int));

/* Tratamento de erro */
if (v == NULL) {
    printf ("Memória insuficiente.\n");
    exit(1); // aborta o programa e retorna 1 para o sistema operacional.
}
````
- no programa, v pode ser tratado como um vetor alocado estaticamente

## Liberação de memória
``free(ponteiro)``
  - Libera a memória apontada por **ponteiro**
  - A posição de memória apontada por ponteiro **deve ter sido alocada dinamicamente**

#### Exemplo
````c
/* Cálculo da média de um número n de números reais */
# include <stdio.h>
# include <stdlib.h>

float media(int n, float *v){
    int i;
    float s;
    for (i = 0; i < n; i++)
        s += v[i];
    return s/n; 
}

int main(void) {
    int i, n;
    float *v;
    scanf("%d", &n); // leitura do número n de valores
    v = (float*) malloc (n * sizeof(float)); // alocação dinâmica
    if (v == NULL){
        printf("Memória insuficiente.\n")
        return 1;
    }
    for (i = 0; i < n; i++)
        scanf("%f", &v[i]);
    med = media(n, v);
    printf("Media = %.2f \n", med);
    free(v); // libera Memória
    return 0
}
````

## Ponteiros e Tipos Estruturados

### Tipo Estrutura (struct)
- Tipo de dado composto por outros elementos (campos)
- Campos são acessados atráves do operador de acesso "ponto" (.)
````c
struct ponto2d { // declara ponto2d do tipo struct
    float x;
    float y;
};
...
struct ponto2d p; // declara p como variável do tipo struct ponto2d
...
p.x = 10.0; // acessa os elementos de ponto2d
p.y = 5.0;
````

Exemplo:
````c
/* Capture e imprima as coordenadas de um ponto qualquer */
# include <stdio.h>
struct ponto2d {
    float x;
    float y;
};

int main (void){
    struct ponto2d p;
    printf("Digite as coordenadas do ponto (x, y):");
    scanf("%f %f", &p.x, &p.y);
    printf("O ponto fornecido foi: (%.2f, %.2f)\n". p.x, p.y);
    return 0;
}
````
### Ponteiros para Estruturas
- Acesso ao **valor** de um campo **x** de uma variável estrutura **p:p.x**
- Acesso ao **valor** de um campo **x** de uma **variável ponteiro pp: pp -> x**
- Acesso ao **endereço** de um campo **x** de uma **variável ponteiro pp: &pp -> x**

````c
struct ponto2d *pp;
...
pp -> x = 12.0;
````

### Alocação dinâmica de Estruturas
- Tamanho do espaço de memória alocado dinamicamente é dado pelo operador **sizeof** aplicado sobre o tipo de estrutura
- A função **malloc** retorna o endereço de espaço alocado, que é então convertido para o tipo ponteiro da estrutura.

````c
struct ponto2d *p;
p = (struct ponto2d*) malloc(sizeof(struct ponto2f));
...
p -> x = 12.0;
````

### Definir um nome para o tipo
``typedef``
  - permite criar nomes de tipos 
  - útil para abreviar nomes de tipos e para tratar tipos complexos

````c
struct ponto2d { // ponto2d representa uma estrutura com 2 campos float
    float x;
    float y;
};
typedef struct ponto2d Tponto2d; // Tponto2d representa a estrutura ponto2d
````
Ou
````c
typedef struct ponto2d {
    float x;
    float y;
} Tponto2d;
````
### Exemplo Prático: Lista Simplesmente Encadeada

#### Definição da lista

Esse exemplo a lista tem um campo inteiro **info** e um ponteiro **prox** para o próximo nó da lista.

````c
typedef struct lista {
    int info;
    struct lista *prox;
} TLista;
````

#### Funções de Manipulação da Lista

**cria_lista**
  - Cria uma lista vazia, representada pelo ponteiro NULL
```c
    TLista *cria_lista (void) {
    return NULL;
}
```

**insere_inicio**
- Insere um elemento no início da lista
- Retorna a lista atualizada

````c
TLista* insere_inicio (TLista* li, int elem) {
    TLista* novo = (TLista*) malloc (sizeof (TLista));
    novo -> info = elem;
    novo -> prox  = li;
    return novo;
}
````
**imprime_lista**
- Imprime os elementos da lista

````c
void *imprime_lista (Tlista* li) {
    Tlista *p;
    for (p = li; p != NULL; p = p -> prox)
        printf("info = %d\n"), p -> info);
}
````
**insere_fim**
  - Insere um elemento no fim da lista
  - Retorna ponteiro para a lista atualizada
````c
TLista* insere_fim (TLista* li, int elem){
    Tlista *novo = (Tlista *) malloc (sizeof (Tlista));
    novo -> info = elem;
    novo -> prox = NULL;
    TLista *p = li;
    Tlista *ant = li;
    while (p != NULL){ // encontra o ultimpo elemento
        ant = p;
        p = p -> prox;
    }
    
    if (ant != NULL) // se a lista não estiver vazia
        ant -> prox = novo;
    else
        li = novo;
    return li;
}
````
**insere_ordenado**
- Insere um elemento na lista de forma que ela esteja sempre ordenada
- Retorna ponteiro para a lista atualizada

````c
TLista* insere_ordenado (TLista* li, int elem){
    TLista* novo;
    TLista* ant = NULL; // ponteiro para elemento anterior
    TLista* p = li; // ponteiro para percorrer a lista
    
    /* procura posição de inserção */
    while (p != NULL && p -> info < elem){
        ant = p;
        p = p -> prox;
    }
    
    /* cria novo elemento */
    novo = (TLista*) malloc (sizeof (TLista));
    novo -> info = elem;
    
    /* encadeia o elemento */
    if (ant == NULL) { // insere elemento no início
        novo -> prox = li;
        li = novo;
    } else { // insere no meio da lista
        novo -> prox = ant -> prox;
        ant -> prox = novo;
    }
    return li;
}
````

## Funções Recursivas
Quando a **função chama a si mesma**, dizemos que a função é recursiva

**Pontos importantes**:
- Forma fácil de dividir para conquistar - Trata-se um item e chama-se recursivamente para os demais
- É preciso ter um critério de parada para evitar loop infinito de chamadas

### insere_fim recursivo
````c
TLista* insere_fim_recursivo (TLista* li, int elem){
    TLista* novo = (TLista *) malloc (sizeof (TLista));
    novo -> info = elem;
    novo -> prox = NULL;
    if (li == NULL)
        li = novo;
    else
        if (li -> prox == NULL) // chegou no último nó da lista
            li -> prox = novo;
        else
            insere_fim_recursivo(li -> prox, elem);
    return li;     
}
````

### insere_ordenado_recursivo
````c
TLista *insere_ordenado_recursivo(TLista* li, TLista* ant, int elem) {
    TLista* novo = (TLista *) malloc(sizeof(TLista));
    novo -> info = elem;
    if (li == NULL){ //lista vazia
        li = novo;
        novo -> prox = NULL;
    } else {
        if (li -> info > elem){
            novo -> prox = li;
            li = novo;
            if (ant != NULL) {
                ant -> prox = novo;
            }
        }
        else {
            if (li -> prox == NULL) { //insere no fim da lista
                li -> prox = novo;
                novo -> prox = NULL;
            }
            else
                insere_ordenado_recursivo(li -> prox, li, elem);
        }
    }
    return li;
}
````