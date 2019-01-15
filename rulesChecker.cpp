//
// Created by Michal on 08.01.2019.
//

#include <iostream>
#include "rulesChecker.h"

enum colours {
    white, black
};

rulesChecker::rulesChecker() {
    Board = new chessBoard();
    Board->setBoard();
}

/*
 * Method that check which chessboard is on given field
 * and return list of  possible moves
 * */
vector<vertexes> rulesChecker::checkMove(int x, int y, chessBoard *source) {
    Board = source;
    vector<vertexes> possibilities;
    if (Board->getBoard(x, y).getChessMan()->getName() == "Pawn") {
        checkPawnMove(possibilities, x, y);
    } else if (Board->getBoard(x, y).getChessMan()->getName() == "Knight") {
        checkKnightMove(possibilities, x, y);
    } else if (Board->getBoard(x, y).getChessMan()->getName() == "King") {
        checkKingMove(possibilities, x, y);
    } else if (Board->getBoard(x, y).getChessMan()->getName() == "Rook") {
        checkRookMove(possibilities, x, y);
    } else if (Board->getBoard(x, y).getChessMan()->getName() == "Bishop") {
        checkBishopMove(possibilities, x, y);
    } else if (Board->getBoard(x, y).getChessMan()->getName() == "Queen") {
        checkQueenMove(possibilities, x, y);
    }

    return possibilities;
}

/*
 * Next 6 methods create list of fields that are possible to move for each chesspiece
 * */
void rulesChecker::checkPawnMove(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    int shift;

    if (Board->getBoard(x, y).getChessMan()->getColour() == white)
        shift = 1;

    else shift = -1;


    //classic move
    if ((y < 7 && shift == 1) || (y > 0 && shift == -1))
        if (Board->getBoard(x, y + shift).getChessMan() == nullptr) {
            temp.X = x;
            temp.Y = y + shift;
            possibilities.push_back(temp);
        }

    //double move
    if ((y == 1 && shift == 1) || (y == 6 && shift == -1))
        if (Board->getBoard(x, y + 2 * shift).getChessMan() == nullptr &&
            Board->getBoard(x, y + shift).getChessMan() == nullptr) {

            temp.X = x;
            temp.Y = y + 2 * shift;
            possibilities.push_back(temp);
        }

    //right attack
    if ((x < 7 && y < 7 && shift == 1) || (x > 0 && y > 0 && shift == -1))
        if (Board->getBoard(x + shift, y + shift).getChessMan() != nullptr &&
            Board->getBoard(x + shift, y + shift).getChessMan()->getColour() !=
            Board->getBoard(x, y).getChessMan()->getColour()) {

            temp.X = x + shift;
            temp.Y = y + shift;
            possibilities.push_back(temp);
        }

    //left attack
    if ((x > 0 && y < 7 && shift == 1) || (x < 7 && y > 0 && shift == -1))
        if (Board->getBoard(x - shift, y + shift).getChessMan() != nullptr &&
            Board->getBoard(x - shift, y + shift).getChessMan()->getColour() !=
            Board->getBoard(x, y).getChessMan()->getColour()) {

            temp.X = x - 1;
            temp.Y = y + 1;
            possibilities.push_back(temp);
        }
}

void rulesChecker::checkKnightMove(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    for (int i = -2; i < 3; i += 4)
        for (int j = -1; j < 2; j += 2) {
            temp.X = x + i;
            temp.Y = y + j;
            if (inBoard(temp))
                possibilities.push_back(temp);
        }

    for (int i = -1; i < 2; i += 2)
        for (int j = -2; j < 3; j += 4) {
            temp.X = x + i;
            temp.Y = y + j;
            if (inBoard(temp))
                possibilities.push_back(temp);

        }
}

void rulesChecker::checkKingMove(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0)
                continue;
            else {
                temp.X = x + i;
                temp.Y = y + j;

                if (inBoard(temp))
                    possibilities.push_back(temp);
            }

        }
}

