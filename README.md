# geography-game


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

## Develop

### Run

To run (generate QBF formula): `make run`

The input is taken from `./input.txt`.
The output is redirected to `./test.qcir`.

To run QBF solver: `./lib/quabs --partial-assignment ./test.qcir`

## Input format

All nodes must be numbers between 0 and 9.

The start node is on the first line. For the next lines, each contains two numbers `(u, v)` indicating an edge from `u` and `v`. There must be an edge to `u` before adding any edges from `u`.

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

