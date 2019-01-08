//
// Created by Michal on 03.01.2019.
//

#ifndef LAB3_CHESSBOARD_H
#define LAB3_CHESSBOARD_H

#include<string>
#include "Field.h"
#include <vector>

using namespace std;
struct vertexes {
    int X;
    int Y;
};


class chessBoard {
    Field board[8][8];
    bool inBoard(vertexes v);
    void setPawns();
    void setKings();
    void setQueens();
    void setBishops();
    void setRooks();
    void setKnights();
    void checkPawnMove(vector<vertexes>& possibilities, int x, int y);
    void checkKnightMove(vector<vertexes> &possibilities, int x, int y);




public:
    chessBoard();
    Field& getBoard(int X ,  int Y);
    void setBoard();
    void move(vertexes from, vertexes to);
    void show();
    vector<vertexes> checkMove(int x, int y);




};


#endif //LAB3_CHESSBOARD_H
