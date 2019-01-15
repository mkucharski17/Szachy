//
// Created by Michal on 15.01.2019.
//

#include <iostream>
#include "gameStatus.h"

gameStatus::gameStatus() {
    judge = new rulesChecker();
    board = new chessBoard();
    board->setBoard();
}

bool gameStatus::isCheck(int colour) {
    vector<vertexes> possibilities;
    vector<vertexes>::iterator it;

    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            if (board->getBoard(j, i).isEmpty() || board->getBoard(j, i).getChessMan()->getColour() == colour)
                continue;
            else {
                possibilities = judge->checkMove(j, i, board);
                for (it = possibilities.begin(); it - 1 != possibilities.end(); it++) {
                    if (board->getBoard(it->X, it->Y).getChessMan()->getName() == "King")
                        return true;

                }
            }
        }
    }
    return false;
}

bool gameStatus::isPat() {
    vector<vertexes> possibilities;

    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            if (board->getBoard(j, i).isEmpty())
                continue;
            else {
                if (!possibilities.empty())
                    return false;
            }
        }
    }
    return true;
}
