#include <vector>
#include <algorithm>
#include "dataframe.hpp"
namespace pandas{
    static std::vector<bool> vecAND(vector<bool> &a, vector<bool> &b);
    static std::vector<bool> vecOR(vector<bool> &a, vector<bool> &b);
    static std::vector<bool> vecNOR(vector<bool> &a, vector<bool> &b);
    static std::vector<bool> vecNAND(vector<bool> &a, vector<bool> &b);
    static std::vector<bool> vecXOR(vector<bool> &a, vector<bool> &b);
    static std::vector<bool> vecEQ(vector<bool> &a, vector<bool> &b);
    static std::vector<bool> vecNEQ(vector<bool> &a, vector<bool> &b);
 }
