# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
    int row;
    int col;
} position;

// Selection Sort usada para ordenar o array de entrada
void selectionSort(position* array, int n) {
    int i, j, min;
    position temp;
    for (i = 0; i < (n - 1); i++) {
        min = i;
        for (j = (i + 1); j < n; j++) {
            if (array[j].col < array[min].col) {
                min = j;
            } else {
                if (array[j].col == array[min].col) {
                    if (array[j].row < array[min].row) {
                        min = j;
                    }
                }
            }
        }
        if (i != min) {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

// Binary Search usada para verificar se o movimento válido corresponde
// a posição de alguma cavalo existente
int binarySearch(position* array, int n, int keyA, int keyB) {
    int mid, begin, end;
    end = n - 1;
    begin = 0;

    while (end >= begin) {
        mid = (end + begin) / 2;
        if (keyA == array[mid].col) {
            if (keyB == array[mid].row) {
                return 1;
            } else {
                if (keyB > array[mid].row) {
                    begin = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        } else {
            if (keyA > array[mid].col) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
    }
    return -1;
}

// Checa os movimentos validos e usa a binary search
int checkMoves(position* array, int n) {
    int binarySearch(position*, int, int, int);

    const int MAX = 8;
    int flag = 0;

    int rowMoves[] = {2, 2, 1, -1, -2, -2, -1, 1};
    int colMoves[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < MAX; j++) {
            int newRow = array[i].row + rowMoves[j];
            int newCol = array[i].col + colMoves[j];

            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                if (binarySearch(array, n, newCol, newRow) == 1) {
                    printf("Os cavalos estao em guerra!\n");
                    return 1;
                }
            }
        }
    }
    return flag;
}

// Le as posicoes de entrada
void readPositions(position* array, int n) {
    char col;
    int row;
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &col, &row);
        array[i].row = row - 1;
        array[i].col = col - 'A';
    }
}

// Usada para debug
void printPositions(position* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", array[i].col + 'A', array[i].row + 1);
    }
    puts("");
}

int main()
{
    void selectionSort(position*, int);
    void readPositions(position*, int);
    int checkMoves(position*, int);

    int n, flag;
    scanf("%d", &n);
    position* array = (position*)malloc(n * sizeof(position));
    readPositions(array, n);
    selectionSort(array, n);
    flag = checkMoves(array, n);
    if (flag == 0) {
        printf("Paz no reino!\n");
    }

    free(array);
    return 0;
}