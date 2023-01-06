#include <iostream>
#include <vector>
#include "column.hpp"




int main(){
 std::cout << "Hi Mike\n";

std::vector<double> d({0.33, 0.33, 0.33});
std::vector<int> i({5,10,15});

 Column c(10, d, i);
 c.print();
}


/*
Column Class

*/

/*
    SingleColumnCreation - input a 2d array and return a single column
*/
