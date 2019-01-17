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

/*following class represents chessboard
 * */
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

    Field &getBoard(int X, int Y);

    void setBoard();

    void move(vertexes from, vertexes to);

    void show();

    chessBoard &operator=(chessBoard &primaryBoard);

    bool inBoard(vertexes v);

    bool isAttack(vertexes v, int colour);


};


#endif //LAB3_CHESSBOARD_H
