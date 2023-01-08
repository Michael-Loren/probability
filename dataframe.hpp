#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "column.hpp"


using namespace std;

class Dataframe{
    Dataframe();

    // Print the full dataframe in a format that makes sense
    void print();

    // Add a single column
    //void coladd(string colname, map<int,float> generator);

    void colremove();

    void rowadd(vector<int> row);

    void rowremove();

    void boolarray();

    
    // Given a condition, query a subset of the larger dataframe and return the Dataframe
    Dataframe subset();

    // Probabilities can be manipulated in another file.

    //void probability(int colnum, int subset);

    //void probabilityAgivenB(const vector<int> colA, const vector<int> varA, const vector<int> colB, const vector<int> varB);


    //void tablegen(string[] colnamearray, vector<map<int,float>> genArray)


    private:
        vector<Column> cols;
        int colnum;
    }; 