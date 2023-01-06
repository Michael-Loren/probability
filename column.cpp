#include <vector>
#include <map>
#include <random>
#include <algorithm>
#include "column.hpp"
using namespace std;

Column::Column(int size, int low, int high) : col(size){

    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(low, high);
    generate(col.begin(), col.end(), [&] { return dist(rng); });
    
}
/*

```c++

code stuff

```

*/
void Column::print(){
    for (auto &i : col){
        cout << i << "\n";
    }
}
