/*  UNIVERSIDADE TECNOL�GICA FEDERAL DO PARAN� - Campus de Corn�lio Proc�pio

    ALUNO: Giliard Almeida de Godoi - RA 1581597
    DISCIPLINA: IF53B - ESTRUTURA DE DADOS - TURMA - N13
    Prof. Danilo Sipoli Sanches

    LISTA DE EXERC�CIOS REFERENTE � APS 1 -
    DATA DA ENTREGA: 04/05/2015
*/

/* QUEST�O 6 -
        Construa uma fun��o para remover todos os elementos pares de uma lista duplamente
encadeada circular. Obs: implementar as fun��es necess�rias para inser��o, remo��o e
impress�o da lista duplamente encadeada circular.
*/
#include<stdlib.h>
#include<stdio.h>

typedef struct lista{
    int info;
    struct lista* prox;
    struct lista* ant;
}Lista;

int circular_dupla_verificaVazia(Lista* L){
    return ( L == NULL);
}

Lista* circular_dupla_insere(Lista* L, int info){
    Lista *novo, *aux;
    aux = L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = info;
    if(circular_dupla_verificaVazia(L)){
        novo->prox = novo;
        novo->ant = novo;
        L = novo;
    }else{
        novo->prox = L;
        L->ant = novo;
        while(aux->prox!=L){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }
    return L;
}
Lista* circular_dupla_removeValor(Lista* L, int valor){
    Lista* aux = L;
    /* verifica se a lista � vazia */
    if(circular_dupla_verificaVazia(L)){
        printf("\nLista vazia!!\n");
        return L;
    }
    /* verifica se o elemento � o primeiro */
    if(aux->info == valor){ // aqui aux ainda est� apontando para L, primeiro elemento da lista
        /* verifica se � o �nico elemento */
        if(aux->prox == L && aux->ant == L ){ //bastaria fazer aux->prox == L para determinar se � o elemento �nico
            free(L);
            aux = NULL;
            L = NULL;
        }else{
            L = L->prox; /** Se � o primeiro elemento que vai ser eliminado,
                            o ponteiro que marca o in�cio da lista vai para o pr�ximo elemento,
                            como se a lista andasse no sentido hor�rio.
                            Isto vai influenciar no comportamento da fun��o para remover n�meros pares. */
        }
    }else{
        do{
            aux = aux->prox;
        }while(aux != L && aux->info != valor);
    }
        /* verifica se encontrou o elemento */
        if(aux != L){
            /* retira o elemento da lista */
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
            aux = NULL;
        }
        return L;
}

Lista* circular_dupla_liberaLista(Lista* L){
    while(!(circular_dupla_verificaVazia(L))){
        L = circular_dupla_removeValor(L,L->info);
    }
    return L;
}

void circular_dupla_imprime(Lista* L){
    Lista* aux = L;
    printf("\n");
    if(circular_dupla_verificaVazia(L)){
        printf("Lista vazia!!");
    }
    if(!(circular_dupla_verificaVazia(L))){
        do{
            printf("%d   ",aux->info);
            aux = aux->prox;
        }while(aux!=L);
    }
    printf("\n");
}
/** RESPOSTA AO ENUNCIADO DA QUEST�O

    A fun��o os elementos pares da Lista Duplamente Encadeada Circular, que recebe como par�metro.

    A fun��o retorna uma nova lista com todos os valores �mpares ou ent�o retorna NULL.
*/
Lista* circular_dupla_removePares(Lista* L){
    Lista* aux = L;
    if(circular_dupla_verificaVazia(L)){
        return L;
    }
    do{
        if((aux->info)%2 == 0){
            aux = aux->ant;
            L = circular_dupla_removeValor(L, aux->prox->info);
        }else{
            aux = aux->ant;
        }
    }while(aux!=L);
    /* � necess�rio mais essa verifica��o para se garantir que todos os elementos foram verificados
        Se L n�o foi atualizado, isto �, o primeiro elemento � �mpar, vamos verificar a c�lula de inicio novamente.
        Se L foi atualizado, ou seja, o primeiro elemento � par, vamos garantir a verifica��o de todos os elementos. */
    if((aux->info)%2 == 0){
        L = circular_dupla_removeValor(L, aux->info);
    }

    return L;

}
// FUN��O PRINCIPAL
int main(){
    Lista* L = NULL;
    int i = 0, tam, num;

    printf("\nTamanho da lista := ");
    scanf("%d",&tam);
    while(i < tam){
        printf("Insira o valor para a %d.o posicao := ", i+1);
        scanf("%d",&num);
        L = circular_dupla_insere(L, num);
        i++;
    }
    circular_dupla_imprime(L);

    // insira o novo c�digo de testes aqui
    L = circular_dupla_removePares(L);

    circular_dupla_imprime(L);

    L = circular_dupla_liberaLista(L);

    //circular_dupla_imprime(L);

    system("PAUSE");
    return 0;
}



