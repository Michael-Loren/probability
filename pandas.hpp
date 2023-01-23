#ifndef PANDAS_HPP
#define PANDAS_HPP
#include <vector>
#include <algorithm>
#include "dataframe.hpp"
#include "column.hpp"
#include <boost/dynamic_bitset.hpp>

using boolean_mask = boost::dynamic_bitset<>;

namespace pandas{
    double probAgivenB(Dataframe df, boolean_mask &conditionA, boolean_mask &conditionB);
    //  double probBgivenA(Dataframe df, boolean_mask &conditionA, boolean_mask &conditionB);
    double bayesTheorem(Dataframe df, boolean_mask &conditionA, boolean_mask &conditionB, double pBgivenA);
 }
#endif