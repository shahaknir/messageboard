#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Board.hpp"
using namespace std;

namespace ariel
{
    void Board::post(unsigned int r, unsigned int c, ariel::Direction a, string m){cout<<"empty"<<endl;}
    string Board::read(unsigned int r, unsigned int c, ariel::Direction s, int len){return "";}
    void Board::show(){}
}


