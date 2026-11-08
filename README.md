# Chess board

A plain C program that prints an empty 8x8 chessboard. It does not yet
implement moves or chess rules.

## Build and run

You need a C11 compiler and `make`.

```sh
make
./chess
```

Run `make test` to check the board and `make clean` to remove build files.

## Board representation

`board.h` defines the board and piece types; `board.c` initializes and prints
the board. In `board.squares[rank][file]`, rank 0 is 1 and file 0 is a:

```c
board.squares[0][0] = PIECE_WHITE_ROOK; /* a1 */
board.squares[7][7] = PIECE_BLACK_ROOK; /* h8 */
```

In the output, `#` marks an empty dark square. Piece letters are uppercase for
white and lowercase for black: P (pawn), N (knight), B (bishop), R (rook),
Q (queen), and K (king).
