#include "board.h"

int main(void)
{
    Board board;

    board_init(&board);
    board_print(&board, stdout);
    return 0;
}
