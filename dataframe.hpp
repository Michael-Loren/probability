#ifndef DATAFRAME_HPP
#define DATAFRAME_HPP
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "column.hpp"


using namespace std;

namespace pandas{
class Dataframe{

    //----------------------CONSTRUCTORS-----------------------------
    public:
    Dataframe();

    // Create a dataframe with a certain number of rows and columns - random
    Dataframe(int rowNum, int colNum);

    Dataframe(int rowNum, vector<vector<double>> weights, vector<vector<int>> values, vector<string> names = {});

    Dataframe(int rowNum, int colNum, vector<double> weights, vector<int> values);

    Dataframe(vector<Column> newcols); 

    // Create a dataframe from a 2d matrix of integers. 
    Dataframe(vector<vector<int>> DataMatrix);

    // Print the full dataframe in a format that makes sense
    void print();


    //------------------------OPERATIONS-----------------------------
    // Append a single column to the colarray
    void operator+=(Column column);

    //insert column to specific index in dataframe
    void insert(int index, Column column);

    operator vector<Column>();
    
    void colremove(string colname);
    void colremove(int index);
    
    

    // Return the Column that matches the name
    Column operator[](string name);

    // Return the dataframe of rows for which the mask is true.
    Dataframe operator[](vector<bool> mask);

    void rowadd(vector<int> row);
    void remove(int index);

    int getrows();
    int getcols();



    private:

        //Vector of columns
        vector<Column> cols;

        // number of Columns in Cols
        int colnum;

        //number of rows in each col
        int rownum;
    }; 
}
#endif