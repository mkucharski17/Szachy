//
// Created by Michal on 03.01.2019.
//

#include "chessBoard.h"

chessBoard::chessBoard() {
    for(int i = 0 ; i < 8 ; i++)
        for(int j = 0 ; j < 8 ; j++)
            board[i][j] = Field();
}


Field& chessBoard::getBoard(int X , int Y) {
    return board[X][Y];
}