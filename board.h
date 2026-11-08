#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>

#define BOARD_SIZE 8

typedef enum {
    PIECE_EMPTY = ' ',
    PIECE_WHITE_PAWN = 'P',
    PIECE_WHITE_KNIGHT = 'N',
    PIECE_WHITE_BISHOP = 'B',
    PIECE_WHITE_ROOK = 'R',
    PIECE_WHITE_QUEEN = 'Q',
    PIECE_WHITE_KING = 'K',
    PIECE_BLACK_PAWN = 'p',
    PIECE_BLACK_KNIGHT = 'n',
    PIECE_BLACK_BISHOP = 'b',
    PIECE_BLACK_ROOK = 'r',
    PIECE_BLACK_QUEEN = 'q',
    PIECE_BLACK_KING = 'k'
} Piece;

typedef struct {
    /* Rank 0 is 1, and file 0 is a. */
    Piece squares[BOARD_SIZE][BOARD_SIZE];
} Board;

void board_init(Board *board);
void board_print(const Board *board, FILE *stream);

#endif
