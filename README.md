# geography-game

## Commands

### Run

`make run`: convert the graph to formulas and use the QBF solver to solve it.

The input is taken from `./input.txt`.
The formula can be found at `./test.qcir`.

### Solve
`make solve`: run QBF solver without generating the formula.

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

### Unsatisfiable

`r UNSAT`

### Statisfiable

There's no way the first user can win.

```
V s1v1 s2v2 s3v3 ...
r SAT
```

`s1v1` is positive if value `v1` is chosen at step `s1`. Otherwise, it's negative.

**Ex:** the output of the graph above:

Output the steps that the first user can win.

```
V 11 -12 -13 -14 -16 -17 -15 -21 -22 23 -24 -26 -27 -25 -31 -32 -33 -34 36 -37 -35 -41 -42 -43 -44 -46 -47 -45 0
r SAT
```
`11, 23, and 36` are postive. That means:

- Step 1: Choose node 1
- Step 2: Choose node 3
- Step 3: Choose node 6


## Usage

### Operators.h > Exists
`Exists(vector<string> arr)` => exists(arr[0], arr[1], ...)

### Operators.h > Forall
`Forall(vector<string> arr)` => forall(arr[0], arr[1], ...)

### Operators.h > And

`And(string n, vector<string> arr)` => n = and(arr[0], arr[1], ...)

### Operators.h > Or

`Or(string n, vector<string> or)` => n = or(arr[0], arr[1], ...)

### Operators.h > write

`write(string s)` => write a string to `./test.qcir`.

### main.cpp > get

`get()` returns the next unused variable.

### main.cpp > getMultiple

`getMultiple(int cnt)` return a vector contains `cnt` unused variables.


