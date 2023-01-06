#include <iostream>
class Column{
    public:
        Column();
        

        // generate column with random number of rows
        // dictionary generator = {0:0.4, 1:0.2, 2:0.2, 3:0.2}
        // vector of dictionary generator
        


        
        Column(int size, int low, int high);
        void print();

    private:
       std::vector<int> col;
};