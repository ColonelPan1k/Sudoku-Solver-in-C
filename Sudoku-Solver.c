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
#define SUBGRID_DIM = 3;

typedef struct
puzzle_t
{
        int values[DIM][DIM];
        bool isFixed[DIM][DIM];
        bool subgridHasVal[2][2][9];
        bool colHasVal[9][9];
        bool rowHasval[9][9];
        
}Puzzle;

Puzzle*
loadPuzzle(char* fileName)
{

        Puzzle* p = (Puzzle*)malloc(sizeof(Puzzle));

        memset(p->values, 0, 81);
        memset(p->isFixed, 0, 81);
        memset(p->colHasVal, 0, 81);
        memset(p->rowHasval, 0, 81);
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
                        
                        p->values[row][col] = puzzleVal - 48;
                        printf("%i. [%i][%i]: %i\n", i, row, col, p->values[row][col]);
                        
                        ++i;
                }
        }

                

                


        fclose(fp);
        return p;
}

int isSafe(Puzzle* p, int val, int row, int col)
{
        //TODO
}

void
placeVal(Puzzle* p, int val, int row, int col)
{
        p->values[row][col] = val;
        p->subgridHasVal[row / SUBGRID_DIM][col / SUBGRID_DIM][val] = true;
        p->rowHasval[row][val] = true;
        p->colHasVal[col][val] = true;
}

void
removeVal(Puzzle* p, int val, int row, int col)
{
        p->values[row][col] = 0;
        p->subgridHasVal[row / SUBGRID_DIM][col / SUBGRID_DIM][val] = false;
        p->rowHasval[row][val] = false;
        p->colHasVal[col][val] = false;

}

int
solvePuzzle(Puzzle* p, int n){
        if (n == 81){
                return true;
        }

        int row = n / 9;
        int col = n % 9;

        if (p->isFixed[row][col]){
                if(solvePuzzle(p, (n+1))){
                        return true;
                }
        }

        for (int val = 1; val < DIM + 1; ++val){
                if(isSafe(p, val, row, col)){
                        placeVal(p, val, row, col)
                

                        if (solvePuzzle(p, n+1)){
                            return true;
                        }
                        
                        removeVal(p, row, col, val);
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
        //TODO
}

int
main(int argc, char** argv)
{
        
        Puzzle* p = loadPuzzle(argv[1]);

        if(WRAPPER_Solve(p) == 1){
                printf("Solution found\n");
                // printPuzle(p);
        } else {
                printf("Something went wrong\n");
        }
        
        free(p);
        return 0;
}
