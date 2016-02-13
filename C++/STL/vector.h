#ifndef VECTOR_PRCTICE_H_INCLUDED
#define VECTOR_PRCTICE_H_INCLUDED
#include <vector>
#include <iostream>

class Vector_Practice
{
public:
    static void RunAllTests();
    
private:
    static void Test_Constructor();
    static void Test_Operator();
    //Iterators:
    static void Test_BeginOrEnd();
    static void Test_rBeginOrrEnd();
    static void Test_cBeginOrcEnd();
    
    //Capacity
    static void Test_Size();
    static void Test_Modifier();
private:
    static void Show(const std::vector<int> &v);
};



#endif // VECTOR_PRCTICE_H_INCLUDED