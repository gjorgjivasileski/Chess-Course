#include "board.h"

void board_init(Board *board)
{
    for (int rank = 0; rank < BOARD_SIZE; ++rank) {
        for (int file = 0; file < BOARD_SIZE; ++file) {
            board->squares[rank][file] = PIECE_EMPTY;
        }
    }
}

void board_print(const Board *board, FILE *stream)
{
    static const char labels[] = "    a   b   c   d   e   f   g   h\n";
    static const char border[] = "  +---+---+---+---+---+---+---+---+\n";

    fputs(labels, stream);
    for (int rank = BOARD_SIZE - 1; rank >= 0; --rank) {
        fputs(border, stream);
        fprintf(stream, "%d |", rank + 1);
        for (int file = 0; file < BOARD_SIZE; ++file) {
            Piece piece = board->squares[rank][file];
            char symbol = piece == PIECE_EMPTY
                ? ((rank + file) % 2 == 0 ? '#' : ' ')
                : (char)piece;
            fprintf(stream, " %c |", symbol);
        }
        fprintf(stream, " %d\n", rank + 1);
    }
    fputs(border, stream);
    fputs(labels, stream);
}
