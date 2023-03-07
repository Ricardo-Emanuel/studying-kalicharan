// String sort using insertion sort
# include <stdio.h>
# include <string.h>

# define MaxNameSize 14
# define MaxNameBuffer MaxNameSize + 1
# define MaxNames 8

// This is a regular insertion sort but sorts strings
void insertionSort(int lo, int hi, char list[][MaxNameBuffer]) {
    char key[MaxNameBuffer];
    for (int h = lo + 1; h <= hi; h++) {
        strcpy(key, list[h]);
        int k = h - 1;
        while (k >= lo && strcmp(key, list[k]) < 0) {
            strcpy(list[k + 1], list[k]);
            --k;
        }
        strcpy(list[k + 1], key);
    }
}

int main() {
    void insertionSort(int, int, char[][MaxNameBuffer]);
    char name[MaxNames][MaxNameBuffer] = {"Taylor, Victor", "Duncan, Denise", 
                                    "Owen, David", "Khan, Carol", "Ali, Michel",
                                    "Sawh, Anisa", "Ramdhan, Kamal", 
                                    "Singh, Krishna"};
    insertionSort(0, MaxNames-1, name);
    printf("\nThe sorted names are\n\n");
    for (int h = 0; h < MaxNames; h++) printf("%s\n", name[h]);

    return 0;
}