#include <iostream>
#include <vector>
#include <string>

#include <map>
#include <random>
#include <algorithm>
using std::vector;



class Column{
    public:
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
        Column(int size, const vector<double>& weights, const vector<int>& values);

        // Make a colun from a vector input.
        Column(vector<int> colvec);

        // When casted to a vector, return the vector elements in the Column object.
        operator vector<int>();

        // Bool Masking and Operator Functions
        vector<bool> operator>(int value);
        vector<bool> operator<(int value);
        vector<bool> operator>=(int value);
        vector<bool> operator<=(int value);
        vector<bool> operator==(int value);
        vector<bool> operator!=(int value);


        // Return Elements that meet an operator condition.
        Column operator[](vector<bool> mask);

        // Return rows {1, 2, 3, 4}
        Column operator[](vector<int> rows);



        void print();

    private:
        // Column values
        vector<int> colvec;

        // Column size
        int size;

        std::string name;
};