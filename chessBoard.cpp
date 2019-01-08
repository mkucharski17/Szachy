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

enum colours{white,black};

chessBoard::chessBoard() {
    for(int i = 0 ; i < 8 ; i++)
        for(int j = 0 ; j < 8 ; j++)
            board[i][j] = Field();
}


Field& chessBoard::getBoard(int X , int Y) {
    return board[X][Y];
}

void chessBoard::setPawns() {

    for(int i = 0 ;  i < 8 ; i++){
        chessPiece*ch = new Pawn(white);
        board[1][i].setChessMan(ch);
        ch = new Pawn(black);
        board[6][i].setChessMan(ch);
    }
}

void chessBoard::setKings() {

    for(int i = 0 ;  i < 8 ; i++){
        chessPiece*ch = new King(white);
        board[0][4].setChessMan(ch);
        ch = new King(black);
        board[7][4].setChessMan(ch);
    }
}

void chessBoard::setQueens() {

    for(int i = 0 ;  i < 8 ; i++){
        chessPiece*ch = new Queen(white);
        board[0][3].setChessMan(ch);
        ch = new Queen(black);
        board[7][3].setChessMan(ch);
    }
}

void chessBoard::setBishops() {

    for(int i = 2 ;  i < 8 ; i+=3){
        chessPiece*ch = new Bishop(white);
        board[0][i].setChessMan(ch);
        ch = new Bishop(black);
        board[7][i].setChessMan(ch);
    }
}

void chessBoard::setKnights() {

    for(int i = 1 ;  i < 8 ; i+=5){
        chessPiece*ch = new Knight(white);
        board[0][i].setChessMan(ch);
        ch = new Knight(black);
        board[7][i].setChessMan(ch);
    }
}

void chessBoard::setRooks() {

    for(int i = 0 ;  i < 8 ; i+=7){
        chessPiece*ch = new Rook(white);
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