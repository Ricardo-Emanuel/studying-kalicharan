# include <stdio.h>
# include <string.h>

# define max 8

void parallelSort(int lo, int hi, char list[][max], int id[]) {

    char key[max];
    for (int h = lo + 1; h <= hi; h++) {
        strcpy(key, list[h]);
        int m = id[h];
        int k = h - 1;
        while (k >= lo && strcmp(key, list[k]) < 0) {
            strcpy(list[k + 1], list[k]);
            id[k + 1] = id[k];
            --k;
        }
        strcpy(list[k + 1], key);
        id[k + 1] = m;
    }
}

