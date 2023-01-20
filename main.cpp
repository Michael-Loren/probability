#include <iostream>
#include <vector>

#include "pandas.hpp"
#include <algorithm>
#include <typeinfo>

using namespace std;
using namespace pandas;


int main(){
    std::cout << "Hi Mike\n";

    std::vector<double> d({0.33, 0.33, 0.33});
    std::vector<int> i({5,10,15});

    Column c(10, d, i, "mycol");
    
    c.print();

    std::cout << c.name() << endl;

    vector<vector<double>> weights{{0.2, 0.4, 0.2, 0.2},{0.3, 0.2, 0.5},{0.6, 0.4}};
    vector<vector<int>> values{{2, 4, 6, 8},{3, 13, 16},{100, 5}};


    // Specific Dataframe Constructor
    Dataframe specified(100, weights, values);

    specified.print();

    cout << "++++++++++++++++++++++++++++++++++++++++++\n";




    // vector<bool> b1 = {0, 1, 0, 1};
    // vector<bool> b2 = {1, 1, 0, 0};

    // vector<bool> newvec = b1 & b2;

    // for (auto b : newvec) {
    //     cout << b << " ";
    // }
 
 
 
 
    // Random Dataframe constructor
    Dataframe df(100, 6, d, i);
    df.print();

   

    cout << "++++++++++++++++++++++++++++++++++++++++++\n";


    vector<bool> conditionA = vecAND(df["3"] == 5, vecAND(df["1"] == 5, df["3"] == 5) );


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

    double pBgA = probAgivenB(df, conditionA, conditionB);
    cout << pBgA << endl;

    double pAgB = bayesTheorem(df, conditionA, conditionB, pBgA);
    cout << pAgB << endl;


   
}


// double divideAbyB(double a, double b);

// divideBbyA(5,6);

// divide(5, 6)
// divide(6, 5)
// double divideBbyA(double a, double b);

// P(A = 5 | B = 15)


// P(A|B) = P(AintB)/P(B) = P(A and B) / P(B)


