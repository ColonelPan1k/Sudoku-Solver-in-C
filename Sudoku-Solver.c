/* Sudoku Solver in C
 * 
 * Use 0 for blank values when writing out a puzzle
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DIM 9
#define SUBGRID_DIM  3

typedef struct
puzzle_t
{
        int values[DIM][DIM];
        bool isFixed[DIM][DIM];
        bool subgridHasVal[2][2][9];
        bool colHasVal[9][9];
        bool rowHasVal[9][9];
        
}Puzzle;

Puzzle*
loadPuzzle(char* fileName)
{

        Puzzle* p = (Puzzle*)malloc(sizeof(Puzzle));

        memset(p->values, 0, 81);
        memset(p->isFixed, 0, 81);
        memset(p->colHasVal, 0, 81);
        memset(p->rowHasVal, 0, 81);
        memset(p->subgridHasVal, 0, 36);
        
        FILE *fp;
        fp = fopen(fileName, "r");

        int puzzleVal;
        int i = 0;
        int buffer[81];
        
        while((puzzleVal = fgetc(fp)) != EOF){
                if (puzzleVal >= 48 && puzzleVal <=57){
                        int row = i / 9;
                        int col = i % 9;
                        int val = puzzleVal - 48;

                        p->values[row][col] = val;
                        
                        if( val > 0){
                                p->isFixed[row][col]   = true;
                                p->rowHasVal[row][val] = true;
                                p->colHasVal[col][val] = true;
                                p->subgridHasVal[row / SUBGRID_DIM][col / SUBGRID_DIM][val] = true;
                                }
 
                        ++i;
                }
        }


        fclose(fp);
        return p;
}

int isSafe(Puzzle* p, int val, int row, int col)
{
        return (!(p->rowHasVal[row][val])
                && !(p->colHasVal[col][val])
                && !(p->subgridHasVal[row / SUBGRID_DIM][col / SUBGRID_DIM][val])
                && !(p->isFixed[row][col])                );
}

void
placeVal(Puzzle* p, int val, int row, int col)
{

        p->values[row][col] = val;
        p->subgridHasVal[row / SUBGRID_DIM][col / SUBGRID_DIM][val] = true;
        p->rowHasVal[row][val] = true;
        p->colHasVal[col][val] = true;
        printf("placed val: %i\n", val);
}

void
removeVal(Puzzle* p, int val, int row, int col)
{
        p->values[row][col] = 0;
        p->subgridHasVal[row / SUBGRID_DIM][col / SUBGRID_DIM][val] = false;
        p->rowHasVal[row][val] = false;
        p->colHasVal[col][val] = false;

}

/* I'm copying in my original notes to help me think this through */
int
solvePuzzle(Puzzle* p, int n){

        printf("%i\n", n);
        if (n == 81){
                return true;
        }


        
        int row = n / 9;
        int col = n % 9;

        if (p->isFixed[row][col]){
                if( solvePuzzle(p, n + 1)){
                        return true;
                }
        }

        for (int val = 1; val < 9; ++val){
                if (isSafe(p, val, row, col)){
                        placeVal(p, val, row, col);

                        if (solvePuzzle(p, n + 1)){
                                return true;
                        }


                        removeVal(p, val, row, col);
                }
        }

        return false;
}

int
WRAPPER_Solve(Puzzle* p)
{
        int found = solvePuzzle(p, 0);
        return found;
}

void
printPuzzle(Puzzle* p)
{
        // Still need to fix, this is just to test if it's working
        for(int row = 0; row < 9; ++row){
                for (int col = 0; col < 9; ++col){
                        printf("%i ", p->values[row][col]);
                }
                putchar('\n');
        }
}

int
main(int argc, char** argv)
{
        
        Puzzle* p = loadPuzzle(argv[1]);

        printf("Your initial puzzle looks like this:\n");
        printPuzzle(p);

        int result = WRAPPER_Solve(p);
        if(result == 1){
                printf("Solution found\n");
                printPuzzle(p);
        } else if (result == 0) {
                printf("Something went wrong\n");
                printPuzzle(p);
        } else {
                printf("Something isn't right, the program returned: %i\n", result);
        }
        
        
        free(p);
        return 0;
}
