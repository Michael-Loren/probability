#include <iostream>
#include <vector>
#include <string>
#include <map>
#include 'column.hpp'


using namespace std;

class Dataframe{
    Dataframe();
    Dataframe();

    // Print the full dataframe in a format that makes sense
    void print();

    // Add a single column
    //void coladd(string colname, map<int,float> generator);

    void colremove();

    void rowadd(int[colnum] row);

    void rowremover();


    //void tablegen(string[] colnamearray, vector<map<int,float>> genArray)


    private:
        vector<column> cols;
        int colnum;
    }; 