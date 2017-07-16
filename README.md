# lem-in
###### An algorithmic exploration of input parsing, recursive backtracking, and output formatting.

Get all the ants from the start to the finish using the fewest number of hops.

## Input parsing:
Instructions:
1.  "make"
2.  "./lem-in -v < maps/long_Chloe"
3.  Observe. ;]

![Input Content](https://raw.githubusercontent.com/wobula/lem_in/master/img1.png)

## Recursive backtracking:
The algorithm first creates a linked list that simulates the structure of the maze.
Next, it starts at the beginning and checks every single door of every room until it finds an exit.
 * No room repeat checks
 * No exit checks
 * Checks for no start and/or finish and/or too many starts/finishes
 * Picks first, shortest path

![Input Content](https://raw.githubusercontent.com/wobula/lem_in/master/img2.png)

## Output formatting:
The syntax of the output is:

1. Re-print input content
2. Print two newlines
3. Print line by line animation of ants traversing through the map
 * The syntax for ant movements is "L[Ant Number]-[Room Number]"
 * Never more than one ant per room, only one movement per turn, per ant

![Input Content](https://raw.githubusercontent.com/wobula/lem_in/master/img3.png)