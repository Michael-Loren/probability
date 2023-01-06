#include <iostream>
#include <vector>





int main(){
 std::cout << "Hi Mike\n";
 std::vector<int> vec({2,3,4,5});
 
 for (int &i : vec){
    std::cout << i << "\n";
 }
}


/*
Column Class

*/

/*
    SingleColumnCreation - input a 2d array and return a single column
*/
