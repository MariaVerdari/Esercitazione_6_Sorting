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
	
    const unsigned int n = v.size();
	
	for(unsigned int i = 0; i < n - 1; i++)
    {
		for (unsigned int j = i+1; j< n; j++)
		{
			if (v[j] < v[i])
			{
				// swap:
				T tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
 

        
    }
	
}

template<Sortable T>
void HeapSort(std::vector<T>& v)
{
	const unsigned int n = v.size();
	T heap[n];
	heap[0] = v[0];

	unsigned int padre;
	unsigned int maggiore;

	for (unsigned int i = 1; i < n; i++) {
		
		unsigned int j = i;
		bool okay = false;
		while (not okay) {
			if (j % 2 == 0)
				padre = (j-2)/2;
			else
				 padre = (j-1)/2;
			
			if (v[i] > heap[padre])
			{
				T tmp = heap[padre];
				heap[padre] = v[i];
				heap[j] = tmp;
				j = padre;
				if (j == 0)
					okay = true;
				
			}
			else {
				heap[j] = v[i];
				okay = true;
			}
			
			
		
		}	

	}
	
	unsigned int heap_size = n;
	while (heap_size > 0){
		v[heap_size-1] = heap[0];
		heap[0] = heap[heap_size-1];
		
		unsigned int i=0;
		bool correct = false;
		
		while(2*i + 1 < heap_size && not correct){ // ha almeno un figlio
			if (2*i + 2 < heap_size){ // ha 2 figli
			if (heap[2*i+1] >= heap[2*i+2])
				 maggiore = 2*i + 1;
			else 
				 maggiore = 2*i + 2;
		
			if (heap[i] < heap[maggiore]){
				T tmp = heap[i];
				heap[i] = heap[maggiore];
				heap[maggiore] = tmp;
				i = maggiore;
				}
			else
				correct = true;
			
			}
			else{ // ha solo un figlio
				if (heap[2*i + 1 ] > heap[i])   {
					T tmp = heap[i];
					heap[i] = heap[2*i + 1 ];
					heap[2*i + 1 ] = tmp;
					i = 2*i + 1;
									
				}
				correct = true;
				
			}
						
		}
		heap_size -=1;
			
	}
		
	
	
	
	
	
	


}


}
