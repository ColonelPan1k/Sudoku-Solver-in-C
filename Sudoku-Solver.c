/* Sudoku Solver in C
 * 
 * Use 0 for blank values when writing out a puzzle
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEFAULT_FILESIZE 169


/* 
 * subgridHasVal[x][y][val]
 * Uses x,y coords of the subgrids, ie
 * (0,0) (0,1) (0,2)
 * (1,0) (1,1) (1,2)
 * (2,0) (2,1) (2,2)
 *
 * All txt files for this program will have a constant filesize
 */ 

typedef struct
puzzle_t
{
        int values[9][9];
        bool isFixed[9][9];
        bool subgridHasVal[2][2][9];
        bool colHasVal[9][9];
        bool rowHasval[9][9];
        
}Puzzle;

Puzzle*
loadPuzzle(char* fileName)
{
        /* Initialize new puzzle */
        Puzzle* p = (Puzzle*)malloc(sizeof(Puzzle));

        memset(p->values, 0, 81);
        memset(p->isFixed, 0, 81);
        memset(p->colHasVal, 0, 81);
        memset(p->rowHasval, 0, 81);
        memset(p->subgridHasVal, 0, 36);

        /* Read contents of file into puzzle 
         * and set values based on those nums
         */
        
        FILE *fp;
        fp = fopen(fileName, "r");

        // Having trouble reading the contents of the file into
        // a buffer properly

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
