Assignment_2/CS 2303

Fivos Kavassalis -- fikavassalis

The program that is created is a simulation of the “Game of Life” by John Conway. It begins by readingthe input from the command-shell. After that, it processes the arguments given and decides whether it can keep going with these data (Arguments in command-shell must be between (including) 0 and 7, rows and columns must be positive, valid txt file and print, pause requirements (‘y’ or ‘n’, etc.)). Then, it allocates memory for 4 arrays and fills them with zero: the past generation, the current generation, the next generation and an empty array for an empty board (when all cells are dead). Then, the program reads one line at a time and counts the characters for each line, it closes the file and allocates memory according to the calculations done above. It opens and reads the file again and assigns ‘x’, ‘o’ to 1 and 0 accordingly. In the case of unexpected characters, an error is thrown. Then, the program centers the “shape” of the generation (territory of alive population, taken from input file) by subtracting the rows, columns of the input file from the rows and columns requested by the user, and divide by 2 (rounding-up result). Therefore, shape of population is put after those resulting numbers of cells of columns androws (This centered result is assigned to the current2D array which is the array of the of the current generation). Then the manyGens() function is called, which is where the game is played. This function
assigns the current array to the past generation array and plays one generation. In each generation the program iterates through each cell, to count its neighbors and judge whether this cell will die, survive, or come to life. After each generation, the next generation array is assigned to the current generation
array. If the user requested for printing, each generation array is printed with its corresponding numerical value (Game starts from 0 generation = input file configuration). If pausing is requested, the program waits for the user to press a key in the keyboard, and then continue with the next generation. The program is designed to stop after the requested number of generations, except if the generations repeat the same configuration contiguously, or if all cells are dead (This is why I needed the empty array). Finally, the program prints the final configuration again, so it is shown more clearly.


In order for the program to compile and run in the command shell, type:

1) make all

2) ./life X Y gens input [print] [pause]
      where x is rows, y is columns, gens is generations input is the input .txt file and the
      optional arguments: print, pause.
