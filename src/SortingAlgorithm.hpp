#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {


template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
	/*
    const unsigned int n = v.size();

    for(unsigned int i = 0; i < n - 1; i++)
    {
        unsigned int min_index = i;
        for(unsigned int j = i + 1; j < n; j++)
        {
            if(v[j] < v[min_index])
                min_index = j;
        }

        // swap:
        T tmp = v[i];
        v[i] = v[min_index];
        v[min_index] = tmp;
    }
	*/
}

template<Sortable T>
void HeapSort(std::vector<T>& v)
{
	/*
    const unsigned int n = v.size();

    for(unsigned int i = 1; i < n; i++)
    {
        unsigned int j = i;
        while(j > 0 && v[j] < v[j - 1])
        {
            // swap:
            T tmp = v[j];
            v[j] = v[j - 1];
            v[j - 1] = tmp;

            j--;
        }


    }
*/
}


}
