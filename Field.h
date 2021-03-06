//
// Created by Michal on 07.01.2019.
//

#ifndef LAB3_FIELD_H
#define LAB3_FIELD_H

#include <string>
#include "chessPiece.h"

using namespace std;

/*
 * class Field represent one from 64 fields which are on the chessboard
 * */
class Field {
    chessPiece *chessMan = nullptr;

public:
    chessPiece *getChessMan();

    void setChessMan(chessPiece *sth);

    bool isEmpty();

};


#endif //LAB3_FIELD_H
