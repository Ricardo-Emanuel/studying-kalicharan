# include <stdio.h>
# include <stdlib.h>
// ISSO AQUI NAO PASSA DE UM TESTE

typedef struct _vector{float *val; int len;} Vector;

Vector *createVector(int n){Vector *u = (Vector *)calloc(1, sizeof(Vector)); u->val = (float *)calloc(n, sizeof(float)); u->len = n; return u;}
void destructVector(Vector **u){if((*u) != NULL){if((*u)->val != NULL) free((*u)->val); free(*u); (*u) = NULL;}}

int main(){Vector *a = createVector(2); printf("%d", a->len); destructVector(&a); return 0;}