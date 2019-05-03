/*  UNIVERSIDADE TECNOL�GICA FEDERAL DO PARAN� - Campus de Corn�lio Proc�pio

    ALUNO: Giliard Almeida de Godoi - RA 1581597
    DISCIPLINA: IF53B - ESTRUTURA DE DADOS - TURMA - N13
    Prof. Danilo Sipoli Sanches

    LISTA DE EXERC�CIOS REFERENTE � APS 1 -
    DATA DA ENTREGA: 04/05/2015
*/

/* QUEST�O  9 -
    Fa�a um programa que verifique se duas filas din�micas s�o iguais. Obs:implementar as
fun��es necess�rias para inser��o, remo��o e impress�o da fila din�mica.

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista* prox;
}Lista;
typedef struct fila{
    Lista* ini;
    Lista* fim;
}Fila;

Fila* fila_criar(){
    Fila* f;
    f = (Fila*) malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int fila_vazia(Fila* f){
    return (f->ini == NULL);
}

void fila_insere(Fila* f, int info){
    Lista* novo;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = info;
    novo->prox = NULL;
    if(f->ini == NULL){
        f->ini = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}
void fila_removeElemento(Fila* f){
    Lista* aux;
    aux = f->ini;
    if(fila_vazia(f)){
        // a fila est� vazia
        f->fim = NULL;
    }else{
        f->ini = f->ini->prox;
        free(aux);
        if(fila_vazia(f)){
            f->fim = NULL;
        }

    }
}
void fila_imprime(Fila* f){
    Lista *aux;
    aux = f->ini;
    printf("\n");
    while(aux!= NULL){
        printf("%d   ",aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
/** RESPOSTA AO ENUNCIADO DO EXERC�CIO

    Fun��o verifica se duas FILAS s�o iguais. Recebe, para tanto, duas filas como par�metro.

    Retorna UM para verdadeiro.
    Retorna  ZERO para falso.*/
int fila_verificaIguais(Fila* f1, Fila* f2){
    Lista* aux1 = f1->ini;
    Lista* aux2 = f2->ini;

    int resultado = 1;
    int controle = 1;

    if(fila_vazia(f1) || fila_vazia(f2)){
        controle = 0;
        resultado = controle;
    }
    while(controle){
        if(aux1->info != aux2->info){
            controle = 0;
            resultado = 0;
        }else{
            aux1 = aux1->prox;
            aux2 = aux2->prox;
            if(aux1!=NULL && aux2!=NULL){
                // n�o acontece nada. A execu��o do programa volta para o while
            }else if(aux1 == NULL && aux2 == NULL){
                controle = 0; // por causa deste teste que eu devo ter uma vari�vel controle e a outra teste
            }else if(aux1==NULL && aux2!=NULL){
                controle = 0;
                resultado = 0;
            }else if(aux1!= NULL && aux2 == NULL){
                controle = 0;
                resultado = 0;
            }
        } // fim do else
    } // fim do while

    return resultado;
}

// FUN��O PRINCIPAL
int main(){
    Fila* f1;
    Fila* f2;
    f1 = fila_criar();
    f2 = fila_criar();
    int i= 0, tam, num;

    printf("Insira a quantidade de elementos da PRIMEIRA FILA ");
    scanf("%d", &tam);
    while(i<tam){
        printf("Insira o %d.o elemento -> ", i+1);
        scanf("%d",&num);
        fila_insere(f1,num);
        i++;
    }
    i = 0;
    printf("\nInsira a quantidade de elementos da SEGUNDA FILA ");
    scanf("%d", &tam);
    while(i<tam){
        printf("Insira o %d.o elemento -> ", i+1);
        scanf("%d",&num);
        fila_insere(f2,num);
        i++;
    }

    printf("\nPRIMEIRA FILA:");
    fila_imprime(f1);
    printf("\nSEGUNDA FILA");
    fila_imprime(f2);

    printf("\nAS FILAS SAO IGUAIS?\n\tUM -> verdadeiro\n\tZERO -> falso\n\tRESULTADO -> %d",fila_verificaIguais(f1,f2));

    return 0;
}
