#include "stdio.h"
#include "stdlib.h"

#include "definitii.h"

#define F1 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define F2 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"
#define F3 "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"

int main(void)
{
    initializare();

    S_BOARD tab[1];

    ParseFEN(START_FEN, tab);
    PrintBoard(tab);

    ParseFEN(F1, tab);
    PrintBoard(tab);

    ParseFEN(F2, tab);
    PrintBoard(tab);

    ParseFEN(F3, tab);
    PrintBoard(tab);

    return 0;
}