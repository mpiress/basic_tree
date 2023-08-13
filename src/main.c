#include "tree.h"
#include "fila.h"

int main(){
	int reg[] = {33, 47, 28, 19, 25, 60, 8, 39};
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;

	printf("Árvore vazia: %d\n", TVazia(&raiz));

	printf("ELEMENTOS DA ARVORE: { ");
  
	for(int i=0; i< 8; i++){
		r.key = reg[i];
		r.value = i;
		insertTree(&raiz, r);
  		printf("%d ", reg[i]);
	}

	r.key = 42;
	r.value = 8;
	insertTree_alt(&raiz, r);
  	printf("%d ", r.key);
  	printf("}\n");


  	printf("Árvore vazia: %d\n\n", TVazia(&raiz));
  	
	printf("METODO PREORDEM: { ");
  	preordem(raiz);
  	printf("}\n\n");


  	printf("METODO CENTRAL: { ");
  	central(raiz);
	printf("}\n\n");

  	printf("METODO POSORDEM: { ");
  	posordem(raiz);
  	printf("}\n\n");

  	printf("METODO LARGURA: { ");
  	widthPath(raiz);
  	printf("}\n\n");

	r.key = 2;
	pesquisa(&raiz, &aux, r);
	
	printf("PESQUISA 2 E IMPRIME A SUBARVORE { ");
	central(aux);
	printf("}\n\n");

	r.key = 3;
	removeTree(&raiz, r);

	printf("REMOVE 3 E IMPRIME A ARVORE { ");
	central(raiz);
	printf("}\n\n");



	printf("PESQUISA ALTERNATIVA");
	aux = pesquisa_alt(&raiz, 25);
	if(aux == NULL)
		printf("DADO NÃO ENCONTRADO");
	else
		printf("VALOR:%d\n", aux->reg.value);



	printf("PESQUISA ALTERNATIVA NÃO RECURSIVA");
	aux = pesquisa_alt(&raiz, 39);
	if(aux == NULL)
		printf("DADO NÃO ENCONTRADO");
	else
		printf("VALOR:%d\n", aux->reg.value);

}