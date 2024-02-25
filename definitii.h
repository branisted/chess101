#ifndef DEFINITII_H

#define DEFINITII_H

#include "stdlib.h"

/* DEBUG */

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if (!(n)) { \
printf("%s - Failed ", #n); \
printf("On %s ", __DATE__); \
printf("At %s ", __TIME__); \
printf("In File %s ", __FILE__); \
printf("At Line %d ", __LINE__); \
exit(1);}
#endif

typedef unsigned long long U64;

#define NAME "brad 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };

enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

enum { WHITE, BLACK, BOTH };

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE };

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 }; // permisiune de rocada

typedef struct {

    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    U64 posKey;
    
} S_UNDO;


typedef struct {

    int piese[BRD_SQ_NUM]; // tabla

    U64 pawns[3]; // 3x 8 * 8 biti ca sa reprezinte pozitia pionilor de fiecare culoare de pe fiecare patrat

    int KingSq[2]; // unde se afla regele

    int side;
    int enPas;
    int fiftyMove; // 100 de fapt, deoarece numaram jumatati de miscari

    int ply; // legat de cautari, miscari
    int hisPly;

    int castlePerm; // permisiunea pt rocada

    U64 posKey; // cheie unica pt fiecare "state" de pozitii din joc

    int pceNum[13]; // nr pieselor
    int bigPce[3]; // ca la pioni, orice in afara de pioni
    int majPce[3]; // piese "majore" - turnuri si regine
    int minPce[3]; // nebuni si knights

    S_UNDO history[MAXGAMEMOVES];

    int pList[13][10]; // lista de piese

} S_BOARD;

/* MACRO */

#define FR2SQ(f, r) ((21 + (f)) + ((r) * 10))
#define SQ64(sq120) Sq120ToSq64[sq120]
#define POP(b) PopBit(b)
#define CNT(b) CountBits(b)

/* GLOBAL */

extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];

/* FUNCTII */

//init.c
extern void initializare();

//bitboards.c
extern void PrintBitBoard(U64 bb);
extern int PopBit(U64 *bb);
extern int CountBits(U64 b);

#endif