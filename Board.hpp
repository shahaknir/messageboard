#include <iostream>
#include <string>
#include "Direction.hpp"
using namespace std;

namespace ariel
{
    class Board{
        public:
        Board();
        void post(unsigned int r, unsigned int c, Direction d, string m);
        string read(unsigned int r, unsigned int c,Direction d, int len);
        void show();
    };
}