#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"

using namespace std;
using namespace ariel;
Board board;

TEST_CASE("Good Horizontal Test"){
    board.post(0,0,Direction::Horizontal,"aaa");
    CHECK(board.read(0,0,Direction::Horizontal,3)=="aaa");
    CHECK(board.read(1,0,Direction::Horizontal,3)=="aa_");
    CHECK(board.read(2,0,Direction::Horizontal,3)=="a__");
    CHECK(board.read(3,0,Direction::Horizontal,3)=="___");
    board.post(0,1,Direction::Horizontal,"bbbb");
    CHECK(board.read(0,1,Direction::Horizontal,1)=="b");
    CHECK(board.read(0,1,Direction::Horizontal,2)=="bb");
    CHECK(board.read(0,1,Direction::Horizontal,3)=="bbb");
    CHECK(board.read(0,1,Direction::Horizontal,4)=="bbbb");
    board.post(0,2,Direction::Horizontal,"__c__");
    CHECK(board.read(0,2,Direction::Horizontal,5)=="__c__");
    board.post(0,0,Direction::Horizontal,"dd");
    CHECK(board.read(0,0,Direction::Horizontal,3)=="dda");
    CHECK(board.read(1,0,Direction::Horizontal,3)=="da_");
    CHECK(board.read(2,0,Direction::Horizontal,3)=="a__");
    CHECK(board.read(3,0,Direction::Horizontal,3)=="___");
}

TEST_CASE("Bad Horizontal test"){
     board.post(0,0,Direction::Horizontal,"aaa");
    CHECK_FALSE(board.read(0,0,Direction::Horizontal,3)=="___");
    CHECK_FALSE(board.read(1,0,Direction::Horizontal,3)=="aaa");
    CHECK_FALSE(board.read(2,0,Direction::Horizontal,3)=="aa_");
    CHECK_FALSE(board.read(3,0,Direction::Horizontal,3)=="aaa");
    board.post(0,1,Direction::Horizontal,"bbbb");
    CHECK_FALSE(board.read(0,1,Direction::Horizontal,1)=="_");
    CHECK_FALSE(board.read(0,1,Direction::Horizontal,2)=="b_");
    CHECK_FALSE(board.read(0,1,Direction::Horizontal,3)=="_bb");
    CHECK_FALSE(board.read(0,1,Direction::Horizontal,4)=="bbb_");
    CHECK_FALSE(board.read(0,1,Direction::Horizontal,5)=="bbbbb");
    board.post(2,0,Direction::Horizontal,"__c__");
    CHECK_FALSE(board.read(2,0,Direction::Horizontal,5)=="_____");
    board.post(0,0,Direction::Horizontal,"dd");
    CHECK_FALSE(board.read(0,0,Direction::Horizontal,1)=="a");
    CHECK_FALSE(board.read(0,0,Direction::Horizontal,2)=="aa");
    CHECK_FALSE(board.read(0,0,Direction::Horizontal,3)=="dd_");
    
}
TEST_CASE("Good Vertical Test"){
    board.post(0,0,Direction::Vertical,"1234");
    board.post(1,0,Direction::Vertical,"1111");
    CHECK(board.read(0,0,Direction::Vertical,4)=="1234");
    CHECK(board.read(0,1,Direction::Vertical,4)=="234_");
    CHECK(board.read(0,2,Direction::Vertical,4)=="34__");
    CHECK(board.read(0,3,Direction::Vertical,4)=="4___");
    CHECK(board.read(0,4,Direction::Vertical,4)=="____");
    CHECK(board.read(1,0,Direction::Vertical,1)=="1");
    CHECK(board.read(1,0,Direction::Vertical,2)=="11");
    CHECK(board.read(1,0,Direction::Vertical,3)=="111");
    CHECK(board.read(1,0,Direction::Vertical,4)=="1111");
    CHECK(board.read(1,0,Direction::Vertical,5)=="1111_");
    board.post(1,0,Direction::Vertical,"2222");
    CHECK(board.read(1,0,Direction::Vertical,1)=="2");
    CHECK(board.read(1,0,Direction::Vertical,2)=="22");
    CHECK(board.read(1,0,Direction::Vertical,3)=="222");
    CHECK(board.read(1,0,Direction::Vertical,4)=="2222");
    CHECK(board.read(1,0,Direction::Vertical,5)=="2222_");
    

    
}
TEST_CASE("Bad Vertical test"){
    board.post(0,0,Direction::Vertical,"1234");
    board.post(1,0,Direction::Vertical,"1111");
    CHECK_FALSE(board.read(0,0,Direction::Vertical,4)=="_234");
    CHECK_FALSE(board.read(0,1,Direction::Vertical,4)=="_34_");
    CHECK_FALSE(board.read(0,2,Direction::Vertical,4)=="_4__");
    CHECK_FALSE(board.read(0,3,Direction::Vertical,4)=="____");
    CHECK_FALSE(board.read(0,4,Direction::Vertical,4)=="1234");
    CHECK_FALSE(board.read(1,0,Direction::Vertical,1)=="_");
    CHECK_FALSE(board.read(1,0,Direction::Vertical,2)=="__");
    CHECK_FALSE(board.read(1,0,Direction::Vertical,3)=="___");
    CHECK_FALSE(board.read(1,0,Direction::Vertical,4)=="____");
    
}
TEST_CASE("Test of string size- vertical and horizontal"){
    board.post(0,0,Direction::Vertical,"1234");
    board.post(0,0,Direction::Horizontal,"1111");
    CHECK(board.read(0,0,Direction::Vertical,4)=="1234");
    CHECK(board.read(0,1,Direction::Vertical,3)=="234");
    CHECK(board.read(0,2,Direction::Vertical,2)=="34");
    CHECK(board.read(0,3,Direction::Vertical,1)=="4");
    CHECK(board.read(0,4,Direction::Vertical,0)=="");
    CHECK(board.read(0,0,Direction::Horizontal,1)=="1");
    CHECK(board.read(0,0,Direction::Horizontal,2)=="11");
    CHECK(board.read(0,0,Direction::Horizontal,3)=="111");
    CHECK(board.read(0,0,Direction::Horizontal,4)=="1111");
    CHECK(board.read(0,0,Direction::Horizontal,5)=="1111_");
    
}
TEST_CASE("Test of both vertical and horizontal"){
    board.post(0,0,Direction::Vertical,"1234");
    board.post(0,0,Direction::Horizontal,"1111");
    board.post(1,0,Direction::Horizontal,"1111");
    board.post(2,0,Direction::Horizontal,"1111");
    board.post(3,0,Direction::Horizontal,"1111");
    CHECK(board.read(0,0,Direction::Vertical,1)=="1");
    CHECK(board.read(0,0,Direction::Vertical,2)=="11");
    CHECK(board.read(0,0,Direction::Vertical,3)=="111");
    CHECK(board.read(0,0,Direction::Vertical,4)=="1111");
    board.post(1,0,Direction::Vertical,"1234");
    CHECK(board.read(0,0,Direction::Horizontal,4)=="1111");
    CHECK(board.read(0,1,Direction::Horizontal,4)=="1211");
    CHECK(board.read(0,2,Direction::Horizontal,4)=="1131");
    CHECK(board.read(0,3,Direction::Horizontal,4)=="1114");
    
    
}