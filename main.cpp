#include <iostream>
#include <vector>
#include "dataframe.hpp"
#include <algorithm>
#include <typeinfo>

using namespace std;

int main(){
    std::cout << "Hi Mike\n";

    std::vector<double> d({0.33, 0.33, 0.33});
    std::vector<int> i({5,10,15});

    Column c(10, d, i, "mycol");
    
    c.print();

    std::cout << c.name() << endl;

  
    Dataframe df(15, 5, d, i);
    
    for (auto a : static_cast<vector<Column>>(df)){
        a.print();
    }
    df = Dataframe(15, 4, d, i);
    

    for (auto a : static_cast<vector<Column>>(df)){
        a.print();
    }
    // std::sort(i.begin(), i.end(), [&](int a, int b) {return a > b; });

    // for (auto &a : i){
    //     std::cout << a << "\n";
    // }

}
