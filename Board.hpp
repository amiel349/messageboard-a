#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
using namespace std;
using ariel::Direction;
namespace ariel{
    class Board{
        

   public:
   // constructor and destructor
     Board();
    ~Board();
    // methods
     void post(unsigned int row,unsigned int column,Direction direction, string m_s);
     string read(unsigned int row,unsigned int column,Direction direction, unsigned int m_r);
     string show();
  
   
   };
}
