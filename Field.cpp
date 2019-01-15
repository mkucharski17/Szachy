//
// Created by Michal on 07.01.2019.
//

#include "Field.h"

chessPiece* Field::getChessMan() {
    return chessMan;
}


void Field::setChessMan(chessPiece *sth) {
    chessMan = sth;
}

bool Field::isEmpty() {
        if(chessMan == nullptr)
            return true;

        return false;
}