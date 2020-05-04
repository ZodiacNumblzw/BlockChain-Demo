#pragma once
#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include "HashTable.h"
#include <iostream>
//区块链中的块
class Block
{
public:
    std::string data,previous,hashValue;
    Block(std::string data,std::string previous):data(data),previous(previous)
    {
        hashValue=hashmydata();
    }
    std::string hashmydata()
    {
        return getHash::getHashValue(data+previous);
    }
    /*void outPut()
    {
        std::cout<<"data = "<<data<<", previous = "<<previous<<",hashValue = "<<hashValue<<std::endl;
    }*/
    friend std::ostream& operator<<(std::ostream& os,const Block& myBlock)
    {
        os<<"data = "<<myBlock.data<<", previous = "<<myBlock.previous<<",hashValue = "<<myBlock.hashValue<<std::endl;
        return os;
    }
};

#endif // BLOCK_H_INCLUDED
