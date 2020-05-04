#pragma once
#ifndef CHAIN_H_INCLUDED
#define CHAIN_H_INCLUDED
#include "Block.h"
#include<unordered_map>

//�������е�������unordered_map��������O(1)��ѯ
class Chain
{
private:
    //LinkHashMap��ʽʵ�������ѯ
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
    //��Link�Ľ�β���һ��Block
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
    //��ѯBlock
    Block* getBlock(const int id)
    {
        assert(id<tol);
        return BlockID[id];
    }
    //����BlockChain�ĺϷ���
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
