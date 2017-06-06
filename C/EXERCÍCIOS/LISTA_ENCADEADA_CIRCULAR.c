/*
 Problema de Josephus. Imagine que temos n pessoas dispostas em c�rculo. Suponha que as pessoas est�o numeradas 1 a n no sentido hor�rio.
 Come�ando com a pessoa de n�mero 1, percorra o c�rculo no sentido hor�rio e elimine cada m-�sima pessoa enquanto o c�rculo tiver duas ou mais pessoas.
 Qual o n�mero do sobrevivente?

 */

#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista* ant;
    struct lista* prox;
}lstc;

lstc* lstc_insere(lstc* L, int valor){
    lstc* aux = L;
    lstc* novo;
    novo = (lstc*) malloc(sizeof(lstc));
    novo->info = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    if(L == NULL){ // verifica se a lista � vazia
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    }
    while(aux->prox != L ){
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux;
    novo->prox = L;
    L->ant = novo;

    return L;
}

void lstc_imprime(lstc* L){
    lstc* aux = L;
    if(aux!=NULL){
         do{
            printf("%d  ",aux->info);
            aux = aux->prox;
        }while(aux!= L);
    }
}

lstc* lstc_apagaElemento(lstc* L, int valor){
    lstc* aux = L;
    if(L == NULL){ //verifica se a fila � fazia
        return L;
    }
    do{
            aux = aux->prox;
    }while(aux!= L && aux->info != valor);
    if(aux->ant->prox == L && aux->info != valor){ // percorreu a lista mas n�o encontrou o valor procurado
        return L;
    }
    if(aux->ant->prox == L && aux->info == valor){ // o elemento � o primeiro
        L = L->prox;
        aux->ant->prox = L;
        L->ant = aux->ant;
    }else if(aux->info == valor){ // elimina elemento do meio ou o '�ltimo'
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    free(aux);
    return L;

}
int lstc_verificaElementoUnico(lstc* L){
    int resultado = 0;
    if(L->prox == L && L->ant == L){
        resultado = 1;
    }
    return resultado;
}

lstc* lstc_josephus(lstc* L, int pos){
    lstc* aux = L;
    int i = 0, teste;
    if(L == NULL){
        return NULL;
    }
    while(!(lstc_verificaElementoUnico(L))){
        i = 0;
        while(i < pos){
            teste = aux->info;
            i++;
            aux = aux->prox;
            if(i== pos){
                printf("\n%d", teste);
                L = lstc_apagaElemento(L, teste);
            }
        }
    }
    return L;
}

int main(){
    lstc* L = NULL;
    int i = 0;
    for(i = 1; i < 101; i++){
        L = lstc_insere(L, i);
    }
    printf("\nIMPRIME LISTA CIRCULAR\n\n");
    lstc_imprime(L);

    L = lstc_josephus(L,52);
    printf("\n\nRESULTADO: ");
    lstc_imprime(L);

    system("PAUSE");
    return 0;
}
