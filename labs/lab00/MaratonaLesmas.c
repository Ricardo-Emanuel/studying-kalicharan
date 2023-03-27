# include <stdio.h>
# include <stdlib.h>

int canFinish(int time, int speed) {
    switch (time) {
        case 1:
            if (speed <= 100) return 1;
            return 0;
        case 2:
            if (speed <= 20) return 1;
            return 0;
        case 3:
            if (speed <= 10) return 1;
            return 0;
        default:
            return 0;
    }
}

int max(int a, int b) {
    if (a > b) return a;
    else {
        return b;
    }
}

int main() {

    int canFinish(int, int);
    int max(int, int);
    void printArray(int[], int);

    int n, time;
    int result = 0;
    int *array;

    scanf("%d", &n);
    if (n > 0) {
        array = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
        scanf("%d", &time);

        for (int i = 0; i < n; i++) {
            if (canFinish(time, array[i])) {
                result = max(result, array[i]);
            }
        }
        free(array);
        if (result > 0) printf("%d", result);
        else printf("%d", -1);
    }
    else {
        puts("The size is invalid!");
        return 1;
    }
    return 0;
}