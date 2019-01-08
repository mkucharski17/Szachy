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
    movingTest();

    cout<<"so everything is ok";
}

void Test::creatingBoardTest() {
    chessBoard B = chessBoard();

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (B.getBoard(i, j).getChessMan() == nullptr)
                continue;

            else cout << "error in creating board";

        }
    cout << "CREATING board is ok"<<endl;
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
    cout<<"so SETTING is OK"<<endl;
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

/*checking start position for pieces which are one of each colour
 * Y is second vertex of position for chess piece
 */

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
/*checking start position for pieces which are two of each colour
 * difference is difference between two chess pieces of each colour
 * first is first number from vertexes
 */
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


void Test::movingTest() {
    chessBoard ch;
    ch.setBoard();
    vertexes from,to;
    from.X = 0;
    from.Y = 0;
    to.X = 4;
    to.Y = 4;
    ch.move(from,to);
    if(ch.getBoard(from.X,from.Y).getChessMan() != nullptr)
        cout<<"problem with field which chespiece go from";

    if(ch.getBoard(to.X,to.Y).getChessMan()->getName() != "Rook" &&
    ch.getBoard(to.X,to.Y).getChessMan()->getColour() != white)
        cout<<"problem with field which chespiece go to";

    cout<<"MOVING is  ok"<<endl;
}





