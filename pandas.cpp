
#include "pandas.hpp"
using namespace std;
namespace pandas{
     std::vector<bool> vecAND(const vector<bool> &a, const vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x & y; });
        return output;
    }
     std::vector<bool> vecOR(const vector<bool> &a, const vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x | y; });
        return output;
    }



     std::vector<bool> vecNAND(const vector<bool> &a, const vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return !(x & y); });
        return output;
    }
     std::vector<bool> vecNOR(const vector<bool> &a, vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return !(x & y); });
        return output;
    }
     std::vector<bool> vecXOR(const vector<bool> &a, const vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x ^ y; });
        return output;
    }
     std::vector<bool> vecEQ(const vector<bool> &a, const vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x == y; });
        return output;
    }
     std::vector<bool> vecNEQ(const vector<bool> &a, const vector<bool> &b){
        vector<bool> output;
        output.resize(a.size());
        std::transform(a.begin(), a.end(), b.begin(), output.begin(), [](bool x, bool y)
                       { return x != y; });
        return output;
    }




    double probAgivenB(Dataframe df, const vector<bool> &conditionA, const vector<bool> &conditionB) {
        double pB = (double)df[conditionB].getrows() / (double)df.getrows();
        double pAintB = (double)df[vecAND(conditionA, conditionB)].getrows()/ (bool) df.getrows();
        double pAgivenB = pAintB/pB;
        return pAgivenB;
    }
    
    // double probBgivenA(Dataframe df, const vector<bool> &conditionA, const vector<bool> &conditionB) {
    //     double pA = (double)df[conditionA].getrows() / (double)df.getrows();
    //     double pAintB = (double)df[vecAND(conditionA, conditionB)].getrows()/ (bool) df.getrows();
    //     double pBgivenA = pAintB/pA;
    //     return pBgivenA;
    // }

    double bayesTheorem(Dataframe df, const vector<bool> &conditionA, const vector<bool> &conditionB, double pBgivenA) {
        double pA = (double)df[conditionA].getrows() / (double)df.getrows();
        double pB = (double)df[conditionB].getrows() / (double)df.getrows();
        double pAgivenB = pBgivenA * pA/pB;
        return pAgivenB;
    }

// (A and B and C and D) / (A and C)


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