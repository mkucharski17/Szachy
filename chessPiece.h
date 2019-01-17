//
// Created by Michal on 02.01.2019.
//

#ifndef LAB3_CHESSPIECE_H
#define LAB3_CHESSPIECE_H

#include <string>

using namespace std;


class chessPiece {
protected:
    string Name;
    int Colour; //0 - White    1 - Black

public:
    chessPiece() = default;

    string &getName();

    int &getColour();

};


#endif //LAB3_CHESSPIECE_H
