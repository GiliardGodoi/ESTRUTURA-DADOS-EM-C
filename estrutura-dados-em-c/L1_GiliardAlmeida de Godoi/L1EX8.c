/*  UNIVERSIDADE TECNOL�GICA FEDERAL DO PARAN� - Campus de Corn�lio Proc�pio

    ALUNO: Giliard Almeida de Godoi - RA 1581597
    DISCIPLINA: IF53B - ESTRUTURA DE DADOS - TURMA - N13
    Prof. Danilo Sipoli Sanches

    LISTA DE EXERC�CIOS REFERENTE � APS 1 -
    DATA DA ENTREGA: 04/05/2015
*/

/* QUEST�O 8 -
        Fa�a uma fun��o que receba uma lista encadeada L1 e retorne a lista L1 com os elementos
invertidos. Para isso, dever� ser utilizada uma pilha. Exemplo: Lista1 = {1,2,3}, ap�s passar
pela fun��o a Lista1 ficar�: Lista1 = {3,2,1}.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

typedef struct pilha{
    Lista* topo;
}Pilha;


// fun��es sobre lista
Lista* lista_InsereFim(Lista* L, int num){
    Lista* novo, *aux = L;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    if(L == NULL){
        L = novo;
    }else{
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = novo;

    }

    return L;
}

void lista_Imprime(Lista* aux){
    printf("\n");
    while(aux!= NULL){
        printf("%d  ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

// fun��es sobre pilha
Pilha* criaPilha(){
    Pilha* P;
    P = (Pilha*)malloc(sizeof(Pilha));
    P->topo = NULL;
    return P;
}
void push(Pilha* P, int valor){
    Lista* novo;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = P->topo;
    P->topo = novo;
}
Lista* pop(Pilha* P){
    if(pilha_vazia(P)){
        return NULL;
    }
    Lista* aux;
    aux = P->topo;
    P->topo = P->topo->prox;
    aux->prox = NULL;
    return aux;
    // aqui a ordem das instru��es alternam o resultado sim!!
}
int pilha_vazia(Pilha* P){
    return (P->topo == NULL);
    /* Em C os valores l�gicos verdadeiro e falso s�o implementados como o sendo 0 ZERO para falso,
        e qualquer outro n�mero para verdadeiro. Ent�o essa fun��o vai retornar 1 se a compara��o
        for verdadeira. */
}

/** RESPOSTA AO ENUNCIADO DO PROBLEMA
    Fun��o inverte os elementos de uma lista, usando uma pilha na sua implementa��o.
    Recebe como par�metro uma lista e retorna a os elementos invertidos.
    */
Lista* lista_Inverte(Lista* L){
    Pilha* P;
    P = criaPilha();
    Lista* aux;
    while(L != NULL){
        push(P,L->info);
        L = L->prox;
    }

    while(!(pilha_vazia(P))){
        aux = pop(P);
        L = lista_InsereFim(L,aux->info);
        free(aux);
    }
    return L;
}

//FUN��O PRINCIPAL
int main(){
    Lista* L = NULL;
    int i = 0, tam, num;

    printf("Numero de elementos da LISTA := ");
    scanf("%d",&tam);

    while(i < tam){
        printf("Insira o %d.o valor := ", i+1);
        scanf("%d",&num);
        L = lista_InsereFim(L , num);
        i++;
    }
    lista_Imprime(L);
    L = lista_Inverte(L);
    lista_Imprime(L);

}

