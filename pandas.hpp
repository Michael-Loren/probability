#ifndef PANDAS_HPP
#define PANDAS_HPP
#include <vector>
#include <algorithm>
#include "dataframe.hpp"
#include "column.hpp"

namespace pandas{
     std::vector<bool> vecAND(vector<bool> &a, vector<bool> &b);
     std::vector<bool> vecOR(vector<bool> &a, vector<bool> &b);
     std::vector<bool> vecNOR(vector<bool> &a, vector<bool> &b);
     std::vector<bool> vecNAND(vector<bool> &a, vector<bool> &b);
     std::vector<bool> vecXOR(vector<bool> &a, vector<bool> &b);
     std::vector<bool> vecEQ(vector<bool> &a, vector<bool> &b);
     std::vector<bool> vecNEQ(vector<bool> &a, vector<bool> &b);
 }
#endif