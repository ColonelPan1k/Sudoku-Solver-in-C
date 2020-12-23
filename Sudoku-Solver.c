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



int
main(int argc, char** argv)
{
        
        Puzzle* p = loadPuzzle(argv[1]);



        free(p);
        return 0;
}
