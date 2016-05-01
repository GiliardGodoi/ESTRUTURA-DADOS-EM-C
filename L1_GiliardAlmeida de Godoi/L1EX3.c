/*  UNIVERSIDADE TECNOL�GICA FEDERAL DO PARAN� - Campus de Corn�lio Proc�pio

    ALUNO: Giliard Almeida de Godoi - RA 1581597
    DISCIPLINA: IF53B - ESTRUTURA DE DADOS - TURMA - N13
    Prof. Danilo Sipoli Sanches

    LISTA DE EXERC�CIOS REFERENTE � APS 1 -
    DATA DA ENTREGA: 04/05/2015
*/

/* QUEST�O 3 -
            Fa�a uma rotina para verificar se os elementos de uma FILA (representada por listas
    encadeadas) est�o ordenados de forma crescente.

*/
#include<stdlib.h>
#include<stdio.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

typedef struct fila{
    Lista* ini;
    Lista* fim;
}Fila;

Fila* criaFila(){
    Fila* F;
    F = (Fila*) malloc(sizeof(Fila));
    F->ini = NULL;
    F->fim = NULL;

    return F;
}

void insereFila(Fila* F, int valor){
    Lista* novo;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;
    if(F->ini == NULL){
        F->ini = novo;
        F->fim = novo;
    }else{
        F->fim->prox = novo;
        F->fim = novo;
    }
}

void liberaFila(Fila* F){
    if(F->ini != NULL){
        Lista* aux = F->ini;
        Lista* ant = NULL;
        F->ini = NULL;
        F->fim = NULL;
        while(aux != NULL){
            ant = aux;
            aux =aux->prox;
            free(ant);
        }
    }
}

void imprimeFila(Fila* F){
    Lista* aux = F->ini;
    printf("\n");
    while(aux!= NULL){
        printf("%d  ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}


/** RESPOSTA AO ENUNCIADO DA QUEST�O

    Fun��o verifica se os elementos est�o ordenados de forma crescente.
    A fun��o recebe uma fila como par�metro.

    Retorna UM para verdadeiro
    Retorna ZERO para falso */

int filaCrescente(Fila* F){
    int resultado = 0;
    int teste = 0;
    Lista* aux = F->ini;
    if(aux != NULL){
        do{
            teste = aux->info;
            aux = aux->prox;
        }while(aux!= NULL && teste < aux->info);
        if(aux == NULL){
            resultado = 1;
        }
    }
    return resultado;
}


// FUN��O PRINCIPAL
int main(){
    Fila* F;
    F = criaFila();
    int i = 0, tam, num;

    printf("Numero de elementos da FILA := ");
    scanf("%d",&tam);

    while(i < tam){
        printf("Insira o %d.o valor := ", i+1);
        scanf("%d",&num);
        insereFila(F , num);
        i++;
    }

    imprimeFila(F);

    printf("Eh crescente??\n R... %d",filaCrescente(F));

}
