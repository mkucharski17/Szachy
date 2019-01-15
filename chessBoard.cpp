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

chessBoard& chessBoard::operator=(chessBoard &primary) {
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            board[j][i].setChessMan(primary.getBoard(j,i).getChessMan());
        }
    }
    return *this;
}

void chessBoard::load(chessBoard &source) {
    *this = source;
}








