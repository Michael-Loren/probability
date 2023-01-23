#include "column.hpp"
using namespace std;
using namespace pandas;



int Column::count = random_device{}();

/**
 * @brief Construct a new Column object
 *
 * @param size Number of rows in column
 * @param weights Weights of values
 * @param values Values to be chosen from
 */

//default constructor (empty column)
Column::Column(){count++;}
// Column Constructor - Random Values
Column::Column(int csize, const vector<double> &weights, const vector<int> &values, string name = "") : rows(csize), size(csize), colname(name)
{
    
    // Initialize a random number generator
    mt19937 rng(++Column::count);

    // Initialize the discrete distribution
    discrete_distribution<int> dist(weights.begin(), weights.end());

    // Generate and Return values for every element of rows
    generate(rows.begin(), rows.end(), [&] { return values[dist(rng)]; });
}

// Column Constructor 
Column::Column(vector<int> vec) : rows(vec), size(vec.size()) {count++;}

// Return vector from Column call
Column::operator std::vector<int>(){
    return rows;
}

// Boolean Mask Logic.

// vector<bool> Column::operator>(int value){
//     vector<bool> mask;
//     for (int i = 0; i < size; i++) {
//         mask.push_back(rows[i] > value);
//     }
//     return mask;
// }

boost::dynamic_bitset<> Column::operator>(int value){
    boost::dynamic_bitset<> mask(size);
    for (int i = 0; i < size; i++) {
        mask[i] = rows[i] > value;
    }
    return mask;
}

// vector<bool> Column::operator<(int value){
//     vector<bool> mask;
//     for (int i = 0; i < size; i++) {
//         mask.push_back(rows[i] < value);
//     }
//     return mask;
// }

boost::dynamic_bitset<> Column::operator<(int value){
    boost::dynamic_bitset<> mask(size);
    for (int i = 0; i < size; i++) {
        mask[i] = rows[i] < value;
    }
    return mask;
}

// vector<bool> Column::operator>=(int value){
//     vector<bool> mask;
//     for (int i = 0; i < size; i++) {
//         mask.push_back(rows[i] >= value);
//     }
//     return mask;
// }

boost::dynamic_bitset<> Column::operator>=(int value){
    boost::dynamic_bitset<> mask(size);
    for (int i = 0; i < size; i++) {
        mask[i] = rows[i] >= value;
    }
    return mask;
}

// vector<bool> Column::operator<=(int value){
//     vector<bool> mask;
//     for (int i = 0; i < size; i++) {
//         mask.push_back(rows[i] <= value);
//     }
//     return mask;
// }

boost::dynamic_bitset<> Column::operator<=(int value){
    boost::dynamic_bitset<> mask(size);
    for (int i = 0; i < size; i++) {
        mask[i] = rows[i] <= value;
    }
    return mask;
}

// vector<bool> Column::operator==(int value){
//     vector<bool> mask;
//     for (int i = 0; i < size; i++) {
//         mask.push_back(rows[i] == value);
//     }
//     return mask;
// }

boost::dynamic_bitset<> Column::operator==(int value){
    boost::dynamic_bitset<> mask(size);
    for (int i = 0; i < size; i++) {
        mask[i] = rows[i] == value;
    }
    return mask;
}

// vector<bool> Column::operator!=(int value){
//     vector<bool> mask;
//     for (int i = 0; i < size; i++) {
//         mask.push_back(rows[i] != value);
//     }
//     return mask;
// }

boost::dynamic_bitset<> Column::operator!=(int value){
    boost::dynamic_bitset<> mask(size);
    for (int i = 0; i < size; i++) {
        mask[i] = rows[i] != value;
    }
    return mask;
}

void Column::print(){
    for (auto &i : rows)
    {
        cout << i << " "; 
    }
    cout << '\n';
}

/**
 * @brief Create a Column object that contains a select number of rows from a vector of ints.
 *
 * @param rows Rows that are selected
 */
Column Column::operator[](boost::dynamic_bitset<> mask){
    vector<int> selected;
    for (int i = 0; i < size; i++) {
        if (mask[i]) {
            selected.push_back(this->rows[i]);
        }
    }
    return Column(selected);
}

// Option to select rows from a column.
Column Column::operator[](vector<int> rowMask)
{
    vector<int> selected;
    for(auto &i: rowMask)
        if(i<size) // check if index is within the size of the rows array
            selected.push_back(this->rows[i]);
        else{
            throw std::logic_error("Attempted to access rows that don't exist.");
            exit(1);
        }
    return Column(selected);
}

// Column Column::operator[](vector<bool> mask)
// {
//     vector<int> selected;

//     // For indexer i, if bool is true, we add that values from colvec to selected.
//     for(int i = 0; i < size; i++) if (mask[i]) selected.push_back(rows[i]);
//     return Column(selected);
// }


string Column::name(){
    return colname;
}
const int Column::getsize(){
    return size;
}
void Column::rename(string newname){colname = newname;};
