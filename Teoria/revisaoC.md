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