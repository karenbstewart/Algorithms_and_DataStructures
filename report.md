# Noughts and Crosses Game 
## Coursework for ALGORITHMS and DATA STRUCTURES class SET 08122
## noughts_and_crosses.c

### INTRODUCTION
This purpose of this coursework was to design and implement a noughts and crosses game written in the C programming language. I worked on designing both a PLAYER vs PLAYER mode of the game and a PLAYER vs COMPUTER mode. Looking to save the inputted commands in Array of different data types so they could be utilised at different areas of the code to achieve different outcomes. (ie, knowing when a row of 3 matching symbols had been reached so that a winner could be declared)

### DESIGN

### ENHANCEMENTS 

* #### Undo and Redo behaviour during game play

I would I implement a struct data structure set set an algorithm to make it run as a Stack, the data within this feature would be stored in persistent memory on the heap using malloc. With this data structure set up to run as a Stack. Each command given by the players would be pushed onto the stack then when *popped off* it would create the undo behaviour necessary. With this feature it makes it a LIFO (Last In First Off) data structure and is perfect for an undo facility in the game, to undo the last position where either a nought or a cross was placed

* #### Earlier games to be automatically replayed from memory

Queue
Moves stored in persistent memory on the heap using malloc

* #### Players able to sizing up the game board to be of a bigger size (ie a 5 by 5 board or 10 by 10)
### CRITICAL EVALUATION

### PERSONAL EVALUATION
