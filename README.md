# A Sudoku Solver in C

This is a port of a project I did during my Harvard CS class.  The original program was written in Java and 
much of the nonessential code was written by the prof.  I've gone back through it, rewritten it all in C and 
made it much more my own.

If you'd like to read about how I wrote this and how it works, check out my blog post [here](https://zhaba.dev/2021/01/04/Programming-a-Sudoku-Solver-in-C.html)

# How to use

1. Make a .txt file with the initial puzzle, adding spaces between each number and using 0 for blank spaces.  A few example 
   puzzles have been provided in the "Test puzzles" folder.
   
2. Use the CLI command "Sudoku [filename.txt]"

3. Enjoy your solved puzzle


# Python Extensions for the Sudoku Solver: The Very Overengineered Sudoku Solver

My original intention with this program was to just let it exist as a C program
and move on to something else.  Though I got the bright idea to try something new
and see if I could 1. make python bindings for the C functions and 2. combine it
with OpenCV to solve sudoku puzzles using a webcam rather than having to manually
write out sudoku puzzles in a text file.

If everything goes well, you should be able to start this from a command line, hold
up a sudoku puzzle to your webcam and have a solved printout of that puzzle within a
few seconds or add an image as a command line argument and solve from that. 

The only bottleneck is that I don't really know how to extend python with C nor do I
know anything about using OpenCV/Tensorflow, so it might be a little bit before 
everything is working how it should.  Regardless, this gives me a great reason to 
learn a lot of things that I've wanted to dip my toes into, mainly OpenCV, Tensorflow,
and extending Python with C. (I particularly like extending python with C because I like
C much more than I do python, but I also love how easy it is to write Python).

# Planned Updates
## Main Functionality
1. Tensorflow Integration
   - This will remove the largest bottleneck in the system and let you
   read in a puzzle as an image file rather than having to go through 
   and write out the puzzle as a raw text file.

2. OpenCV Integration
   - I don't really know how I'll go about implementing this, since
   solving the major bottleneck has more to do with adding tensorflow 
   than letting you read a puzzle in from a webcam.  But regardless, I'd
   like to learn some OpenCV so I'll figure it out. 

## Fancy Features/QOL
1. Add an option to output the solution as an  image rather
   than a text file
   - This will probably be the first thing I implement once 
   I've got the Python bindings figured out.  I've done it 
   before with my Cyberpunk 2020 character creator and it's 
   quite simple to implement.
   
2. Add option to solve from a single image rather than a video feed.
   - This would mean the program would cover all the bases.  You could
   choose either to solve from a raw text file, a screenshot or picture
   of a puzzle, or from a webcam feed of 

3. Make the command line argumet parsing a bit more formal
   - This is really just adding a formal set of command line options
   for each of the new features added above.  There will be options 
   to solve from a raw text file, a single image, or a video feed
   
|Python Packages to be used|
|--------------------------|
|Tensorflow | Pull out the numbers from a picture of a sudoku puzzle|
|OpenCV | Image Processing and preppping for tensorflow|
|--------------------------|
