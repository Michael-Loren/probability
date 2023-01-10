#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "column.hpp"


using namespace std;

class Dataframe{

    // Constructors

    Dataframe();

    // Create a dataframe with a certain number of rows and columns - random
    Dataframe(int rowNum, int colNum);

    // Create a dataframe from a 2d matrix of integers. 
    Dataframe(vector<vector<int>> DataMatrix);

    // Print the full dataframe in a format that makes sense
    void print();

    // Add a single column to the colarray
    void coladd(Column column, string colname);

    // I'm shaky on this
    /*Df['newcol'] = Column object - we fill the empty dataframe of size rownum with elements from the column object.
    
    */

    void colremove(vector<string> newcol);


    // Getters

    // Df['newcol'] - if a new string is created, we create a new col and add to the dataframe - empty by default of size col
    Dataframe operator[](vector<string> newcol);


    
    operator Column();

    void rowadd(vector<int> row);

    //void rowremove(int rownum);
    
    // Given a condition, query a subset of the larger dataframe and return the Dataframe

    // Using operator overloads...
    //***
    //Dataframe& subset(colname > 5);

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