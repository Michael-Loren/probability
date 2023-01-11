#include <iostream>
#include <vector>
#include "column.hpp"
#include "dataframe.hpp"
#include <algorithm>
#include <typeinfo>



int main(){
    std::cout << "Hi Mike\n";

    std::vector<double> d({0.33, 0.33, 0.33});
    std::vector<int> i({5,10,15});

    Column c(10, d, i, "mycol");
    
    c.print();

    std::cout << c.name();

    Dataframe df();
    
   



    // std::sort(i.begin(), i.end(), [&](int a, int b) {return a > b; });

    // for (auto &a : i){
    //     std::cout << a << "\n";
    // }

}
