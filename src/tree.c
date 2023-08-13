#include "tree.h"
#include"fila.h"



Tree* CreateTree(){
	return NULL;
}

bool TVazia(Tree **t){
  return *t == NULL;
}

void insertTree(Tree **t, Record r){

  if(TVazia(t)){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
    }
  
  }

}


void pesquisa(Tree **t, Tree **aux, Record r){

  if(*t == NULL){
    printf("[ERROR]: Node not found!");
    return;
  }

  if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;
}


Tree* pesquisa_alt(Tree **t, int key){

  if((*t)->reg.key == key || *t == NULL)
    return *t;
  
  if((*t)->reg.key > key)
      return pesquisa_alt(&(*t)->esq, key);
      
  else
    return pesquisa_alt(&(*t)->dir, key);

}


Tree* pesquisa_alt_nr(Tree *t, int key){

  Tree *aux = t;
  while(aux->reg.key != key && aux != NULL){
    if(aux->reg.key > key)
      aux = aux->esq;   
    else
      aux = aux->dir;
  }

  return aux;
}



int isInTree(Tree *t, Record r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void removeTree(Tree **t, Record r){
	Tree *aux;
  	
	if (*t == NULL){ 
		printf("[ERROR]: Record not found!!!\n");
  	return;
	}

	if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, r); return; }
	if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, r); return; }

	if ((*t)->dir == NULL){ 
		aux = *t;  
		*t = (*t)->esq;
  	free(aux);
  	return;
	}

	if ((*t)->esq != NULL){ antecessor(&(*t)->esq, *t); return; }

	aux = *t;  
	*t = (*t)->dir;
	free(aux);

}


void preordem(Tree *t)
{
  if(!(t == NULL)){
    printf("%d ", t->reg.key);
    preordem(t->esq); 
    preordem(t->dir); 
  }
}


void central(Tree *t)
{
  if(!(t == NULL)){
    central(t->esq); 
    printf("%d ", t->reg.key);
    central(t->dir); 
  }
}

void posordem(Tree *t)
{
  if(!(t == NULL)){
    posordem(t->esq); 
    posordem(t->dir); 
    printf("%d ", t->reg.key);
  }
}


void widthPath(Tree *t){
  Fila q;
  Item no, filho;
  
  FFVazia(&q);
  no.p = t;
  Enfileira(&q, no);

  while (!isVazia(&q)){

    Desenfileira(&q, &no);
    printf("%d ", no.p->reg.key);

    if(no.p->esq != NULL){
      filho.p = no.p->esq;
      Enfileira(&q, filho);
      //printf(" Entrei esquerda! ");
    }

    if(no.p->dir != NULL){
      filho.p = no.p->dir;
      Enfileira(&q, filho);
      //printf(" Entrei direita! ");
    }

  }


}