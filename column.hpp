#include <iostream>
#include <vector>

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
        


        
        Column(int size, int low, int high);

        /**
         * @brief Construct a new Column object
         * 
         * @param size - Number of rows
         * @param weights - Weights of values
         * @param values - Values to be chosen from
         */
        Column(int size, const vector<double>& weights, const vector<int>& values);
        void print();

    private:
       std::vector<int> col;
};