//
// Created by Michal on 07.01.2019.
//

#include <iostream>
#include "Test.h"
#include "chessBoard.h"
#include "Pawn.h"

using namespace std;

enum colours {
    white, black
};

Test::Test() {
    creatingBoardTest();
    settingBoardTest();
}

void Test::creatingBoardTest() {
    chessBoard B = chessBoard();

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (B.getBoard(i, j).getChessMan() == nullptr)
                continue;

            else cout << "error in creating board";

        }
    cout << "creating board is ok"<<endl;
}


void Test::settingBoardTest() {
    chessBoard *ch = new chessBoard();
    ch->setBoard();
    settingEmptyFieldsTest(ch);
    settingPawnsTest(ch);
    settingOnePiecesTest(ch,"King",4);
    settingOnePiecesTest(ch,"Queen",3);
    settingTwoPiecesTest(ch,"Bishop",2,3);
    settingTwoPiecesTest(ch,"Knight",1,5);
    settingTwoPiecesTest(ch,"Rook",0,7);

    cout<<"so everything is ok";
}

void Test::settingEmptyFieldsTest(chessBoard *testPtr) {
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < 8; j++) {
            if (testPtr->getBoard(i, j).getChessMan() == nullptr)
                continue;
            else cout << "error with board setting (empty fields)";
        }
    cout << "empty fields setting is ok" << endl;
}

void Test::settingPawnsTest(chessBoard *testPtr) {

    for (int i = 1; i < 8; i += 5) {
        for (int j = 0; j < 8; j++) {
            if (testPtr->getBoard(i, j).getChessMan()->getName() == "Pawn") {
                if (i == 1) {
                    if (testPtr->getBoard(i, j).getChessMan()->getColour() == white)
                        continue;
                    else cout << "problem with Pawns white colour";
                }

                else {
                    if (testPtr->getBoard(i, j).getChessMan()->getColour() == black)
                        continue;
                    else cout << "problem with Pawns black colour";

                }

            } else cout << "problem with Pawns position";
        }
    }
    cout << "Pawn setting is ok"<<endl;
}

void Test::settingOnePiecesTest(chessBoard *testPtr, string Name, int Y) {

    for (int i = 0; i < 8; i += 7) {
        if (testPtr->getBoard(i, Y).getChessMan()->getName() == Name) {
            if (i == 0) {
                if (testPtr->getBoard(i, Y).getChessMan()->getColour() == white)
                    continue;
                else cout << "problem with" << Name << "white colour";
            }

            else {
                if (testPtr->getBoard(i, Y).getChessMan()->getColour() == black)
                    continue;
                else cout << "problem with" << Name << "black colour";
            }

        }

        else cout << "problem with" << Name << "position";
    }
    cout<<Name<<"setting is ok"<< endl;
}

void Test::settingTwoPiecesTest(chessBoard *testPtr, string Name, int first, int difference) {

    for (int i = 0; i < 8; i += 7) {
        for (int j = first ; j < 8; j += difference) {
            if (testPtr->getBoard(i, j).getChessMan()->getName() == Name) {
                if (i == 0 ) {
                    if (testPtr->getBoard(i, j).getChessMan()->getColour() == white)
                        continue;
                    else cout << "problem with" << Name << " white colour";
                }

                else {
                    if (testPtr->getBoard(i, j).getChessMan()->getColour() == black)
                        continue;
                    else cout << "problem with " << Name << " black colour";
                }

            }

            else {cout << "problem with " << Name << " position";
            cout<<testPtr->getBoard(i,j).getChessMan()->getName()<<"dupa dupa"<<endl;}
        }
    }
    cout <<Name<<"  setting is ok"<<endl;
}






