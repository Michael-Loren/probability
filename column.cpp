
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
Column::Column(int csize, const vector<double> &weights, const vector<int> &values) : col(csize), size(csize)
{
    // Initialize a random number generator
    mt19937 rng(random_device{}());

    // Initialize the discrete distribution
    discrete_distribution<int> dist(weights.begin(), weights.end());

    // Generate and Return values for every element of col
    generate(col.begin(), col.end(), [&] { return values[dist(rng)]; });
}

// Column Constructor 

// Boolean Mask Logic.

bool Column::operator>(int value)
{
    bool* mask = new bool[size];
    for (int i = 0; i < size; i++) {
        mask[i] = (col[i] > value);
    }
    return mask;
}

bool Column::operator<(int value)
{
    bool* mask = new bool[size];
    for (int i = 0; i < size; i++) {
        mask[i] = (col[i] <= value);
    }
    return mask;
}

bool Column::operator>=(int value)
{
    bool* mask = new bool[size];
    for (int i = 0; i < size; i++) {
        mask[i] = (col[i] > value);
    }
    return mask;
}

bool Column::operator<=(int value)
{
    bool* mask = new bool[size];
    for (int i = 0; i < size; i++) {
        mask[i] = (col[i] <= value);
    }
    return mask;
}

bool Column::operator==(int value)
{
    bool* mask = new bool[size];
    for (int i = 0; i < size; i++) {
        mask[i] = (col[i] == value);
    }
    return mask;
}

bool Column::operator!=(int value)
{
    bool* mask = new bool[size];
    for (int i = 0; i < size; i++) {
        mask[i] = (col[i] != value);
    }
    return mask;
}

int* Column::operator[](bool mask)
{
    int selected[size];
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (mask[i]) {
            selected[count] = col[i];
            count++;
        }
    }
    return selected;
}

void Column::print()
{
    for (auto &i : col)
    {
        cout << i << "\n";
    }
}
