#include<stdlib.h>
#include<stdio.h>

typedef struct lista{
    int info;
    struct lista* prox;
}Lista;

Lista* insereFim(Lista *L, int num){
    Lista *novo, *aux;
    aux = L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;

    if(L == NULL){
        return novo;
    }else{
       while(aux->prox!=NULL){
            aux = aux->prox;
       }
       aux->prox = novo;
       return L;
    }
}

void apagarImpar(Lista* aux){
    Lista *ant;
    while(aux!= NULL){
        if((aux->info%2)!=0){
            printf("\n%d",aux->info);
        }
    }
}

void imprimeLista(Lista *aux){
    printf("\n");
    while(aux != NULL){
        printf("/t%d",aux->info);
        aux = aux->prox;
    }
    printf("\n");
}


int main(){
    Lista *L1 = NULL;
    int i = 1;
    for(i = 1; i <11; i++){
       L1 = insereFim(L1,i);
    }

    imprimeLista(L1);

    apagarImpar(L1);
    imprimeLista(L1);
    return 0;
}
