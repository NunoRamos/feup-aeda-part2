/**
 * @file sequentialSearch.h
 *
 * @brief Code for sequential search*/

#include <vector>
using namespace std;

/**
 * @brief Search for x in v
 *
 * @param v Where to check in
 * @param x What to check for
 */
template <class Comparable>
int sequentialSearch(const vector<Comparable> &v, Comparable x)
{
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i] == x)
           return i;   // found it
    return -1;
}
