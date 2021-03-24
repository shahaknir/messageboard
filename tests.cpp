#include "Direction.hpp"
#include "Board.hpp"
#include "doctest.h"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;
ariel::Board board;

TEST_CASE("Good board") {
    string st = "abcd";
    board.post(100, 200, Direction::Horizontal, "abcd");
    CHECK(st == board.read(100, 2, Direction::Horizontal, 4));

    board.post(100, 199, Direction::Vertical, "gsdhgs");
    CHECK(st == board.read(100, 199, Direction::Vertical, 6));

    //there was no change to "abcd"
    CHECK(st == board.read(100, 2, Direction::Horizontal, 4));

    board.post(12, 1,Direction::Vertical, "How U doin'?");
    string temp1 = "How U doin'?";
    CHECK(temp1 == board.read(12, 1, Direction::Vertical, 12));
    
}

TEST_CASE("Bad board"){
    CHECK_THROWS();
}