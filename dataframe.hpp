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

    Dataframe operator[][](vector<bool> mask, vector<string> colnames);


    // Df['newcol'] - if a new string is created, we create a new col and add to the dataframe - empty by default of size col
    Dataframe operator[](string newcol);

    /*Df['newcol'] = Column object - we fill the empty dataframe of size rownum with elements from the column object.
    
    */
    operator Column();

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

        //Vector of columns
        vector<Column> cols;
        // number of Columns in Cols
        int colnum;

        //number of rows in each col
        int rownum;
    }; 