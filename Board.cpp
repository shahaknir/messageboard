#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include "Direction.hpp"
#include "Board.hpp"
using namespace std;


// Function Declaration
void post(unsigned int row, unsigned int col, ariel::Direction d, string str);
string read(unsigned int row, unsigned int col, ariel::Direction d, unsigned int size);
void show();


namespace ariel
{

    

    void Board::post(unsigned int row, unsigned int col, Direction d, string str)
    {
        std::map<unsigned int, string> temp;
        std::map<unsigned int,std::map<unsigned int, string>>::iterator big_itr;
        std::map<unsigned int, string>::iterator small_itr;
        
        bool is_run_over = false;

        // Insert blank spaces
        for(int x = row; x>0 ;x--)
        {
            for(int y = col; y>0 ;y--)
            {
                if(board.empty())
                {
                   board[x].insert(std::make_pair(y,"_")); 
                }
            }
        }

        // Transfer the string to char[]
        char c_str[str.length()+1];
        strcpy(c_str, str.c_str());

        // Declaration of varibales
        int size = str.length()+1;
        int i = row;
        int count = 0;
        int j = col;

        // Insertion verticaly
        if(d == Direction::Vertical)
        {
            while(i < size)
            {
                char ct = c_str[count];
                temp[col] = ct;
                board[i] = temp;
                count++;
                i++;
                temp.clear();
            }
        }
        else
        {
            while(i < size)
            {
                char tc = c_str[count];
                temp[j] = tc;
                board[row] = temp;
                count++;
                j++;
                temp.clear();
            }
        }


    
    }


    string Board::read(unsigned int row, unsigned int col, Direction d, 
        unsigned int size)
    {
        string out = "";
        if(d != Direction::Vertical)
        {
            for(int i = col; i<col+size; i++)
            {
                out = out + board.at(i);
            }
        }



        return "";
    }

    void Board::show()
    {

    }
}


