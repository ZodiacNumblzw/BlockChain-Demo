#pragma once
#ifndef CHAIN_H_INCLUDED
#define CHAIN_H_INCLUDED
#include "Block.h"
#include<unordered_map>

//区块链中的链，用unordered_map可以做到O(1)查询
class Chain
{
private:
    //LinkHashMap方式实现随机查询
    std::unordered_map<int,Block*> BlockID;
    Block *head,*tail;
    int tol;
public:
    Chain()
    {
        tol=0;
        head=tail=nullptr;
        BlockID.clear();
    }
    //在Link的结尾添加一个Block
    void addBlock(const std::string& mydata)
    {
        if(head == nullptr)
        {
            head = new Block(mydata,"");
            tail = head;
        }
        else
        {
            tail = new Block(mydata,tail->hashValue);
        }
        BlockID[tol++] = tail;
    }
    //查询Block
    Block* getBlock(const int id)
    {
        assert(id<tol);
        return BlockID[id];
    }
    //检验BlockChain的合法性
    bool check()
    {
        for(int i=0;i<tol;i++)
        {
            Block* temp=BlockID[i];
            if(temp->hashValue!=temp->hashmydata())
            {
                std::cerr<<"The data has been modified."<<std::endl;
                return false;
            }
            if(i>0&&temp->previous!=BlockID[i-1]->hashValue)
            {
                std::cerr<<"The BlockChain has been disconnected."<<i<<std::endl;
            }
        }
        return true;
    }
};

#endif // CHAIN_H_INCLUDED
