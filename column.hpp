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
        
        Column(vector<int> colvec);

        //Bool Masking and Operator Functions
        
        operator vector<int>();

        vector<bool> operator>(int value);
        vector<bool> operator<(int value);
        vector<bool> operator>=(int value);
        vector<bool> operator<=(int value);
        vector<bool> operator==(int value);
        vector<bool> operator!=(int value);


        Column operator[](vector<bool> mask);



        void print();

    private:
        // Column values
        vector<int> colvec;

        // Column size
        int size;

        std::string name;
};