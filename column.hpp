#ifndef COLUMN_HPP
#define COLUMN_HPP

#include <iostream>
#include <vector>
#include <string>

#include <map>
#include <random>
#include <algorithm>
#include <boost/dynamic_bitset.hpp>
#include "pandas.hpp"

using std::vector;
using std::string;
namespace pandas{
class Column{
    public:

        using mask_t = std::bitset<30>;

        Column();
        

        // generate column with random number of rows
        // dictionary generator = {0:0.4, 1:0.2, 2:0.2, 3:0.2}
        // vector of dictionary generator
        


        
        

        /**
         * @brief Construct a new Column object with random values
         * 
         * @param size - Number of rows to generate
         * @param weights - Weights of values
         * @param values - Values to be chosen from
         */
        Column(int size, const vector<double>& weights, const vector<int>& values, string name);

        // Make a colunm from a vector input.
        Column(vector<int> colvec);

        // When casted to a vector, return the vector elements in the Column object.
        operator vector<int>();

        // Bool Masking and Operator Functions
        boost::dynamic_bitset<> operator>(int value);
        boost::dynamic_bitset<> operator<(int value);
        boost::dynamic_bitset<> operator>=(int value);
        boost::dynamic_bitset<> operator<=(int value);
        boost::dynamic_bitset<> operator==(int value);
        boost::dynamic_bitset<> operator!=(int value);


        // Return Elements that meet an operator condition.
        Column operator[](boost::dynamic_bitset<> mask);

        // Return rows {1, 2, 3, 4}
        Column operator[](vector<int> rows);

        // Return the name of the column
        string name();
        void rename(string newname);


        void print();

        const int getsize();

        // Count number of rows with each unique value of variable
        unordered_map<int, int> value_counts();
    
    private:
        // Column values
        vector<int> rows;

        // Column size
        int size;

        std::string colname;

        //for random number seed because i'm too lazy to use an entropic seed
        static int count;
        
};
}
#endif