
#include "pandas.hpp"
using namespace std;
namespace pandas{

    // Takes the bitwise unsigned integers a and b and performs a bitwise AND operation
    std::unsigned int vecAND(const unsigned int &a, const unsigned int &b){
        return a & b;
    }
    // Takes the bitwise unsigned integers a and b and performs a bitwise OR operation
    std::unsigned int vecOR(const unsigned int &a, const unsigned int &b){
        return a | b;
    }

    //Takes the bitwise unsigned integers a and b and performs a bitwise NAND operation
    std::unsigned int vecNAND(const unsigned int &a, const unsigned int &b){
        return ~(a & b);
    }

    //Takes the bitwise unsigned integers a and b and performs a bitwise NOR operation
    std::unsigned int vecNOR(const unsigned int &a, unsigned int &b){
        return ~(a | b);
    }

    //Takes the bitwise unsigned integers a and b and performs a bitwise XOR operation
    std::unsigned int vecXOR(const unsigned int &a, const unsigned int &b){
        return a ^ b;
    }

    //Takes the bitwise unsigned integers a and b and performs a bitwise == operation
     std::unsigned int vecEQ(const unsigned int &a, const unsigned int &b){
        return ~(a ^ b);
    }

    //Takes the bitwise unsigned integers a and b and performs a bitwise != operation
     std::unsigned int vecNEQ(const unsigned int &a, const unsigned int &b){
        return a ^ b;
    }




    double probAgivenB(Dataframe df, const unsigned int &conditionA, const unsigned int &conditionB) {
        double pB = (double)df[conditionB].getrows() / (double)df.getrows();
        double pAintB = (double)df[vecAND(conditionA, conditionB)].getrows()/ (bool) df.getrows();
        double pAgivenB = pAintB/pB;
        return pAgivenB;
    }
    
    // double probBgivenA(Dataframe df, const unsigned int &conditionA, const unsigned int &conditionB) {
    //     double pA = (double)df[conditionA].getrows() / (double)df.getrows();
    //     double pAintB = (double)df[vecAND(conditionA, conditionB)].getrows()/ (bool) df.getrows();
    //     double pBgivenA = pAintB/pA;
    //     return pBgivenA;
    // }

    double bayesTheorem(Dataframe df, const unsigned int &conditionA, const unsigned int &conditionB, double pBgivenA) {
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