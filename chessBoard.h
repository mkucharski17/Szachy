//
// Created by Michal on 03.01.2019.
//

#ifndef LAB3_CHESSBOARD_H
#define LAB3_CHESSBOARD_H

#include<string>

using namespace std;

struct field{
    bool Empty = false;
    string pieceName;
};


class chessBoard {
    field board[8][8];

public:
    chessBoard();
};


#endif //LAB3_CHESSBOARD_H
