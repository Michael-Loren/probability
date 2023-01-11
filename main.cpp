#include <iostream>
#include <vector>

#include "pandas.hpp"
#include <algorithm>
#include <typeinfo>

using namespace std;

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
    for (auto a : static_cast<vector<Column>>(df)){
        cout << a.name() << ' ';
        a.print();
    }

    auto something = df["2"];
    cout << "------------------\n";
    something.print();
    vector<bool> conditionA = df["2"] > 5;


    vector<bool> conditionB = df["3"] < 10;
    for (auto i : conditionA){
        cout << i << " ";
    }
    cout << endl;
    for (auto i : conditionB){
        cout << i << " ";
    }
    cout << endl;
    
    vector<bool> conditionC = pandas::vecAND(conditionA, conditionB);
    
    c[conditionA].print();
    c[conditionB].print();
    
    for (auto i : conditionC){
        cout << i << " ";
    }
    cout << endl;

    double prob = (double)c[conditionC].getsize() / (double)c.getsize();
    cout << prob << endl;
    


   
}

// def pAgivenB(dataset, conditionA, conditionB):
//     pB = len(dataset[conditionB])/len(dataset)
//     pAintB = len(dataset[conditionA & conditionB])/len(dataset)
//     pAgivenB = pAintB/pB
//     return pAgivenB

