//#include <stdio.h>
//#include <stdlib.h>
//
//struct lista {
//    int info;
//    struct lista *prox;
//};
//typedef struct lista Tlista;
//
//Tlista *cria_lista (void) {
//    return NULL;
//}
//
//Tlista *insere_inicio (Tlista *li, int i){
//    Tlista *novo = (Tlista*) malloc (sizeof (Tlista));
//    novo -> info = i;
//    novo -> prox = li;
//    return novo;
//}
//
//Tlista *insere_fim (Tlista *li, int i){
//    Tlista *novo = (Tlista*) malloc (sizeof(Tlista));
//    novo -> info = i;
//    novo -> prox = NULL;
//    Tlista *p = li;
//    Tlista *ant = li;
//    while (p != NULL){ /* encontra o ultimo elemento*/
//        ant = p; /* ant vai sempre apontar pro elemento anterior */
//        p = p -> prox;
//    }
//    if (ant != NULL) /* se a lista original não estiver vazia */
//        ant -> prox = novo;
//    else
//        li = novo;
//    return li;
//}
//
//void imprime_lista (Tlista *li){
//    Tlista *p;
//    for (p = li; p != NULL; p = p ->prox)
//        printf(" %d", p ->info);
//}
//
//int main (void) {
//    Tlista* L = cria_lista();
//    int entrada, tamanhoLista, escolha;
//
//    printf("\nDigite a quantidade de elementos para inserir:");
//    scanf("%d", &tamanhoLista);
//
//    for (int i = 0; i < tamanhoLista;  i++){
//        printf("\nPara inserir no inicio (1), Para inserir no fim (0):");
//        scanf("%d", &escolha);
//
//        printf("\nDigite o numero a ser inserido:");
//        scanf("%d", &entrada);
//
//        if (escolha)
//            L = insere_inicio(L, entrada);
//        else
//            L = insere_fim(L, entrada);
//    }
//
//    printf("info: ");
//    imprime_lista(L);
//
//    return 0;
//}