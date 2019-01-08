//
// Created by Michal on 07.01.2019.
//

#ifndef LAB3_FIELD_H
#define LAB3_FIELD_H

#include <string>
#include "chessPiece.h"

using namespace std;




class Field {
    chessPiece *chessMan = nullptr;

public:
    chessPiece* getChessMan();
    void setChessMan(chessPiece* sth );

};


#endif //LAB3_FIELD_H
