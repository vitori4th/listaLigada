#include<stdio.h>
#include<stdlib.h>

typedef struct No{
	int dado;
	struct No * ant;
	struct No * prox; //ponteiro do tipo struct No
}No;

typedef struct No * p_no;//p_no=No *


p_no criar_lista(){ //função lista tipo No*
	return NULL;
}

p_no adicionar_elemento(int valor, p_no lista){
	p_no novo =(p_no) malloc(sizeof(No)); //apontador pra nó
	novo->dado=valor; // mesmo que (*novo).dado=x; acessando variável que o apontador novo aponta e o campo dado
	novo->prox=lista; //próximo é igual a nulo
	return novo;
}

void libera_lista(p_no lista){
	if(lista == NULL) return;
	libera_lista(lista->prox);
	free(lista);
}

int acessa(p_no lista, int k){
	p_no atual = lista;
	int i=0;
	while(lista !=NULL){
		if(i==k) return atual->dado;
		i++;
		atual=atual->prox;
	}
	return 0;
}

p_no remover_elemento(int valor, p_no lista){
	if (lista != NULL && lista->dado == valor) {
      p_no rem=lista->prox;
      free(lista);
      return rem;
    }
    p_no ant=lista;
	p_no proximo=lista->prox;
	while (proximo != NULL && proximo->dado != valor) {
     ant = proximo;
     proximo = proximo->prox;
   }
	if (proximo != NULL && proximo->dado == valor) {
      ant->prox = proximo->prox;
      free (proximo);
   }
   return lista;
}

void imprime_lista(p_no lista){
	if(lista == NULL) return;
	printf("%d ",lista->dado);// mesmo que (*lista).dado
	imprime_lista(lista->prox);

}

p_no remover_varios(int valor, p_no lista){
	p_no aux=lista;
	while(aux!=NULL){
		lista = remover_elemento(valor,lista);
		aux=aux->prox;
	}
	return lista;
}
int main(){
	p_no lista = criar_lista(); //mesmo que struct No * lista
	
	lista =adicionar_elemento(10,lista);
	lista =adicionar_elemento(50,lista);
	lista =adicionar_elemento(5,lista);
	lista =adicionar_elemento(50,lista);
	lista =adicionar_elemento(5,lista);
	
	lista = remover_elemento(8,lista);
	lista = remover_varios(5,lista);
	
	imprime_lista(lista);
	printf("\n");
	
	
	libera_lista(lista);
	
	return 0;
}

