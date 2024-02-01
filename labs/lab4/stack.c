/* stack.h */

#define DEBUG 1

#include "stack.h"
#include <stdlib.h>

#if DEBUG==1
#include <stdio.h>
#endif

#define STACK_BLOCK 10



typedef unsigned Element_t;

struct Stack {
    Element_t* st;
    int nElem;
    int sp;
};

Stack_t initStack(){
    Element_t* s=malloc(STACK_BLOCK*sizeof(struct Stack));
    if (!s){
    	return NULL;
	}
	Stack_t st=malloc(1*sizeof(struct Stack));
	st->st=s;
	st->sp=0;
	st->nElem=STACK_BLOCK;
	return st;
}

Stack_t push(Stack_t s, Element_t e){
    /*atentie ca nu se intampla nimic daca nu incape; ar trebui sa implementati asta*/
#if DEBUG==1
    printf("Il bagam pe %u in stiva care are varful la %u\n", e, s->sp);
#endif
    if (s->sp<s->nElem){
    	s->st[s->sp]=e;
    	s->sp=s->sp+1;
	}
	return s;
}
Element_t pop(Stack_t s){
    /*nu se intampla nimic daca stiva e deja vida; trebuie sa implementati asta */
    if (s->sp>0){
    	Element_t el=s->st[s->sp-1];
#if DEBUG==1
		printf("Sp inainte de extragere este %u\n", s->sp);
#endif
    	s->sp=s->sp-1;
#if DEBUG==1
		printf("Sp dupa extragere este %u\n", s->sp);
#endif
    	return el;
	}
	return 0;	//atentie ca aici trebuie implementat ce trebuie ca sa mearga cand vreau sa scot element din stiva vida
}
Element_t peek(Stack_t s){
	Element_t el=s->st[s->sp-1];
#if DEBUG==1
	printf("Stiva are varful la %u si elementul este %u\n",s->sp, el);
#endif
    return el;
}
