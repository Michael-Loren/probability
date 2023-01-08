
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
Column::Column(int csize, const vector<double> &weights, const vector<int> &values) : colvec(csize), size(csize)
{
    // Initialize a random number generator
    mt19937 rng(random_device{}());

    // Initialize the discrete distribution
    discrete_distribution<int> dist(weights.begin(), weights.end());

    // Generate and Return values for every element of colvec
    generate(colvec.begin(), colvec.end(), [&] { return values[dist(rng)]; });
}

// Column Constructor 

// Boolean Mask Logic.

vector<bool> Column::operator>(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(colvec[i] > value);
    }
    return mask;
}

vector<bool> Column::operator<(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(colvec[i] < value);
    }
    return mask;
}

vector<bool> Column::operator>=(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(colvec[i] >= value);
    }
    return mask;
}

vector<bool> Column::operator<=(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(colvec[i] <= value);
    }
    return mask;
}

vector<bool> Column::operator==(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(colvec[i] == value);
    }
    return mask;
}


vector<bool> Column::operator!=(int value)
{
    vector<bool> mask;
    for (int i = 0; i < size; i++) {
        mask.push_back(colvec[i] != value);
    }
    return mask;
}

void Column::print()
{
    for (auto &i : colvec)
    {
        cout << i << " "; 
    }
    cout << '\n';
}

//df[numbirds>1]

//numbirds>1 -> {true, false, true, ...}
//df[numbirds>1] -> the desired rows.

// filter(df, [](auto arg) {return arg < 5;})

vector<int> Column::operator[](vector<bool> mask)
{
    vector<int> selected;

    // For indexer i, if bool is true, we add that values from colvec to selected.
    for(int i = 0; i < size; i++) if (mask[i]) selected.push_back(colvec[i]);
    return selected;
}