
#include "pandas.hpp"
using namespace std;
namespace pandas{


    double probAgivenB(Dataframe df, boolean_mask &conditionA, boolean_mask &conditionB) {
        double pB = (double)df[conditionB].getrows() / (double)df.getrows();
        double pAintB = (double)df[conditionA & conditionB].getrows()/ (bool) df.getrows();
        double pAgivenB = pAintB/pB;
        return pAgivenB;
    }
    
    // double probBgivenA(Dataframe df, boolean_mask &conditionA, boolean_mask &conditionB) {
    //     double pA = (double)df[conditionA].getrows() / (double)df.getrows();
    //     double pAintB = (double)df[vecAND(conditionA, conditionB)].getrows()/ (bool) df.getrows();
    //     double pBgivenA = pAintB/pA;
    //     return pBgivenA;
    // }

    // Multiply the dataframes
    // Dataframe is a vector of columns, each column is a vector of ints.
    // Dataframe matmult(Dataframe left, Dataframe right){

    // }

    // Divide the dataframes


    // If we use armadillo, we start here.

    // Markov Chain to level n

    // Infinite Markov Chain

    double bayesTheorem(Dataframe df, boolean_mask &conditionA, boolean_mask &conditionB, double pBgivenA) {

        // if (conditionA.size() != conditionB.size()){
        //     throw invalid_argument("differently sized bitwise operands");
        // }


        double pA = (double)df[conditionA].getrows() / (double)df.getrows();
        double pB = (double)df[conditionB].getrows() / (double)df.getrows();
        double pAgivenB = pBgivenA * pA/pB;
        return pAgivenB;
    }

    // Naive Bayesian Clasifier: Given condition 1, return condition 2.
    // If it randomly hits, set the value equal to a condition.

// (A and B and C and D) / (A and C)


// Bad Practice
// std::vector<bool> operator&(vector<bool> a, vector<bool> b){
//     if (a.size() != b.size()){
//         throw invalid_argument("differently sized bitwise operands");
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