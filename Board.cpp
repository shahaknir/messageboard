#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
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
        std::unordered_map<unsigned int, string> temp;
        
        
        bool is_run_over = false;

        // Insert blank spaces
        for(unsigned int x = row; x>0 ;x--)
        {
            for(unsigned int y = col; y>0 ;y--)
            {
                if(b_map.empty())
                {
                   b_map[x].insert(std::make_pair(y,"_")); 
                }
            }
        }

        // Transfer the string to char vector
        std::vector<char> c_str(str.begin(), str.end());
        

        // Declaration of varibales
        unsigned int size = str.length()+1;
        unsigned int i = row;
        unsigned int count = 0;
        unsigned int j = col;
        

        // Insertion verticaly
        if(d == Direction::Vertical)
        {
            while(i < size)
            {
                char ct = c_str[count];
                temp[col] = ct;
                b_map[i] = temp;
                count++;
                i++;
                temp.clear();
            }
        }
        // Insertion horizontaly
        else
        {
            while(j < size)
            {
                char tc = c_str[count];
                temp[j] = tc;
                b_map[row] = temp;
                count++;
                j++;
                temp.clear();
            }
        }
    
    }


    string Board::read(unsigned int row, unsigned int col, Direction d, 
        unsigned int size)
    {
        std::unordered_map<unsigned int, string>::iterator small_itr;
        unsigned int count = 0;
        std::vector <string> out;
        string str_ans;
        if(d != Direction::Vertical)
        {
            for(unsigned int i = 0; i<(col+size); i++)
            {

                str_ans += b_map[row][i];
            }
        }
        else
        {
            for(unsigned int i = 0; i<(row+size); i++)
            {
                str_ans += b_map[i][col];
            }
        }

        return str_ans;
    }


    void Board::show()
    {
        // std::unordered_map<unsigned int,std::unordered_map<unsigned int, string>>::iterator big_itr;
        // std::unordered_map<unsigned int, string>::iterator small_itr;
        for(auto &iter : b_map)
        {
            for(auto &i : iter.second)
            {
                cout << i.second;
            }
        }
    }


}
