# Noughts and Crosses Game 
## Coursework for ALGORITHMS and DATA STRUCTURES class SET 08122
## noughts_and_crosses.c

### INTRODUCTION
This purpose of this coursework was to design and implement a noughts and crosses game written in the C programming language. I worked on designing both a PLAYER vs PLAYER mode of the game and a PLAYER vs COMPUTER mode. Looking to save the inputted commands in Array of different data types so they could be utilised at different areas of the code to achieve different outcomes. (ie, knowing when a row of 3 matching symbols had been reached so that a winner could be declared)

### DESIGN
#### I implemented 2 different types of data structures 
Arrays and structs based around these two types of data structures I implemented different algorithms to allow me to manipulate the data stored within these structures in different ways. 

I implemented algorithms to initiate an array of a specific size outlined in a #define at the start of my program (with the thought behind this being that if I had had the time it would have helped me to implement bigger arrays fit for a larger game board in a simpler way allowing me to reuse existing code already in the program).

#### I also wrote code for algorithms for the arrays to:
* INSERT a character at a specified element position in an array.
* REPLACE one character with another at a specifies element position in an array (This may sound similar to INSERT, but INSERT puts a character at a specific element in an array and moves any existing elements up buy one position in the array. However, REPLACE just directly switches out whatever was at that element number and leaves all the other elements in the array unaltered)
* DELETE a character at a specified element position in an array.
* REVERSE an entire array so the last element becomes the first and vice versa, but keeping all the elements in the original order they were in, just flipped back to front.
* SEARCH
* REMOVE A NEWLINE CHARACTER

#### I also wrote out algorithms myself to allow me to write code to 
* CHECK_WINNER Check if there had been a winner in the game yet on each loop iteration of game play ie. Had was there 3 consecutive characters in the game board that ran either horizontally, vertically or diagonally.
* VS_PLAYER_OR_COMPUTER Did player 1 want to play a game of noughts and crosses against another human component or play a game against the computer?
* ONE_PLAYER
* TWO_PLAYER

#### I then wrote algorithms for the API’s needed to implement behaviour of the data stored in the stack algorithm based round a struct data structure
* INIT_STACK
* PUSH
* POP


### ENHANCEMENTS 

* #### Undo and Redo behaviour during game play

I would I implement a struct data structure set set an algorithm to make it run as a Stack, the data within this feature would be stored in persistent memory on the heap using malloc. With this data structure set up to run as a Stack. Each command given by the players would be pushed onto the stack then when *popped off* it would create the undo behaviour necessary. With this feature it makes it a LIFO (Last In First Off) data structure and is perfect for an undo facility in the game, to undo the last position where either a nought or a cross was placed

* #### Earlier games to be automatically replayed from memory

Queue
Moves stored in persistent memory on the heap using malloc

* #### Players able to sizing up the game board to be of a bigger size (ie a 5 by 5 board or 10 by 10)
### CRITICAL EVALUATION

### PERSONAL EVALUATION

