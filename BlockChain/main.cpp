#include "Chain.h"

int main()
{
    Chain myBlockChain;
    std::string myidol="luotuo",num="0";
    //检验区块链的添加，查询功能
    for(int i=0;i<9;i++)
    {
        num[0]=(i+'0');
        myBlockChain.addBlock(myidol+num);
        std::cout<<*myBlockChain.getBlock(i)<<std::endl;
    }
    //修改第7个Block的data
    myBlockChain.getBlock(7)->data=myidol+"10";
    myBlockChain.check();
    /*for(int i=0;i<9;i++)
    {
        std::cout<<*myBlockChain.getBlock(i)<<std::endl;
    }*/

    //修改第7个Block的hashValue
    Block* temp=myBlockChain.getBlock(7);
    temp->hashValue=temp->hashmydata();
    myBlockChain.check();

    return 0;
}
