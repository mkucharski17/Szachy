//
// Created by Michal on 03.01.2019.
//

#ifndef LAB3_CHESSBOARD_H
#define LAB3_CHESSBOARD_H

#include<string>
#include "Field.h"

using namespace std;


class chessBoard {
    Field board[8][8];
    void setPawns();
    void setKings();
    void setQueens();
    void setBishops();
    void setRooks();
    void setKnights();

public:
    chessBoard();
    Field& getBoard(int X ,  int Y);
    void setBoard();



};


#endif //LAB3_CHESSBOARD_H
