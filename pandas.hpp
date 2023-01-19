#ifndef PANDAS_HPP
#define PANDAS_HPP
#include <vector>
#include <algorithm>
#include "dataframe.hpp"
#include "column.hpp"

namespace pandas{
     std::vector<bool> vecAND(const vector<bool> &a, const vector<bool> &b);
     std::vector<bool> vecOR(const vector<bool> &a, const vector<bool> &b);
     std::vector<bool> vecNOR(const vector<bool> &a, const vector<bool> &b);
     std::vector<bool> vecNAND(const vector<bool> &a, const vector<bool> &b);
     std::vector<bool> vecXOR(const vector<bool> &a, const vector<bool> &b);
     std::vector<bool> vecEQ(const vector<bool> &a, const vector<bool> &b);
     std::vector<bool> vecNEQ(const vector<bool> &a, const vector<bool> &b);

     double probAgivenB(Dataframe df, const vector<bool> &conditionA, const vector<bool> &conditionB);
    //  double probBgivenA(Dataframe df, const vector<bool> &conditionA, const vector<bool> &conditionB);
     double bayesTheorem(Dataframe df, const vector<bool> &conditionA, const vector<bool> &conditionB, double pBgivenA);
     
 }
#endif