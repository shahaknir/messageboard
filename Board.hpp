#include <iostream>
#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;
#define TEN = 10
extern std::map<unsigned int,std::map<unsigned int, string>> board;


namespace ariel
{
    class Board{
        unsigned int row;
        unsigned int col;

    public:
        
        Board();
        static void post(unsigned int row, unsigned int col, Direction d, string str);
        static string read(unsigned int row, unsigned int col, Direction d, 
            unsigned int size);
        void show();
    };
}