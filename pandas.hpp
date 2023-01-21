#ifndef PANDAS_HPP
#define PANDAS_HPP
#include <vector>
#include <algorithm>
#include "dataframe.hpp"
#include "column.hpp"

namespace pandas{
     std::unsigned int vecAND(const unsigned int &a, const unsigned int &b);
     std::unsigned int vecOR(const unsigned int &a, const unsigned int &b);
     std::unsigned int vecNOR(const unsigned int &a, const unsigned int &b);
     std::unsigned int vecNAND(const unsigned int &a, const unsigned int &b);
     std::unsigned int vecXOR(const unsigned int &a, const unsigned int &b);
     std::unsigned int vecEQ(const unsigned int &a, const unsigned int &b);
     std::unsigned int vecNEQ(const unsigned int &a, const unsigned int &b);

     double probAgivenB(Dataframe df, const unsigned int &conditionA, const unsigned int &conditionB);
    //  double probBgivenA(Dataframe df, const unsigned int &conditionA, const unsigned int &conditionB);
     double bayesTheorem(Dataframe df, const unsigned int &conditionA, const unsigned int &conditionB, double pBgivenA);
     
 }
#endif