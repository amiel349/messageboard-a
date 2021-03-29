#include "Board.hpp"
#include <iostream>
using namespace std;

namespace ariel{ 

Board::Board(){}
void Board::post(unsigned int width,unsigned int length,ariel::Direction x, string m_s){};

string Board::read(unsigned int width,unsigned int length,ariel::Direction y,unsigned int num_of_lettters){
    return "hellow word";
};
string Board::show(){return "_";};

Board::~Board(){};

}