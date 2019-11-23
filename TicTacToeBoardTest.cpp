/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitestName)
{
	ASSERT_TRUE(true);
}
*/


//These two tests check for the turns 
TEST(TicTacToeBoardTest, oTurn)
{
  TicTacToeBoard boardTest;
  Piece turnO = boardTest.toggleTurn();

  ASSERT_EQ(turnO, O);
}

TEST( TicTacToeBoardTest, xTurn )
{
    TicTacToeBoard boardTest;
    boardTest.toggleTurn();
    Piece turnX = boardTest.toggleTurn();

    ASSERT_EQ(turnX, X);
}

//The first (checkWinner) is just one of many combinations I can use
//You basically have to come up with the all the different scenarios which is A LOT OF TESTS TO WRITE
//is there any way to do it all at once?
TEST( TicTacToeBoardTest, checkWinner )
{
    TicTacToeBoard boardTest;
    boardTest.placePiece(0,0); 
    boardTest.placePiece(0,1);
    boardTest.placePiece(1,0); 
    boardTest.placePiece(0,2);
    boardTest.placePiece(2,0);
    Piece win = boardTest.getWinner();
    ASSERT_EQ(win, X);
}
/* couldmt get this to work...
TEST(TicTacToeBoardTest, getTie)
{
	TicTacToeBoard boardTest;
	boardTest.placePiece(0,0);
	boardTest.placePiece(1,1);
	boardTest.placePiece(0,2);
	boardTest.placePiece(0,1);
	boardTest.placePiece(2,0);
	boardTest.placePiece(1,0);
  boardTest.placePiece(1,2);
	boardTest.placePiece(2,2);
	boardTest.placePiece(2,1);

  tie = boardTest.getWinner();

	ASSERT_EQ(tie, Blank);
}
*/

//placement tests 1)can we place X 2) can we place O 3) can we make an illegal placement (out of bounds) 
//4) is the space already occupied?
TEST( TicTacToeBoardTest, placeX){
    TicTacToeBoard boardTest;
    Piece place = boardTest.placePiece(1,1); 
    ASSERT_EQ(place, X);
}

TEST( TicTacToeBoardTest, placeO){
    TicTacToeBoard boardTest;
    boardTest.placePiece(2,2);
    Piece place = boardTest.placePiece(2,1);
    ASSERT_EQ(place, O);
}

TEST( TicTacToeBoardTest, placeIllegal){
    TicTacToeBoard boardTest;
    Piece place = boardTest.placePiece(5,5); 
    ASSERT_EQ(place, Invalid);
}


TEST( TicTacToeBoardTest, placeTaken){
    TicTacToeBoard boardTest;
    boardTest.placePiece(1,1); 
    Piece place = boardTest.placePiece(1,1); 
    ASSERT_EQ(place, X); 
}

