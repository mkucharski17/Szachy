//
// Created by Michal on 15.01.2019.
//

#ifndef LAB3_GAMESTATUS_H
#define LAB3_GAMESTATUS_H


#include "chessBoard.h"
#include "rulesChecker.h"
/*
 * use following class to checking what is the status of the game
 * */
class gameStatus {

    chessBoard* board;
    rulesChecker* judge;

public:
    gameStatus();
    bool isCheck(int colour);
    bool isPat();
    void loadBoard(chessBoard *source);

};


#endif //LAB3_GAMESTATUS_H
