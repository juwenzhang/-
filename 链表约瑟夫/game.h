#ifndef GAME_H
#define GAME_H

struct Boy {
    int code;
    Boy* pNext;
};

void playGame(int numOfBoys, int m, int k);

#endif