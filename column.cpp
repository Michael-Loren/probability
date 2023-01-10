
#include "column.hpp"
using namespace std;
/**
 * @brief Construct a new Column object
 *
 * @param size Number of rows in column
 * @param weights Weights of values
 * @param values Values to be chosen from
 */

// Column Constructor - Random Values
Column::Column(int csize, const vector<double> &weights, const vector<int> &values) : rows(csize), size(csize)
{
    // Initialize a random number generator
    mt19937 rng(random_device{}());

    // Initialize the discrete distribution
    discrete_distribution<int> dist(weights.begin(), weights.end());

    // Generate and Return values for every element of rows
    generate(rows.begin(), rows.end(), [&] { return values[dist(rng)]; });
}

// Column Constructor 
Column::Column(vector<int> vec) : rows(vec), size(vec.size()) {}

// Return vector from Column call
Column::operator std::vector<int>(){
    return rows;
}

// Boolean Mask Logic.

vector<bool> Column::operator>(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(rows[i] > value);
    }
    return mask;
}

vector<bool> Column::operator<(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(rows[i] < value);
    }
    return mask;
}

vector<bool> Column::operator>=(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(rows[i] >= value);
    }
    return mask;
}

vector<bool> Column::operator<=(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(rows[i] <= value);
    }
    return mask;
}

vector<bool> Column::operator==(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(rows[i] == value);
    }
    return mask;
}

vector<bool> Column::operator!=(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(rows[i] != value);
    }
    return mask;
}

void Column::print()
{
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
Column Column::operator[](vector<int> rows)
{
    vector<int> selected;

    // ***
    for(auto &i: rows) selected.push_back(rows[i]);
    return Column(selected);

}



//df[numbirds>1]

//numbirds>1 -> {true, false, true, ...}
//df[numbirds>1] -> the desired rows.

// filter(df, [](auto arg) {return arg < 5;})

Column Column::operator[](vector<bool> mask)
{
    vector<int> selected;

    // For indexer i, if bool is true, we add that values from colvec to selected.
    for(int i = 0; i < size; i++) if (mask[i]) selected.push_back(rows[i]);
    return Column(selected);
}