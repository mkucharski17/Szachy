//
// Created by Michal on 07.01.2019.
//

#ifndef LAB3_TEST_H
#define LAB3_TEST_H


#include "chessBoard.h"

class Test {

    void creatingBoardTest();

    void settingPawnsTest(chessBoard *testPtr);

    void settingOnePiecesTest(chessBoard *testPtr, string Name, int Y);

    void settingTwoPiecesTest(chessBoard *testPtr, string Name, int first, int difference);

    void settingEmptyFieldsTest(chessBoard *testPtr);

    void settingBoardTest();

    void movingTest();

public:
    Test();

};


#endif //LAB3_TEST_H
