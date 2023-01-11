
#include "pandas.hpp"
using namespace std;
namespace pandas{
     std::vector<bool> vecAND(vector<bool> &a, vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x & y; });
        return output;
    }
     std::vector<bool> vecOR(vector<bool> &a, vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x | y; });
        return output;
    }
     std::vector<bool> vecNAND(vector<bool> &a, vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return !(x & y); });
        return output;
    }
     std::vector<bool> vecNOR(vector<bool> &a, vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return !(x & y); });
        return output;
    }
     std::vector<bool> vecXOR(vector<bool> &a, vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x ^ y; });
        return output;
    }
     std::vector<bool> vecEQ(vector<bool> &a, vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x == y; });
        return output;
    }
     std::vector<bool> vecNEQ(vector<bool> &a, vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x != y; });
        return output;
    }


// Bad Practice
// std::vector<bool> operator&(vector<bool> a, vector<bool> b){
//     if (a.size() != b.size()){
//         throw std::invalid_argument("differently sized bitwise operands");
//     }
        
//     vector<bool> newvec;

//     vector<bool>::iterator ait;
//     vector<bool>::iterator bit;
    
//     for (ait = a.begin(), bit = b.begin(); ait < a.end(), bit < b.end(); ait++, bit++){
//         bool boola = *ait;
//         bool boolb = *bit;

//         newvec.push_back(boola & boolb);
//     }

//     return newvec;
    
// }



}