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
        board[1][i].setChessMan(ch);
        ch = new Pawn(black);
        board[6][i].setChessMan(ch);
    }
}

void chessBoard::setKings() {
    for (int i = 0; i < 8; i++) {
        chessPiece *ch = new King(white);
        board[0][4].setChessMan(ch);
        ch = new King(black);
        board[7][4].setChessMan(ch);
    }
}

void chessBoard::setQueens() {
    for (int i = 0; i < 8; i++) {
        chessPiece *ch = new Queen(white);
        board[0][3].setChessMan(ch);
        ch = new Queen(black);
        board[7][3].setChessMan(ch);
    }
}

void chessBoard::setBishops() {
    for (int i = 2; i < 8; i += 3) {
        chessPiece *ch = new Bishop(white);
        board[0][i].setChessMan(ch);
        ch = new Bishop(black);
        board[7][i].setChessMan(ch);
    }
}

void chessBoard::setKnights() {
    for (int i = 1; i < 8; i += 5) {
        chessPiece *ch = new Knight(white);
        board[0][i].setChessMan(ch);
        ch = new Knight(black);
        board[7][i].setChessMan(ch);
    }
}

void chessBoard::setRooks() {
    for (int i = 0; i < 8; i += 7) {
        chessPiece *ch = new Rook(white);
        board[0][i].setChessMan(ch);
        ch = new Rook(black);
        board[7][i].setChessMan(ch);
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

vector<vertexes> chessBoard::checkPawnMove(chessBoard *boardPtr, int x, int y) {
    vector<vertexes> possibilities;
    vertexes temp;
    int shift;

    if (boardPtr->getBoard(x, y).getChessMan()->getColour() == white)
        shift = 1;

    else shift = -1;


    //classic move
    if ((y < 7 && shift == 1) || (y > 0 && shift == -1))
        if(boardPtr->getBoard(x, y + shift).getChessMan() == nullptr) {
            temp.X = x;
            temp.Y = y + shift;
            possibilities.push_back(temp);
    }
    //double move
    if ((y == 1 && shift == 1) || (y == 6 && shift == -1))
        if(boardPtr->getBoard(x, y + 2 * shift).getChessMan() == nullptr &&
            boardPtr->getBoard(x, y + shift).getChessMan() == nullptr && x == 1) {

            temp.X = x;
            temp.Y = y + 2 * shift;
            possibilities.push_back(temp);
        }
    //right attack
    if ((x < 7 && y < 7 && shift == 1) || (x > 0 && y > 0 && shift == -1))
        if (boardPtr->getBoard(x + shift, y + shift).getChessMan()->getColour() !=
            getBoard(x, y).getChessMan()->getColour()) {

            temp.X = x + shift;
            temp.Y = y + shift;
            possibilities.push_back(temp);
        }
    //lef attack
    if ((x > 0 && y < 7 && shift == 1) ||(x < 7 && y > 0 && shift == -1 ) )
        if(boardPtr->getBoard(x - shift, y + shift).getChessMan()->getColour() != getBoard(x,y).getChessMan()->getColour()) {
        temp.X = x - 1;
        temp.Y = y + 1;
        possibilities.push_back(temp);
    }

    return possibilities;

}