# geography-game

This program works for any graph with nodes labeled from 0-9. The game is encoded into 6 conditions (see `./src/solver.cpp` for details):
- Condition 1: No two nodes are chosen at the same step
- Condition 2: Step i-th must not be visited before
- Condition 3: Step i-th must be adjacent to step (i+1)-th
- Condition 4: Step i-th must be adjacent to step (i-1)-th
- Condition 5: First step must be adjacent to root
- Condition 6: Winning condition

## Commands

### Run

`make run`: converts the graph to qucir formulas and use the QBF solver to solve.

The input is taken from `./input.txt`.
The formula can be found at `./test.qcir`.

### Solve
`make solve`: runs QBF solver without generating the formula.

## Input format

All nodes must be numbers between 0 and 9.

The start node is on the first line. For the next lines, each contains two numbers `(u, v)` indicating an edge from `u` and `v`.

Ex:

```
0
0 1
0 2
1 3
1 4
3 6
4 7
2 5
```
<img width="547" alt="Screenshot 2022-11-20 at 12 21 00 AM" src="https://user-images.githubusercontent.com/81574365/202886968-a977f8d2-388b-4e7a-ac1f-1c175e10a702.png">

## Ouput format

If there's a way for the first user to win, prints out the steps.

**Ex:** the output of the graph above:

```
Player 1 chooses 1
Player 2 chooses 3
Player 1 chooses 6
```
