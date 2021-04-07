#include <iostream>
#include <string>
#include <unordered_map>
#include "Direction.hpp"
using namespace std;
#define TEN = 10
extern std::unordered_map<unsigned int,std::unordered_map<unsigned int, string>> b_map;


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
        static void show();
    };
}