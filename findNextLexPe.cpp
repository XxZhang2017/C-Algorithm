#include <algorithm>
#include <vector>

/* 
 * Computes the next lexicographical permutation of the specified
 * vector in place, returning whether a next permutation existed.
 * (Returns false when the argument is already the last possible
 * permutation.)
 */
template <typename T>
bool next_permutation(std::vector<T> &array) {
    // Find non-increasing suffix
    if (array.size() == 0)
        return false;
    typename std::vector<T>::iterator i = array.end() - 1;
    while (i > array.begin() && *(i - 1) >= *i)
        --i;
    if (i == array.begin())
        return false;

    // Find successor to pivot
    typename std::vector<T>::iterator j = array.end() - 1;
    while (*j <= *(i - 1))
        --j;
    std::iter_swap(i - 1, j);

    // Reverse suffix
    std::reverse(i, array.end());
    return true;
}
