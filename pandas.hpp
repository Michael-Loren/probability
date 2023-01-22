#ifndef PANDAS_HPP
#define PANDAS_HPP
#include <vector>
#include <algorithm>
#include "dataframe.hpp"
#include "column.hpp"
#include <bitset>

namespace pandas{
    double probAgivenB(Dataframe df, const unsigned int &conditionA, const unsigned int &conditionB);
    //  double probBgivenA(Dataframe df, const unsigned int &conditionA, const unsigned int &conditionB);
    double bayesTheorem(Dataframe df, const unsigned int &conditionA, const unsigned int &conditionB, double pBgivenA);
 }
#endif