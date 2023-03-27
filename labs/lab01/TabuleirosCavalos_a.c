# include <stdio.h>
# include <stdlib.h>

// Registro usado para definir a posição de um cavalo no tabuleiro
typedef struct {
    int row;
    int col;
} position;

// Returns the initial position 
position translateInput(char a, int b) {
    int row = b - 1;
    int col = a - 'A';
    position pos = {row, col};
    return pos;
}

// Checa e printa todos os movimentos possíveis
void checkMoves(position init) {
    const int MAX = 8;
    int rowMoves[] = {2, 2, 1, -1, -2, -2, -1, 1};
    int colMoves[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    
    // Laço usado para verificar todos os movimentos
    for (int i = 0; i < MAX; i++) {
        int newRow = init.row + rowMoves[i];
        int newCol = init.col + colMoves[i];

        // Validação do movimento
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            printf("%c %d\n", newCol + 'A', newRow + 1);
        }
    }
}

int main()
{
    void checkMoves(position);
    position translateInput(char, int);

    int row;
    char col;
    scanf(" %c %d", &col, &row);
    position pos = translateInput(col, row);
    checkMoves(pos);

    return 0;
}
