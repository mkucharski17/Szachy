//
// Created by Michal on 15.01.2019.
//

#ifndef LAB3_GAMESTATUS_H
#define LAB3_GAMESTATUS_H


#include "chessBoard.h"
#include "rulesChecker.h"

class gameStatus {

    chessBoard* board;
    rulesChecker* judge;

public:
    gameStatus();
    bool isCheck(int colour);
    bool isPat();

};


#endif //LAB3_GAMESTATUS_H
