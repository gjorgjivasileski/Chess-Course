#include "board.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(condition)                                                      \
    do {                                                                      \
        if (!(condition)) {                                                   \
            fprintf(stderr, "Check failed at %s:%d: %s\n",                    \
                    __FILE__, __LINE__, #condition);                          \
            return EXIT_FAILURE;                                              \
        }                                                                     \
    } while (0)

int main(void)
{
    static const char expected[] =
        "    a   b   c   d   e   f   g   h\n"
        "  +---+---+---+---+---+---+---+---+\n"
        "8 | k | # |   | # |   | # |   | r | 8\n"
        "  +---+---+---+---+---+---+---+---+\n"
        "7 | # |   | # |   | # |   | # |   | 7\n"
        "  +---+---+---+---+---+---+---+---+\n"
        "6 |   | # |   | # |   | # |   | # | 6\n"
        "  +---+---+---+---+---+---+---+---+\n"
        "5 | # |   | # |   | # |   | # |   | 5\n"
        "  +---+---+---+---+---+---+---+---+\n"
        "4 |   | # |   | # |   | # |   | # | 4\n"
        "  +---+---+---+---+---+---+---+---+\n"
        "3 | # |   | # |   | # |   | # |   | 3\n"
        "  +---+---+---+---+---+---+---+---+\n"
        "2 |   | # |   | # |   | # |   | # | 2\n"
        "  +---+---+---+---+---+---+---+---+\n"
        "1 | R |   | # |   | # |   | # | K | 1\n"
        "  +---+---+---+---+---+---+---+---+\n"
        "    a   b   c   d   e   f   g   h\n";
    Board board;
    FILE *output;
    char actual[sizeof expected];
    size_t length;

    board_init(&board);
    for (int rank = 0; rank < BOARD_SIZE; ++rank) {
        for (int file = 0; file < BOARD_SIZE; ++file) {
            CHECK(board.squares[rank][file] == PIECE_EMPTY);
        }
    }

    board.squares[0][0] = PIECE_WHITE_ROOK;
    board.squares[0][7] = PIECE_WHITE_KING;
    board.squares[7][0] = PIECE_BLACK_KING;
    board.squares[7][7] = PIECE_BLACK_ROOK;

    output = tmpfile();
    CHECK(output != NULL);
    board_print(&board, output);
    CHECK(fseek(output, 0, SEEK_SET) == 0);
    length = fread(actual, 1, sizeof actual - 1, output);
    actual[length] = '\0';
    CHECK(!ferror(output));
    CHECK(strcmp(actual, expected) == 0);
    CHECK(fgetc(output) == EOF);
    CHECK(!ferror(output));
    CHECK(fclose(output) == 0);

    puts("Board tests passed.");
    return EXIT_SUCCESS;
}
