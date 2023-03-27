# include <stdio.h>

# define MaxNumbers 10
# define DefaultFirstIndex 0

void insertionSort(int list[], int lo, int hi) {

    // O(n^2)
    void insertInPlace(int, int [], int, int);
    for (int h = lo + 1; h <= hi; h++) {
        insertInPlace(list[h], list, lo, h - 1);
    }
}

void insertInPlace(int newItem, int list[], int m, int n) {

    int k = n;
    while (k >= m && newItem < list[k]) {
        list[k + 1] = list[k];
        --k;
    }
    list[k + 1] = newItem;
}

int main() {
    void insertionSort(int [], int, int);
    int num[MaxNumbers];
    printf("Type up to %d numbers followed by 0\n", MaxNumbers);
    int n = 0, v;
    scanf("%d", &v);
    while (v != 0 && n < MaxNumbers) {
        num[n++] = v;
        scanf("%d", &v);
    }
    if (v != 0) {
        printf("\nMore than %d numbers entered\n", MaxNumbers);
        printf("First %d used\n", MaxNumbers);
    }
    insertionSort(num, DefaultFirstIndex, MaxNumbers - 1);
    printf("\nThe sorted numbers are\n");
    for (int h = 0; h < n; h++) printf("%d ", num[h]);
    printf("\n");

    return 0;
}