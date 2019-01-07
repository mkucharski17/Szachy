//
// Created by Michal on 07.01.2019.
//

#include <iostream>
#include "Test.h"
#include "chessBoard.h"

using namespace std;

Test::Test(){
    creatingBoardTest();
}

void Test::creatingBoardTest() {
    chessBoard B = chessBoard();

    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++) {
            cout<<B.getBoard(i,j).getChessPieceName()<<"    ";
        }
        cout<<endl;
    }
}



