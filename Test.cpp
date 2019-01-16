//
// Created by Michal on 07.01.2019.
//

#include <iostream>
#include "Test.h"
#include "chessBoard.h"
#include "Pawn.h"
#include "rulesChecker.h"
#include "gameStatus.h"

using namespace std;

enum colours {
    white, black
};

Test::Test() {

    creatingBoardTest();
    settingBoardTest();
    movingTest();
    checkMoveTest();
    checkTest();
    cout<<"so everything is ok";
}

void Test::creatingBoardTest() {
    chessBoard B = chessBoard();

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (B.getBoard(i, j).isEmpty())
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
            if (testPtr->getBoard(j, i).isEmpty())
                continue;
            else cout << "error with board setting (empty fields)";
        }
    cout << "empty fields setting is ok" << endl;
}


void Test::settingPawnsTest(chessBoard *testPtr) {

    for (int i = 1; i < 8; i += 5) {
        for (int j = 0; j < 8; j++) {
            if (testPtr->getBoard(j, i).getChessMan()->getName() == "Pawn") {
                if (i == 1) {
                    if (testPtr->getBoard(j, i).getChessMan()->getColour() == white)
                        continue;
                    else cout << "problem with Pawns white colour";
                }

                else {
                    if (testPtr->getBoard(j, i).getChessMan()->getColour() == black)
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

void Test::settingOnePiecesTest(chessBoard *testPtr, string Name, int X) {
    for (int i = 0; i < 8; i += 7) {
        if (testPtr->getBoard(X, 0).getChessMan()->getName() == Name) {
            if (i == 0) {
                if (testPtr->getBoard(X, i).getChessMan()->getColour() == white)
                    continue;
                else cout << "problem with" << Name << "white colour";
            }

            else {
                if (testPtr->getBoard(X, i).getChessMan()->getColour() == black)
                    continue;
                else cout << "problem with" << Name << "black colour";
            }

        }

        else cout << "problem with" << Name << " position";
    }
    cout<<Name<<" setting is ok"<< endl;
}
/*checking start position for pieces which are two of each colour
 * difference is difference between two chess pieces of each colour
 * first is first number from vertexes
 */
void Test::settingTwoPiecesTest(chessBoard *testPtr, string Name, int first, int difference) {

    for (int i = 0; i < 8; i += 7) {
        for (int j = first ; j < 8; j += difference) {
            if (testPtr->getBoard(j, i).getChessMan()->getName() == Name) {
                if (i == 0 ) {
                    if (testPtr->getBoard(j, i).getChessMan()->getColour() == white)
                        continue;
                    else cout << "problem with" << Name << " white colour";
                }

                else {
                    if (testPtr->getBoard(j, i).getChessMan()->getColour() == black)
                        continue;
                    else cout << "problem with " << Name << " black colour";
                }

            }

            else {cout << "problem with " << Name << " position";
            cout<<testPtr->getBoard(j,i).getChessMan()->getName()<<"dupa dupa"<<endl;}
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


void Test::checkMoveTest() {
    vector<vertexes> v;
    chessBoard ch;
    ch.setBoard();
    rulesChecker r;

    v = r.checkMove(0,0,&ch);
    if(!v.empty())
        cout<<"problem with checking move (1";

    v = r.checkMove(6,0,&ch);

    if(v.size() != 2)
        cout<<"problem with checking move (2";

    cout<<"checking move is ok"<<endl;

}

void Test::checkTest() {

    chessBoard ch;
    ch.setBoard();
    vertexes from,to;

    from.X = 4;
    from.Y = 0;
    to.X = 3;
    to.Y = 5;

    ch.move(from,to);

    gameStatus g;

    g.loadBoard(&ch);

    if(!g.isCheck(1))
        cout<<"error in checking check";

    cout<<"checking check is ok"<<endl;

}







