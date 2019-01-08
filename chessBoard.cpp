//
// Created by Michal on 03.01.2019.
//

#include <iostream>
#include "chessBoard.h"
#include "Bishop.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Rook.h"

using namespace std;
enum colours {
    white, black
};


chessBoard::chessBoard() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = Field();
}


Field &chessBoard::getBoard(int X, int Y) {
    return board[X][Y];
}

void chessBoard::setPawns() {
    for (int i = 0; i < 8; i++) {
        chessPiece *ch = new Pawn(white);
        board[i][1].setChessMan(ch);
        ch = new Pawn(black);
        board[i][6].setChessMan(ch);
    }
}

void chessBoard::setKings() {
    for (int i = 0; i < 8; i++) {
        chessPiece *ch = new King(white);
        board[4][0].setChessMan(ch);
        ch = new King(black);
        board[4][7].setChessMan(ch);
    }
}

void chessBoard::setQueens() {
    for (int i = 0; i < 8; i++) {
        chessPiece *ch = new Queen(white);
        board[3][0].setChessMan(ch);
        ch = new Queen(black);
        board[3][7].setChessMan(ch);
    }
}

void chessBoard::setBishops() {
    for (int i = 2; i < 8; i += 3) {
        chessPiece *ch = new Bishop(white);
        board[i][0].setChessMan(ch);
        ch = new Bishop(black);
        board[i][7].setChessMan(ch);
    }
}

void chessBoard::setKnights() {
    for (int i = 1; i < 8; i += 5) {
        chessPiece *ch = new Knight(white);
        board[i][0].setChessMan(ch);
        ch = new Knight(black);
        board[i][7].setChessMan(ch);
    }
}

void chessBoard::setRooks() {
    for (int i = 0; i < 8; i += 7) {
        chessPiece *ch = new Rook(white);
        board[i][0].setChessMan(ch);
        ch = new Rook(black);
        board[i][7].setChessMan(ch);
    }
}

void chessBoard::setBoard() {
    setPawns();
    setKings();
    setQueens();
    setBishops();
    setRooks();
    setKnights();
}

void chessBoard::show() {
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            if (board[j][i].getChessMan() != nullptr) {
                cout << board[j][i].getChessMan()->getName();
                cout << board[j][i].getChessMan()->getColour() << "(" << j << "," << i << ")" << "  ";
            } else cout << "empty" << "(" << j << "," << i << ")" << "  ";

        }
        cout << endl;
    }
}

void chessBoard::move(vertexes from, vertexes to) {

    board[to.X][to.Y].setChessMan(board[from.X][from.Y].getChessMan());
    board[from.X][from.Y].setChessMan(nullptr);
}

vector<vertexes> chessBoard::checkMove(int x, int y) {
    vector<vertexes> possibilities;
    if (board[x][y].getChessMan()->getName() == "Pawn") {
        checkPawnMove(possibilities, x, y);
    }

    else if (board[x][y].getChessMan()->getName() == "Knight") {
        checkKnightMove(possibilities, x, y);
    }

    vector<vertexes>::iterator iterator;

    for (iterator = possibilities.begin(); iterator != possibilities.end(); ++iterator) {
        cout << iterator->X << " " << iterator->Y << endl;
    }
}

void chessBoard::checkPawnMove(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    int shift;

    if (board[x][y].getChessMan()->getColour() == white)
        shift = 1;

    else shift = -1;


    //classic move
    if ((y < 7 && shift == 1) || (y > 0 && shift == -1))
        if (board[x][y + shift].getChessMan() == nullptr) {
            temp.X = x;
            temp.Y = y + shift;
            possibilities.push_back(temp);
        }

    //double move
    if ((y == 1 && shift == 1) || (y == 6 && shift == -1))
        if (board[x][y + 2 * shift].getChessMan() == nullptr && board[x][y + shift].getChessMan() == nullptr) {

            temp.X = x;
            temp.Y = y + 2 * shift;
            possibilities.push_back(temp);
        }

    //right attack
    if ((x < 7 && y < 7 && shift == 1) || (x > 0 && y > 0 && shift == -1))
        if (board[x + shift][y + shift].getChessMan() != nullptr &&
            board[x + shift][y + shift].getChessMan()->getColour() != board[x][y].getChessMan()->getColour()) {

            temp.X = x + shift;
            temp.Y = y + shift;
            possibilities.push_back(temp);
        }

    //left attack
    if ((x > 0 && y < 7 && shift == 1) || (x < 7 && y > 0 && shift == -1))
        if (board[x - shift][y + shift].getChessMan() != nullptr &&
            board[x - shift][y + shift].getChessMan()->getColour() != board[x][y].getChessMan()->getColour()) {

            temp.X = x - 1;
            temp.Y = y + 1;
            possibilities.push_back(temp);
        }

}

void chessBoard::checkKnightMove(vector<vertexes> &possibilities, int x, int y) {
    vertexes temp;
    for (int i = -2; i < 3; i += 4)
        for (int j = -1; j < 2; j += 2) {
            temp.X = x + i;
            temp.Y = y + j;
            if(inBoard(temp))
                possibilities.push_back(temp);
        }

    for (int i = -1; i < 2; i += 2)
        for (int j = -2; j < 3; j += 4) {
            temp.X = x + i;
            temp.Y = y + j;
            if(inBoard(temp))
                possibilities.push_back(temp);

        }
}

bool chessBoard::inBoard(vertexes v) {
    if(v.X < 0 || v.X > 7 || v.Y < 0 || v.Y > 7)
        return false;

    else return true;
}