void rulesChecker::checkRookMove(vector<vertexes> &possibilities, int x, int y) {
    checkUp(possibilities, x, y);
    checkLeft(possibilities, x, y);
    checkRight(possibilities, x, y);
    checkDown(possibilities, x, y);
}

void rulesChecker::checkBishopMove(vector<vertexes> &possibilities, int x, int y) {
    checkUpLeft(possibilities, x, y);
    checkDownLeft(possibilities, x, y);
    checkUpRight(possibilities, x, y);
    checkDownRight(possibilities, x, y);
}

void rulesChecker::checkQueenMove(vector<vertexes> &possibilities, int x, int y) {
    checkUpLeft(possibilities, x, y);
    checkDownLeft(possibilities, x, y);
    checkUpRight(possibilities, x, y);
    checkDownRight(possibilities, x, y);
    checkUp(possibilities, x, y);
    checkLeft(possibilities, x, y);
    checkRight(possibilities, x, y);
    checkDown(possibilities, x, y);
}

/*
 * Method which check if field  is possible to move on.
 * if yes - return true
 * if not - return false
 * */
bool rulesChecker::canAddToPossibilities(vertexes temp) {

    if (Board->getBoard(temp.X, temp.Y).getChessMan() == nullptr)
        return true;
    else {
        if (isAttack(temp, Board->getBoard(temp.X, temp.Y).getChessMan()->getColour()))
            return true;
    }
    return false;
}

/*
 * Next 8 methods are creating a list of possible moves for each directions(row , columns, diagonals)
 * */
void rulesChecker::checkRight(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    temp.Y = y;
    for (int i = 1; x + i < 8; i++) {
        temp.X = x + i;
        if (canAddToPossibilities(temp))
            possibilities.push_back(temp);
        else break;
    }
}

void rulesChecker::checkLeft(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    temp.Y = y;
    for (int i = 1; x - i >= 0; i++) {
        temp.X = x - i;
        if (canAddToPossibilities(temp))
            possibilities.push_back(temp);
        else break;
    }
}

void rulesChecker::checkDown(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    temp.X = x;
    for (int i = 1; y - i >= 0; i++) {
        temp.Y = y - i;
        if (canAddToPossibilities(temp))
            possibilities.push_back(temp);
        else break;
    }
}

void rulesChecker::checkUp(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    temp.X = x;
    for (int i = 1; y + i < 8; i++) {
        temp.Y = y + i;
        if (canAddToPossibilities(temp))
            possibilities.push_back(temp);
        else break;
    }
}

void rulesChecker::checkUpRight(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    for (int i = 1; y + i < 8 && x + i < 8; i++) {
        temp.X = x + i;
        temp.Y = y + i;
        if (canAddToPossibilities(temp))
            possibilities.push_back(temp);
        else break;
    }
}

void rulesChecker::checkDownRight(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    for (int i = 1; y - 1 >= 0 && x + i < 8; i++) {
        temp.X = x + i;
        temp.Y = y - i;
        if (canAddToPossibilities(temp))
            possibilities.push_back(temp);
        else break;
    }
}

void rulesChecker::checkDownLeft(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    for (int i = 1; y - i >= 0 && x - i >= 0; i++) {
        temp.X = x - i;
        temp.Y = y - i;
        if (canAddToPossibilities(temp))
            possibilities.push_back(temp);
        else break;
    }
}

void rulesChecker::checkUpLeft(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;

    for (int i = 1; y + i < 8 && x - i >= 0; i++) {
        temp.X = x - i;
        temp.Y = y + i;
        if (canAddToPossibilities(temp))
            possibilities.push_back(temp);
        else break;
    }
}

/*
 * Method which check if vertexes are in chessboard
 * */
bool rulesChecker::inBoard(vertexes v) {
    if (v.X < 0 || v.X > 7 || v.Y < 0 || v.Y > 7)
        return false;

    return true;
}

/*
 * Method which check if move is an attack
 * */
bool rulesChecker::isAttack(vertexes v, int colour) {
    if (Board->getBoard(v.X, v.Y).getChessMan() != nullptr)
        if (Board->getBoard(v.X, v.Y).getChessMan()->getColour() != colour)
            return true;

    return false;
}


