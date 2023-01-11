#include <iostream>
#include <vector>

#include "pandas.hpp"
#include <algorithm>
#include <typeinfo>

using namespace std;
using namespace pandas;


// double probAgivenB(Dataframe df, vector<bool> conditionA, vector<bool> conditionB) {
//     double pB = (double)df[conditionB].getrows() / (double)df.getrows();
//     double pAintB = (double)df[vecAND(conditionA, conditionB)].getrows()/ (bool) df.getrows();
//     double pAgivenB = pAintB/pB;
//     return pAgivenB;
// }
// double probBgivenA(Dataframe df, vector<bool> conditionA, vector<bool> conditionB) {
//     double pA = (double)df[conditionA].getrows() / (double)df.getrows();
//     double pAintB = (double)df[vecAND(conditionA, conditionB)].getrows()/ (bool) df.getrows();
//     double pBgivenA = pAintB/pA;
//     return pBgivenA;
// }
// double bayesTheorem(Dataframe df, vector<bool> conditionA, vector<bool> conditionB, double pBgivenA) {
//     double pA = (double)df[conditionA].getrows() / (double)df.getrows();
//     double pB = (double)df[conditionB].getrows() / (double)df.getrows();
//     double pAgivenB = pBgivenA * pA/pB;
//     return pAgivenB;
// }
int main(){
    std::cout << "Hi Mike\n";

    std::vector<double> d({0.33, 0.33, 0.33});
    std::vector<int> i({5,10,15});

    Column c(10, d, i, "mycol");
    
    c.print();

    std::cout << c.name() << endl;



    // vector<bool> b1 = {0, 1, 0, 1};
    // vector<bool> b2 = {1, 1, 0, 0};

    // vector<bool> newvec = b1 & b2;

    // for (auto b : newvec) {
    //     cout << b << " ";
    // }
 
 
 
 
 
    Dataframe df(10, 4, d, i);
    df.insert(2, c);
    df.print();

   

    cout << "+++++++++++++++++++++++\n";


    vector<bool> conditionA = df["2"] == 5;


    vector<bool> conditionB = df["3"] == 10;


    cout << "-----------df[conditionA]---------------------\n";
    for (auto i : conditionA){
        cout << i << " ";
    }
    cout << endl;
    cout << "------------df[conditionB]--------------------\n";

    for (auto i : conditionB){
        cout << i << " ";
    }
    cout << endl;
    
    vector<bool> conditionC = pandas::vecAND(conditionA, conditionB);
    

    // df[conditionA].print();

    // df[conditionB .print();
    cout << "------------df[conditionC]--------------------\n";

    for (auto i : conditionC){
        cout << i << " ";
    }
    cout << endl;

    double prob = (double)df[conditionC].getrows() / (double)df.getrows();
    cout << prob << endl;

    // double probability = probAgivenB(df, conditionA, conditionB);
    // cout << probability << endl;
   
}




// P(A = 5 | B = 15)


// P(A|B) = P(AintB)/P(B) = P(A and B) / P(B)


