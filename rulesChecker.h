//
// Created by Michal on 08.01.2019.
//

#ifndef LAB3_RULESCHECKER_H
#define LAB3_RULESCHECKER_H


#include "chessBoard.h"

class rulesChecker {

    chessBoard*  Board;
    void checkPawnMove(vector<vertexes>& possibilities, int x, int y);
    void checkKnightMove(vector<vertexes> &possibilities, int x, int y);
    void checkKingMove(vector<vertexes> &possibilities, int x, int y);
    void checkRookMove(vector<vertexes> &possibilities, int x, int y);
    void checkBishopMove(vector<vertexes> &possibilities, int x, int y);
    void checkQueenMove(vector<vertexes> &possibilities, int x, int y);
    bool inBoard(vertexes v);
    bool isAttack(vertexes v, int colour);
    void checkUp(vector<vertexes> &possibilities, int x, int y);
    void checkDown(vector<vertexes> &possibilities, int x, int y);
    void checkRight(vector<vertexes> &possibilities, int x, int y);
    void checkLeft(vector<vertexes> &possibilities, int x, int y);
    void checkUpLeft(vector<vertexes> &possibilities, int x, int y);
    void checkUpRight(vector<vertexes> &possibilities, int x, int y);
    void checkDownLeft(vector<vertexes> &possibilities, int x, int y);
    void checkDownRight(vector<vertexes> &possibilities, int x, int y);
    bool canAddToPossibilities(vertexes temp);


public:

    rulesChecker();
    vector<vertexes> checkMove(int x, int y);

};


#endif //LAB3_RULESCHECKER_H
