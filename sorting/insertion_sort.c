# include <stdio.h>

# define MaxNumbers 10

void insertionSort(int list[], int n) {

    // O(n^2)
    for (int h = 1; h < n; h++) {
        int key = list[h];
        int k = h - 1;
        
        // O(n)
        while (k >= 0 && key < list[k]) {
            list[k + 1] = list[k];
            --k;
        }
        list[k + 1] = key;
    }
}

int main() {
    void insertionSort(int [], int);
    int num[MaxNumbers];
    printf("Type up to %d numbers followed by 0\n", MaxNumbers);
    int n = 0, v;
    scanf("%d", &v);
    while (v != 0 && n < MaxNumbers) {
        num[n++] = v;
        scanf("%d", &v);
    }
    if (v != 0) {
        printf("More than %d numbers entered\n", MaxNumbers);
        printf("First %d used\n", MaxNumbers);
    }
    insertionSort(num, n);
    printf("\nThe sorted numbers are\n");
    for (int h = 0; h < n; h++) printf("%d ", num[h]);
    printf("\n");

    return 0;
}