#include<stdlib.h>
#include<ctime>
#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
using namespace std;

Board board;

TEST_CASE("Porperly use to MessageBoard code"){
    srand(std::time(NULL));
    uint r = 0;
    uint c = 0;
    int i = 0;

    // check if the board correctly assigning the range asked
    CHECK(board.read(1, 1, Direction::Horizontal, 10).compare("___________"));
    CHECK(board.read(451, 12, Direction::Vertical, 1).compare("_"));
    CHECK(board.read(56, 65, Direction::Horizontal, 1).compare("_"));
    CHECK(board.read(6, 22, Direction::Vertical, 10).compare("___________"));
    CHECK(board.read(98765, 64531, Direction::Horizontal, 6).compare("______"));
    
    // check post & read
    CHECK_NOTHROW(board.post(1, 1, Direction::Horizontal, "You're braver than you believe"));
    CHECK(board.read(1, 1, Direction::Horizontal, 30).compare("You're braver than you believe"));
    
    CHECK_NOTHROW(board.post(2, 1, Direction::Horizontal, "stronger than you seem"));
    CHECK(board.read(2, 1, Direction::Horizontal, 22).compare("stronger than you seem"));
    
    CHECK_NOTHROW(board.post(3, 1, Direction::Horizontal, "and smarter than you think"));
    CHECK(board.read(3, 1, Direction::Horizontal, 26).compare("and smarter than you think"));

    CHECK(board.read(1, 1, Direction::Vertical, 6).compare("Ysa___"));
    
    CHECK_NOTHROW(board.post(100, 2, Direction::Horizontal, "abcd"));
    CHECK(board.read(100, 2, Direction::Horizontal, 4).compare("abcd"));
    CHECK(board.read(100, 2, Direction::Vertical, 4).compare("a___"));

    CHECK_NOTHROW(board.post(100, 199, Direction::Vertical, "gsdhgs"));
    CHECK(board.read(100, 199, Direction::Vertical, 6).compare("gsdhgs"));
    CHECK(board.read(100, 199, Direction::Horizontal, 4).compare("gbcd"));
    
    CHECK_NOTHROW(board.post(12, 1,Direction::Vertical, "How U doin'?"));
    CHECK(board.read(12, 1, Direction::Vertical, 12).compare("How U doin'?"));

    CHECK_NOTHROW(board.post(6, 95, Direction::Vertical, "I am short, fat and proud of that"));
    CHECK(board.read(6, 95, Direction::Vertical, 33).compare("I am short, fat and proud of that"));

}