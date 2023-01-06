
#include "column.hpp"
using namespace std;
/**
 * @brief Construct a new Column object
 *
 * @param size Number of rows in column
 * @param weights Weights of values
 * @param values Values to be chosen from
 */
Column::Column(int size, const vector<double> &weights, const vector<int> &values) : col(size)
{

    mt19937 rng(random_device{}());
    discrete_distribution<int> dist(weights.begin(), weights.end());

    generate(col.begin(), col.end(), [&] { return values[dist(rng)]; });
}

void Column::print()
{
    for (auto &i : col)
    {
        cout << i << "\n";
    }
}
