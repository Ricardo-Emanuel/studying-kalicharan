# include <stdio.h>
# include <stdlib.h>

// Código completamente inútil para testar ponteiros e malloc()

typedef struct {
    int *pointer;
    int counter;
} pointerArr;

pointerArr insertArray(int newItem, int list[], int size) {

    int countElem(int [], int);
    pointerArr temp;
    int *p;
    int counter = countElem(list, size);

    if (size < counter + 1) {
        p = malloc((counter + 1) * sizeof(int));
        if (p == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        else {
            for (int i = 0; i < size; i++) {
                p[i] = list[i];
            }
            p[counter] = newItem;
        }
    } 
    else {
        p = list;
        p[counter] = newItem;
    }
    temp.pointer = p;
    temp.counter = counter;

    return temp;
}

int countElem(int arr[], int size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) counter++;
    }
    return counter;
}

int main() {

    pointerArr insertArray(int, int [], int);
    int list[4] = {1,2,3};
    int size = sizeof(list)/sizeof(int);
    
    pointerArr p = insertArray(1, list, size);
    
    for (int i = 0; i < p.counter+1; i++){
        printf("%d ", p.pointer[i]);
    }

    free(p.pointer);
    return 0;
}
