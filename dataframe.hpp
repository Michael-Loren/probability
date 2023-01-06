#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "column.hpp"


using namespace std;

class Dataframe{
    Dataframe();
    Dataframe();

    // Print the full dataframe in a format that makes sense
    void print();

    // Add a single column
    //void coladd(string colname, map<int,float> generator);

    void colremove();

    void rowadd(vector<int> row);

    void rowremove();

    void boolarray();

    void probability(int colnum, int subset);


    //void tablegen(string[] colnamearray, vector<map<int,float>> genArray)


    private:
        vector<Column> cols;
        int colnum;
    }; 