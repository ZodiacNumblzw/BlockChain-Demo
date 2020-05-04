#pragma once
#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include<string>
#include<cassert>
//ascii:33-125

//�ַ�����HashValue���㷽�����Լ����д�ģ�
class HashTable
{
private:
    const int hashLen=20;
public:
    HashTable(){}
    std::string getHashValue(const std::string& myKey)const
    {
        std::string hashValue="";
        int temp=233;
        int len=myKey.length();
        assert(len<=(hashLen+20));
        for(int i=0;i<len;i++)
            temp+=myKey[i];
        for(int i=0;i<hashLen;i++)
        {
            if(i<len)
                temp^=myKey[i];
            else
                temp^=i;
            hashValue+=(char)(temp%93+33);
        }
        return hashValue;
    }
};

//����ģʽ
class getHash
{
private:
    getHash(){}
public:
    static HashTable instance;
    static std::string getHashValue(const std::string& myKey)
    {
        return instance.getHashValue(myKey);
    }
};

HashTable getHash::instance = HashTable();


#endif // HASHTABLE_H_INCLUDED
