#include <iostream>
#include <vector>
#include "column.hpp"
#include <algorithm>
#include <typeinfo>



int main(){
    std::cout << "Hi Mike\n";

    std::vector<double> d({0.33, 0.33, 0.33});
    std::vector<int> i({5,10,15});

    Column c(10, d, i);
    c.print();


    
    auto ret = c.operator<(10);

    for (bool i : ret){
    std::cout << i << ' ';
    }





    // std::sort(i.begin(), i.end(), [&](int a, int b) {return a > b; });

    // for (auto &a : i){
    //     std::cout << a << "\n";
    // }

}
