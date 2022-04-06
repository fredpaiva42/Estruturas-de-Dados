/* Cálculo da média de 10 números reais */
#include <stdio.h>

float media (int n, float *v){
    int i;
    float s = 0.0;
    for (i = 0; i < n; i++)
        s += v[i];
    return s/n;
}

int main (void) {
    float v[10];
    float med = 0.0;
    int i;

    /* leitura dos valores */
    for (i = 0; i < 10; i++)
        scanf("%f", &v[i]); // acesso ao endereço da i-ésima posição de v

//    /* cálculo da média */
//    for (i = 0; i < 10; i++)
//        med = med + v[i]; // acesso ao conteúdo de v[i]
//    med = med / 10;
    med = media(10, v);

    /* exibição do resultado */
    printf("Media = %f \n", med);
    return 0;
}