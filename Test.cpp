#include "Direction.hpp"
#include "Board.hpp"
#include "doctest.h"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;
ariel::Board board;

TEST_CASE("Porperly initialized")
{
    CHECK(board.read(1, 1, Direction::Horizontal, 10) == string("___________"));
    CHECK(board.read(451, 12, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(56, 65, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(6, 22, Direction::Vertical, 10) == string("___________"));
    CHECK(board.read(1, 1, Direction::Horizontal, 6) == string("______"));
}

TEST_CASE("Post correctly on the board")
{
    CHECK_NOTHROW(board.post(1, 1, Direction::Horizontal, "You're braver than you believe"));
    CHECK_NOTHROW(board.post(2, 1, Direction::Horizontal, "stronger than you seem"));
    CHECK_NOTHROW(board.post(3, 1, Direction::Horizontal, "and smarter than you think"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "abcd"));
    CHECK_NOTHROW(board.post(100, 199, Direction::Vertical, "gsdhgs"));
    CHECK_NOTHROW(board.post(12, 1,Direction::Vertical, "How U doin'?"));
    CHECK_NOTHROW(board.post(6, 95, Direction::Vertical, "I am short, fat and proud of that"));
}

TEST_CASE("Read correctly")
{
    CHECK_THROWS(board.read(100, 2, Direction::Horizontal, 4) = "abcd");
    CHECK_THROWS(board.read(100, 199, Direction::Vertical, 6) = "gsdhgs");
    CHECK_THROWS(board.read(100, 2, Direction::Vertical, 4) = "a___");
    CHECK_THROWS(board.read(12, 1, Direction::Vertical, 12) = "How U doin'?");
    CHECK_THROWS(board.read(1, 1, Direction::Horizontal, 30) = "You're braver than you believe");
    CHECK_THROWS(board.read(2, 1, Direction::Horizontal, 22) = "stronger than you seem");
    CHECK_THROWS(board.read(3, 1, Direction::Horizontal, 26) = "and smarter than you think");
    CHECK_THROWS(board.read(6, 95, Direction::Vertical, 33) = "I am short, fat and proud of that");
}