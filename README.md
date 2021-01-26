# Sudoku-Solver-in-C

This is a simple CLI sudoku solver that I've ported over from Java.  I wrote the main parts of the original Java version over the summer for a Harvard CS class and 
I thought it would be fun to rewrite the project in C.  Currently, the biggest bottleneck for this is actually getting the puzzle into the program.  It takes a few
minutes to transcribe the puzzle into a readable text file. For now, I have plans to add some module to generate puzzles, which can then be fed back into the 
program and solved.  Further in the future, I'd like to play around with some openCV in python and see if I can use computer vision to trasnscribe the puzzle, but
that's still a loooong ways off.

If you'd like to read about how I wrote this and how it works, check out my blog post [here](https://zhaba.dev/2021/01/04/Programming-a-Sudoku-Solver-in-C.html)

# How to use

1. Make a .txt file with the initial puzzle, adding spaces between each number and using 0 for blank spaces.  A few example 
   puzzles have been provided in the "Test puzzles" folder.
   
2. Compile using "gcc Sudoku-Solver.c -o Sudoku"
   
3. Use the CLI command "Sudoku [filename.txt]"

4. Enjoy your solved puzzle
